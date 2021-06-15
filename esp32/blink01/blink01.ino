#include <OneWire.h>
#include <DallasTemperature.h>

#define LED_BUILTIN 2
// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 13 // maybe 13?

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("blink start");
  Serial.println("Dallas Temperature IC Control Library Demo");
  // Start up the library
  sensors.begin(); // IC Default 9 bit. If you have troubles consider upping it 12. Ups the delay giving the IC more time to process the temperature measurement
}

// the loop function runs over and over again forever
void loop() {
  
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  Serial.println("blink on");

  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");

  Serial.print("Temperature for Device 1 is: ");
  Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire

  
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  Serial.println("blink off");
  delay(500);
}
