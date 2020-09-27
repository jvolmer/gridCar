#include "stop.hpp"
#include "followLine.hpp"
#include "linePilot.hpp"
#include "startRightTurn.hpp"
#include "alignInRightTurn.hpp"
#include "findLineInRightTurn.hpp"
#include "startLeftTurn.hpp"
#include "alignInLeftTurn.hpp"
#include "findLineInLeftTurn.hpp"
#include "startTurnAround.hpp"
#include "alignInTurnAround.hpp"
#include "findLineInTurnAround.hpp"
#include "leaveFirstLineInTurnAround.hpp"
#include "findSecondLineInTurnAround.hpp"
#include "stopFinally.hpp"

class Coordinate;
class Position;
class Timer;
class Motor;

LinePilot::LinePilot(Coordinate& goal, Position& position, Tracker& tracker, Timer& timer, Motor& motor) :
    _stop{ Stop(*this, goal, position, motor) },
    _followLine{ FollowLine(*this, goal, position, tracker, motor) },
    _startRightTurn{ StartRightTurn(*this, tracker, motor) },
    _alignInRightTurn{ AlignInRightTurn(*this, timer, motor) },
    _findLineInRightTurn{ FindLineInRightTurn(*this, position, tracker, motor) },
    _startLeftTurn{ StartLeftTurn(*this, tracker, motor) },
    _alignInLeftTurn{ AlignInLeftTurn(*this, timer, motor) },
    _findLineInLeftTurn{ FindLineInLeftTurn(*this, position, tracker, motor) },
    _startTurnAround{ StartTurnAround(*this, tracker, motor) },
    _alignInTurnAround{ AlignInTurnAround(*this, timer, motor) },
    _findLineInTurnAround{ FindLineInTurnAround(*this, position, tracker, motor) },
    _leaveFirstLineInTurnAround{ LeaveFirstLineInTurnAround(*this, tracker, motor) },
    _findSecondLineInTurnAround{ FindSecondLineInTurnAround(*this, position, tracker, motor) },
    _stopFinally{ StopFinally( motor ) },
    _motion { &_followLine },
    _goal { goal }
{}

void LinePilot::changeMotion(MotionName name)
{
    switch(name)
    {
    case MotionName::stop:
        _motion = &_stop;
        break;
    case MotionName::followLine:
        _motion = &_followLine;
        break;
    case MotionName::startRightTurn:
        _motion = &_startRightTurn;
        break;
    case MotionName::alignInRightTurn:
        _motion = &_alignInRightTurn;
        break;
    case MotionName::findLineInRightTurn:
        _motion = &_findLineInRightTurn;
        break;
    case MotionName::startLeftTurn:
        _motion = &_startLeftTurn;
        break;
    case MotionName::alignInLeftTurn:
        _motion = &_alignInLeftTurn;
        break;
    case MotionName::findLineInLeftTurn:
        _motion = &_findLineInLeftTurn;
        break;
    case MotionName::startTurnAround:
        _motion = &_startTurnAround;
        break;
    case MotionName::alignInTurnAround:
        _motion = &_alignInTurnAround;
        break;
    case MotionName::findLineInTurnAround:
        _motion = &_findLineInTurnAround;
        break;
    case MotionName::leaveFirstLineInTurnAround:
        _motion = &_leaveFirstLineInTurnAround;
        break;
    case MotionName::findSecondLineInTurnAround:
        _motion = &_findSecondLineInTurnAround;
        break;
    case MotionName::stopFinally:
        _motion = &_stopFinally;
    default:
        _motion = &_stopFinally;
    }
}

void LinePilot::setAlignmentPeriodInTurn(unsigned long period)
{
    _alignInRightTurn.setAlignmentPeriod(period);
    _alignInLeftTurn.setAlignmentPeriod(period);
}
