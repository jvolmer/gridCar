#ifndef ENTITY_OPERATOR_OVERLOADING_H
#define ENTITY_OPERATOR_OVERLOADING_H

#include "entity/transmission.hpp"
#include "entity/coordinate.hpp"
#include "entity/direction.hpp"
#include <iostream>

bool operator== (const TransmissionToCar& lhs, const TransmissionToCar& rhs);
std::ostream& operator<< (std::ostream& out, const TransmissionToCar& transmission);

bool operator== (const TransmissionFromCar& lhs, const TransmissionFromCar& rhs);

std::ostream& operator<< (std::ostream& out, const Coordinate& point);
bool operator== (const Coordinate& lhs, const Coordinate& rhs);

std::ostream& operator<< (std::ostream& out, const Direction& direction);

#endif
