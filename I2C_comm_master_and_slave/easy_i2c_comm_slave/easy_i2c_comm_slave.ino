#include <Wire.h>
#define I2C_SLAVE_ADDR  0x08

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(115200);  // start serial for output
  Wire.setClockStretchLimit(15000);
}

void loop() {
  Wire.requestFrom(I2C_SLAVE_ADDR, 1);    // request 6 bytes from slave device #8

  while (Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    Serial.print(c);         // print the character
  }

}
