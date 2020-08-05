#include "Wire.h"
#include "Plc_AI.h"

#include "Arduino.h"

// Assuming a 100kHz clock the address and config byte take 18 clock
// cycles, or 180 microseconds. Use a timeout of 250us to be safe.

const PlcX_AI::Channel PlcX_AI::ch1 = Channel(0x00);
const PlcX_AI::Channel PlcX_AI::ch2 = Channel(0x20);
const PlcX_AI::Channel PlcX_AI::ch3 = Channel(0x40);
const PlcX_AI::Channel PlcX_AI::ch4 = Channel(0x60);

const PlcX_AI::Mode PlcX_AI::oneShot = Mode(0x00);
const PlcX_AI::Mode PlcX_AI::continous = Mode(0x10);

const PlcX_AI::Resolution PlcX_AI::r12 = Resolution(0x00);
const PlcX_AI::Resolution PlcX_AI::r14 = Resolution(0x04);
const PlcX_AI::Resolution PlcX_AI::r16 = Resolution(0x08);
const PlcX_AI::Resolution PlcX_AI::r18 = Resolution(0x0c);

const PlcX_AI::Gain PlcX_AI::g1 = Gain(0x00);
const PlcX_AI::Gain PlcX_AI::g2 = Gain(0x01);
const PlcX_AI::Gain PlcX_AI::g4 = Gain(0x02);
const PlcX_AI::Gain PlcX_AI::g8 = Gain(0x03);

uint8_t PlcX_AI::init(void)
{
  Wire.beginTransmission(0x00);
  Wire.write(0x06);
  return Wire.endTransmission();
}

uint8_t PlcX_AI::generalCallLatch(void)
{
  Wire.beginTransmission(0x00);
  Wire.write(0x04);
  return Wire.endTransmission();
}

uint8_t PlcX_AI::generalCallConversion(void)
{
  Wire.beginTransmission(0x00);
  Wire.write(0x08);
  return Wire.endTransmission();
}

void PlcX_AI::normalise(long &result, Config config)
{
  /* Resolution is 12, 14, 16,or 18; gain is 1, 2, 4, or 8. Shift
   * least places necessary such that all possibilities can be
   * accounted for:
   *
   * 18 - resolution + 3 - log2(gain)
   *
   * Largest shift is for resolution==12 and gain==1 (9 places)
   * Smallest is for resolution==18 and gain==8 (0 places) This means
   * that the lowest 21 bits of the long result are used and that up
   * to 1024 results can be safely accumulated without
   * underflow/overflow.
   */ 
  result <<= (21 - int(config.getResolution()) - config.getGain().log2());
}


PlcX_AI::PlcX_AI(void) : address(0x68)
{
  ;
}
				
PlcX_AI::PlcX_AI(uint8_t add) : address(add)
{
  ;
}

bool PlcX_AI::autoprobe(const uint8_t *addressList, uint8_t len)
{
  for (uint8_t i = 0; i < len; ++i) {
    Wire.requestFrom(addressList[i], (uint8_t)1);
    if (Wire.available()) {
      address = addressList[i];
      return true;
    }
  }
  return false;
}


/** Initiate a conversion by writing to the configuration register
 */
PlcX_AI::error_t PlcX_AI::convert(Channel channel, Mode mode, Resolution resolution, Gain gain)
 {
    return convert(Config(channel, mode, resolution, gain));
  }

PlcX_AI::error_t PlcX_AI::configure(const Config &config) const
{
  Wire.beginTransmission(address);
  Wire.write(config.val);
  if (Wire.endTransmission())
    return errorConfigureFailed;
  else
    return errorNone;
}

PlcX_AI::error_t PlcX_AI::convert(const Config &config) const
{
  Wire.beginTransmission(address);
  Wire.write(config.val | newConversionMask);
  if (Wire.endTransmission())
    return errorConvertFailed;
  else
    return errorNone;
}

PlcX_AI::error_t PlcX_AI::read(long &result, Config& status) const
{
  // Read 4 bytes, the 4th byte will configuration. From that deduce
  // if 18 bit conversion. If not use the 3rd byte, as that is the
  // most appropriate configuration value (ready may have changed).
  const uint8_t len = 4;
  uint8_t buffer[len] = {};
  Wire.requestFrom(address, len);
  if (Wire.available() != len)
    return errorReadFailed;
  
  for (uint8_t i = 0; i < len; ++i)
    buffer[i] = Wire.read();

  uint8_t dataBytes;
  if ((buffer[3] & 0x0c) == 0x0c) {
    status = Config(buffer[3]); // 18 bit conversion
    dataBytes = 3;
  }
  else {
    status = Config(buffer[2]);
    dataBytes = 2;
  }
  
  if ((status & notReadyMask) != 0)
    return errorConversionNotReady;

  long signBit = 0;    // Location of sign bit
  long signExtend = 0; // Bits to be set if sign is set
  switch (int(status.getResolution())) {
  case 12:
    signBit = 0x800;
    signExtend = 0xFFFFF000;
    break;
  case 14:
    signBit = 0x2000;
    signExtend = 0xFFFFC000;
    break;
  case 16:
    signBit = 0x8000;
    signExtend = 0xFFFF0000;
    break;
  case 18:
    signBit = 0x20000;
    signExtend = 0xFFFC0000;
    break;
  }

  result = 0;
  for (uint8_t i = 0; i < dataBytes; ++i) {
    result <<= 8;
    result |= (long)buffer[i];
  }
  
  // Fill/blank remaining bits  
  if ((result & signBit) != 0)
    result |= signExtend; // Sign bit is set, sign-extend

  return errorNone;  
}



PlcX_AI::error_t PlcX_AI::convertAndRead(Channel channel, Mode mode, Resolution resolution, Gain gain, unsigned long timeout, long &result, Config &status)
{
  error_t err = convert(channel, mode, resolution, gain);
  if (err != errorNone)
    return err;
  unsigned long t = micros() + timeout;
  unsigned long convTime = resolution.getConversionTime();
  if (convTime > 16383) {
    // Unreliable (see arduino reference), use delay() instead
    convTime /= 1000;
    delay(convTime);
  }
  else
    delayMicroseconds(convTime);

  do {
    err = read(result, status);
    if (!err && status.isReady())
	{
		switch (int(status.getResolution())) {
			case 12:
				result = result - 385;
				break;
			case 14:
				result = result - 1535;
				break;
			case 16:
				result = result - 6133;
				break;
			case 18:
				result = result - 24519;
				break;
		}
		
		return err;
	}

  } while (long(micros() - t) >= 0);
  return errorReadTimeout;
}

unsigned long PlcX_AI::Resolution::getConversionTime(void) const
{
  switch ((int)(*this)) {
  case 12:
    return 4167; // 240 SPS
  case 14:
    return 16667; // 60 SPS
  case 16:
    return 66667; // 15 SPS
  case 18:
    return 266667; // 3.75 SPS
  }
  return 0; // Shouldn't happen
}

unsigned long PlcX_AI::Config::getConversionTime(void) const
{
  return Resolution(val).getConversionTime();
  // switch ((int)getResolution()) {
  // case 12:
  //   return 4167; // 240 SPS
  // case 14:
  //   return 16667; // 60 SPS
  // case 16:
  //   return 66667; // 15 SPS
  // case 18:
  //   return 266667; // 3.75 SPS
  // }
  // return 0; // Shouldn't happen
}

