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

The graphs look like this:
![Alt text](/README_img/graph_8000.png)