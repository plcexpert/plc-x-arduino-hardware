/* MAX5816 DAC driver for the Arduino platform.  
 *
 * This library depends on the  <a href="https://www.arduino.cc/en/Reference/Wire">
 * Arduino Wire library</a>, included in a standard Arduino installation.
 *
 * Written by Gabriel de Benevides M. Melo
 */

#ifndef __MAX5816_H__
#define __MAX5816_H__

#include <Wire.h>
#include "Arduino.h"
/*CODEn command with respective DAC _addr*/
#define dacAaddr 0x01         //0000 1000 
#define dacBaddr 0x09         //0000 1001   
#define dacCaddr 0x05         //0000 1010
#define dacDaddr 0x0D         //0000 1011  
#define codeALoadA 0x81       //0001 1000
#define codeBLoadB 0x89       //0001 1001  
#define codeCLoadC 0x85       //0001 1010    
#define codeDLoadD 0x8D       //0001 1011  

/**************************************************************************/
/* 
   Class for reading DAC Output
*/
/**************************************************************************/
class MAX5816
{
    
private:    
    //const Wire _I2CBUS;
    uint8_t _addr;
    uint8_t _buf[2];     // buffer to hold DAC data
    uint8_t _bufChannelA[2], _bufChannelB[2], _bufChannelC[2], _bufChannelD[2];

public:
    /**************************************************************************/
    /*  
        Constructs a new DAC object.
        7-bit i2c address of the DAC                
    */
    /**************************************************************************/

    /*
    MAX5816(Wire &I2cBus, bool A0, bool A1)     //cannot create Wire object
        {
            _I2CBUS = I2cBus;
            _addr = 0x18 | (uint8_t)A0 << 1 | (uint8_t)A1 << 2; //Ajustar endereço
        }
    */

    MAX5816(bool A0, bool A1)                               //The cosntrutor must have the same class name
    {
        _addr = 0x81 | (uint8_t)A1 << 2 | (uint8_t)A0 << 1; //  0001 1000 or 0000 0(A1)0(R/W) or 0000 00(A0)(R/W)  
    }

    /**************************************************************************/
    /*
            Set the voltage that will apear in DAC ChannelN.
            With N = A,B,C or D
    */
    /**************************************************************************/

    void SetVoltage(uint8_t milliVoltChannelA, uint8_t milliVoltChannelB, uint8_t milliVoltChannelC, uint8_t milliVoltChannelD)
    {

        _bufChannelA[1] = (milliVoltChannelA >> 4) & 0x0F;
        _bufChannelA[0] = (milliVoltChannelA << 4) & 0xF0;

        _bufChannelB[1] = (milliVoltChannelB >> 4) & 0x0F;
        _bufChannelB[0] = (milliVoltChannelB << 4) & 0xF0;

        _bufChannelC[1] = (milliVoltChannelC >> 4) & 0x0F;
        _bufChannelC[0] = (milliVoltChannelC << 4) & 0xF0;

        _bufChannelD[1] = (milliVoltChannelD >> 4) & 0x0F;
        _bufChannelD[0] = (milliVoltChannelD << 4) & 0xF0;

        Wire.beginTransmission(_addr);
        /*Channel A*/
        Wire.write(byte(codeALoadA));
        Wire.write(_bufChannelA[1]);
        Wire.write(_bufChannelA[0]);
        /*Channel B*/
        Wire.write(byte(codeBLoadB));
        Wire.write(_bufChannelB[1]);
        Wire.write(_bufChannelB[0]);
        /*Channel C*/
        Wire.write(byte(codeCLoadC));
        Wire.write(_bufChannelC[1]);
        Wire.write(_bufChannelC[0]);
        /*Channel D*/
        Wire.write(byte(codeDLoadD));
        Wire.write(_bufChannelD[1]);
        Wire.write(_bufChannelD[0]);

        Wire.endTransmission(_addr);
    }

    void GetVoltage(uint8_t &milliVoltChannelA, uint8_t &milliVoltChannelB, uint8_t &milliVoltChannelC, uint8_t &milliVoltChannelD)
    {
        uint8_t idx = 0;
        /*Channel A*/
        Wire.beginTransmission(_addr);
        Wire.write(dacAaddr);
        Wire.endTransmission(false);
        Wire.requestFrom(_addr, (uint8_t)2);
        while (Wire.available() && idx < 2)
        {
            _buf[idx] = Wire.read();
            ++idx;
        }
        milliVoltChannelA = (((_buf[0] & 0x0F) << 4) | ((_buf[1] & 0xF0) >> 4));
        idx = 0;
        /*Channel B*/
        Wire.beginTransmission(_addr);
        Wire.write(dacBaddr);
        Wire.endTransmission(false);
        Wire.requestFrom(_addr, (uint8_t)2);
        while (Wire.available() && idx < 2)
        {
            _buf[idx] = Wire.read();
            ++idx;
        }
        milliVoltChannelB = (((_buf[0] & 0x0F) << 4) | ((_buf[1] & 0xF0) >> 4));
        idx = 0;
        /*Channel C*/
        Wire.beginTransmission(_addr);
        Wire.write(dacCaddr);
        Wire.endTransmission(false);
        Wire.requestFrom(_addr, (uint8_t)2);
        while (Wire.available() && idx < 2)
        {
            _buf[idx] = Wire.read();
            ++idx;
        }
        milliVoltChannelC = (((_buf[0] & 0x0F) << 4) | ((_buf[1] & 0xF0) >> 4));
        idx = 0;
        /*Channel D*/
        Wire.beginTransmission(_addr);
        Wire.write(dacDaddr);
        Wire.endTransmission(false);
        Wire.requestFrom(_addr, (uint8_t)2);
        while (Wire.available() && idx < 2)
        {
            _buf[idx] = Wire.read();
            ++idx;
        }
        milliVoltChannelD = (((_buf[0] & 0x0F) << 4) | ((_buf[1] & 0xF0) >> 4));
    }
};

#endif
