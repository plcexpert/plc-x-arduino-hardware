/******************************************************************
  Project name : MicroPLC example project
  Author       : 
  Date Time    : 
  Description  : 
  CPU BOARD    : MicroPLC
  URL          : www.plc-expert.com
******************************************************************/
#include "PLC_MicroPLC.h"
PLC_MicroPLC plc;

bool state;

void setup(){
} 

void loop(){  
  plc.Output(1, state);
  plc.Output(2, state);
  plc.Output(3, state);
  plc.Output(4, state);
  plc.Output(5, state);
  plc.Output(6, state);
  plc.Output(7, state);
  plc.Output(8, state);  
  delay(2000);
  
  state = !state;
  delay(2000);
}
