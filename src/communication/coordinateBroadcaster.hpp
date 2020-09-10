#ifndef COORDINATE_BROADCASTER_H
#define COORDINATE_BROADCASTER_H

class CoordinateListener;

class CoordinateBroadcaster
{
public:
    virtual void subscribe(CoordinateListener* listener) = 0;
    virtual void broadcast() const = 0;
};

#endif
