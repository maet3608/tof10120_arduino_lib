# tof10120_arduino_lib

Arduino library for the VL53L0X Time-of-Flight ranging sensor.

Should work with most Arduino, ESP32 and ESP8266 boards.

For more details see 
[TOF10120 Distance Sensor with Arduino](https://www.makerguides.com/tof10120-distance-sensor-with-arduino/)



## Example 

A simple example that includes the library and uses the distance() function 
to print the distance measured by the VL53L0X sensor to the Serial Monitor.

```
#include "TOF10120.h"

TOF10120 sensor = TOF10120();

void setup() {
  Serial.begin(9600);
  sensor.init();
}

void loop() {
  Serial.println(sensor.distance());
  delay(100);
}
```