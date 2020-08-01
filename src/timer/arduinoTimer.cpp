#include "arduinoTimer.hpp"
#include "Arduino.h"

ArduinoTimer::ArduinoTimer()
{}

unsigned long ArduinoTimer::moment()
{
    return millis();
}
