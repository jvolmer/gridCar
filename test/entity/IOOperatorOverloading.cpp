#include "src/entity/transmission.hpp"
#include "src/entity/coordinate.hpp"
#include "src/entity/direction.hpp"
#include "IOOperatorOverloading.hpp"
#include <math.h>
#include <iostream>

std::ostream& operator<< (std::ostream& out, const TransmissionToCar& transmission)
{
    return out << transmission.getGoal();
}

std::ostream& operator<< (std::ostream& out, const Coordinate& point)
{
    return out << "(" << point.getx() << "mm, " << point.gety() << "mm)";
}

std::ostream& operator<< (std::ostream& out, const Direction& direction)
{
    return out << (int)direction;
}
