#ifndef POSITION_H
#define POSITION_H

#include "coordinate.hpp"
#include "relativeDirection.hpp"

class Position
{
public:
    virtual void turnLeft() = 0;
    virtual void turnRight() = 0;
    virtual void moveForward() = 0;
    virtual bool isLocatedAt(const Coordinate& coordinate) const = 0;
    virtual RelativeDirection relativeDirectionToReach(const Coordinate& coordinate) const = 0;
};

#endif
