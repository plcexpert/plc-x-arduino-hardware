#include <Wire.h>

void setup(void)
{
  Serial.begin(9600);
  Wire.begin();
  Serial.println();
  
  for (uint8_t add = 0X0; add < 0X80; add++) {
    Wire.requestFrom(add, (uint8_t)1);
    if (Wire.available()) {
      Serial.print("Found device at: 0x");
      Serial.println(add, HEX);
    }
  }
  Serial.println("Done");
}

void loop(void)
{
}
