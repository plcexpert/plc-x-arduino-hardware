/******************************************************************
  Project name : PLC-Micro board Library v. 1.1
  Author       : 
  Date Time    :
  Description  : 
  CPU BOARD    : PLC-Micro
  URL          : www.plc-expert.com
******************************************************************/

#ifndef PLC_Micro_h
#define PLC_Micro_h

#include <Arduino.h>

class PLC_Micro
{
public:
    PLC_Micro()
	{	
		SetupPorts();
	};
	~PLC_Micro(){};
	
private:
   void SetupPorts();
};
#endif
