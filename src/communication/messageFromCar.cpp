#include "transmitter.hpp"
#include "../movement/position/coordinate.hpp"
#include "messageFromCar.hpp"

MessageFromCar::MessageFromCar(Transmitter& transmitter) :
    _transmitter { transmitter },
    _coordinate { 0, 0 }
{}

const Coordinate& MessageFromCar::supply() const
{
    _transmitter.replyWith( _coordinate );
    return _coordinate;
}
