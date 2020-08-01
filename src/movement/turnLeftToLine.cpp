#include "pilot.hpp"
#include "motor/motor.hpp"
#include "tracker/tracker.hpp"
#include "tracker/roadLayout.hpp"
#include "motionName.hpp"
#include "turnLeftToLine.hpp"

TurnLeftToLine::TurnLeftToLine(Pilot& pilot, Tracker& tracker, Motor& motor) :
    _pilot { pilot },
    _tracker { tracker },
    _motor { motor }
{}

void TurnLeftToLine::move()
{
    _motor.turnLeft();
    if ( _tracker.checkRoad() == RoadLayout::straight )
    {
        _pilot.changeMotion( MotionName::followLine );
    }
}
