//========================================================
//ESP32 Web Server: Reading Potentiometer Value using AJAX
//========================================================
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "webpage.h"
#include "secrets.h"

WebServer server(80);

#define LED_BUILTIN 2
#define ONE_WIRE_BUS 15
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

// Must be included after variables server and sensor are defined.
#include "handleFunctions.h" 


void setup() 
{
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
    sensors.begin(); // IC Default 9 bit. If you have troubles consider upping it 12. Ups the delay giving the IC more time to process the temperature measurement

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password); 
    Serial.println("Connected to WiFi"); 
    while(WiFi.waitForConnectResult() != WL_CONNECTED) 
    {
        delay(500);
        Serial.print(".");
    }
    Serial.print("ID address address: "); 
    Serial.println(WiFi.localIP()); 

    server.on("/", handleRoot);
    server.on("/readTEMP",handleTEMP);
    server.begin(); 
    Serial.println("HTTP server started"); 
}

void loop(void) 
{
    server.handleClient(); 
    delay(1); 
}
