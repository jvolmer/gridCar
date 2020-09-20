#ifndef LINE_PILOT_H
#define LINE_PILOT_H

#include "pilot.hpp"
#include "motion.hpp"
#include "stop.hpp"
#include "followLine.hpp"
#include "startRightTurn.hpp"
#include "alignInRightTurn.hpp"
#include "findLineInRightTurn.hpp"
#include "startLeftTurn.hpp"
#include "alignInLeftTurn.hpp"
#include "findLineInLeftTurn.hpp"
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
    StartRightTurn _startRightTurn;
    AlignInRightTurn _alignInRightTurn;
    FindLineInRightTurn _findLineInRightTurn;
    StartLeftTurn _startLeftTurn;
    AlignInLeftTurn _alignInLeftTurn;
    FindLineInLeftTurn _findLineInLeftTurn;
    Motion* _motion;
    Coordinate& _goal;

public:
    LinePilot(Coordinate& goal, Position& position, Tracker& tracker, Timer& timer, Motor& motor);
    void move() override { _motion->move(); }
    void changeMotion(MotionName Name) override;
    void update(const Coordinate& goal) override { _goal = goal; }
    void listenTo(CoordinateBroadcaster& broadcaster) override { CoordinateListener::listenTo(broadcaster); }
    void setAlignmentPeriodInTurn(unsigned long period);
};

#endif
