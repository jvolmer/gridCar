#ifndef MESSAGE_FROM_CAR_H
#define MESSAGE_FROM_CAR_H

#include "../movement/position/coordinate.hpp"

class Transmitter;

class MessageFromCar
{
private:
    Transmitter& _transmitter;
    Coordinate _coordinate;

public:
    MessageFromCar(Transmitter& transmitter);
    void set(Coordinate& coordinate){ _coordinate = coordinate; }
    const Coordinate& supply() const;
};

#endif
