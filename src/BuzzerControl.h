#ifndef BuzzerControl_h
#define BuzzerControl_h

#include "Arduino.h"

class BuzzerControl {
  public:
    BuzzerControl(bool peripheralType, int pin); //peripheralType means buzzer connection type, 0 -> on GPIO, 1 -> on PCF7574
    void BuzzSound(int onTime);
  private:
    int _pin;
    bool _on = HIGH;
	bool _off = LOW; 
	bool _peripheralType;
};

#endif