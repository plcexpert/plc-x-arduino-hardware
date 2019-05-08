/******************************************************************
  Project name : DS18B20 board Library v. 1.1
  Author       : 
  Date Time    :
  Description  : Temperature sensor library to simplify usage
  CPU BOARD    : 
  URL          : www.plc-expert.com
******************************************************************/

#include "PLC_DS18B20.h"
#include <OneWire.h>


PLC_DS18B20::PLC_DS18B20(){
	SetDelay(1000);
};

void PLC_DS18B20::SetDelay(int sensorDelay){
	SensorDelay = sensorDelay;
};
//PUBLIC METHODSfloat PLC_DS18B20::ReadSensor(int PinNumber){
  //Declare sensor
  OneWire Sensor(PinNumber);
  
  //Following code is from : http://playground.arduino.cc/Learning/OneWire
  byte i;
  byte present = 0;
  byte data[12];
  byte addr[8];

  Sensor.reset_search();

  if (!Sensor.search(addr))
  {    
    Sensor.reset_search();
    return -99;
  }

  if (OneWire::crc8(addr, 7) != addr[7])
  {
    return -98;
  }

  //Device is not a DS18S20 family device
  if (addr[0] != 0x10 && addr[0] != 0x28)
  {
    return -97;
  }

  Sensor.reset();
  Sensor.select(addr);
  Sensor.write(0x44,1);     // start conversion, with parasite power on at the end
  
  delay(SensorDelay);          // maybe 750ms is enough, maybe not
  // we might do a ds.depower() here, but the reset will take care of it.
  
  present = Sensor.reset();
  Sensor.select(addr);    
  Sensor.write(0xBE);         // Read Scratchpad
   
  for ( i = 0; i < 9; i++)  // we need 9 bytes
  {
    data[i] = Sensor.read();
  }

  //Converting values to temperature (Celsius)
  int HighByte, LowByte, TReading, SignBit, Tc_100, Whole, Fract;

  LowByte = data[0];
  HighByte = data[1];
  TReading = (HighByte << 8) + LowByte;
  SignBit = TReading & 0x8000;  // test most sig bit
  
  if (SignBit) // negative
  {
    TReading = (TReading ^ 0xffff) + 1; // 2's comp
  }

  //Calculate values
  Tc_100 = (6 * TReading) + TReading / 4;    // multiply by (100 * 0.0625) or 6.25
  Whole = Tc_100 / 100;  // separate off the whole and fractional portions
  Fract = Tc_100 % 100;

  //Temperature
  float temperature = Whole + (float)Fract/100;
  temperature = (SignBit ? -1 * temperature : temperature);
  return temperature;	}