#include "../pilot.hpp"
#include "../motor/motor.hpp"
#include "../tracker/tracker.hpp"
#include "../tracker/roadLayout.hpp"
#include "motionName.hpp"
#include "leaveLine.hpp"
#include "leaveOriginLineInLeftTurn.hpp"

LeaveOriginLineInLeftTurn::LeaveOriginLineInLeftTurn(Pilot& pilot, Tracker& tracker, Motor& motor) :
    LeaveLine {},
    _pilot { pilot },
    _tracker { tracker },
    _motor { motor }
{}

void LeaveOriginLineInLeftTurn::turn()
{
    _motor.turnLeft();
}

bool LeaveOriginLineInLeftTurn::hasLeft()
{
    return _tracker.checkRoad() == RoadLayout::sharpRight;
}

void LeaveOriginLineInLeftTurn::changeMotion()
{
    _pilot.changeMotion( MotionName::findNextLineInLeftTurn );
}
