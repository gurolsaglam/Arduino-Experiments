#include <DigiUSB.h>
int pin = 0;

void setup() {
    DigiUSB.begin();
    pinMode(0,OUTPUT); //yellow
    pinMode(1,OUTPUT); //red
}

void loop() {
  DigiUSB.println("Waiting for input...");
  int lastRead;
  while (true) {
    if (DigiUSB.available()) {
      lastRead = DigiUSB.read();
      if (lastRead == '\n') {
        break;
      }
      pin=lastRead;
    }
    DigiUSB.delay(100);
  }
  pin=pin-48;
  analogWrite(pin,HIGH);
  delay(1000);
  analogWrite(pin,LOW);
  delay(1000);
}
