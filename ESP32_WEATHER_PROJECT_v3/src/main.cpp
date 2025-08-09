#include <ThingSpeak.h>
#include <Arduino.h>
#include <WiFi.h>
#include "BMP280.h"
#include "SHT41.h"
#include "GUVA_S12SD.h"

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

WiFiClient client;

const char* writeAPIKey = "YOUR_WRITE_API_KEY";
unsigned long channelNumber = YOUR_CHANNEL_NUMBER;

int sda = 21; //SDA
int scl = 22; //SCL;

BMP BMP280;
SHT SHT41;
unsigned long delayTime;

void setup() {
  Serial.begin(115200); // or change if you want a different baud rate

  analogReadResolution(12);
  analogSetAttenuation(ADC_11db);
  
  Wire.begin(sda, scl);

  //Remove if you don't have a BMP280
  BMP280.setup(); //SDA SCL

  //Remove if you don't have a SHT41
  SHT41.setup(); //SDA SCL

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  ThingSpeak.begin(client);

  delayTime = 60000;
}


void printAll() {
  //Remove if you don't have a BMP280
  BMP280.printValues();

  Serial.println();

  //Remove if you don't have a SHT41
  SHT41.printValues();

  Serial.println();

  //Remove if you don't have a GUVA-S12SD
  GUVA_S12SD.printValues();

  Serial.println();
}

void sendAll() {
  SHTData shtValues = SHT41.getValues();

  ThingSpeak.setField(1, shtValues.temperature); // modify to your field numbers
  ThingSpeak.setField(2, shtValues.humidity); // modify to your field numbers
  ThingSpeak.setField(3, BMP280.getPressure()); // modify to your field numbers
  ThingSpeak.setField(4, BMP280.getTemperature()); // modify to your field numbers

  int result = ThingSpeak.writeFields(channelNumber, writeAPIKey);
  if (result == 200) {
    Serial.println("Channel update successful.");
  } else {
    Serial.println("An error occured. HTTP error code: ");
    Serial.println(result);
  }
}

void reconnect() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Trying to reconnect..");
    while (WiFi.status() != WL_CONNECTED) {
      WiFi.begin(ssid, password); 
      delay(5000); 
    }
    Serial.println("Connected");
  }
}

void loop() {
  reconnect();
  //printAll();
  sendAll();
  delay(delayTime);
}

