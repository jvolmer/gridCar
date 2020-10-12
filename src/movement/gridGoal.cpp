#include "position/coordinate.hpp"
#include "position/relativeDirection.hpp"
#include "position/position.hpp"
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

RelativeDirection GridGoal::turningDirectionFrom(const Position& position) const
{
    if (position.isLocatedAt(_coordinate))
    {
        return RelativeDirection::at;
    }

    double angle = position.turningAngleToReach(_coordinate);

    if ( ((angle > -.5) && (angle < .5)) ||
         ((angle > 1.5) && (angle < 2.5)) )
    {
        return RelativeDirection::inFront;
    }
    else if ( ((angle < -1) && (angle >=-1.5)) ||
              ((angle < 1)  && (angle >= .5)) )
    {
        return RelativeDirection::onTheLeft;
    }
    else if ( ((angle > -1) && (angle <= -.5)) ||
              ((angle > 1) && (angle >= 1.5)) )
    {
        return RelativeDirection::onTheRight;
    }
    else if ( (angle == -1) || (angle == 1) )
    {
        return RelativeDirection::exactlyBehind;
    }
    else
    {
        return RelativeDirection::undefined;
    }
}
