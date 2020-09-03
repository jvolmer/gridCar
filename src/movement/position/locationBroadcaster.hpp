#ifndef LOCATION_BROADCASTER_H
#define LOCATION_BROADCASTER_H

class LocationListener;

class LocationBroadcaster
{
public:
    virtual void subscribe(LocationListener* listener) = 0;
    virtual void broadcast() const = 0;
};

#endif
