/*
Copyright 2012-2014 Kasper Skårhøj, SKAARHOJ K/S, kasper@skaarhoj.com

This file is part of the Blackmagic Design ATEM Client library for Arduino

The ATEM library is free software: you can redistribute it and/or modify 
it under the terms of the GNU General Public License as published by the 
Free Software Foundation, either version 3 of the License, or (at your 
option) any later version.

The ATEM library is distributed in the hope that it will be useful, but 
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
or FITNESS FOR A PARTICULAR PURPOSE. 
See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along 
with the ATEM library. If not, see http://www.gnu.org/licenses/.


IMPORTANT: If you want to use this library in your own projects and/or products,
please play a fair game and heed the license rules! See our web page for a Q&A so
you can keep a clear conscience: http://skaarhoj.com/about/licenses/
*/


#include "ATEMstd.h"

/**
 * Constructor (using arguments is deprecated! Use begin() instead)
 */
ATEMstd::ATEMstd() {}



void ATEMstd::delay(const unsigned int delayTimeMillis) {  // Responsible delay function which keeps the ATEM run loop up! DO NOT USE INSIDE THIS CLASS! Recursion could happen...
  runLoop(delayTimeMillis);
}




/********************************
 *
 * ATEM Switcher state methods
 * Returns the most recent information we've 
 * got about the switchers state
 *
 ********************************/

uint16_t ATEMstd::getProgramInput() {
  return getProgramInputVideoSource(0);
}
uint16_t ATEMstd::getPreviewInput() {
  return getPreviewInputVideoSource(0);
}
boolean ATEMstd::getProgramTally(uint8_t inputNumber) {
  return (getTallyByIndexTallyFlags(inputNumber - 1) & 1) > 0 ? true : false;
}
boolean ATEMstd::getPreviewTally(uint8_t inputNumber) {
  return (getTallyByIndexTallyFlags(inputNumber - 1) & 2) > 0 ? true : false;
}


// *********************************
// **
// ** Implementations in ATEMstd.c:
// **
// *********************************

void ATEMstd::_parseGetCommands(const char *cmdStr) {
  uint8_t mE, keyer, colorGenerator, aUXChannel, mediaPlayer, macroIndex;
  uint16_t index, audioSource, sources;
  long temp;
  uint8_t readBytesForTlSr;


  if (!strcmp_P(cmdStr, PSTR("AMLv"))) {
    _readToPacketBuffer(36);
  } else if (!strcmp_P(cmdStr, PSTR("TlSr"))) {
    readBytesForTlSr = ((ATEM_packetBufferLength - 2) / 3) * 3 + 2;
    _readToPacketBuffer(readBytesForTlSr);
  } else {
    _readToPacketBuffer();  // Default
  }




  if (!strcmp_P(cmdStr, PSTR("TlIn"))) {
    sources = word(_packetBuffer[0], _packetBuffer[1]);
    if (sources <= 20) {
#if ATEM_debug
      temp = atemTallyByIndexSources;
#endif
      atemTallyByIndexSources = word(_packetBuffer[0], _packetBuffer[1]);
#if ATEM_debug
      if ((_serialOutput == 0x80 && atemTallyByIndexSources != temp) || (_serialOutput == 0x81 && !hasInitialized())) {
        //Serial.print(F("atemTallyByIndexSources = "));
        //Serial.println(atemTallyByIndexSources);
      }
#endif
      //Serial.printf("%u", sources);
      for (uint8_t a = 0; a < sources; a++) {
#if ATEM_debug
        temp = atemTallyByIndexTallyFlags[a];
#endif

        atemTallyByIndexTallyFlags[a] = _packetBuffer[2 + a];
#if ATEM_debug
        if ((_serialOutput == 0x80 && atemTallyByIndexTallyFlags[a] != temp) || (_serialOutput == 0x81 && !hasInitialized())) {
          //Serial.println(atemTallyByIndexTallyFlags[a]);
        }
#endif
      }
    }
  }
}




/**
			 * Get Program Input; Video Source
			 * mE 	0: ME1, 1: ME2
			 */
uint16_t ATEMstd::getProgramInputVideoSource(uint8_t mE) {
  return atemProgramInputVideoSource[mE];
}

/**
			 * Get Preview Input; Video Source
			 * mE 	0: ME1, 1: ME2
			 */
uint16_t ATEMstd::getPreviewInputVideoSource(uint8_t mE) {
  return atemPreviewInputVideoSource[mE];
}

/**
			 * Get Tally By Index; Sources
			 */
uint16_t ATEMstd::getTallyByIndexSources() {
  return atemTallyByIndexSources;
}

/**
			 * Get Tally By Index; Tally Flags
			 * sources 	0-20: Number of
			 */
uint8_t ATEMstd::getTallyByIndexTallyFlags(uint16_t sources) {
  return atemTallyByIndexTallyFlags[sources];
}
