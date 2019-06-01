/******************************************************************
  Project name : CAN BUS SLAVE MODULE
  Author       :
  Date Time    : 2019-05-19
  Description  :
  CPU BOARD    : PLC-Micro
  URL          : www.plc-expert.com
******************************************************************/
#include <PLC_Automation.h>
#include <PLC_Micro.h>

// I/O declaration
PLC_Micro micro;          //Micro Board, initializes pin modes automatically
PLC_Automation plc;       //Automation features
IoPorts Inputs;           // Inputs 1-8
IoPorts Outputs;          // Outputs 1-8

void setup()
{
}

void loop()
{  
  ReadInputs();
  SetupOutputs();
  
  delay(200);
}


void ReadInputs()
{
  Inputs.port1 = plc.Input(INPUT_1);
  Inputs.port2 = plc.Input(INPUT_2);
  Inputs.port3 = plc.Input(INPUT_3);
  Inputs.port4 = plc.Input(INPUT_4);
  Inputs.port5 = plc.Input(INPUT_5);
  Inputs.port6 = plc.Input(INPUT_6);
  Inputs.port7 = plc.Input(INPUT_7);
  Inputs.port8 = plc.Input(INPUT_8);
}

void SetupOutputs() 
{
    plc.Output(OUTPUT_1, Outputs.port1);
    plc.Output(OUTPUT_2, Outputs.port2);
    plc.Output(OUTPUT_3, Outputs.port3);
    plc.Output(OUTPUT_4, Outputs.port4);
    plc.Output(OUTPUT_5, Outputs.port5);
    plc.Output(OUTPUT_6, Outputs.port6);
    plc.Output(OUTPUT_7, Outputs.port7);
    plc.Output(OUTPUT_8, Outputs.port8);
}
