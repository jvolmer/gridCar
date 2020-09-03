#ifndef LOCATION_LISTENER_H
#define LOCATION_LISTENER_H

class Coordinate;

class LocationListener
{
public:
    virtual void updateLocation(const Coordinate& location) = 0;
};

#endif
