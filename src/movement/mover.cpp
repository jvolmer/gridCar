#include "motor/motor.hpp"
#include "tracker/tracker.hpp"
#include "coordinate.hpp"
#include "direction.hpp"
#include "tracker/roadLayout.hpp"
#include "mover.hpp"

LineSteering::LineSteering(Motor& motor, Tracker& tracker) :
    _motor { motor },
    _tracker { tracker }
{}

void LineSteering::turnRightUpToNextPerpendicularLine()
{
    _motor.turnRight();
    if (_tracker.checkRoad() == RoadLayout::blocked) {
        _motor.stop();
        _direction = _direction + 1;
    }
}

void LineSteering::turnLeftUpToNextPerpendicularLine()
{
    _motor.turnLeft();
    if (_tracker.checkRoad() == RoadLayout::blocked) {
        _motor.stop();
        _direction = _direction - 1;
    }
}

void LineSteering::followLine()
{
    switch(_tracker.checkRoad())
    {
    case RoadLayout::none:
    case RoadLayout::blocked:
        _motor.stop();
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
    default:
        break;
    }
}

void LineSteering::followLineUpTo(const Coordinate& coordinate)
{
    followLine();
    if (_tracker.checkRoad() == RoadLayout::blocked) {
        _position = _position + Coordinate(_direction);
        if (_position == coordinate)
        {
            _motor.stop();
        }
        else
        {
            _motor.goStraight();
        }
    }
}

bool LineSteering::directsTowards(const Coordinate& coordinate)
{
    return (
        ( (_direction == Direction::positiveX) && (coordinate.getx() > _position.getx()) ) ||
        ( (_direction == Direction::negativeX) && (coordinate.getx() < _position.getx()) ) ||
        ( (_direction == Direction::positiveY) && (coordinate.gety() > _position.gety()) ) ||
        ( (_direction == Direction::negativeY) && (coordinate.gety() < _position.gety()) )
        );
}
