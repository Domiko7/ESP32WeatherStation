#ifndef SHT41_H
#define SHT41_H
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_SHT4x.h>
#include <Arduino.h>

struct SHTData {
  float temperature;
  float humidity;
};

class SHT {
  public:
    SHT();
    void setup();
    SHTData getValues();
    void printValues();
  private:
    Adafruit_SHT4x sht;

};

#endif
