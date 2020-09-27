#ifndef LINE_PILOT_H
#define LINE_PILOT_H

#include "pilot.hpp"
#include "motion.hpp"

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
