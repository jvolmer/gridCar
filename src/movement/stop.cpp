#include "pilot.hpp"
#include "motor/motor.hpp"
#include "position/position.hpp"
#include "motionName.hpp"
#include "stop.hpp"

class Coordinate;

Stop::Stop(Pilot& pilot, Coordinate& goal, Position& position, Motor& motor):
    _pilot { pilot },
    _goal { goal },
    _position { position },
    _motor { motor }
{}

void Stop::move()
{    
    _motor.stop();

    if ( !_position.isLocatedAt(_goal) )
    {
        _pilot.changeMotion( MotionName::followLine );
    }
}
