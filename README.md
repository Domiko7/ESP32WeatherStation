# ESP32 Sensor Data Logger with ThingSpeak

This project reads sensor data from BMP280 (pressure & temperature), SHT41 (temperature & humidity), and GUVA-S12SD (UV light sensor) connected to an ESP32, then uploads the data to ThingSpeak via WiFi.

## Features

- Reads temperature, humidity, and pressure from BMP280 and SHT41 sensors
- Sends sensor data to ThingSpeak channel fields
- Automatically reconnects to WiFi if connection drops
- Configurable update interval (default 60 seconds)

## Hardware Requirements

- ESP32 development board
- BMP280 sensor (I2C)
- SHT41 sensor (I2C)
- Connecting wires

## Software Requirements

- Arduino IDE with ESP32 board support installed
- Libraries:
  - `ThingSpeak`
  - `WiFi`
  - `BMP280` (your specific BMP280 library)
  - `SHT41` (your specific SHT41 library)

## Wiring

| Sensor     | ESP32 Pin         |
|------------|-------------------|
| BMP280 SDA | GPIO 21 (SDA)     |
| BMP280 SCL | GPIO 22 (SCL)     |
| SHT41 SDA  | GPIO 21 (SDA)     |
| SHT41 SCL  | GPIO 22 (SCL)     |

*Note: BMP280 and SHT41 share I2C lines.*

## Configuration

Update the following variables in the code:

```cpp
const char* ssid = "YOUR_SSID";                // Your WiFi network name
const char* password = "YOUR_PASSWORD";        // Your WiFi password

const char* writeAPIKey = "YOUR_WRITE_API_KEY"; // ThingSpeak Write API Key
unsigned long channelNumber = YOUR_CHANNEL_NUMBER; // ThingSpeak Channel Number
