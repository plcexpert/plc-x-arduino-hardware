/******************************************************************
  Project name : DS18B20 board Library v. 1.1
  Author       : 
  Date Time    :
  Description  : Temperature sensor library to simplify usage
  CPU BOARD    : 
  URL          : www.plc-expert.com
******************************************************************/

#ifndef PlcX_DS18B20_h
#define PlcX_DS18B20_h

#include <Arduino.h>

#define PlcX_DS18B20_LIB_VERSION "0.1"

class PlcX_DS18B20
{
public:
	PlcX_DS18B20();
	~PlcX_DS18B20(){};
	float ReadSensor(int PinNumber);
	void SetDelay(int sensorDelay);
private:
	int SensorDelay = 1000;
};
#endif
