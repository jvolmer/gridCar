#ifndef TURN_LEFT_TO_LINE_H
#define TURN_LEFT_TO_LINE_H

#include "motion.hpp"

class Pilot;
class Tracker;
class Motor;

class TurnLeftToLine: public Motion
{
private:
    Pilot& _pilot;
    Tracker& _tracker;
    Motor& _motor;

public:
    TurnLeftToLine(Pilot& pilot, Tracker& tracker, Motor& motor);
    void move() override;    
};

#endif
