#include "pilot.hpp"
#include "motor/motor.hpp"
#include "position/position.hpp"
#include "goal.hpp"
#include "motionName.hpp"
#include "stop.hpp"

class Coordinate;

Stop::Stop(Pilot& pilot, Goal& goal, Position& position, Motor& motor):
    _pilot { pilot },
    _goal { goal },
    _position { position },
    _motor { motor }
{}

void Stop::move()
{    
    _motor.stop();

    switch( _goal.turningDirectionFrom(_position))
    {
        case RelativeDirection::at :
            break;
        case RelativeDirection::inFront :
            _pilot.changeMotion( MotionName::followLine );
            break;
        case RelativeDirection::onTheRight :
            _pilot.changeMotion( MotionName::centerInRightTurn );
            break;
        case RelativeDirection::onTheLeft :
            _pilot.changeMotion( MotionName::centerInLeftTurn );
            break;
        case RelativeDirection::exactlyBehind :
            _pilot.changeMotion( MotionName::centerInTurnAround );
            break;
        default:
            break;
    }
}
