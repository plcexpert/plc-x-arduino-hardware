/******************************************************************
  Project name : PlcX-Micro PLC board Library
  Author       : 
  Date Time    :
  Description  :   
  CPU BOARD    : PLC-Micro
  URL          : www.plc-expert.com
******************************************************************/
#include "PlcX_Micro13.h"

//PRIVATE METHODS
void PlcX_Micro13::SetupPorts(){
  //Setup port mode
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

  pinMode(OUTPUT_1, OUTPUT);
  pinMode(OUTPUT_2, OUTPUT);
  pinMode(OUTPUT_3, OUTPUT);
  pinMode(OUTPUT_4, OUTPUT);
  pinMode(OUTPUT_5, OUTPUT);
  pinMode(OUTPUT_6, OUTPUT);
  pinMode(OUTPUT_7, OUTPUT);
  pinMode(OUTPUT_8, OUTPUT);
}