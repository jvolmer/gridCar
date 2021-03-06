#ifndef GRID_GOAL_H
#define GRID_GOAL_H

#include "position/coordinate.hpp"
#include "../communication/coordinateListener.hpp"
#include "position/relativeDirection.hpp"
#include "goal.hpp"

class CoordinateBroadcaster;
class Position;


// Receives goal updates.
// Knows in which direction the current goal is located
// relative to a given position.

class GridGoal : public Goal, public CoordinateListener
{
private:
    Coordinate _coordinate;
    const Coordinate _boundary;

public:
    GridGoal(Coordinate&& boundary);
    void set(const Coordinate& coordinate) override;
    void set(Coordinate&& coordinate){ set(coordinate); }
    const Coordinate& get() override { return _coordinate; }
    RelativeDirection turningDirectionFrom(const Position& position) const override;

    // communication
    void update(const Coordinate& coordinate) override { set(coordinate); }
    void listenTo(CoordinateBroadcaster& broadcaster) override { CoordinateListener::listenTo(broadcaster); }

};

#endif
