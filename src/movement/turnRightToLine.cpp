#include "pilot.hpp"
#include "motor/motor.hpp"
#include "tracker/tracker.hpp"
#include "tracker/roadLayout.hpp"
#include "motionName.hpp"
#include "turnRightToLine.hpp"

TurnRightToLine::TurnRightToLine(Pilot& pilot, Tracker& tracker, Motor& motor) :
    _pilot { pilot },
    _tracker { tracker },
    _motor { motor }
{}

void TurnRightToLine::move()
{
    _motor.turnRight();
    if ( _tracker.checkRoad() == RoadLayout::straight )
    {
        _pilot.changeMotion( MotionName::followLine );
    }
}
