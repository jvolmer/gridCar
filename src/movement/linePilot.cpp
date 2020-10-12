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

class Coordinate;
class Goal;
class Position;
class Timer;
class Motor;

LinePilot::LinePilot(Goal& goal, Position& position, Tracker& tracker, Timer& timer, Motor& motor) :
    _stopFinally{ StopFinally( motor ) },
    _stop{ Stop(*this, goal, position, motor) },
    _followLine{ FollowLine(*this, position, tracker, motor) },
    _centerInRightTurn{ CenterInRightTurn(*this, timer, motor) },
    _leaveOriginLineInRightTurn{ LeaveOriginLineInRightTurn(*this, tracker, motor) },
    _findNextLineInRightTurn{ FindNextLineInRightTurn(*this, position, tracker, motor) },
    _centerInLeftTurn{ CenterInLeftTurn(*this, timer, motor) },
    _leaveOriginLineInLeftTurn{ LeaveOriginLineInLeftTurn(*this, tracker, motor) },
    _findNextLineInLeftTurn{ FindNextLineInLeftTurn(*this, position, tracker, motor) },
    _centerInTurnAround{ CenterInTurnAround(*this, timer, motor) },
    _leaveOriginLineInTurnAround{ LeaveOriginLineInTurnAround(*this, tracker, motor) },
    _findNextLineInTurnAround{ FindNextLineInTurnAround(*this, position, tracker, motor) },
    _leaveNextLineInTurnAround{ LeaveNextLineInTurnAround(*this, tracker, motor) },
    _findNextToNextLineInTurnAround{ FindNextToNextLineInTurnAround(*this, position, tracker, motor) },
    _motion { &_stop },
    _goal { goal }
{}

void LinePilot::changeMotion(MotionName name)
{
    switch(name)
    {
    case MotionName::stopFinally:
        _motion = &_stopFinally;
        break;
    case MotionName::stop:
        _motion = &_stop;
        break;
    case MotionName::followLine:
        _motion = &_followLine;
        break;
    case MotionName::centerInRightTurn:
        _motion = &_centerInRightTurn;
        break;
    case MotionName::leaveOriginLineInRightTurn:
        _motion = &_leaveOriginLineInRightTurn;
        break;
    case MotionName::findNextLineInRightTurn:
        _motion = &_findNextLineInRightTurn;
        break;
    case MotionName::centerInLeftTurn:
        _motion = &_centerInLeftTurn;
        break;
    case MotionName::leaveOriginLineInLeftTurn:
        _motion = &_leaveOriginLineInLeftTurn;
        break;
    case MotionName::findNextLineInLeftTurn:
        _motion = &_findNextLineInLeftTurn;
        break;
    case MotionName::centerInTurnAround:
        _motion = &_centerInTurnAround;
        break;
    case MotionName::leaveOriginLineInTurnAround:
        _motion = &_leaveOriginLineInTurnAround;
        break;
    case MotionName::findNextLineInTurnAround:
        _motion = &_findNextLineInTurnAround;
        break;
    case MotionName::leaveNextLineInTurnAround:
        _motion = &_leaveNextLineInTurnAround;
        break;
    case MotionName::findNextToNextLineInTurnAround:
        _motion = &_findNextToNextLineInTurnAround;
        break;
    default:
        _motion = &_stopFinally;
    }
}

void LinePilot::setAlignmentPeriodInTurn(unsigned long period)
{
    _centerInRightTurn.setAlignmentPeriod(period);
    _centerInLeftTurn.setAlignmentPeriod(period);
    _centerInTurnAround.setAlignmentPeriod(period);
}
