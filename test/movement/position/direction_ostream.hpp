#ifndef DIRECTION_OSTREAM_H
#define DIRECTION_OSTREAM_H

#include "src/movement/position/direction.hpp"
#include <iostream>

std::ostream& operator<< (std::ostream& out, const Direction& direction);

#endif
