#include "stop.hpp"
#include "followLine.hpp"
#include "linePilot.hpp"

class Coordinate;
class Position;
class Motor;

LinePilot::LinePilot(Coordinate& goal, Position& position, Motor& motor):
    _stop{ Stop(*this, motor) },
    _followLine{ FollowLine(*this, goal, position, motor) },
    _motion { &_stop }
{}

void LinePilot::changeMotion(MotionName name)
{
    switch(name)
    {
    case MotionName::stop:
        _motion = &_stop;
        break;
    case MotionName::followLine:
        _motion = & _followLine;
        break;
    default:
        _motion = &_stop;
    }
}
