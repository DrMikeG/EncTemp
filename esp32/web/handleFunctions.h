// Handle functions executed upon client request 
void handleRoot() 
{
    server.send(200, "text/html", webpageCode);
}

void handleTEMP()
{
    Serial.print("Requesting temperatures...");
    sensors.requestTemperatures(); // Send the command to get temperatures
    Serial.println("DONE");
    float temp = sensors.getTempCByIndex(0);
    Serial.print(temp); // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire

    String POTval = String(temp);
    server.send(200,"text/plane", POTval);
}
