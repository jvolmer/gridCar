#ifndef GRID_GOAL_H
#define GRID_GOAL_H

#include "position/coordinate.hpp"
#include "../communication/coordinateListener.hpp"
#include "goal.hpp"

class CoordinateBroadcaster;

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
    
    void update(const Coordinate& coordinate) override { set(coordinate); }
    void listenTo(CoordinateBroadcaster& broadcaster) override { CoordinateListener::listenTo(broadcaster); }

};

#endif
