#ifndef START_LEFT_TURN_H
#define START_LEFT_TURN_H

#include "motion.hpp"

class Pilot;
class Tracker;
class Motor;

class StartLeftTurn: public Motion
{
private:
    Pilot& _pilot;
    Tracker& _tracker;
    Motor& _motor;

public:
    StartLeftTurn(Pilot& pilot, Tracker& tracker, Motor& motor);
    void move() override;
};

#endif
