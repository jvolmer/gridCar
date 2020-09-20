#ifndef GRID_POSITION_H
#define GRID_POSITION_H

#include "coordinate.hpp"
#include "direction.hpp"
#include "position.hpp"
#include "relativeDirection.hpp"
#include "../../communication/coordinateBroadcaster.hpp"

class CoordinateListener;

class GridPosition: public Position, public CoordinateBroadcaster
{
private:
    Coordinate _location { Coordinate(0,0) };
    Direction _forwardDirection { Direction::positiveX };

public:
    GridPosition() {};
    GridPosition(const Coordinate& location, const Direction& direction);
    GridPosition(Coordinate&& location, Direction&& direction);

    void turnLeft() override { _forwardDirection = _forwardDirection - 1; }
    void turnRight() override { _forwardDirection = _forwardDirection + 1; }
    void moveForward() override;
    bool isLocatedAt(const Coordinate& coordinate) const override { return _location == coordinate; }
    RelativeDirection relativeDirectionToReach(const Coordinate& coordinate) const override;

    void subscribe(CoordinateListener* listener) override { CoordinateBroadcaster::subscribe(listener); broadcast(_location); }
    void broadcast(const Coordinate& location) const override { CoordinateBroadcaster::broadcast(location); }

    friend bool operator== (const GridPosition& lhs, const GridPosition& rhs);
};


#endif
