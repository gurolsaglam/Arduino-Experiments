#include <DigiMouse.h>

void setup() {
  // put your setup code here, to run once:
  DigiMouse.begin();
}
void clickerLeft(){
  DigiMouse.setButtons(1<<0);
  DigiMouse.delay(100);
  DigiMouse.setButtons(0);
  DigiMouse.leftClick();
  DigiMouse.setButtons(0);
  DigiMouse.delay(500);
}

void clickerRight(){
  DigiMouse.setButtons(2<<0);
  DigiMouse.delay(100);
  DigiMouse.setButtons(0);
  DigiMouse.rightClick();
  DigiMouse.setButtons(0);
  DigiMouse.delay(100);
}

void clickerMiddle(){
  DigiMouse.setButtons(4<<0);
  DigiMouse.delay(100);
  DigiMouse.setButtons(0);
  DigiMouse.middleClick();
  DigiMouse.setButtons(0);
  DigiMouse.delay(100);
}



void loop() {
  // put your main code here, to run repeatedly:
  clickerRight();
}
