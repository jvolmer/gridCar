#ifndef TURN_RIGHT_FROM_LINE_H
#define TURN_RIGHT_FROM_LINE_H

#include "motion.hpp"

class Pilot;
class Tracker;
class Motor;

class TurnRightFromLine: public Motion
{
private:
    Pilot& _pilot;
    Tracker& _tracker;
    Motor& _motor;

public:
    TurnRightFromLine(Pilot& pilot, Tracker& tracker, Motor& motor);
    void move() override;
};

#endif
