/******************************************************************
  Project name : PLC automation Library v. 1.1
  Author       : 
  Date Time    :
  Description  : 
  CPU BOARD    : PLC hardware
  URL          : www.plc-expert.com
******************************************************************/

#ifndef PlcX_Automation_h
#define PlcX_Automation_h

#include <Arduino.h>

union IoPorts
{
	uint8_t Value;
	struct
	{
		bool port1 : 1;
		bool port2 : 1;
		bool port3 : 1;
		bool port4 : 1;
		bool port5 : 1;
		bool port6 : 1;
		bool port7 : 1;
		bool port8 : 1;
	};
};

class PlcX_Automation
{
public:
    PlcX_Automation(){
	};
	~PlcX_Automation(){
		
	};
	
	bool Input(uint8_t InputNumber);
    void Output(uint8_t OutputNumber, bool NewState);
    bool Output(uint8_t OutputNumber);
	
private:

};	
#endif
