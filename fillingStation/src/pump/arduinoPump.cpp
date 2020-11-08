#include "arduinoPump.hpp"
#include "Arduino.h"

ArduinoPump::ArduinoPump(const byte pin) : _pin{pin} {}

void ArduinoPump::setup()
{
    stop();
}

void ArduinoPump::start()
{
    digitalWrite(_pin, LOW);
}

void ArduinoPump::stop()
{
    digitalWrite(_pin, HIGH);
}
