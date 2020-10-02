#ifndef LINE_PILOT_H
#define LINE_PILOT_H

#include "pilot.hpp"
#include "motion.hpp"
#include "motionName.hpp"

#include "stop.hpp"
#include "followLine.hpp"
#include "linePilot.hpp"
#include "centerInRightTurn.hpp"
#include "leaveOriginLineInRightTurn.hpp"
#include "findNextLineInRightTurn.hpp"
#include "centerInLeftTurn.hpp"
#include "leaveOriginLineInLeftTurn.hpp"
#include "findNextLineInLeftTurn.hpp"
#include "centerInTurnAround.hpp"
#include "leaveOriginLineInTurnAround.hpp"
#include "findNextLineInTurnAround.hpp"
#include "leaveNextLineInTurnAround.hpp"
#include "findNextToNextLineInTurnAround.hpp"
#include "stopFinally.hpp"

class Goal;
class Position;
class Tracker;
class Timer;
class Motor;

class LinePilot: public Pilot
{
private:
    StopFinally _stopFinally;
    Stop _stop;
    FollowLine _followLine;
    CenterInRightTurn _centerInRightTurn;
    LeaveOriginLineInRightTurn _leaveOriginLineInRightTurn;
    FindNextLineInRightTurn _findNextLineInRightTurn;
    CenterInLeftTurn _centerInLeftTurn;
    LeaveOriginLineInLeftTurn _leaveOriginLineInLeftTurn;
    FindNextLineInLeftTurn _findNextLineInLeftTurn;
    CenterInTurnAround _centerInTurnAround;
    LeaveOriginLineInTurnAround _leaveOriginLineInTurnAround;
    FindNextLineInTurnAround _findNextLineInTurnAround;
    LeaveNextLineInTurnAround _leaveNextLineInTurnAround;
    FindNextToNextLineInTurnAround _findNextToNextLineInTurnAround;

    Motion* _motion;
    Goal& _goal;

public:
    LinePilot(Goal& goal, Position& position, Tracker& tracker, Timer& timer, Motor& motor);
    void move() override { _motion->move(); }
    void changeMotion(MotionName Name) override;
    void setAlignmentPeriodInTurn(unsigned long period);
};

#endif
