#include "PLC_DS18B20.h"

//DS18B20 temperature sensors
PLC_DS18B20 ds;
#define dspin 9  //Where is connected your DS18B20 sensor

void setup() {
  //serial port is shared with CAN-BUS
  Serial.begin(57600);

  ds.SetDelay(500);     //Communication delay, default value is 1000
}

void loop() {
  Serial.println(ds.ReadSensor(dspin));
  delay(200);
}

