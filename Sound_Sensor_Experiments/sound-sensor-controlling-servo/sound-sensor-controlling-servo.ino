#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int soundDetectedPin = 10; // Use Pin 10 as our Input
int soundDetectedVal = HIGH; // This is where we record our Sound Measurement
boolean bAlarm = false;
unsigned long lastSoundDetectTime;
int soundAlarmTime = 500;

void setup() {
  Serial.begin(9600);  
  pinMode (soundDetectedPin, INPUT) ; // input from the Sound Detection Module
  myservo.attach(11);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  soundDetectedVal = digitalRead(soundDetectedPin);            // reads the value of the potentiometer (value between 0 and 1023)
  //soundDetectedVal = map(soundDetectedVal, 0, 1, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  //myservo.write(soundDetectedVal);                  // sets the servo position according to the scaled value
  delay(1500);                           // waits for the servo to get there
    if (soundDetectedVal == LOW) // If we hear a sound
  {
  
    lastSoundDetectTime = millis(); // record the time of the sound alarm
    // The following is so you don't scroll on the output screen
    if (!bAlarm){
      Serial.println("LOUD, LOUD");
      Serial.println(soundDetectedVal);
      bAlarm = true;
      myservo.write(160);
    }
  }
  else
  {
    if( (millis()-lastSoundDetectTime) > soundAlarmTime  &&  bAlarm){
      Serial.println("quiet");
      Serial.println(soundDetectedVal);
      bAlarm = false;
      myservo.write(20);
    }
  }
}
//NOT DONE YET
