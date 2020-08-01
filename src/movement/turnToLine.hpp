#ifndef TURN_TO_LINE_H
#define TURN_TO_LINE_H

#include "motion.hpp"

class Pilot;
class Tracker;
class Motor;

class TurnToLine: public Motion
{
private:
    Pilot& _pilot;
    Tracker& _tracker;
    Motor& _motor;

public:
    TurnToLine(Pilot& pilot, Tracker& tracker, Motor& motor);
    void move() override;    
};

#endif
