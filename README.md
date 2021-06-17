# An Esp32 Temperature Monitor

This project is an ESP32 dev module combined with a KY-001 temperature sensor.

This allows me a plot a graph of the temperature logged in 5 second increments over time.

The data is gathered an graphed in a web browser (session remains connected, polling temperature of Ajax)

![Alt text](/README_img/crop_cover.jpg)

I am using this to gather some numbers for the temperature in my 3D printer enclosure.

This is a temporary breadboard project - I am sure there are better, permanent solutions - the requirement for me was what could I build just with things from my spare parts bin.

Code available in \esp32\blink01 shows code for reading from a sensor on gpio pin 15.

Code available in \esp32\web shows code for connecting to wifi, starting a webserver and serving a graphing page and the ajax data.
The code is not complete - secrets.h should not be committed. You'll need to create your own with your SSID and password in.


## 2021.06.15 ##

I have a KY-001 temp sensor.

https://arduinomodules.info/ky-001-temperature-sensor-module/

The KY-001 Temperature Sensor Module consists of a DS18B20 single-bus digital temperature sensor, a LED and a resistor. Compatible with popular electronics platforms like Arduino, Raspberry Pi and Esp8266.

Operating Voltage	3.0V to 5.5V
Temperature Measurement Range	-55°C to 125°C [-57°F to 257°F]
Measurement Accuracy Range	±0.5°C

Connect the Power line (middle) and ground (-) to +5 and GND respectively. Connect signal (S) to pin 2 on the Arduino.

KY-001	Arduino
S	Pin 2
middle	+5V
-	GND


Example Code
```
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

void setup(void)
{
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");
  // Start up the library
  sensors.begin(); // IC Default 9 bit. If you have troubles consider upping it 12. Ups the delay giving the IC more time to process the temperature measurement
}

void loop(void)
{ 
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");

  Serial.print("Temperature for Device 1 is: ");
  Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
}
```

I also have an ESP32 wroom 30 pin

I don't remember how to program these from the arduino app.

plugged in esp32 dev board.
From port menu picked /dev/cu.SLAB_USBtoUART

Need to make sure board in installed in Arduino. https://www.instructables.com/id/How-to-Set-Up-WeMos-TTgo-ESP32-Uno-D1-R32/

https://dl.espressif.com/dl/package_esp32_index.json

There is a flash example (and others) here https://github.com/LilyGO/ESP32-MINI-32-V2.0/blob/master/Module_test/Blink/Blink.ino

Installed the ESP 32 dev board driver for arduino. Selected board ESP32 Dev Module Chose Port /dev/cu.chbubserialfa130

Selected board "Esp32 dev module"

It's programmed and reporting on the serial, but I don't think pin 22 is the LED

Installing required libraries for example code:

#include <OneWire.h>
#include <DallasTemperature.h>

Using arduino 1.8.15 lib manager. 
Installing OneWire by Paul Stoffregen
Installing DallasTemperature by Miles Burton

I've coped the example code into the flash example.
I've connected the board up so that Vin,GND,and neighbouring pin 13 are being used.
It is reporting a temperature of 27.37 - which I believe.