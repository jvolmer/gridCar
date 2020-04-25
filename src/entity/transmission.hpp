#ifndef TRANSMISSION_H
#define TRANSMISSION_H

#include "entity/coordinate.hpp"
#include <iostream>

class TransmissionToCar
{
private:
    Coordinate goal;

public:
    TransmissionToCar();
    TransmissionToCar(Coordinate goal);
    Coordinate* getGoal() { return &goal; };
    friend bool operator== (const TransmissionToCar& lhs, const TransmissionToCar& rhs);
    friend std::ostream& operator<< (std::ostream& out, const TransmissionToCar& transmission);
};

class TransmissionFromCar
{
private:
    Coordinate position;
    float scale_value_in_g;
    float battery_charge_in_percent;

public:
    TransmissionFromCar();
    TransmissionFromCar(const Coordinate& position, float scale, float battery_charge);
    void print() const;
    friend bool operator== (const TransmissionFromCar& lhs, const TransmissionFromCar& rhs);
};
    

#endif
