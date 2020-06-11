#ifndef ARDUINO_MOVER_H
#define ARDUINO_MOVER_H

#include "motor/motor.hpp"
#include "tracker/tracker.hpp"
#include "mover.hpp"

class ArduinoMover: public Mover
{
public:
    ArduinoMover(Motor& motor, Tracker& tracker);
    void print();
};

#endif
