#ifndef MESSAGE_TO_CAR_H
#define MESSAGE_TO_CAR_H

#include "coordinateBroadcaster.hpp"
#include "../movement/position/coordinate.hpp"

class Transmitter;
class CoordinateListener;

class MessageToCar : public CoordinateBroadcaster
{
private:
    Transmitter& _transmitter;
    Coordinate _message;

public:
    MessageToCar(Transmitter& transmitter);
    const Coordinate& receive();
    void subscribe(CoordinateListener* listener) override { CoordinateBroadcaster::subscribe(listener); }
    void broadcast(const Coordinate& message) const override { CoordinateBroadcaster::broadcast(message); }
};

#endif
