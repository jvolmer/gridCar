#ifndef START_TURN_AROUND_H
#define START_TURN_AROUND_H

#include "motion.hpp"

class Pilot;
class Tracker;
class Motor;

class StartTurnAround: public Motion
{
private:
    Pilot& _pilot;
    Tracker& _tracker;
    Motor& _motor;

public:
    StartTurnAround(Pilot& pilot, Tracker& tracker, Motor& motor);
    void move() override;
};

#endif
