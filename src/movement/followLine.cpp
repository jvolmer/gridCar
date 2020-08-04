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
    followLine();

    if ( _position.isLocatedAt(_goal) )
    {
        _pilot.changeMotion( MotionName::stop );
    }
    else if ( _position.isAtTurningPointToReach(_goal))
    {
        int turnTrend = _position.getTurnTrendToReach(_goal);
        if (turnTrend == 1) {
            _pilot.changeMotion( MotionName::turnRightFromLine );
        }
        else if (turnTrend == -1) {
            _pilot.changeMotion( MotionName::turnLeftFromLine );
        }
    }
}

void FollowLine::followLine()
{
    switch( _tracker.checkRoad() )
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
    default:
        break;
    }
}
