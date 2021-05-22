#include <Wire.h>
byte a = 0;

void setup() {
  Wire.begin();
}

void loop() {
  Wire.beginTransmission(1);
  Wire.write("OUTPUT: ");
  Wire.write(a);
  Wire.endTransmission();
  a++;
  delay(250);
}
