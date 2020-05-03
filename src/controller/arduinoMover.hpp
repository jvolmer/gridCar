#ifndef ARDUINO_MOVER_H
#define ARDUINO_MOVER_H

#include "model/motor.hpp"
#include "model/tracker.hpp"
#include "controller/mover.hpp"

class ArduinoMover: public Mover
{
public:
    ArduinoMover(Motor& motor, Tracker& tracker);
    void print();
};

#endif
