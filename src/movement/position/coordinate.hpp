#ifndef COORDINATE_H
#define COORDINATE_H

#include "direction.hpp"
#include <math.h>

class Coordinate
{
private:
    int _x;
    int _y;

public:
    Coordinate(int x, int y);
    Coordinate(const Direction& direction);

    Coordinate& operator= (const Coordinate& point);
    int getx() const { return _x; }
    int gety() const { return _y; }
    double arctan2() const { return atan2((double)_y, (double)_x); }
    bool hasSameXAs(const Coordinate& coordinate) const { return _x == coordinate._x; }
    bool hasSameYAs(const Coordinate& coordinate) const { return _y == coordinate._y; }
    
    friend bool operator== (const Coordinate& lhs, const Coordinate& rhs);
    friend Coordinate operator+(const Coordinate& coordinate1, const Coordinate& coordinate2);
    friend Coordinate operator-(const Coordinate& coordinate1, const Coordinate& coordinate2);

};
    
#endif
