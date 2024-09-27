# Readme

Arduino library for the VL53L0X Time-of-Flight ranging sensor.

Should work with most Arduino, ESP32 and ESP8266 boards. The code is based on the
[Supplier documentation for the TOF10120](https://www.makerguides.com/wp-content/uploads/2024/09/TOF10120-supplier-doc.zip)

For more details see 
[TOF10120 Distance Sensor with Arduino](https://www.makerguides.com/tof10120-distance-sensor-with-arduino/)



## Example 

A simple example that includes the library and uses the distance() function 
to print the distance measured by the VL53L0X sensor to the Serial Monitor.

The code assumes that pin 6 (SCL) and  pin 5 (SDA) of the VL53L0X 
are connected to the standard SCL and SDA pins of the micrcontroller.
However, you can use `sensor.init(sda, scl)` to set specific pins, e.g.
for software I2C on ESP32 and ESP8266 boards.

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