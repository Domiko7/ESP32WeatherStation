#include "BMP280.h"

BMP::BMP() {

}

void BMP::setup()
{


  Serial.println(F("BMP280 test"));

  bool status = bmp.begin(0x76);

  if (!status) {
    Serial.println("Could not get data from BMP280, make sure you're using the correct sensor and wiring");
  }
  Serial.println("-- TEST usage --");

  Serial.println();
}

float BMP::getTemperature()
{
  return bmp.readTemperature();
}


float BMP::getPressure()
{
  return bmp.readPressure() / 100.0;
}


void BMP::printValues()
{
  Serial.println("BMP280: ");
  
  Serial.println("Temperature: ");
  Serial.println(getTemperature());
  Serial.println("℃");

  Serial.println();

  Serial.println("Pressure: ");
  Serial.println(getPressure());
  Serial.println("hPa");

}



