#ifndef LINE_PILOT_H
#define LINE_PILOT_H

#include "pilot.hpp"
#include "motion.hpp"
#include "stop.hpp"
#include "followLine.hpp"
#include "turnRightFromLine.hpp"
#include "alignInRightTurn.hpp"
#include "turnRightToLine.hpp"
#include "turnLeftFromLine.hpp"
#include "alignInLeftTurn.hpp"
#include "turnLeftToLine.hpp"
#include "motionName.hpp"

class Coordinate;
class Position;
class Tracker;
class Timer;
class Motor;

class LinePilot: public Pilot
{
private:
    Stop _stop;
    FollowLine _followLine;
    TurnRightFromLine _turnRightFromLine;
    AlignInRightTurn _alignInRightTurn;
    TurnRightToLine _turnRightToLine;
    TurnLeftFromLine _turnLeftFromLine;
    AlignInLeftTurn _alignInLeftTurn;
    TurnLeftToLine _turnLeftToLine;
    Motion* _motion;

public:
    LinePilot(Coordinate& goal, Position& position, Tracker& tracker, Timer& timer, Motor& motor);
    void move() override { _motion->move(); }
    void changeMotion(MotionName Name) override;
};

#endif
