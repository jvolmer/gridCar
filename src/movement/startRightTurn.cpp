#include "pilot.hpp"
#include "motor/motor.hpp"
#include "tracker/tracker.hpp"
#include "tracker/roadLayout.hpp"
#include "motionName.hpp"
#include "startRightTurn.hpp"

StartRightTurn::StartRightTurn(Pilot& pilot, Tracker& tracker, Motor& motor) :
    _pilot { pilot },
    _tracker { tracker },
    _motor { motor }
{}

void StartRightTurn::move()
{
    _motor.turnRight();
    if (_tracker.checkRoad() == RoadLayout::sharpLeft )
    {
        _pilot.changeMotion( MotionName::alignInRightTurn );
    }
}
