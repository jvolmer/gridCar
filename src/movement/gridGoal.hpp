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
    void set(Coordinate&& coordinate) override;
    const Coordinate& get() override { return _coordinate; }
    
    void update(const Coordinate& goal) override { _coordinate = goal; }
    void listenTo(CoordinateBroadcaster& broadcaster) override { CoordinateListener::listenTo(broadcaster); }

};

#endif
