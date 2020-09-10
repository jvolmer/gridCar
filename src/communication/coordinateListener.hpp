#ifndef COORDINATE_LISTENER_H
#define COORDINATE_LISTENER_H

class Coordinate;

class CoordinateListener
{
public:
    virtual void update(const Coordinate& location) = 0;
};

#endif
