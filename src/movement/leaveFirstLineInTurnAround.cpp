#include "pilot.hpp"
#include "motor/motor.hpp"
#include "tracker/tracker.hpp"
#include "tracker/roadLayout.hpp"
#include "motionName.hpp"
#include "leaveFirstLineInTurnAround.hpp"

LeaveFirstLineInTurnAround::LeaveFirstLineInTurnAround(Pilot& pilot, Tracker& tracker, Motor& motor) :
    _pilot { pilot },
    _tracker { tracker },
    _motor { motor }
{}

void LeaveFirstLineInTurnAround::move()
{
    _motor.turnRight();
    if (_tracker.checkRoad() == RoadLayout::sharpLeft )
    {
        _pilot.changeMotion( MotionName::findSecondLineInTurnAround );
    }
}
