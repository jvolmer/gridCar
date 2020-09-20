#include "transmitter.hpp"
#include "../movement/position/coordinate.hpp"
#include "messageToCar.hpp"

MessageToCar::MessageToCar(Transmitter& transmitter) :
    _transmitter { transmitter },
    _message { 0, 0}
{}

const Coordinate& MessageToCar::receive()
{
    _message = _transmitter.replyToReception( _message );
    broadcast(_message);
    return _message;
}
