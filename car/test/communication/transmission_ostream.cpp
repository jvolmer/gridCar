#include "src/communication/transmission.hpp"
#include "transmission_ostream.hpp"
#include <iostream>

std::ostream& operator<< (std::ostream& out, const TransmissionToCar& transmission)
{
    return out << transmission.getGoal();
}
