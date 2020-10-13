#ifndef LEAVE_ORIGIN_LINE_IN_LEFT_TURN_H
#define LEAVE_ORIGIN_LINE_IN_LEFT_TURN_H

#include "leaveLine.hpp"

class Pilot;
class Tracker;
class Motor;

class LeaveOriginLineInLeftTurn: public LeaveLine
{
private:
    Pilot& _pilot;
    Tracker& _tracker;
    Motor& _motor;

public:
    LeaveOriginLineInLeftTurn(Pilot& pilot, Tracker& tracker, Motor& motor);
    void turn();
    bool hasLeft();
    void changeMotion();
};

#endif
