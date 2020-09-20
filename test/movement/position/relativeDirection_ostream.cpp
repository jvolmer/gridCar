#include "src/movement/position/relativeDirection.hpp"
#include "relativeDirection_ostream.hpp"
#include <iostream>

std::ostream& operator<< (std::ostream& out, const RelativeDirection& direction)
{
    return out << (int)direction;
}
