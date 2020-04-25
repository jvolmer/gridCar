#include "model/motor.hpp"
#include "model/tracker.hpp"
#include "entity/package.hpp"
#include "entity/direction.hpp"
#include "mover.hpp"

Mover::Mover(Motor& motor, Tracker& tracker, Point& startPosition, Direction& startDirection) :
    _motor { motor },
    _tracker { tracker },
    _position { startPosition },
    _direction { startDirection },
    _velocity { 200 }
{}

void Mover::turnRightAtCrossing()
{
    do {
        _motor.run(_velocity, -_velocity);
    } while(_tracker.checkSensors() != 7);
    _motor.run(0, 0);
    
    _direction = (Direction)(((int)_direction + 1) % 4);
}

void Mover::turnLeftAtCrossing()
{
    do {
        _motor.run(-_velocity, _velocity);
    } while(_tracker.checkSensors() != 7);
    _motor.run(0, 0);
    
    _direction = (Direction)((((int)_direction - 1)+4) % 4);
}

void Mover::goStraightUntilCrossingCount(int nCrossing)
{
}
