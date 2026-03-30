
#include "ATEMbase.h"


ATEMbase::ATEMbase() {}

/**
 * Setting up IP address for the switcher (and local port to send packets from)
 * Using local port here is deprecated. Rather let the library pick a random one
 */
void ATEMbase::begin(const IPAddress ip) {
  begin(ip, random(50100, 65300));
}
void ATEMbase::begin(const IPAddress ip, const uint16_t localPort) {
	if (_Udp) {
    _Udp.stop();  // 释放之前的 UDP 资源
  }

  neverConnected = true;
  waitingForIncoming = false;

  // Set up Udp communication object:
#ifdef ESP8266
  WiFiUDP Udp;
#else
  EthernetUDP Udp;
#endif

  _Udp = Udp;

  _switcherIP = ip;        // Set switcher IP address
  _localPort = localPort;  // Set default local port

  _lastContact = 0;
  _serialOutput = 0;

  //resetCommandBundle();
}

/**
 * Initiating connection handshake to the ATEM switcher
 */
void ATEMbase::connect() {
  connect(false);
}

/**
 * Initiating connection handshake to the ATEM switcher
 * If useFixedPortNumber is true, the same port number will be used on subsequent connects, otherwise - and recommended - a new, random port number is used.
 */
//要
void ATEMbase::connect(const boolean useFixedPortNumber) {
  _localPacketIdCounter = 0;  // Init localPacketIDCounter to 0;
  _initPayloadSent = false;   // Will be true after initial payload of data is delivered (regular 12-byte ping packages are transmitted.)
  _hasInitialized = false;    // Will be true after initial payload of data is resent and received well
  _isConnected = false;       // Will be true after the initial hello-package handshakes.
  _sessionID = 0x53AB;        // Temporary session ID - a new will be given back from ATEM.
  _lastContact = millis();    // Setting this, because even though we haven't had contact, it constitutes an attempt that should be responded to at least
  memset(_missedInitializationPackages, 0xFF, (ATEM_maxInitPackageCount + 7) / 8);
  _initPayloadSentAtPacketId = ATEM_maxInitPackageCount;  // The max value it can be
  uint16_t portNumber = useFixedPortNumber ? _localPort : random(50100, 65300);

  _Udp.begin(portNumber);


  // Send connectString to ATEM:
  if (_serialOutput) {
    //Serial.print(F("Sending connect packet to ATEM switcher on IP "));
    //Serial.print(_switcherIP);
    //Serial.print(F(":"));
    //Serial.println(portNumber);
  }

  _wipeCleanPacketBuffer();
  _createCommandHeader(ATEM_headerCmd_HelloPacket, 12 + 8);
  _packetBuffer[12] = 0x01;  // This seems to be what the client should send upon first request.
  _packetBuffer[9] = 0x3a;   // This seems to be what the client should send upon first request.

  _sendPacketBuffer(20);
}

/**
 * Keeps connection to the switcher alive
 * Therefore: Call this in the Arduino loop() function and make sure it gets call at least 2 times a second
 * Other recommendations might come up in the future.
 */
