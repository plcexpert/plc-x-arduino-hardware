
// FILE: PLC_DIO.h
// AUTHOR: PLC-EXPERT
// PURPOSE: Digital Input/Output Board
// PRODUCT NAME: PLC-DIO (13 in; 7 out)
// URL: http://www.plc-expert.com


#ifndef PLC_DS18B20_h
#define PLC_DS18B20_h

#include <Arduino.h>

#define PLC_DS18B20_LIB_VERSION "0.1"

class PLC_DS18B20
{
public:
	PLC_DS18B20();
	~PLC_DS18B20(){};
	float ReadSensor(int PinNumber);
	void SetDelay(int sensorDelay);
private:
	int SensorDelay = 1000;
};
#endif
