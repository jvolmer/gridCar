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
    followLine();

    if ( isAtCrossing )
    {
        _pilot.changeMotion( MotionName::stop );
    }
}

void FollowLine::followLine()
{
    switch( _tracker.roadLayout() )
    {
    case RoadLayout::none:
        _motor.stop();
        isAtCrossing = false;
        break;
    case RoadLayout::blocked:
        if (!isAtCrossing)
        {
            _position.moveForward();
            isAtCrossing = true;
            _motor.goStraight();
        }
        break;
    case RoadLayout::sharpRight:
    case RoadLayout::right:
        _motor.turnRight();
        isAtCrossing = false;
        break;
    case RoadLayout::straight:
    case RoadLayout::enclosed:
        _motor.goStraight();
        isAtCrossing = false;
        break;
    case RoadLayout::sharpLeft:
    case RoadLayout::left:
        _motor.turnLeft();
        isAtCrossing = false;
        break;
    }
}
