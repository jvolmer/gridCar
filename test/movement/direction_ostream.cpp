#include "src/movement/direction.hpp"
#include "direction_ostream.hpp"
#include <iostream>

std::ostream& operator<< (std::ostream& out, const Direction& direction)
{
    return out << (int)direction;
}
