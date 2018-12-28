#include "PLC_TM.h"

PLC_TM tm;
SoftwareSerial wifiSerial (PIN_RX, PIN_TX);

void setup(){
	wifiSerial.begin(57600);
} 

void loop(){
  
  //Read input state
  bool input_state = tm.Input(1);
  
  tm.Output(2, !input_state);
  
  wifiSerial.print("Input state");
  wifiSerial.println(input_state);
  
  delay(1000);
}