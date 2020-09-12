#include "transmitter.hpp"
#include "../movement/position/coordinate.hpp"
#include "messageToCar.hpp"
#include "coordinateListener.hpp"

MessageToCar::MessageToCar(Transmitter& transmitter) :
    _transmitter { transmitter },
    _message { 0, 0}
{}

const Coordinate& MessageToCar::receive()
{
    _message = _transmitter.replyToReception( _message );
    broadcast();
    return _message;
}

void MessageToCar::subscribe(CoordinateListener* listener)
{
    _listener = listener;
    broadcast();
}

void MessageToCar::broadcast() const
{
    if (_listener)
    {
        _listener->update(_message);
    }
}