void ATEMbase::runLoop() {
  runLoop(0);
}
void ATEMbase::runLoop(uint16_t delayTime) {
  if (neverConnected) {
    neverConnected = false;
    connect();
    //		Serial.println("Connecting first time...");
  }

  unsigned long enterTime = millis();

  do {
    while (true) {  // Iterate until UDP buffer is empty
      uint16_t packetSize = _Udp.parsePacket();
      if (_Udp.available()) {
        _Udp.read(_packetBuffer, 12);  // Read header
        _sessionID = word(_packetBuffer[2], _packetBuffer[3]);
        uint8_t headerBitmask = _packetBuffer[0] >> 3;
        _lastRemotePacketID = word(_packetBuffer[10], _packetBuffer[11]);
        if (_lastRemotePacketID < ATEM_maxInitPackageCount) {
          _missedInitializationPackages[_lastRemotePacketID >> 3] &= ~(B1 << (_lastRemotePacketID & 0x07));
        }

        uint16_t packetLength = word(_packetBuffer[0] & B00000111, _packetBuffer[1]);

        if (packetSize == packetLength) {  // Just to make sure these are equal, they should be!
          _lastContact = millis();
          waitingForIncoming = false;

          if (headerBitmask & ATEM_headerCmd_HelloPacket) {  // Respond to "Hello" packages:
            _isConnected = true;

            // _packetBuffer[12]	The ATEM will return a "2" in this return package of same length. If the ATEM returns "3" it means "fully booked" (no more clients can connect) and a "4" seems to be a kind of reconnect (seen when you drop the connection and the ATEM desperately tries to figure out what happened...)
            // _packetBuffer[15]	This number seems to increment with about 3 each time a new client tries to connect to ATEM. It may be used to judge how many client connections has been made during the up-time of the switcher?

            _wipeCleanPacketBuffer();
            _createCommandHeader(ATEM_headerCmd_Ack, 12);
            _packetBuffer[9] = 0x03;  // This seems to be what the client should send upon first request.
            _sendPacketBuffer(12);
          }

          // If a packet is 12 bytes long it indicates that all the initial information
          // has been delivered from the ATEM and we can begin to answer back on every request
          // Currently we don't know any other way to decide if an answer should be sent back...
          // The QT lib uses the "InCm" command to indicate this, but in the latest version of the firmware (2.14)
          // all the camera control information comes AFTER this command, so it's not a clear ending token anymore.
          // However, I'm not sure if I checked the _lastRemotePacketID of the packages with the additional camera control info - if it was a resend,
          // "InCm" may still indicate the number of the last init-package and that's all I need to request the missing ones....

          // BTW: It has been observed on an old 10Mbit hub that packages could arrive in a different order than sent and this may
          // mess things up a bit on the initialization. So it's recommended to has as direct routes as possible.
          if (!_initPayloadSent && packetSize == 12 && _lastRemotePacketID > 1) {
            _initPayloadSent = true;
            _initPayloadSentAtPacketId = _lastRemotePacketID;
          }

          if (_initPayloadSent && (headerBitmask & ATEM_headerCmd_AckRequest) && (_hasInitialized || !(headerBitmask & ATEM_headerCmd_Resend))) {  // Respond to request for acknowledge	(and to resends also, whatever...
            _wipeCleanPacketBuffer();
            _createCommandHeader(ATEM_headerCmd_Ack, 12, _lastRemotePacketID);
            _sendPacketBuffer(12);


            if (_serialOutput > 1) {
              //Serial.print(F("rpIDb: "));
              //Serial.print(_lastRemotePacketID, DEC);
              //Serial.println(F(" - ACK!"));
            }
          } else if (_initPayloadSent && (headerBitmask & ATEM_headerCmd_RequestNextAfter) && _hasInitialized) {  // ATEM is requesting a previously sent package which must have dropped out of the order. We return an empty one so the ATEM doesnt' crash (which some models will, if it doesn't get an answer before another 63 commands gets sent from the controller.)
            uint8_t b1 = _packetBuffer[6];
            uint8_t b2 = _packetBuffer[7];
            _wipeCleanPacketBuffer();
            _createCommandHeader(ATEM_headerCmd_Ack, 12, 0);
            _packetBuffer[0] = ATEM_headerCmd_AckRequest << 3;  // Overruling this. A small trick because createCommandHeader shouldn't increment local package ID counter
            _packetBuffer[10] = b1;
            _packetBuffer[11] = b2;
            _sendPacketBuffer(12);

            if (_serialOutput > 1) {
              Serial.print(F("ATEM asking to resend "));
              Serial.println((b1 << 8) | b2, DEC);
            }
          } else {

            if (_serialOutput > 1) {
              //Serial.print(F("rpIDd: "));
              //Serial.println(_lastRemotePacketID, DEC);
            }
          }

          if (!(headerBitmask & ATEM_headerCmd_HelloPacket) && packetLength > 12) {
            _parsePacket(packetLength);
          }
        } else {

          // Flushing:
          while (_Udp.available()) {
            _Udp.read(_packetBuffer, ATEM_packetBufferLength);
          }
        }
      } else break;
    }

    // After initialization, we check which packages were missed and ask for them:
    //要
    if (!_hasInitialized && _initPayloadSent && !waitingForIncoming) {
      for (uint8_t i = 1; i < _initPayloadSentAtPacketId; i++) {
        if (i <= ATEM_maxInitPackageCount) {
          if (_missedInitializationPackages[i >> 3] & (B1 << (i & 0x7))) {


            _wipeCleanPacketBuffer();
            _createCommandHeader(ATEM_headerCmd_RequestNextAfter, 12);
            _packetBuffer[6] = highByte(i - 1);  // Resend Packet ID, MSB
            _packetBuffer[7] = lowByte(i - 1);   // Resend Packet ID, LSB
            _packetBuffer[8] = 0x01;

            _sendPacketBuffer(12);
            waitingForIncoming = true;
            break;
          }
        } else {
          break;
        }
      }
      if (!waitingForIncoming) {
        _hasInitialized = true;
        if (_serialOutput) {
          //Serial.println(F("ATEM _hasInitialized = TRUE"));
        }
      }
    }
  } while (delayTime > 0 && !hasTimedOut(enterTime, delayTime));


  // If connection is gone anyway, try to reconnect:
  //要
  if (hasTimedOut(_lastContact, 3000)) {
    //if (_serialOutput) Serial.println(F("Connection to ATEM Switcher has timed out - reconnecting!"));
    if (_serialOutput) Serial.print(F("R"));
    connect();
  }
}

