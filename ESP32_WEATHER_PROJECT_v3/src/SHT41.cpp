#include "SHT41.h"


SHT::SHT() {
  
}

void SHT::setup()
{

  Serial.println(F("SHT41 test"));

  if (!sht.begin()) {
    Serial.println("Could not get data from SHT41, make sure you're using the correct sensor and wiring");
  }
  
  sht.setPrecision(SHT4X_HIGH_PRECISION);
  //sht.setHeater(SHT4X_NO_HEATER);

  Serial.println("-- TEST usage --");

  Serial.println();
}

SHTData SHT::getValues()
{
  sensors_event_t temp, hum;
  sht.getEvent(&temp, &hum);
  return { hum.relative_humidity, temp.temperature };
}

void SHT::printValues()
{

  SHTData data = getValues();

  Serial.println("SHT41: ");
  
  Serial.println("Temperature: ");
  Serial.println(data.temperature);
  Serial.println("℃");

  Serial.println();

  Serial.println("Humidity: ");
  Serial.println(data.humidity);
  Serial.println("%");

}




