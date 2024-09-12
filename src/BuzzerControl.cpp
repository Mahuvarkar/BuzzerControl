#include "Arduino.h"
#include "BuzzerControl.h"
#include "pcf8574.h"  //library by MSZ98 v1.0.3

/*
addresses available for PCF are between 0x20 and 0x27
A0 A1 A2 -> Address
0  0  0  -> 0x20
0  0  1  -> 0x21
0  1  0  -> 0x22
0  1  1  -> 0x23
1  0  0  -> 0x24
1  0  1  -> 0x25
1  1  0  -> 0x26
1  1  1  -> 0x27
*/

PCF8574 BuzzerEx(0x20);  // Create obhjects as per the hardware addesses set on the IC A0, A1, A2 pins
// PCF8574 BuzzerEx(0x21);  // Create obhjects as per the hardware addesses set on the IC A0, A1, A2 pins
// PCF8574 BuzzerEx(0x22);  // Create obhjects as per the hardware addesses set on the IC A0, A1, A2 pins
// PCF8574 BuzzerEx(0x23);  // Create obhjects as per the hardware addesses set on the IC A0, A1, A2 pins
// PCF8574 BuzzerEx(0x24);  // Create obhjects as per the hardware addesses set on the IC A0, A1, A2 pins
// PCF8574 BuzzerEx(0x25);  // Create obhjects as per the hardware addesses set on the IC A0, A1, A2 pins
// PCF8574 BuzzerEx(0x26);  // Create obhjects as per the hardware addesses set on the IC A0, A1, A2 pins
// PCF8574 BuzzerEx(0x27);  // Create obhjects as per the hardware addesses set on the IC A0, A1, A2 pins

BuzzerControl::BuzzerControl(bool peripheralType, int pin) { /* peripheralType means buzzer connection type, 0 -> on GPIO, 1 -> on PCF7574 */
  _peripheralType = peripheralType;
  if (!_peripheralType) {
    pinMode(pin, OUTPUT);
  } else if (_peripheralType) {
    pinMode(BuzzerEx, pin, OUTPUT);
  }
  _pin = pin;
}

void BuzzerControl::BuzzSound(int onTime) { /* peripheralType means buzzer connection type, 0 -> on GPIO, 1 -> on PCF7574 */
  if (!_peripheralType) {
    digitalWrite(_pin, _on);
    delay(onTime);
    digitalWrite(_pin, _off);
  } else if (_peripheralType) {
    digitalWrite(BuzzerEx, _pin, _on);
    delay(onTime);
    digitalWrite(BuzzerEx, _pin, _off);
  }
}