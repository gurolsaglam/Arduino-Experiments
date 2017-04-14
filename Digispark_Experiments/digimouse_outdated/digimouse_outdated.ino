//#define __AVR_ATtiny85__ eğer Arduino IDE 1.6.11 değilse
#include <DigiMouse.h>

void setup() {
  DigiMouse.begin();
}

void clickerLeft() {
  DigiMouse.setButtons(1<<0);
  DigiMouse.delay(100);
  DigiMouse.setButtons(0);
  DigiMouse.leftClick();
  DigiMouse.setButtons(0);
  DigiMouse.delay(100);
}

void loop() {
  for(int i=0;i<=15;i++){
    DigiMouse.move(-100,50,0);
    DigiMouse.delay(250);
  }
  clickerLeft();
  DigiMouse.move(20,-40,0);
  DigiMouse.delay(100);
  clickerLeft();
  DigiMouse.move(20,-40,0);
  DigiMouse.delay(100);
  clickerLeft();
}
