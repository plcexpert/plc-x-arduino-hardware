/******************************************************************
  Project name : PLC-DIO 1.3 library
  Author       : 
  Date Time    :
  Description  : igital IO shield    
  CPU BOARD    : MicroPLC
  URL          : www.plc-expert.com
******************************************************************/

#ifndef PlcX_DIO13_h
#define PlcX_DIO13_h

#include <Arduino.h>

#define PlcX_DIO13_LIB_VERSION "0.3"

class PlcX_DIO13
{
public:
    PlcX_DIO13()
	{	
		SetupPorts();
	};
	~PlcX_DIO13(){};
	
	bool Input(int InputNumber);
    void Output(int OutputNumber, bool NewState);
	
private:
   void SetupPorts();
};
#endif
