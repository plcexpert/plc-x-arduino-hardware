#include <Wire.h>
#include <PlcX_AI.h>

// 0x68 is the 1st address for all PLC-ANALOG devices
#define DEF_ADDRESS 0x68
#define DEF_TIMEOUT 1000
#define DEF_RESOLUTION PlcX_AI::r18
#define DEF_GAIN PlcX_AI::g1
PlcX_AI adc = PlcX_AI(DEF_ADDRESS);

void setup(void)
{
  Serial.begin(9600);
  Wire.setClock(400000);
  Wire.begin();
    
  // Int devices
  PlcX_AI::init();
  
  // Check device present
  Wire.requestFrom(DEF_ADDRESS, (uint8_t)1);
  if (!Wire.available()) {
    Serial.print("No device found at address ");
    Serial.println(DEF_ADDRESS, HEX);
    while (1);
  }
}

void loop(void)
{
  long value = 0;
  PlcX_AI::Config status;
  
  // Will wait until it can be read
  uint8_t err = adc.convertAndRead(PlcX_AI::ch1, PlcX_AI::oneShot, DEF_RESOLUTION, DEF_GAIN, DEF_TIMEOUT, value, status);
  
//  if (err) {
//    Serial.print("Convert error: ");
//    Serial.println(err);
//  }
//  else {
//    Serial.print("Value: ");
//    Serial.println(value);
//  }
  
  delay(1000);
}
