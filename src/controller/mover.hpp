#ifndef MOVER_H
#define MOVER_H

#include "model/motor.hpp"
#include "model/tracker.hpp"
#include "entity/package.hpp"
#include "entity/direction.hpp"

class Mover
{
private:
    Motor& _motor;
    Tracker& _tracker;
    Point _position;
    Direction _direction;
    int _velocity;
    
public:
    Mover(Motor& motor, Tracker& tracker, Point& startPosition, Direction& startDirection);
    Point getPosition() { return _position; }
    Direction getDirection() { return _direction; }

    void turnRightAtCrossing();
    void turnLeftAtCrossing();
    void goStraightUntilCrossingCount(int nCrossing);
};

#endif
