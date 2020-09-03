#include "transmitter.hpp"
#include "../movement/position/coordinate.hpp"
#include "messageFromCar.hpp"
#include "../movement/position/locationBroadcaster.hpp"

MessageFromCar::MessageFromCar(Transmitter& transmitter, LocationBroadcaster& broadcaster) :
    _transmitter { transmitter },
    _locationBroadcaster { broadcaster },
    _message { 0, 0 }
{
    _locationBroadcaster.subscribe(this);
}

const Coordinate& MessageFromCar::supplyForNextReception() const
{
    _transmitter.setReply( _message );
    return _message;
}
