#ifndef MOVER_H
#define MOVER_H

#include "model/motor.hpp"
#include "model/tracker.hpp"
#include "entity/coordinate.hpp"
#include "entity/direction.hpp"

class Mover
{
private:
    Motor& _motor;
    Tracker& _tracker;
    Coordinate _position;
    Direction _direction;
    int _velocity;
    
public:
    Mover(Motor& motor, Tracker& tracker, Coordinate& startPosition, Direction& startDirection);
    const Coordinate& getPosition() const { return _position; }
    const Direction& getDirection() const{ return _direction; }

    void turnRightAtCrossing();
    void turnLeftAtCrossing();
    void goStraightUntilCrossingCount(int nCrossing);
};

#endif
