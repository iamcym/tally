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


#ifndef ATEMstd_h
#define ATEMstd_h

#include "D:\User.File\Arduino\ESP8266\BMDTally\ATEMbase.h"



class ATEMstd : public ATEMbase {
private:



public:
  ATEMstd();


  void delay(const unsigned int delayTimeMillis);

  /********************************
	* ATEM Switcher state methods
	* Returns the most recent information we've 
	* got about the switchers state
	 ********************************/
  uint16_t getProgramInput();
  uint16_t getPreviewInput();
  boolean getProgramTally(uint8_t inputNumber);
  boolean getPreviewTally(uint8_t inputNumber);


  /********************************
	 * ATEM Switcher Change methods
	 * Asks the switcher to changes something
	 ********************************/
  void changeProgramInput(uint16_t inputNumber);
  void changePreviewInput(uint16_t inputNumber);


  // *********************************
  // **
  // ** Implementations in ATEMstd.h:
  // **
  // *********************************



private:
  void _parseGetCommands(const char *cmdStr);

  // Private Variables in ATEM.h:

  uint16_t atemProtocolVersionMajor;
  uint16_t atemProtocolVersionMinor;
  uint8_t atemVideoModeFormat;
  uint16_t atemProgramInputVideoSource[2];
  uint16_t atemPreviewInputVideoSource[2];
  uint16_t atemTallyByIndexSources;
  uint8_t atemTallyByIndexTallyFlags[21];

public:
  // Public Methods in ATEM.h:

  uint8_t getVideoModeFormat();
  void setVideoModeFormat(uint8_t format);
  uint16_t getProgramInputVideoSource(uint8_t mE);
  void setProgramInputVideoSource(uint8_t mE, uint16_t videoSource);
  uint16_t getPreviewInputVideoSource(uint8_t mE);
  void setPreviewInputVideoSource(uint8_t mE, uint16_t videoSource);
  void performCutME(uint8_t mE);
  void performAutoME(uint8_t mE);
  uint16_t getAuxSourceInput(uint8_t aUXChannel);
  void setAuxSourceInput(uint8_t aUXChannel, uint16_t input);
  uint16_t getTallyByIndexSources();
  uint8_t getTallyByIndexTallyFlags(uint16_t sources);
};

#endif
