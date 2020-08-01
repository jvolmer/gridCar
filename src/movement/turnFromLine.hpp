#ifndef TURN_FROM_LINE_H
#define TURN_FROM_LINE_H

#include "motion.hpp"

class Pilot;
class Tracker;
class Motor;

class TurnFromLine: public Motion
{
private:
    Pilot& _pilot;
    Tracker& _tracker;
    Motor& _motor;

public:
    TurnFromLine(Pilot& pilot, Tracker& tracker, Motor& motor);
    void move() override;
};

#endif
