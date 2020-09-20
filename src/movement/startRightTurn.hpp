#ifndef START_RIGHT_TURN_H
#define START_RIGHT_TURN_H

#include "motion.hpp"

class Pilot;
class Tracker;
class Motor;

class StartRightTurn: public Motion
{
private:
    Pilot& _pilot;
    Tracker& _tracker;
    Motor& _motor;

public:
    StartRightTurn(Pilot& pilot, Tracker& tracker, Motor& motor);
    void move() override;
};

#endif
