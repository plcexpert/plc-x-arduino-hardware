/******************************************************************
  Project name : PLC-DIO 1.3 - Example project 
  Author       : 
  Date Time    :
  Description  :   
  CPU BOARD    : Arduon Uno (Atmel328P)
  URL          : www.plc-expert.com
******************************************************************/
#include <PLC_DIO13.h>
PLC_DIO13 dio;

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
