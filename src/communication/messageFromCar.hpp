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
    Coordinate _message;

public:
    MessageFromCar(Transmitter& transmitter);
    const Coordinate& supplyForNextReception() const;
    void update(const Coordinate& location) override { _message = location; }
    void listenTo(CoordinateBroadcaster& broadcaster) override { CoordinateListener::listenTo(broadcaster); }

};

#endif
