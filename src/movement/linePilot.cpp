#include "motion.hpp"
#include "linePilot.hpp"
#include "position/position.hpp"
#include "motor/motor.hpp"
#include "tracker/tracker.hpp"

LinePilot::LinePilot(Position& position, Motor& motor, Tracker& tracker):
    _stop { Stop(*this, motor) },
    _motion { _stop }
{}
