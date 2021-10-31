#ifndef MESSAGE_OUT_H
#define MESSAGE_OUT_H

#include "../movement/position/coordinate.hpp"
#include "coordinateListener.hpp"

class Transmitter;
class CoordinateBroadcaster;

// Listens for a new coordinate.
// Supplies transmitter with the coordinate.

class MessageOut: public CoordinateListener
{
private:
    Transmitter& _transmitter;
    Coordinate _message;

public:
    MessageOut(Transmitter& transmitter);
    void update(const Coordinate& location) override;
    void listenTo(CoordinateBroadcaster& broadcaster) override { CoordinateListener::listenTo(broadcaster); }

};

#endif
