#ifndef MESSAGE_TO_CAR_H
#define MESSAGE_TO_CAR_H

#include "../movement/position/coordinate.hpp"

class Transmitter;

class MessageToCar
{
private:
    Transmitter& _transmitter;
    Coordinate _message;

public:
    MessageToCar(Transmitter& transmitter);
    const Coordinate& receive();
};

#endif
