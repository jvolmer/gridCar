#ifndef GOAL_H
#define GOAL_H

#include "position/relativeDirection.hpp"

class Coordinate;
class Position;

class Goal
{
public:
    virtual void set(const Coordinate& coordinate) = 0;
    virtual const Coordinate& get() = 0;
    virtual RelativeDirection turningDirectionFrom(const Position& position) const = 0;
};

#endif
