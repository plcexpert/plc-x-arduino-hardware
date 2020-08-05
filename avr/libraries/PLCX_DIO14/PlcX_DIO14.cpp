/******************************************************************
  Project name : PLC-DIO 1.4.
  Author       : 
  Date Time    :
  Description  : Digital IO shield  
  CPU BOARD    : MicroPLC
  URL          : www.plc-expert.com
******************************************************************/

#include "PLC_DIO14.h"

#define INPUT_1 0
#define INPUT_2 1
#define INPUT_3 2
#define INPUT_4 3
#define INPUT_5 4
#define INPUT_6 5
#define INPUT_7 6
#define INPUT_8 A7
#define INPUT_9 A6
#define INPUT_10 A3
#define INPUT_11 A2
#define INPUT_12 A1
#define INPUT_13 A0

#define OUTPUT_1 13
#define OUTPUT_2 12
#define OUTPUT_3 11
#define OUTPUT_4 10
#define OUTPUT_5 9
#define OUTPUT_6 8
#define OUTPUT_7 7

//PRIVATE METHODS
void PLC_DIO14::SetupPorts(){
  pinMode(INPUT_1, INPUT);	
  pinMode(INPUT_2, INPUT);
  pinMode(INPUT_3, INPUT);
  pinMode(INPUT_4, INPUT);
  pinMode(INPUT_5, INPUT);
  pinMode(INPUT_6, INPUT);
  pinMode(INPUT_7, INPUT);
  pinMode(INPUT_8, INPUT);
  pinMode(INPUT_9, INPUT);	
  pinMode(INPUT_10, INPUT);
  pinMode(INPUT_11, INPUT);
  //pinMode(INPUT_12, INPUT);//ANALOG
  //pinMode(INPUT_13, INPUT);//ANALOG
  
  pinMode(OUTPUT_1, OUTPUT);
  pinMode(OUTPUT_2, OUTPUT);
  pinMode(OUTPUT_3, OUTPUT);
  pinMode(OUTPUT_4, OUTPUT);
  pinMode(OUTPUT_5, OUTPUT);
  pinMode(OUTPUT_6, OUTPUT);
  pinMode(OUTPUT_7, OUTPUT); 
}

//PUBLIC METHODSbool PLC_DIO14::Input(int InputNumber){
  	byte port_number;
	
	switch(InputNumber)
	{
		case 1:	
			port_number = INPUT_1;
			break;
		case 2:
			port_number = INPUT_2;
			break;
		case 3:
			port_number = INPUT_3;
			break;
		case 4:
			port_number = INPUT_4;
			break;
		case 5:
			port_number = INPUT_5;
			break;
		case 6:
			port_number = INPUT_6;
			break;
		case 7:
			port_number = INPUT_7;
			break;
		case 8:
			port_number = INPUT_8;
			break;
		case 9:
			port_number = INPUT_9;
			break;
		case 10:		
			port_number = INPUT_10;
			break;
		case 11:
			port_number = INPUT_11;
			break;
		case 12:
			port_number = INPUT_12;
			break;
		case 13:
			port_number = INPUT_13;
			break;
	}
	
	if(port_number == INPUT_12 || port_number == INPUT_13)
	{
		//analog inputs only
		return (analogRead(port_number) < 500);
	}
	else
	{
		return !digitalRead(port_number);  
	}
}

void PLC_DIO14::Output(int OutputNumber, bool NewState){
	byte port_number;

	switch(OutputNumber)
	{
		case 1:	
			port_number = OUTPUT_1;
			break;
		case 2:
			port_number = OUTPUT_2;
			break;
		case 3:
			port_number = OUTPUT_3;
			break;
		case 4:
			port_number = OUTPUT_4;
			break;
		case 5:
			port_number = OUTPUT_5;
			break;
		case 6:
			port_number = OUTPUT_6;
			break;
		case 7:
			port_number = OUTPUT_7;
			break;
	}	
	
	digitalWrite(port_number, NewState);
}