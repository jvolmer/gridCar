#ifndef COORDINATE_OSTREAM_H
#define COORDINATE_OSTREAM_H

#include "src/movement/position/coordinate.hpp"
#include <iostream>

std::ostream& operator<< (std::ostream& out, const Coordinate& point);

#endif
