#ifndef BMP280_H
#define BMP280_H
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <Arduino.h>

class BMP {
  public:
    BMP();
    void setup();
    float getTemperature();
    float getPressure();
    void printValues();
  private:
    Adafruit_BMP280 bmp;

};

#endif
