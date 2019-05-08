/******************************************************************
  Project name : PLC-DIO - Example project 
  Author       : 
  Date Time    :
  Description  :   
  CPU BOARD    : Arduon Uno, Mini, Nano... (Atmel328P)
  URL          : www.plc-expert.com
******************************************************************/
#include <PLC_DIO.h>
PLC_DIO dio;

void setup()
{
}

void loop()
{ 
  if(dio.Input(10))
  {
    dio.Output(1, true);
  }
  else
  {
    dio.Output(1, false);
  }
   
  delay(100);
}
