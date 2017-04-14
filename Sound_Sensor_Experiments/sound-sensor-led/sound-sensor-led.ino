int val;
void setup() {
  // put your setup code here, to run once:
  pinMode(10,INPUT);
  pinMode(12,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  val=digitalRead(10);
  if (val){
  digitalWrite(12,LOW);
  delay(100);
  }else {
    digitalWrite(12,HIGH);
    delay(100);
  }
}
