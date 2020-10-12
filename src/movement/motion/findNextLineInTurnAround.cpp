#include "../pilot.hpp"
#include "../position/position.hpp"
#include "../motor/motor.hpp"
#include "../tracker/tracker.hpp"
#include "../tracker/roadLayout.hpp"
#include "motionName.hpp"
#include "findLine.hpp"
#include "findNextLineInTurnAround.hpp"

FindNextLineInTurnAround::FindNextLineInTurnAround(Pilot& pilot, Position& position, Tracker& tracker, Motor& motor) :
    FindLine {},
    _pilot { pilot },
    _position { position },
    _tracker { tracker },
    _motor { motor }
{}

void FindNextLineInTurnAround::turn()
{
    _motor.turnRight();
}

bool FindNextLineInTurnAround::hasFound()
{
    return _tracker.checkRoad() == RoadLayout::straight;
}

void FindNextLineInTurnAround::updatePosition()
{
    _position.turnRight();
}

void FindNextLineInTurnAround::changeMotion()
{
    _pilot.changeMotion( MotionName::leaveNextLineInTurnAround );
}
