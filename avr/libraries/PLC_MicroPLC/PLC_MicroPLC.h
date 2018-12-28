/******************************************************************
  Project name : Micro PLC board Library v. 1.1
  Author       : 
  Date Time    :
  Description  : 
  CPU BOARD    : MicroPLC
  URL          : www.plc-expert.com
******************************************************************/

#ifndef PLC_MicroPLC_h
#define PLC_MicroPLC_h

#include <Arduino.h>

class PLC_MicroPLC
{
public:
    PLC_MicroPLC()
	{	
		SetupPorts();
	};
	~PLC_MicroPLC(){};
	
	bool Input(int InputNumber);
    void Output(int OutputNumber, bool NewState);
	
private:
   void SetupPorts();
};
#endif
