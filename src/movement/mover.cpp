#include "motor/motor.hpp"
#include "tracker/tracker.hpp"
#include "coordinate.hpp"
#include "direction.hpp"
#include "tracker/roadLayout.hpp"
#include "mover.hpp"

Mover::Mover(Motor& motor, Tracker& tracker) :
    _motor { motor },
    _tracker { tracker }
{}

void Mover::turnRightAtCrossing()
{
    do
    {
        _motor.turnRight();
    } while(_tracker.checkRoad() != RoadLayout::blocked);
    _motor.stop();
    
    _direction = _direction + 1;
}

void Mover::turnLeftAtCrossing()
{
    do
    {
        _motor.turnLeft();
    } while(_tracker.checkRoad() != RoadLayout::blocked);
    _motor.stop();
    
    _direction = _direction - 1;
}

void Mover::followLineUntilCrossing()
{
    _motor.goStraight();
    do
    {
        followLine();
    } while(_tracker.checkRoad() != RoadLayout::blocked);

    _position = _position + Coordinate(_direction);
}

void Mover::followLineUntilCrossingCount(int count)
{
    for (int counter = 0; counter < count; counter++)
    {
        followLineUntilCrossing();
    }
}

void Mover::followLine()
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
