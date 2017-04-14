/*
Adafruit Arduino - Lesson 10. Simple Sounds
*/
 
int leftHand = 12;
int rightHand= 11;
 
int numTones = 10;
int tones[] = {440, 493, 261, 294, 329, 349, 392, 277, 311, 392}; //261, 277, 294, 311, 330, 349, 370, 392, 493, 440};
//              A     B   C    D    E    F    G    C#   D#   F#     //mid C  C#   D    D#   E    F    F#   G    B   A
//              0     1   2    3    4    5    6    7    8    9

void setup()
{
  /*tone(rightHand,tones[4]);
  delay(500);
  tone(rightHand,tones[5]);
  delay(500);
  tone(rightHand,tones[4]);*/
  //left
  tone(leftHand,tones[0]);
  delay(250);
  noTone(leftHand);
  tone(leftHand,tones[0]);
  delay(250);
  noTone(leftHand);
  tone(leftHand,tones[0]);
  delay(250);
  noTone(leftHand);
  tone(leftHand,tones[6]);
  delay(250);
  noTone(leftHand);
  tone(leftHand,tones[0]);
  delay(250);
  noTone(leftHand);
  tone(leftHand,tones[0]);
  delay(250);
  noTone(leftHand);
  tone(leftHand,tones[0]);
  delay(250);
  noTone(leftHand);
  tone(leftHand,tones[1]);
  delay(250);
  noTone(leftHand);
  tone(leftHand,tones[4]);
  delay(250);
  noTone(leftHand);
  tone(leftHand,tones[4]);
  delay(250);
  noTone(leftHand);
  tone(leftHand,tones[4]);
  delay(250);
  noTone(leftHand);
  tone(leftHand,tones[3]);
  delay(250);
  noTone(leftHand);
  //right and left
  /*tone(rightHand,tones[6]);
  tone(leftHand,tones[4]);
  delay(250);
  tone(leftHand,tones[4]);
  delay(250);
  tone(leftHand,tones[4]);
  delay(250);
  tone(leftHand,tones[5]);
  delay(125);
  tone(leftHand,tones[6]);
  delay(125);
  //right and left
  tone(rightHand,tones[4]);
  tone(leftHand,tones[0]);
  delay(250);
  tone(leftHand,tones[0]);
  delay(250);
  tone(leftHand,tones[0]);
  delay(250);
  tone(leftHand,tones[6]);
  delay(250);
  tone(leftHand,tones[0]);
  delay(250);
  tone(leftHand,tones[0]);
  delay(250);
  tone(leftHand,tones[0]);
  delay(250);
  tone(leftHand,tones[1]);
  delay(250);
  tone(leftHand,tones[4]);
  delay(250);
  tone(leftHand,tones[4]);
  delay(250);
  tone(leftHand,tones[4]);
  delay(250);
  tone(leftHand,tones[3]);
  delay(250);
  tone(leftHand,tones[4]);
  delay(250);
  tone(leftHand,tones[4]);
  delay(250);
  tone(leftHand,tones[4]);
  delay(250);
  tone(leftHand,tones[5]);
  delay(125);
  tone(leftHand,tones[6]);
  delay(125);*/
  
  noTone(leftHand);
  noTone(rightHand);
  /*for (int i = 0; i < numTones; i++)
  {
    tone(speakerPin, tones[i]);
    delay(500);
  }
  noTone(speakerPin);*/
}
 
void loop()
{
}
