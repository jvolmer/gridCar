#ifndef LEAVE_ORIGIN_LINE_IN_TURN_AROUND_H
#define LEAVE_ORIGIN_LINE_IN_TURN_AROUND_H

#include "leaveLine.hpp"

class Pilot;
class Tracker;
class Motor;

class LeaveOriginLineInTurnAround: public LeaveLine
{
private:
    Pilot& _pilot;
    Tracker& _tracker;
    Motor& _motor;

public:
    LeaveOriginLineInTurnAround(Pilot& pilot, Tracker& tracker, Motor& motor);
    void turn();
    bool hasLeft();
    void changeMotion();
};

#endif
