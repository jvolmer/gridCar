#ifndef MESSAGE_FROM_CAR_H
#define MESSAGE_FROM_CAR_H

#include "../movement/position/coordinate.hpp"

class Transmitter;

class MessageFromCar
{
private:
    Transmitter& _transmitter;
    Coordinate _message;

public:
    MessageFromCar(Transmitter& transmitter);
    void set(Coordinate& message){ _message = message; }
    const Coordinate& supplyForNextReception() const;
};

#endif
