#include "motor/motor.hpp"
#include "stopFinally.hpp"

class Coordinate;

StopFinally::StopFinally(Motor& motor):
    _motor { motor }
{}

void StopFinally::move()
{    
    _motor.stop();
}
