/******************************************************************
  Project name : PLC-Micro board Library v. 1.1
  Author       : 
  Date Time    :
  Description  : 
  CPU BOARD    : PLC-Micro
  URL          : www.plc-expert.com
******************************************************************/

#ifndef PlcX_Micro13_h
#define PlcX_Micro13_h

#include <Arduino.h>

class PlcX_Micro13
{
public:
    PlcX_Micro13()
	{	
		SetupPorts();
	};
	~PlcX_Micro13(){};
	void SetupPorts();
	 
private:

};
#endif
