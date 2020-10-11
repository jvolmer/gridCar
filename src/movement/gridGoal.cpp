#include "position/coordinate.hpp"
#include "gridGoal.hpp"

GridGoal::GridGoal(Coordinate&& boundary) :
    _coordinate { 0, 0 },
    _boundary { boundary }
{}

void GridGoal::set(const Coordinate& coordinate)
{
    if (coordinate.getx() <= _boundary.getx() &&
        coordinate.gety() <= _boundary.gety())
    {
        _coordinate = coordinate;
    }
}
