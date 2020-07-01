#ifndef ARDUINO_GRID_POSITION_H
#define ARDUINO_GRID_POSITION_H

#include "coordinate.hpp"
#include "direction.hpp"
#include "gridPosition.hpp"

class ArduinoGridPosition: public GridPosition
{
public:
    ArduinoGridPosition();
    ArduinoGridPosition(const Coordinate& location, const Direction& direction);
    void print();
};

#endif
