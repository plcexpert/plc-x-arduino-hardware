#include <Wire.h>
#include <PlcX_AI.h>

#define DEF_ADDRESS 0x68
#define DEF_TIMEOUT 1000
PlcX_AI adc = PlcX_AI(DEF_ADDRESS);

// Configuration and status
PlcX_AI::Config config(PlcX_AI::ch1, PlcX_AI::oneShot, PlcX_AI::r18, PlcX_AI::g1);
PlcX_AI::Config status;

// Inidicate if a new conversion should be started
bool startConversion = false;

void setup(void)
{
  Serial.begin(9600);
  Wire.begin();
    
  // Reset devices
  PlcX_AI::init();
  
  // Check device present
  Wire.requestFrom(DEF_ADDRESS, (uint8_t)1);
  if (!Wire.available()) {
    Serial.print("No device found at address ");
    Serial.println(DEF_ADDRESS, HEX);
    while (1);
  }

  startConversion = true;
}

unsigned long lastLedFlash = 0;
void loop(void)
{
  long value = 0;
  uint8_t err;

  if (startConversion) {
    err = adc.convert(config);
    if (err) {
      Serial.print("Convert error: ");
      Serial.println(err);
    }
    startConversion = false;
  }
  
  err = adc.read(value, status);
  if (!err && status.isReady()) { 
    // For debugging purposes print the return value.
    Serial.print("Value: ");
    Serial.println(value);
    startConversion = true;
  }    
}
