#ifndef TOF10120_H
#define TOF10120_H

#include <Arduino.h>
#include <Wire.h>

class TOF10120
{
public:
    // Constructor that accepts a TwoWire object
    TOF10120(TwoWire &wire = Wire, uint8_t address = 0x52);

    // Method to initialize with the default I2C address
    void init();

    // Method to initialize with a specified I2C address
    void init(uint8_t address);

#ifdef ESP32 || ESP8266
    // Method to initialize with custom SDA and SCL pins
    void init(int sda, int scl);

    // Method to initialize with custom SDA, SCL pins and I2C address
    void init(int sda, int scl, uint8_t address);
#endif

    // Method to read the distance in mm from the sensor
    int distance();

private:
    int _addr;      // I2C address of the sensor
    TwoWire &_wire; // Reference to the TwoWire object
};

#endif // TOF10120_H