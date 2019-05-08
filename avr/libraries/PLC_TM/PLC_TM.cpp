/******************************************************************
  Project name : PLC-TM board Library v. 1.1
  Author       : 
  Date Time    :
  Description  : Temperature module
  CPU BOARD    : 
  URL          : www.plc-expert.com
******************************************************************/

#include "PLC_TM.h"

PLC_TM::PLC_TM(){		
	SetupPorts();	
};

//Constructor
void PLC_TM::SetupPorts()
{
	//INPUTS
	//InputPin_1 is analog input only
	//InputPin_4 is analog input only
    pinMode(InputPin_3, INPUT);
	pinMode(InputPin_4, INPUT);	
	
	//OUTPUTS
    pinMode(OutputPin_1, OUTPUT);
	pinMode(OutputPin_2, OUTPUT);
	pinMode(OutputPin_3, OUTPUT);
	pinMode(OutputPin_4, OUTPUT);
	pinMode(OutputPin_5, OUTPUT);
	pinMode(OutputPin_6, OUTPUT);
}
//PUBLIC METHODSvoid PLC_TM::Output(int OutputNumber, bool NewState){	
		byte port_number;
	
	switch(OutputNumber)
	{
		case 1:	
			port_number = OutputPin_1;
			break;
		case 2:
			port_number = OutputPin_2;
			break;
		case 3:
			port_number = OutputPin_3;
			break;
		case 4:
			port_number = OutputPin_4;
			break;
		case 5:
			port_number = OutputPin_5;
			break;
		case 6:
			port_number = OutputPin_6;
			break;
		default:
			return;
	}	
	
	digitalWrite(port_number, NewState);}
bool PLC_TM::Input(int InputNumber){
  	byte port_number;
	
	switch(InputNumber)
	{
		case 1:	
			port_number = InputPin_1;
			break;
		case 2:
			port_number = InputPin_2;
			break;
		case 3:
			port_number = InputPin_3;
			break;
		case 4:
			port_number = InputPin_4;
			break;
	}
	
	if(port_number == InputPin_1 || port_number == InputPin_2)
	{
		//analog inputs only
		return (analogRead(port_number) < 500);
	}
	else
	{
		return !digitalRead(port_number);  
	}
}