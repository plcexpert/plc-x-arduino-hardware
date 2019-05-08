/******************************************************************
  Project name : PLC-DIO Library v. 1.1
  Author       : 
  Date Time    :
  Description  : Digital IO shield    
  CPU BOARD    : MicroPLC
  URL          : www.plc-expert.com
******************************************************************/

#ifndef PLC_DIO_h
#define PLC_DIO_h

#include <Arduino.h>

#define PLC_DIO_LIB_VERSION "0.2"

class PLC_DIO
{
public:
    PLC_DIO()
	{	
		SetupPorts();
	};
	~PLC_DIO(){};
	
	bool Input(int InputNumber);
    void Output(int OutputNumber, bool NewState);
	
private:
   void SetupPorts();
};
#endif
