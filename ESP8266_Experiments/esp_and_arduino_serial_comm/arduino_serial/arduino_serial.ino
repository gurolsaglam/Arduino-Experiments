void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("heyo");
  //Use Serial.write() to write other stuff, the one
  //above is for strings
  delay(500);
}
