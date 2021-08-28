#include "src/movement/position/coordinate.hpp"
#include "coordinate_ostream.hpp"
#include <iostream>

std::ostream& operator<< (std::ostream& out, const Coordinate& point)
{
    return out << "(" << point.getx() << ", " << point.gety() << ")";
}
