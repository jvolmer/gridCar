#include "coordinate.hpp"

Coordinate::Coordinate(float x, float y):
    _x_in_mm { x },
    _y_in_mm { y }
{
}

Coordinate& Coordinate::operator= (const Coordinate& point)
{
    if (this == &point)
        return *this;
    _x_in_mm = point.getx();
    _y_in_mm = point.gety();
    return *this;
}
