#include "entity/transmission.hpp"
#include "entity/coordinate.hpp"
#include "entity/direction.hpp"
#include "operatorOverloading.hpp"
#include <math.h>
#include <iostream>

bool operator== (const TransmissionToCar& lhs, const TransmissionToCar& rhs)
{
    return (lhs.getGoal() == rhs.getGoal());
}

std::ostream& operator<< (std::ostream& out, const TransmissionToCar& transmission)
{
    return out << transmission.getGoal();
}


bool operator== (const TransmissionFromCar& lhs, const TransmissionFromCar& rhs)
{
    return (lhs.getPosition() == rhs.getPosition())
        && (fabs(lhs.getScaleValue() - rhs.getScaleValue()) < 1E-6)
        && (fabs(lhs.getBatteryCharge() - rhs.getBatteryCharge()) < 1E-6);
}


std::ostream& operator<< (std::ostream& out, const Coordinate& point)
{
    return out << "(" << point.getx() << "mm, " << point.gety() << "mm)";
}


bool operator== (const Coordinate& lhs, const Coordinate& rhs)
{
    return (fabs(lhs.getx() - rhs.getx()) < 1E-6)
        && (fabs(lhs.gety() - rhs.gety()) < 1E-6);
}


std::ostream& operator<< (std::ostream& out, const Direction& direction)
{
    return out << (int)direction;
}
