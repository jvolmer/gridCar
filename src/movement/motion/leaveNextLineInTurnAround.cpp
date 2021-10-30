#include "../pilot.hpp"
#include "../motor/motor.hpp"
#include "../tracker/tracker.hpp"
#include "../tracker/roadLayout.hpp"
#include "motionName.hpp"
#include "leaveNextLineInTurnAround.hpp"

LeaveNextLineInTurnAround::LeaveNextLineInTurnAround(Pilot& pilot, Tracker& tracker, Motor& motor) :
    LeaveLine {},
    _pilot { pilot },
    _tracker { tracker },
    _motor { motor }
{}

void LeaveNextLineInTurnAround::turn()
{
    _motor.turnRight();
}

bool LeaveNextLineInTurnAround::hasLeft()
{
    return _tracker.roadLayout() == RoadLayout::sharpLeft;
}

void LeaveNextLineInTurnAround::changeMotion()
{
    _pilot.changeMotion( MotionName::findNextToNextLineInTurnAround );
}
