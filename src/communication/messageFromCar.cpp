#include "transmitter.hpp"
#include "../movement/position/coordinate.hpp"
#include "messageFromCar.hpp"

MessageFromCar::MessageFromCar(Transmitter& transmitter) :
    _transmitter { transmitter },
    _message { 0, 0 }
{}

const Coordinate& MessageFromCar::supplyForNextReception() const
{
    _transmitter.setReply( _message );
    return _message;
}
