#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

/************************* WiFi Access Point *********************************/

#define WLAN_SSID       "wlanssid"
#define WLAN_PASS       "wlanpassword"

/************************* Adafruit.io Setup *********************************/

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    "username"
#define AIO_KEY         "password"

// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;
// or... use WiFiFlientSecure for SSL
//WiFiClientSecure client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

/****************************** Feeds ***************************************/

// Setup a feed called 'studyRoom' for publishing.
// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname>
Adafruit_MQTT_Publish studyRoom = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/study-room-test");

// Setup a feed called 'studyRoom' for subscribing to changes.
//Adafruit_MQTT_Subscribe studyRoom1 = Adafruit_MQTT_Subscribe(&mqtt, FEED_PATH);

void setup() {
  Serial.begin (115200);
  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("connecting to wifi");
    delay(500);
  }
}

void MQTT_connect() {
  int8_t ret;
  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }
  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
    mqtt.disconnect();
    delay(5000);  // wait 5 seconds
    retries--;
    if (retries == 0) {
      // basically die and wait for WDT to reset me
      while (1);
    }
  }
}

void loop() {
  MQTT_connect();
  
  // Now we can publish stuff!
  if (!mqtt.connected()) {
    Serial.println("not connected");
    mqtt.subscribe(&studyRoom1);
    mqtt.publish(FEED_PATH, "11");
  } else {
    Serial.println("connected");
    studyRoom.publish("11");
  }
  
  if (!studyRoom.publish(dataToSend)) {
    //Serial.println(F("Failed"));
  } else {
    //Serial.println(F("OK!"));
  }

  // ping the server to keep the mqtt connection alive
  // NOT required if you are publishing once every KEEPALIVE seconds
  if(!mqtt.ping()) {
    mqtt.disconnect();
  }
  delay(2000);
}
