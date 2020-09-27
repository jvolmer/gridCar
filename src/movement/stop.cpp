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
        switch( _position.relativeDirectionToReach(_goal) )
        {
        case RelativeDirection::inFront :
            _pilot.changeMotion( MotionName::followLine );
            break;
        case RelativeDirection::onTheRight :
            _pilot.changeMotion( MotionName::startRightTurn );
            break;
        case RelativeDirection::onTheLeft :
            _pilot.changeMotion( MotionName::startLeftTurn );
            break;
        case RelativeDirection::exactlyBehind :
            _pilot.changeMotion( MotionName::alignInTurnAround );
            break;
        default:
            break;
        }
    }
}
