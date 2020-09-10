#ifndef MESSAGE_FROM_CAR_H
#define MESSAGE_FROM_CAR_H

#include "../movement/position/coordinate.hpp"
#include "coordinateListener.hpp"

class Transmitter;
class CoordinateBroadcaster;

class MessageFromCar: public CoordinateListener
{
private:
    Transmitter& _transmitter;
    CoordinateBroadcaster& _locationBroadcaster;
    Coordinate _message;

public:
    MessageFromCar(Transmitter& transmitter, CoordinateBroadcaster& broadcaster);
    void update(const Coordinate& message) override { _message = message; }
    const Coordinate& supplyForNextReception() const;
};

#endif
