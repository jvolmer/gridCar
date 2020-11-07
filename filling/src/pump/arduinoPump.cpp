#include "arduinoPump.hpp"
#include "Arduino.h"

ArduinoPump::ArduinoPump(const byte pinFirstPump, const byte pinSecondPump,
                         const byte pinThirdPump, const byte pinFourthPump)
    : _pinFirstPump{pinFirstPump}, _pinSecondPump{pinSecondPump},
      _pinThirdPump{pinThirdPump}, _pinFourthPump{pinFourthPump} {}

void ArduinoPump::pump() {}
