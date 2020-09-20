#include "coordinate.hpp"
#include "direction.hpp"
#include "gridPosition.hpp"
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

int GridPosition::getTurnTrendToReach(const Coordinate& coordinate) const
{
    const double pi = 3.141592653589793;
    Coordinate diff = coordinate - _location;
    double directDirectionToCoordinateInPi = diff.arctan2() / pi;
    double forwardDirectionInPi = ((4 - (int)_forwardDirection) % 4) * .5;
    double turningDirectionInPi = forwardDirectionInPi - directDirectionToCoordinateInPi;
    
    if ( ((turningDirectionInPi > -.25) && (turningDirectionInPi < .25)) ||
         ((turningDirectionInPi > 1.75) && (turningDirectionInPi < 2.25)) )
    {
        return 0;
    }
    else if ( ((turningDirectionInPi >= -1) && (turningDirectionInPi <=-.25)) ||
              ((turningDirectionInPi >= 1)  && (turningDirectionInPi <= 1.75)) )
    {
        return -1;
    }
    else
        return 1;
}

bool GridPosition::isAtTurningPointToReach(const Coordinate& coordinate) const
{
    return
        ( ( _forwardDirection == Direction::positiveY ||
            _forwardDirection == Direction::negativeY    ) &&
          _location.hasSameYAs( coordinate ) ) ||
        ( ( _forwardDirection == Direction::positiveX ||
            _forwardDirection == Direction::negativeX    ) &&
          _location.hasSameXAs( coordinate ) );
}

bool operator== (const GridPosition& lhs, const GridPosition& rhs)
{
    return ( lhs._location == rhs._location &&
             lhs._forwardDirection == rhs._forwardDirection );
}

