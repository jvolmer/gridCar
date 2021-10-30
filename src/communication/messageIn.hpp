#ifndef MESSAGE_IN_H
#define MESSAGE_In_H

#include "coordinateBroadcaster.hpp"
#include "../movement/position/coordinate.hpp"

class Transmitter;
class CoordinateListener;


// Receives a coordinate from the transmitter
// and broadcasts it to its subscriber.

class MessageIn : public CoordinateBroadcaster
{
private:
    Transmitter& _transmitter;
    Coordinate _message;

public:
    MessageIn(Transmitter& transmitter);
    const Coordinate& receive();
    void subscribe(CoordinateListener* listener) override { CoordinateBroadcaster::subscribe(listener); }
    void broadcast(const Coordinate& message) const override { CoordinateBroadcaster::broadcast(message); }
};

#endif
