#include "coordinate.hpp"
#include <iostream>
#include <math.h>

Coordinate::Coordinate(float x, float y):
    x_in_mm { x },
    y_in_mm { y }
{
}

void Coordinate::print() const
{
    printf("(%fmm, %fmm)\n", x_in_mm, y_in_mm);
}

Coordinate& Coordinate::operator= (const Coordinate& point)
{
    if (this == &point)
        return *this;
    x_in_mm = point.x_in_mm;
    y_in_mm = point.y_in_mm;
    return *this;
}

std::ostream& operator<< (std::ostream& out, const Coordinate& point)
{
    return out << "(" << point.x_in_mm << "mm, " << point.y_in_mm << "mm)";
}


bool operator== (const Coordinate& lhs, const Coordinate& rhs)
{
    return (fabs(lhs.x_in_mm - rhs.x_in_mm) < 1E-6)
        && (fabs(lhs.y_in_mm - rhs.y_in_mm) < 1E-6);
}
