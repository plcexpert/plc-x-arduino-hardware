/******************************************************************
  Project name : Micro PLC example project
  Author       : 
  Date Time    : 
  Description  : 512kB EEPROM usage example
  CPU BOARD    : MicroPLC
  URL          : 
******************************************************************/
#include <Wire.h>

#define EepromAddress 0x50    //Address of eeprom chip
#define target1 0       	  //First Address
#define target2 154013        //Some random address
#define target3 524287        //Last address

void setup() {
  Wire.begin();
  Serial.begin(9600);

  //Write dat to to eeprom while CPU starts
  WriteByte(target1, 37);
  WriteByte( target2, 145);
  WriteByte(target3, 254);
}

void loop() {
  //Read data from eeprom memory and send their values to uart port
  //open terminal to check values
  
  //HEader
  Serial.println("---- EEPROM values ----");
  
  //1st
  Serial.print("[");
  Serial.print(target1);
  Serial.print("]=");
  Serial.println(ReadByte(target1));
  
  //2nd
  Serial.print("[");
  Serial.print(target2);
  Serial.print("]=");
  Serial.println(ReadByte(target2));
  
  //3rd
  Serial.print("[");
  Serial.print(target3);
  Serial.print("]=");
  Serial.println(ReadByte(target3));
    
  delay(10000);
}

void WriteByte(unsigned int MemoryAddress, byte NewValue){
  //We will save the value only if value in memory is different - it saves your eeprom device
  
  byte current_value = ReadByte(MemoryAddress);
  
  if(current_value != NewValue)
  {
	Wire.beginTransmission(EepromAddress);
	Wire.write( (MemoryAddress >> 8) & 0xFF );
	Wire.write( (MemoryAddress >> 0) & 0xFF );
	Wire.write(NewValue);
	Wire.endTransmission();
  }
}

byte ReadByte(unsigned int MemoryAddress){ 
  Wire.beginTransmission(EepromAddress);
  Wire.write( (MemoryAddress >> 8) & 0xFF );
  Wire.write( (MemoryAddress >> 0) & 0xFF );
  Wire.endTransmission();
  delay(5);
  
  Wire.requestFrom(EepromAddress, 1);
  byte eeprom_data = Wire.read();
  return eeprom_data;
}