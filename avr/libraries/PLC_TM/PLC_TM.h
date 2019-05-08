/******************************************************************
  Project name : PLC-TM board Library v. 1.1
  Author       : 
  Date Time    :
  Description  : Temperature module
  CPU BOARD    : 
  URL          : www.plc-expert.com
******************************************************************/


#ifndef PLC_TM_h
#define PLC_TM_h

#include <Arduino.h>

#define PLC_TM_LIB_VERSION "0.1"

//Digital inputs
#define InputPin_1 21	//A7
#define InputPin_2 20	//A6
#define InputPin_3 13
#define InputPin_4 12

//Digital outputs
#define OutputPin_1 14	//A0
#define OutputPin_2 15	//A1
#define OutputPin_3 16	//A2
#define OutputPin_4 17	//A3
#define OutputPin_5 2
#define OutputPin_6 3

#define T1 4
#define T2 5
#define T3 6
#define T4 7
#define T5 8
#define T6 9

//Software serial for ESP8266
#define PIN_RX 10
#define PIN_TX 11

#ifndef SoftwareSerial.h
	#include <SoftwareSerial.h>
#endif

class PLC_TM
{
public:
	PLC_TM();    
	~PLC_TM(){};	
	bool Input(int InputNumber);
    void Output(int OutputNumber, bool NewState);
private:
   void SetupPorts();
};
#endif
