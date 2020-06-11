#ifndef TRANSMISSION_H
#define TRANSMISSION_H

#include "../movement/coordinate.hpp"

class TransmissionToCar
{
private:
    Coordinate _goal;

public:
    TransmissionToCar();
    TransmissionToCar(Coordinate goal);
    const Coordinate& getGoal() const { return _goal; };
};
bool operator== (const TransmissionToCar& lhs, const TransmissionToCar& rhs);

class TransmissionFromCar
{
private:
    Coordinate _position;
    float _scale_value_in_g;
    float _battery_charge_in_percent;
    

public:
    TransmissionFromCar();
    TransmissionFromCar(const Coordinate& position, float scale, float battery_charge);
    const Coordinate& getPosition() const { return _position; }
    float getScaleValue() const { return _scale_value_in_g; }
    float getBatteryCharge() const { return _battery_charge_in_percent; }
};  
bool operator== (const TransmissionFromCar& lhs, const TransmissionFromCar& rhs);

#endif
