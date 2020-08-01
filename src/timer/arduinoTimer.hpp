#ifndef ARDUINO_TIMER_H
#define ARDUINO_TIMER_H

#include "timer.hpp"
#include "Arduino.h"

class ArduinoTimer: public Timer
{
public:
    ArduinoTimer();
    unsigned long millis() override;
};
    
#endif
