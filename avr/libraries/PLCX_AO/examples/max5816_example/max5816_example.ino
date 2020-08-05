#include <MAX5816.h>


/*------------------------------------------------------------------------
 * Init(Wire & I2cBus, bool A0, bool A1)
 * I2cBus:
 * Set A0 and A1 depending the ADDR connection 
 * ADDR | A0 | A1  
 * VDD  | 0  | 0
 * N.C  | 1  | 0
 * GND  | 1  | 1
 * -----------------------------------------------------------------------
 */
MAX5816 max5816(0,0); //ADDR pin connected to VDD example 
uint8_t s = 0;
uint8_t mVChA, mVChB, mVChC, mVChD;

void setup() {
  Serial.begin(115200); // start Serial communication
  Wire.begin(); // start 2-wire communication
  Wire.setClock(400000L); // this sensor supports fast-mode
  delay(100);
}

void loop() {
  max5816.SetVoltage(128,255,0,64);
  max5816.GetVoltage(mVChA, mVChB, mVChC, mVChD);

  Serial.print("mV channel A: ");
  Serial.println(mVChA);
  Serial.print("mV channel B: ");
  Serial.println(mVChB);
  Serial.print("mV channel C: ");
  Serial.println(mVChC);
  Serial.print("mV channel D: ");
  Serial.println(mVChD);
}
