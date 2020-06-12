#ifndef GRID_POSITION_H
#define GRID_POSITION_H

#include "coordinate.hpp"
#include "direction.hpp"
#include "position.hpp"

class GridPosition: public Position
{
private:
    Coordinate _location { Coordinate(0,0) };
    Direction _forwardDirection { Direction::positiveX };

public:
    GridPosition() {};
    GridPosition(const Coordinate& location, const Direction& direction);
    GridPosition(Coordinate&& location, Direction&& direction);
    const Coordinate& getLocation() const { return _location; }
    const Direction& getForwardDirection() const { return _forwardDirection; }

    void turnLeft() override { _forwardDirection = _forwardDirection - 1; }
    void turnRight() override { _forwardDirection = _forwardDirection + 1; }
    void moveForward() override { _location = _location + Coordinate(_forwardDirection); }
    bool isLocatedAt(const Coordinate& coordinate) const override { return _location == coordinate; }
};

bool operator== (const GridPosition& lhs, const GridPosition& rhs);

#endif
