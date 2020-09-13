#include "transmitter.hpp"
#include "../movement/position/coordinate.hpp"
#include "messageFromCar.hpp"
#include "coordinateBroadcaster.hpp"

MessageFromCar::MessageFromCar(Transmitter& transmitter, CoordinateBroadcaster& broadcaster) :
    _transmitter { transmitter },
    _message { 0, 0 }
{
    broadcaster.subscribe(this);
}

const Coordinate& MessageFromCar::supplyForNextReception() const
{
    _transmitter.setReply( _message );
    return _message;
}
