#include "entity/coordinate.hpp"
#include "transmission.hpp"

TransmissionToCar::TransmissionToCar(Coordinate goal) :
    _goal { goal }
{}

TransmissionToCar::TransmissionToCar() :
    _goal {Coordinate(0,0)}
{}



TransmissionFromCar::TransmissionFromCar():
    _position { Coordinate(0,0) },
    _scale_value_in_g { 0 },
    _battery_charge_in_percent { 0 }
{}

TransmissionFromCar::TransmissionFromCar(const Coordinate& position, float weight, float battery_charge):
    _position { position },
    _scale_value_in_g { weight },
    _battery_charge_in_percent { battery_charge }
{}
