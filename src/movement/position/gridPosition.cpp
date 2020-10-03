#include "coordinate.hpp"
#include "direction.hpp"
#include "gridPosition.hpp"
#include "relativeDirection.hpp"
#include "../../communication/coordinateListener.hpp"

GridPosition::GridPosition(const Coordinate& location, const Direction& direction) :
    _location { location },
    _forwardDirection { direction }
{}

GridPosition::GridPosition(Coordinate&& location, Direction&& direction) :
    _location { location },
    _forwardDirection { direction }
{}

void GridPosition::moveForward()
{
    _location = _location + Coordinate(_forwardDirection);
    broadcast(_location);
}

RelativeDirection GridPosition::relativeDirectionToReach(const Coordinate& coordinate) const
{
    if (isLocatedAt(coordinate))
    {
        return RelativeDirection::at;
    }

    const double pi = 3.141592653589793;
    Coordinate diff = coordinate - _location;
    double directDirectionToCoordinateInPi = diff.arctan2() / pi;
    double forwardDirectionInPi = ((4 - (int)_forwardDirection) % 4) * .5;
    double turningDirectionInPi = directDirectionToCoordinateInPi - forwardDirectionInPi;
    
    if ( ((turningDirectionInPi > -.5) && (turningDirectionInPi < .5)) ||
         ((turningDirectionInPi > 1.5) && (turningDirectionInPi < 2.5)) )
    {
        return RelativeDirection::inFront;
    }
    else if ( ((turningDirectionInPi < -1) && (turningDirectionInPi >=-1.5)) ||
              ((turningDirectionInPi < 1)  && (turningDirectionInPi >= .5)) )
    {
        return RelativeDirection::onTheLeft;
    }
    else if ( ((turningDirectionInPi > -1) && (turningDirectionInPi <= -.5)) ||
              ((turningDirectionInPi > 1) && (turningDirectionInPi >= 1.5)) )
    {
        return RelativeDirection::onTheRight;
    }
    else if ( (turningDirectionInPi == -1) || (turningDirectionInPi == 1) )
    {
        return RelativeDirection::exactlyBehind;
    }
    else
    {
        return RelativeDirection::undefined;
    }
}

bool operator== (const GridPosition& lhs, const GridPosition& rhs)
{
    return ( lhs._location == rhs._location &&
             lhs._forwardDirection == rhs._forwardDirection );
}

