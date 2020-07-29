#include "pilot.hpp"
#include "position/position.hpp"
#include "motor/motor.hpp"
#include "motionName.hpp"
#include "followLine.hpp"


class Coordinate;

FollowLine::FollowLine(Pilot& pilot, Coordinate& goal, Position& position, Motor& motor):
    _pilot { pilot },
    _goal { goal },
    _position { position },
    _motor { motor }
{}

void FollowLine::move()
{
    _motor.goStraight();
    if ( _position.isLocatedAt( _goal ) )
    {
        _pilot.changeMotion( MotionName::stop );
    }
}
