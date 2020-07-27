#include "motor/motor.hpp"
#include "pilot.hpp"
#include "stop.hpp"

Stop::Stop(Pilot& pilot, Motor& motor):
    _pilot { pilot },
    _motor { motor }
{}

void Stop::move()
{
    _motor.stop();
}
