#ifndef TRANSMISSION_OSTREAM_H
#define TRANSMISSION_OSTREAM_H

#include "src/communication/transmission.hpp"
#include <iostream>

std::ostream& operator<< (std::ostream& out, const TransmissionToCar& transmission);

#endif
