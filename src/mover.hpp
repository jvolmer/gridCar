#ifndef MOVER_H
#define MOVER_H

#include "motor.hpp"
#include "package.hpp"
#include "direction.hpp"

class Mover
{
private:
    Motor& _motor;
    Point _position;
    Direction _direction;
    int _velocity;
    
public:
    Mover(Motor& motor, Point& startPosition, Direction& startDirection);
    Point getPosition() { return _position; }
    Direction getDirection() { return _direction; }

    void turnRight();
};

#endif
