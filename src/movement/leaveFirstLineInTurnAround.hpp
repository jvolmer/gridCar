#ifndef LEAVE_FIRST_LINE_IN_TURN_AROUND_H
#define LEAVE_FIRST_LINE_IN_TURN_AROUND_H

#include "motion.hpp"

class Pilot;
class Tracker;
class Motor;

class LeaveFirstLineInTurnAround: public Motion
{
private:
    Pilot& _pilot;
    Tracker& _tracker;
    Motor& _motor;

public:
    LeaveFirstLineInTurnAround(Pilot& pilot, Tracker& tracker, Motor& motor);
    void move() override;
};

#endif
