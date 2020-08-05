/******************************************************************
  Project name : PlcX-DIO 1.4 - Example project 
  Author       : 
  Date Time    :
  Description  :   
  CPU BOARD    : Arduon Nano (Atmel328P)
  URL          : www.plc-expert.com
******************************************************************/
#include <PlcX_DIO14.h>
PlcX_DIO14 dio;

void setup()
{
}

void loop()
{ 
  dio.Output(1, true);
  delay(1000);
  dio.Output(1, false);

  dio.Output(5, dio.Input(3));  
  delay(500);
}
