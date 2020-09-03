#ifndef GRID_POSITION_H
#define GRID_POSITION_H

#include "coordinate.hpp"
#include "direction.hpp"
#include "position.hpp"
#include "locationBroadcaster.hpp"

class LocationListener;

class GridPosition: public Position, public LocationBroadcaster
{
private:
    Coordinate _location { Coordinate(0,0) };
    Direction _forwardDirection { Direction::positiveX };
    LocationListener* _listener;

public:
    GridPosition() {};
    GridPosition(const Coordinate& location, const Direction& direction);
    GridPosition(Coordinate&& location, Direction&& direction);
    const Coordinate& getLocation() const { return _location; }
    const Direction& getForwardDirection() const { return _forwardDirection; }

    void turnLeft() override { _forwardDirection = _forwardDirection - 1; }
    void turnRight() override { _forwardDirection = _forwardDirection + 1; }
    void moveForward() override;
    bool isLocatedAt(const Coordinate& coordinate) const override { return _location == coordinate; }
    int getTurnTrendToReach(const Coordinate& coordinate) const override;
    bool isAtTurningPointToReach(const Coordinate& coordinate) const;
    void subscribe(LocationListener* listener) override;
    void broadcast() const override;
};

bool operator== (const GridPosition& lhs, const GridPosition& rhs);

#endif
