#ifndef GRID_POSITION_OSTREAM_H
#define GRID_POSITION_OSTREAM_H

#include "src/movement/position/gridPosition.hpp"
#include <iostream>

std::ostream& operator<< (std::ostream& out, const GridPosition& position);

#endif
