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
#include "../communication/coordinateListener.hpp"
#include "position/coordinate.hpp"

class Position;
class Tracker;
class Timer;
class Motor;
class CoordinateBroadcaster;

class LinePilot: public Pilot, public CoordinateListener
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
    Coordinate& _goal;

public:
    LinePilot(Coordinate& goal, Position& position, Tracker& tracker, Timer& timer, Motor& motor, CoordinateBroadcaster& goalBroadcaster);
    void move() override { _motion->move(); }
    void changeMotion(MotionName Name) override;
    void update(const Coordinate& goal) override { _goal = goal; }
};

#endif
