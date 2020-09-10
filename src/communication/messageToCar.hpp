#ifndef MESSAGE_TO_CAR_H
#define MESSAGE_TO_CAR_H

#include "coordinateBroadcaster.hpp"
#include "../movement/position/coordinate.hpp"

class Transmitter;
class CoordinateListener;

class MessageToCar : CoordinateBroadcaster
{
private:
    Transmitter& _transmitter;
    Coordinate _message;
    CoordinateListener* _listener;

public:
    MessageToCar(Transmitter& transmitter);
    const Coordinate& receive();
    void subscribe(CoordinateListener* listener) override;
    void broadcast() const override;

};

#endif
