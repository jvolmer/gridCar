#ifndef MESSAGE_FROM_CAR_H
#define MESSAGE_FROM_CAR_H

#include "../movement/position/coordinate.hpp"
#include "locationListener.hpp"

class Transmitter;

class MessageFromCar: public LocationListener
{
private:
    Transmitter& _transmitter;
    Coordinate _message;

public:
    MessageFromCar(Transmitter& transmitter);
    void updateLocation(const Coordinate& message) override { _message = message; }
    const Coordinate& supplyForNextReception() const;
};

#endif
