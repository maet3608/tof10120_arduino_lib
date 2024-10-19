#include "TOF10120.h"

// Constructor implementation
TOF10120::TOF10120(TwoWire &wire, uint8_t address)
    : _wire(wire), _addr(address) {}

// Initialize using the default I2C address
void TOF10120::init()
{
    _wire.begin();
}

// Initialize with a specified I2C address
void TOF10120::init(uint8_t address)
{
    _addr = address;
    _wire.begin();
}

#ifdef ESP32 || ESP8266
// Initialize with custom SDA and SCL pins
void TOF10120::init(int sda, int scl)
{
    _wire.begin(sda, scl);
}

// Initialize with custom SDA, SCL pins and a specific I2C address
void TOF10120::init(int sda, int scl, uint8_t address)
{
    _addr = address;
    _wire.begin(sda, scl, address);
}
#endif

// Method to read the distance from the sensor
int TOF10120::distance()
{
    unsigned short dist = 0;

    _wire.beginTransmission(_addr);
    _wire.write(0);
    _wire.endTransmission();
    delay(1);

    _wire.requestFrom(_addr, 2);
    if (_wire.available() != 2)
        return -1;
    dist = _wire.read() << 8;
    dist |= _wire.read();
    return dist;
}
