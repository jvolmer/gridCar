#include "src/movement/position/gridPosition.hpp"
#include "gridPosition_ostream.hpp"
#include "coordinate_ostream.hpp"
#include "direction_ostream.hpp"
#include <iostream>

std::ostream& operator<< (std::ostream& out, const GridPosition& position)
{
    return out << "locaction: " << position.sitsAt() << ", forwardDirection: " << position.headsTo();
}
