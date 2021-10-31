#include "transmitter.hpp"
#include "../movement/position/coordinate.hpp"
#include "messageOut.hpp"

MessageOut::MessageOut(Transmitter& transmitter) :
    _transmitter { transmitter },
    _message { 0, 0 }
{}

void MessageOut::update(const Coordinate &location)
{
    _message = location;
    _transmitter.setReply( _message );
}
