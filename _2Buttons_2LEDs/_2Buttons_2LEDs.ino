
const int buttonPin1 = 0;
const int buttonPin2 = 5;
const int ledPin1 =  1;
const int ledPin2 =  2;

int buttonState1 = 0;
int buttonState2 = 0;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
}

void loop() {
  digitalWrite(ledPin1,!(digitalRead(buttonPin1)));
  digitalWrite(ledPin2,!(digitalRead(buttonPin2)));
}
