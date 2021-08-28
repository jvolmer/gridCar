#ifndef RELATIVE_DIRECTION_OSTREAM_H
#define RELATIVE_DIRECTION_OSTREAM_H

#include "src/movement/position/relativeDirection.hpp"
#include <iostream>

std::ostream& operator<< (std::ostream& out, const RelativeDirection& direction);

#endif
