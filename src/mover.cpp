#include "motor.hpp"
#include "package.hpp"
#include "direction.hpp"
#include "mover.hpp"

Mover::Mover(Motor& motor, Point& startPosition, Direction& startDirection) :
    _motor { motor },
    _position { startPosition },
    _direction { startDirection},
    _velocity { 200 }
{}

void Mover::turnRight()
{
    _motor.run(_velocity, -_velocity);
    _direction = (Direction)(((int)_direction + 1) % 4);
}
