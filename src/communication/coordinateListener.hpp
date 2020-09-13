#ifndef COORDINATE_LISTENER_H
#define COORDINATE_LISTENER_H

class Coordinate;
class CoordinateBroadcaster;

class CoordinateListener
{
public:
    virtual void listenTo(CoordinateBroadcaster& broadcaster) = 0;
    virtual void update(const Coordinate& location) = 0;
};

#endif
