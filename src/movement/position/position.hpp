#ifndef POSITION_H
#define POSITION_H

#include "relativeDirection.hpp"
#include "direction.hpp"

class Coordinate;

class Position
{
public:
    virtual void setLocation(Coordinate&& location) = 0;
    virtual void setDirection(Direction direction) = 0;
    virtual void turnLeft() = 0;
    virtual void turnRight() = 0;
    virtual void moveForward() = 0;
    virtual bool isLocatedAt(const Coordinate& coordinate) const = 0;
    virtual RelativeDirection relativeDirectionToReach(const Coordinate& coordinate) const = 0;
};

#endif
