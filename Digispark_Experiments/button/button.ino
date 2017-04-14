
 #include <DigiUSB.h>
void setup() {
  DigiUSB.begin();
  pinMode(0, INPUT);
}
 
void loop() {
  DigiUSB.println("Waiting for input...");
  int sensorValue = digitalRead(0);
  if(DigiUSB.available()){
    DigiUSB.println(sensorValue);
  }
  DigiUSB.delay(100);
}
