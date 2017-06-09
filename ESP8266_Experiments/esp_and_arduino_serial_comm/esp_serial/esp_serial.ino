void setup() {
  Serial.begin(115200);
}

void loop() {
  String x = (String) Serial.read();
  //Do other stuff
  delay(500);
}
