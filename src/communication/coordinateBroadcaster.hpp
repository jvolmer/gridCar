#ifndef COORDINATE_BROADCASTER_H
#define COORDINATE_BROADCASTER_H

class CoordinateListener;
class Coordinate;

class CoordinateBroadcaster
{
public:
    virtual void subscribe(CoordinateListener* listener) = 0;
    virtual void broadcast(const Coordinate& coordinate) const = 0;
};

#endif
