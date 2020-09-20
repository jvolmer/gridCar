#ifndef COORDINATE_BROADCASTER_H
#define COORDINATE_BROADCASTER_H

class CoordinateListener;
class Coordinate;

class CoordinateBroadcaster
{
private:
    CoordinateListener* _listener = nullptr;

public:
    virtual void subscribe(CoordinateListener* listener) = 0;
    virtual void broadcast(const Coordinate& coordinate) const = 0;
};

#endif
