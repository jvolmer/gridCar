#include "stop.hpp"
#include "followLine.hpp"
#include "linePilot.hpp"
#include "turnRightFromLine.hpp"
#include "alignInRightTurn.hpp"
#include "turnRightToLine.hpp"
#include "turnLeftFromLine.hpp"
#include "alignInLeftTurn.hpp"
#include "turnLeftToLine.hpp"

class Coordinate;
class Position;
class Timer;
class Motor;

LinePilot::LinePilot(Coordinate& goal, Position& position, Tracker& tracker, Timer& timer, Motor& motor):
    _stop{ Stop(*this, goal, position, motor) },
    _followLine{ FollowLine(*this, goal, position, tracker, motor) },
    _turnRightFromLine{ TurnRightFromLine(*this, tracker, motor) },
    _alignInRightTurn{ AlignInRightTurn(*this, timer, motor) },
    _turnRightToLine{ TurnRightToLine(*this, position, tracker, motor) },
    _turnLeftFromLine{ TurnLeftFromLine(*this, tracker, motor) },
    _alignInLeftTurn{ AlignInLeftTurn(*this, timer, motor) },
    _turnLeftToLine{ TurnLeftToLine(*this, position, tracker, motor) },
    _motion { &_followLine }
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
    case MotionName::turnRightFromLine:
        _motion = &_turnRightFromLine;
        break;
    case MotionName::alignInRightTurn:
        _motion = &_alignInRightTurn;
        break;
    case MotionName::turnRightToLine:
        _motion = &_turnRightToLine;
        break;
    case MotionName::turnLeftFromLine:
        _motion = &_turnLeftFromLine;
        break;
    case MotionName::alignInLeftTurn:
        _motion = &_alignInLeftTurn;
        break;
    case MotionName::turnLeftToLine:
        _motion = &_turnLeftToLine;
        break;
    default:
        _motion = &_stop;
    }
}
