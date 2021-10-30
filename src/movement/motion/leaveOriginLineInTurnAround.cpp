#include "../pilot.hpp"
#include "../motor/motor.hpp"
#include "../tracker/tracker.hpp"
#include "../tracker/roadLayout.hpp"
#include "motionName.hpp"
#include "leaveLine.hpp"
#include "leaveOriginLineInTurnAround.hpp"

LeaveOriginLineInTurnAround::LeaveOriginLineInTurnAround(Pilot& pilot, Tracker& tracker, Motor& motor) :
    LeaveLine {},
    _pilot { pilot },
    _tracker { tracker },
    _motor { motor }
{}

void LeaveOriginLineInTurnAround::turn()
{
    _motor.turnRight();
}

bool LeaveOriginLineInTurnAround::hasLeft()
{
    return _tracker.roadLayout() == RoadLayout::sharpLeft;
}

void LeaveOriginLineInTurnAround::changeMotion()
{
    _pilot.changeMotion( MotionName::findNextLineInTurnAround );
}
