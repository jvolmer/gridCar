#ifndef POSITION_H
#define POSITION_H

#include "coordinate.hpp"

class Position
{
public:
    virtual void turnLeft() = 0;
    virtual void turnRight() = 0;
    virtual void moveForward() = 0;
    virtual bool isLocatedAt(const Coordinate& coordinate) const = 0;
};

#endif
