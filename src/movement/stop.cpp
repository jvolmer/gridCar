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

    if ( !_position.isLocatedAt(_goal.get()) )
    {
        switch( _position.relativeDirectionToReach(_goal.get()) )
        {
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
}
