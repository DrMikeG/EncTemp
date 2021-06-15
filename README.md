# EncTemp

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