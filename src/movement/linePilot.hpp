#ifndef LINE_PILOT_H
#define LINE_PILOT_H

#include "pilot.hpp"

#include "motion/motion.hpp"
#include "motion/motionName.hpp"

#include "motion/stopFinally.hpp"
#include "motion/stop.hpp"
#include "motion/followLine.hpp"
#include "motion/centerInRightTurn.hpp"
#include "motion/leaveOriginLineInRightTurn.hpp"
#include "motion/findNextLineInRightTurn.hpp"
#include "motion/centerInLeftTurn.hpp"
#include "motion/leaveOriginLineInLeftTurn.hpp"
#include "motion/findNextLineInLeftTurn.hpp"
#include "motion/centerInTurnAround.hpp"
#include "motion/leaveOriginLineInTurnAround.hpp"
#include "motion/findNextLineInTurnAround.hpp"
#include "motion/leaveNextLineInTurnAround.hpp"
#include "motion/findNextToNextLineInTurnAround.hpp"

class Goal;
class Position;
class Tracker;
class Timer;
class Motor;


// This class is a state machine
// for the different motion types of the car.

class LinePilot: public Pilot
{
private:
    StopFinally _stopFinally;
    Stop _stop;
    FollowLine _followLine;

    // right turn
    CenterInRightTurn _centerInRightTurn;
    LeaveOriginLineInRightTurn _leaveOriginLineInRightTurn;
    FindNextLineInRightTurn _findNextLineInRightTurn;

    // left turn
    CenterInLeftTurn _centerInLeftTurn;
    LeaveOriginLineInLeftTurn _leaveOriginLineInLeftTurn;
    FindNextLineInLeftTurn _findNextLineInLeftTurn;

    // turn around
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
