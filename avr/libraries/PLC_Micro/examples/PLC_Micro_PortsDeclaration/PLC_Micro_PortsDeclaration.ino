/******************************************************************
  Project name : PLC-Micro example project
  Author       : 
  Date Time    : 
  Description  : 
  CPU BOARD    : PLC-Micro
  URL          : www.plc-expert.com
******************************************************************/
#include "PLC_Micro.h"
PLC_Micro plc;

void setup(){
} 

void loop(){
  
  //Read input state
  bool input_state = plc.Input(5);
  
  plc.Output(7, !input_state);
  
  delay(100);
}