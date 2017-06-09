#include "Wire.h"
#define I2C_SLAVE_ADDR  0x08

void setup() {
  Wire.begin();
}

void loop() {
  Wire.beginTransmission(I2C_SLAVE_ADDR);
  Wire.write(1);
  Wire.endTransmission();
  delay(5);
}