/**
 * Returns last Remote Packet ID
 */
uint16_t ATEMbase::getATEM_lastRemotePacketId() {
  return _lastRemotePacketID;
}

/**
 * Get ATEM session ID
 */
uint16_t ATEMbase::getSessionID() {
  return _sessionID;
}

/**
 * If true, we had a response from the switcher when trying to send a hello packet.
 */
bool ATEMbase::isConnected() {
  return _isConnected;
}

/**
 * If true, the initial handshake and "stressful" information exchange has occured and now the switcher connection should be ready for operation. 
 */
bool ATEMbase::hasInitialized() {
  return _hasInitialized;
}






/**************
 *
 * Buffer work
 *
 **************/
//要的
void ATEMbase::_createCommandHeader(const uint8_t headerCmd, const uint16_t lengthOfData) {
  _createCommandHeader(headerCmd, lengthOfData, 0);
}
//要的
void ATEMbase::_createCommandHeader(const uint8_t headerCmd, const uint16_t lengthOfData, const uint16_t remotePacketID) {
  _packetBuffer[0] = (headerCmd << 3) | (highByte(lengthOfData) & 0x07);  // Command bits + length MSB
  _packetBuffer[1] = lowByte(lengthOfData);                               // length LSB

  _packetBuffer[2] = highByte(_sessionID);  // Session ID
  _packetBuffer[3] = lowByte(_sessionID);   // Session ID

  _packetBuffer[4] = highByte(remotePacketID);  // Remote Packet ID, MSB
  _packetBuffer[5] = lowByte(remotePacketID);   // Remote Packet ID, LSB

  if (!(headerCmd & (ATEM_headerCmd_HelloPacket | ATEM_headerCmd_Ack | ATEM_headerCmd_RequestNextAfter))) {
    _localPacketIdCounter++;

    //		if ((_localPacketIdCounter & 0xF) == 0xF) _localPacketIdCounter++;	// Uncommenting this line will jump the local package ID counter every 15 command - thereby introducing a stress test of the robustness of the "resent package" function from the ATEM switcher.

    _packetBuffer[10] = highByte(_localPacketIdCounter);  // Local Packet ID, MSB
    _packetBuffer[11] = lowByte(_localPacketIdCounter);   // Local Packet ID, LSB
  }
}
void ATEMbase::_sendPacketBuffer(uint8_t length) {
  _Udp.beginPacket(_switcherIP, 9910);
  _Udp.write(_packetBuffer, length);
  _Udp.endPacket();  // TODO: Figure out why this may hang!!
}

