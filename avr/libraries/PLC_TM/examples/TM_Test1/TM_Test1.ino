#include "PLC_TM.h"
PLC_TM tm;
SoftwareSerial wifiSerial(PIN_RX, PIN_TX);

//DS18B20 temperature sensors
#include "PLC_DS18B20.h"
PLC_DS18B20 ds;
//OneWire sensors[] = {T1, T2, T3, T4, T5, T6};

bool stav;

void setup() {
  //serial port is shared with CAN-BUS
  Serial.begin(57600);
  wifiSerial.begin(9600);
}

void loop() {
  tm.Output(1, stav);
  delay(100);
  tm.Output(2, stav);
  delay(100);
  tm.Output(3, stav);
  delay(100);
  tm.Output(4, stav);
  delay(100);
  tm.Output(5, stav);
  delay(100);
  tm.Output(6, stav);
  delay(100);  
  
  stav = !stav;

  Serial.println("--- PLC_TM ---");
  Serial.println(millis());
  Serial.println(tm.Input(1));
  Serial.println(tm.Input(2));
  Serial.println(tm.Input(3));
  Serial.println(tm.Input(4));

  ReadSensors();

  wifiSerial.println("Data from PLC-TM to ESP8266-01 Module");
  delay(2000);
}

void ReadSensors(){
  for(int n =T1;n<T6+1;n++)
  {
    Serial.print("Sensor ");
    Serial.print(String(n-3));
    Serial.print("=");
    Serial.println(ds.ReadSensor(n));
    Serial.println("-------");
  }
}
