#ifndef ARDUINO_PUMP_H
#define ARDUINO_PUMP_H

#include "pump.hpp"
#include "Arduino.h"

class ArduinoPump : public Pump {

private:
    const byte _pin;
    
public:
    ArduinoPump(const byte pin);
    void setup() override;
    void start() override;
    void stop() override;
};

#endif
