/******************************************************************
  Project name : PLC-DIO 1.4
  Author       : 
  Date Time    :
  Description  : Digital IO shield    
  CPU BOARD    : MicroPLC
  URL          : www.plc-expert.com
******************************************************************/

#ifndef PLC_DIO14_h
#define PLC_DIO14_h

#include <Arduino.h>

#define PLC_DIO14_LIB_VERSION "0.1"

class PLC_DIO14
{
public:
    PLC_DIO14()
	{	
		SetupPorts();
	};
	~PLC_DIO14(){};
	
	bool Input(int InputNumber);
    void Output(int OutputNumber, bool NewState);
	
private:
   void SetupPorts();
};
#endif
