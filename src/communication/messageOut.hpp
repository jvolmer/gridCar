#ifndef MESSAGE_OUT_H
#define MESSAGE_OUT_H

#include "../movement/position/coordinate.hpp"
#include "coordinateListener.hpp"

class Transmitter;
class CoordinateBroadcaster;

class MessageOut: public CoordinateListener
{
private:
    Transmitter& _transmitter;
    Coordinate _message;

public:
    MessageOut(Transmitter& transmitter);
    const Coordinate& supplyForNextReception() const;
    void update(const Coordinate& location) override { _message = location; }
    void listenTo(CoordinateBroadcaster& broadcaster) override { CoordinateListener::listenTo(broadcaster); }

};

#endif
