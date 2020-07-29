#include "pilot.hpp"
#include "position/position.hpp"
#include "tracker/tracker.hpp"
#include "tracker/roadLayout.hpp"
#include "motor/motor.hpp"
#include "motionName.hpp"
#include "followLine.hpp"

class Coordinate;

FollowLine::FollowLine(Pilot& pilot, Coordinate& goal, Position& position, Tracker& tracker, Motor& motor):
    _pilot { pilot },
    _goal { goal },
    _position { position },
    _tracker { tracker },
    _motor { motor }
{}

void FollowLine::move()
{
    _motor.goStraight();
    if ( _tracker.checkRoad() == RoadLayout::blocked )
    {
        _position.moveForward();
    }
    if ( _position.isLocatedAt( _goal ) )
    {
        _pilot.changeMotion( MotionName::stop );
    }
}
