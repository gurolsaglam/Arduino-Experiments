/*This program is sometimes required when
 *the ESP8266 does not work properly and
 *you are using the wifi.
  */

#include <ESP8266WiFi.h>
#include <WiFiClient.h>

void setup() {
    WiFi.softAPdisconnect(true);
    WiFi.disconnect(true);
}
void loop() {}
