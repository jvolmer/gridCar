#ifndef MESSAGE_FROM_CAR_H
#define MESSAGE_FROM_CAR_H

#include "../movement/position/coordinate.hpp"
#include "locationListener.hpp"

class Transmitter;
class LocationBroadcaster;

class MessageFromCar: public LocationListener
{
private:
    Transmitter& _transmitter;
    LocationBroadcaster& _locationBroadcaster;
    Coordinate _message;

public:
    MessageFromCar(Transmitter& transmitter, LocationBroadcaster& broadcaster);
    void updateLocation(const Coordinate& message) override { _message = message; }
    const Coordinate& supplyForNextReception() const;
};

#endif
