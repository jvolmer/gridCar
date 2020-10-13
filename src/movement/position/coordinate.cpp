#include "direction.hpp"
#include "coordinate.hpp"

Coordinate::Coordinate(int x, int y):
    _x { x },
    _y { y }
{}

Coordinate::Coordinate(const Direction& direction)
{
    switch(direction)
    {
    case Direction::positiveX:
        _x = 1;
        _y = 0;
        break;
    case Direction::negativeX:
        _x = -1;
        _y = 0;
        break;
    case Direction::positiveY:
        _x = 0;
        _y = 1;
        break;
    case Direction::negativeY:
        _x = 0;
        _y = -1;
        break;
    default:
        _x = 0;
        _y = 0;
    }
}

Coordinate& Coordinate::operator= (const Coordinate& point)
{
    if (this == &point)
        return *this;
    _x = point._x;
    _y = point._y;
    return *this;
}

bool operator== (const Coordinate& lhs, const Coordinate& rhs)
{
    return ( lhs._x == rhs._x &&
             lhs._y == rhs._y );
}

Coordinate operator+(const Coordinate& coordinate1, const Coordinate& coordinate2)
{
    return Coordinate( coordinate1._x + coordinate2._x,
                       coordinate1._y + coordinate2._y );
}

Coordinate operator-(const Coordinate& coordinate1, const Coordinate& coordinate2)
{
    return Coordinate( coordinate1._x - coordinate2._x,
                       coordinate1._y - coordinate2._y );
}
