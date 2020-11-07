#ifndef ARDUINO_PUMP_H
#define ARDUINO_PUMP_H

#include "pump.hpp"
#include "Arduino.h"

class ArduinoPump : Pump {
private:
    const byte _pinFirstPump;
    const byte _pinSecondPump;
    const byte _pinThirdPump;
    const byte _pinFourthPump;
    
public:
  ArduinoPump(const byte pinFirstPump, const byte pinSecondPump,
              const byte pinThirdPump, const byte pinFourthPump);
  void pump() override;
};

#endif
