#ifndef GOAL_H
#define GOAL_H

class Coordinate;

class Goal
{
public:
    virtual void set(const Coordinate& coordinate) = 0;
    virtual const Coordinate& get() = 0;
};

#endif
