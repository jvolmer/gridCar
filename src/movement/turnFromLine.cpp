#include "pilot.hpp"
#include "motor/motor.hpp"
#include "tracker/tracker.hpp"
#include "tracker/roadLayout.hpp"
#include "motionName.hpp"
#include "turnFromLine.hpp"

TurnFromLine::TurnFromLine(Pilot& pilot, Tracker& tracker, Motor& motor) :
    _pilot { pilot },
    _tracker { tracker },
    _motor { motor }
{}

void TurnFromLine::move()
{
    _motor.turnRight();
    if ( _tracker.checkRoad() == RoadLayout::sharpLeft )
    {
        _pilot.changeMotion( MotionName::shortStraight );
    }
}
