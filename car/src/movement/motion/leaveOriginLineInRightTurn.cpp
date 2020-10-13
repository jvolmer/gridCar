#include "../pilot.hpp"
#include "../motor/motor.hpp"
#include "../tracker/tracker.hpp"
#include "../tracker/roadLayout.hpp"
#include "motionName.hpp"
#include "leaveLine.hpp"
#include "leaveOriginLineInRightTurn.hpp"

LeaveOriginLineInRightTurn::LeaveOriginLineInRightTurn(Pilot& pilot, Tracker& tracker, Motor& motor) :
    LeaveLine {},
    _pilot { pilot },
    _tracker { tracker },
    _motor { motor }
{}

void LeaveOriginLineInRightTurn::turn()
{
    _motor.turnRight();
}

bool LeaveOriginLineInRightTurn::hasLeft()
{
    return _tracker.checkRoad() == RoadLayout::sharpLeft;
}

void LeaveOriginLineInRightTurn::changeMotion()
{
    _pilot.changeMotion( MotionName::findNextLineInRightTurn );
}
