int soundPin=10;
int soundVal;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(soundPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  soundVal=digitalRead(soundPin);
  Serial.println(soundVal);
  //soundVal=map(soundVal,500,1000,0,180);
  
}
