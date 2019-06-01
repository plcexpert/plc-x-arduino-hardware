/******************************************************************
  Project name : PLC automation Library v. 1.1
  Author       : 
  Date Time    :
  Description  : 
  CPU BOARD    : PLC hardware
  URL          : www.plc-expert.com
******************************************************************/
#include "PLC_Automation.h"

//PRIVATE METHODS


//PUBLIC METHODS
bool PLC_Automation::Input(uint8_t InputNumber){
	if(InputNumber == A6 || InputNumber == A7){
		int val = analogRead(InputNumber);
		
		return !(val > 800);
	}
	else{
		return !digitalRead(InputNumber);
	}	
}

void PLC_Automation::Output(uint8_t OutputNumber, bool NewState){
	digitalWrite(OutputNumber, NewState);	
}

bool PLC_Automation::Output(uint8_t OutputNumber){
	return digitalRead(OutputNumber);
}