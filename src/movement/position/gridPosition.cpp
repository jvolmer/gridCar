#include "coordinate.hpp"
#include "direction.hpp"
#include "gridPosition.hpp"
#include "relativeDirection.hpp"
#include "../../communication/coordinateListener.hpp"

GridPosition::GridPosition(const Coordinate& location, Direction direction) :
    _location { location },
    _forwardDirection { direction }
{}

GridPosition::GridPosition(Coordinate&& location, Direction direction) :
    _location { location },
    _forwardDirection { direction }
{}

void GridPosition::moveForward()
{
    _location = _location + Coordinate(_forwardDirection);
    broadcast(_location);
}

double GridPosition::turningAngleToReach(const Coordinate& coordinate) const
{
    const double pi = 3.141592653589793;
    Coordinate diff = coordinate - _location;
    double totalAngleToCoordinate = diff.arctan2() * 180./ pi;
    double forwardDirectionAngle = (int)_forwardDirection * 90.;
    return totalAngleToCoordinate - forwardDirectionAngle;
}

bool operator== (const GridPosition& lhs, const GridPosition& rhs)
{
    return ( lhs._location == rhs._location &&
             lhs._forwardDirection == rhs._forwardDirection );
}

