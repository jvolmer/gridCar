#include "coordinate.hpp"
#include "direction.hpp"
#include "gridPosition.hpp"

GridPosition::GridPosition(const Coordinate& location, const Direction& direction) :
    _location { location },
    _forwardDirection { direction }
{}

GridPosition::GridPosition(Coordinate&& location, Direction&& direction) :
    _location { location },
    _forwardDirection { direction }
{}

bool operator== (const GridPosition& lhs, const GridPosition& rhs)
{
    return ( lhs.getLocation() == rhs.getLocation() &&
             lhs.getForwardDirection() == rhs.getForwardDirection() );
}
