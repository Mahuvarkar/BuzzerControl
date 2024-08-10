#include <BuzzerControl.h>

// (x, y) x -> peripheraltype (0 = on gpio, 1 = on PCF8574), y -> pin number
BuzzerControl Buzz1(0, 10); 
BuzzerControl Buzz2(1, 1);

void setup() {
  // put your setup code here, to run once:
  Buzz1.BuzzSound(1000);
  delay(1000);
  Buzz2.BuzzSound(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
}