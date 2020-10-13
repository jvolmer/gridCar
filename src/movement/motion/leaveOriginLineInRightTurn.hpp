#ifndef LEAVE_ORIGIN_LINE_IN_RIGHT_TURN_H
#define LEAVE_ORIGIN_LINE_IN_RIGHT_TURN_H

#include "leaveLine.hpp"

class Pilot;
class Tracker;
class Motor;

class LeaveOriginLineInRightTurn: public LeaveLine
{
private:
    Pilot& _pilot;
    Tracker& _tracker;
    Motor& _motor;

public:
    LeaveOriginLineInRightTurn(Pilot& pilot, Tracker& tracker, Motor& motor);
    void turn();
    bool hasLeft();
    void changeMotion();
};

#endif
