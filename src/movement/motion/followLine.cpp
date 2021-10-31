#include "../pilot.hpp"
#include "../position/position.hpp"
#include "../position/relativeDirection.hpp"
#include "../tracker/tracker.hpp"
#include "../tracker/roadLayout.hpp"
#include "../motor/motor.hpp"
#include "motionName.hpp"
#include "followLine.hpp"

class Coordinate;

FollowLine::FollowLine(Pilot& pilot, Position& position, Tracker& tracker, Motor& motor):
    _pilot { pilot },
    _position { position },
    _tracker { tracker },
    _motor { motor }
{}

void FollowLine::move()
{
    switch( _tracker.roadLayout() )
    {
    case RoadLayout::none:
        _motor.stop();
        break;
    case RoadLayout::blocked:
        _position.moveForward();
        _pilot.changeMotion( MotionName::cross );
        break;
    case RoadLayout::sharpRight:
    case RoadLayout::right:
        _motor.turnRight();
        break;
    case RoadLayout::straight:
    case RoadLayout::enclosed:
        _motor.goStraight();
        break;
    case RoadLayout::sharpLeft:
    case RoadLayout::left:
        _motor.turnLeft();
        break;
    }
}
