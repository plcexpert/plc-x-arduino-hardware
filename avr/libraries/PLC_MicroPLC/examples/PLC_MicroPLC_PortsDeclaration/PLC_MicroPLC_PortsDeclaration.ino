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

void setup(){
} 

void loop(){
  
  //Read input state
  bool input_state = plc.Input(5);
  
  plc.Output(7, !input_state);
  
  delay(100);
}