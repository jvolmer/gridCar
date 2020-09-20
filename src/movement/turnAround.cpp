#include "pilot.hpp"
#include "position/position.hpp"
#include "motor/motor.hpp"
#include "tracker/tracker.hpp"
#include "tracker/roadLayout.hpp"
#include "motionName.hpp"
#include "turnAround.hpp"

TurnAround::TurnAround(Pilot& pilot, Position& position, Tracker& tracker, Motor& motor) :
    _pilot { pilot },
    _position { position },
    _tracker { tracker },
    _motor { motor }
{}

void TurnAround::move()
{
    _motor.turnRight();
    if ( _tracker.checkRoad() == RoadLayout::straight )
    {
        _position.turnRight();
        if ( !_turnedOverCrossing )
        {
            _turnedOverCrossing = true;
        }
        else
        {
            _pilot.changeMotion( MotionName::followLine );
            _turnedOverCrossing = false;
        }
    }
}
