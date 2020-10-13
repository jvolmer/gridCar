#include "transmitter.hpp"
#include "../movement/position/coordinate.hpp"
#include "messageIn.hpp"

MessageIn::MessageIn(Transmitter& transmitter) :
    _transmitter { transmitter },
    _message { 0, 0}
{}

const Coordinate& MessageIn::receive()
{
    _message = _transmitter.replyToReception( _message );
    broadcast(_message);
    return _message;
}
