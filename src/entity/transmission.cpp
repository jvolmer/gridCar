#include "entity/coordinate.hpp"
#include "transmission.hpp"
#include <iostream>
#include <math.h>

TransmissionToCar::TransmissionToCar(Coordinate goal) :
    goal { goal }
{}

TransmissionToCar::TransmissionToCar() :
    goal {Coordinate(0,0)}
{}

bool operator== (const TransmissionToCar& lhs, const TransmissionToCar& rhs)
{
    return (lhs.goal == rhs.goal);
}

std::ostream& operator<< (std::ostream& out, const TransmissionToCar& package)
{
    return out << package.goal;
}


TransmissionFromCar::TransmissionFromCar():
    position { Coordinate(0,0) },
    scale_value_in_g { 0 },
    battery_charge_in_percent { 0 }
{}

TransmissionFromCar::TransmissionFromCar(const Coordinate& position, float weight, float battery_charge):
    position { position },
    scale_value_in_g { weight },
    battery_charge_in_percent { battery_charge }
{
}

void TransmissionFromCar::print() const
{
    printf("[ (%fmm, %fmm), %fg, %f%% ]\n", position.getx(), position.gety(), scale_value_in_g, battery_charge_in_percent);
}

bool operator== (const TransmissionFromCar& lhs, const TransmissionFromCar& rhs)
{
    return (lhs.position == rhs.position)
        && (fabs(lhs.scale_value_in_g - rhs.scale_value_in_g) < 1E-6)
        && (fabs(lhs.battery_charge_in_percent - rhs.battery_charge_in_percent) < 1E-6);
}
