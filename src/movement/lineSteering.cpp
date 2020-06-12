#include "motor/motor.hpp"
#include "tracker/tracker.hpp"
#include "tracker/roadLayout.hpp"
#include "position/position.hpp"
#include "position/coordinate.hpp"
#include "lineSteering.hpp"

LineSteering::LineSteering(Position& position, Motor& motor, Tracker& tracker) :
    _position { position },
    _motor { motor },
    _tracker { tracker }
{}

void LineSteering::turnRightUpToNextCrossLine()
{
    _motor.turnRight();
    if (_tracker.checkRoad() == RoadLayout::blocked) {
        _motor.stop();
        _position.turnRight();
    }
}

void LineSteering::turnLeftUpToNextCrossLine()
{
    _motor.turnLeft();
    if (_tracker.checkRoad() == RoadLayout::blocked) {
        _motor.stop();
        _position.turnLeft();;
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
        _position.moveForward();
        if ( _position.isLocatedAt(coordinate) )
        {
            _motor.stop();
        }
        else
        {
            _motor.goStraight();
        }
    }
}

// bool LineSteering::directsTowards(const Coordinate& coordinate)
// {
//     return (
//         ( (_direction == Direction::positiveX) && (coordinate.getx() > _position.getx()) ) ||
//         ( (_direction == Direction::negativeX) && (coordinate.getx() < _position.getx()) ) ||
//         ( (_direction == Direction::positiveY) && (coordinate.gety() > _position.gety()) ) ||
//         ( (_direction == Direction::negativeY) && (coordinate.gety() < _position.gety()) )
//         );
// }
