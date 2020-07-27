#include "stop.hpp"
#include "linePilot.hpp"

class Motor;

LinePilot::LinePilot(Motor& motor):
    _stop{ Stop(*this, motor) },
    _motion { &_stop }
{}