/**
 * Sets all zeros in packet buffer:
 */
void ATEMbase::_wipeCleanPacketBuffer() {
  memset(_packetBuffer, 0, ATEM_packetBufferLength);
}

/**
 * Reads from UDP channel to buffer. Will fill the buffer to the max or to the size of the current segment being parsed
 * Returns false if there are no more bytes, otherwise true 
 */
bool ATEMbase::_readToPacketBuffer() {
  return _readToPacketBuffer(ATEM_packetBufferLength);
}
//要的
bool ATEMbase::_readToPacketBuffer(uint8_t maxBytes) {
  maxBytes = maxBytes <= ATEM_packetBufferLength ? maxBytes : ATEM_packetBufferLength;
  int remainingBytes = _cmdLength - 8 - _cmdPointer;

  if (remainingBytes > 0) {
    if (remainingBytes <= maxBytes) {
      _Udp.read(_packetBuffer, remainingBytes);
      _cmdPointer += remainingBytes;
      return false;  // Returns false if finished.
    } else {
      _Udp.read(_packetBuffer, maxBytes);
      _cmdPointer += maxBytes;
      return true;  // Returns true if there are still bytes to be read.
    }
  } else {
    return false;
  }
}

/**
 * If a package longer than a normal acknowledgement is received from the ATEM Switcher we must read through the contents.
 * Usually such a package contains updated state information about the mixer
 * Selected information is extracted in this function and transferred to internal variables in this library.
 */
//要的
void ATEMbase::_parsePacket(uint16_t packetLength) {
  // If packet is more than an ACK packet (= if its longer than 12 bytes header), lets parse it:
  uint16_t indexPointer = 12;  // 12 bytes has already been read from the packet...
  while (indexPointer < packetLength) {

    // Read the length of segment (first word):
    _Udp.read(_packetBuffer, 8);
    _cmdLength = word(_packetBuffer[0], _packetBuffer[1]);
    _cmdPointer = 0;

    // Get the "command string", basically this is the 4 char variable name in the ATEM memory holding the various state values of the system:
    char cmdStr[] = {
      _packetBuffer[4], _packetBuffer[5], _packetBuffer[6], _packetBuffer[7], '\0'
    };

    // If length of segment larger than 8 (should always be...!)
    if (_cmdLength > 8) {
      _parseGetCommands(cmdStr);

      while (_readToPacketBuffer()) {}  // Empty, if not done yet.
      indexPointer += _cmdLength;
    } else {
      indexPointer = 2000;


      // Flushing the buffer:
      while (_Udp.available()) {
        _Udp.read(_packetBuffer, ATEM_packetBufferLength);
      }
    }
  }
}

/**
 * This method should be overloaded in subclasses in order to handle specific get-commands
 */
//要的
void ATEMbase::_parseGetCommands(const char *cmdString) {
  //	uint8_t mE, keyer, mediaPlayer, aUXChannel, windowIndex, multiViewer, memory, colorGenerator, box;
  //	uint16_t audioSource, videoSource;
  //	long temp;

  uint8_t numberOfReads = 1;
  while (_readToPacketBuffer()) {
    numberOfReads++;
  }
}






/**************
 *
 * Utilities from SkaarhojTools class:
 *
 **************/

/**
 * Setter method: If _serialOutput is set, the library may use Serial.print() to give away information about its operation - mostly for debugging.
 * 0= no output
 * 1= normal output (info)
 * 2= verbose
 * &0x80 (bit 7 set): verbose initial connection information
 */
void ATEMbase::serialOutput(uint8_t level) {
  _serialOutput = level;
}

/**
 * Timeout check
 */
//要的
bool ATEMbase::hasTimedOut(unsigned long time, unsigned long timeout) {
  if ((unsigned long)(time + timeout) <= (unsigned long)millis()) {  // This should "wrap around" if time+timout is larger than the size of unsigned-longs, right?
    return true;
  } else {
    return false;
  }
}





uint8_t ATEMbase::getATEMmodel() {
  return _ATEMmodel;
}
