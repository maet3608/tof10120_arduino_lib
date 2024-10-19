#include "TOF10120.h"

TOF10120 sensor = TOF10120();

void setup()
{
    Serial.begin(9600);
    sensor.init();
}

void loop()
{
    Serial.println(sensor.distance());
    delay(100);
}