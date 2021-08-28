#include "transmitter.hpp"
#include "../movement/position/coordinate.hpp"
#include "messageOut.hpp"

MessageOut::MessageOut(Transmitter& transmitter) :
    _transmitter { transmitter },
    _message { 0, 0 }
{}

const Coordinate& MessageOut::supplyForNextReception() const
{
    _transmitter.setReply( _message );
    return _message;
}
