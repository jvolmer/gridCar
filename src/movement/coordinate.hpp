#ifndef COORDINATE_H
#define COORDINATE_H

#include "direction.hpp"

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
};

bool operator== (const Coordinate& lhs, const Coordinate& rhs);
Coordinate operator+(const Coordinate& coordinate1, const Coordinate& coordinate2);
Coordinate operator-(const Coordinate& coordinate1, const Coordinate& coordinate2);

    
#endif
