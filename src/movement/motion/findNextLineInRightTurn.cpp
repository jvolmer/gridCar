#include "../pilot.hpp"
#include "../position/position.hpp"
#include "../motor/motor.hpp"
#include "../tracker/tracker.hpp"
#include "../tracker/roadLayout.hpp"
#include "motionName.hpp"
#include "findLine.hpp"
#include "findNextLineInRightTurn.hpp"

FindNextLineInRightTurn::FindNextLineInRightTurn(Pilot& pilot, Position& position, Tracker& tracker, Motor& motor) :
    FindLine {},
    _pilot { pilot },
    _position { position },
    _tracker { tracker },
    _motor { motor }
{}

void FindNextLineInRightTurn::turn()
{
    _motor.turnRight();
}

bool FindNextLineInRightTurn::hasFound()
{
    return _tracker.checkRoad() == RoadLayout::straight;
}

void FindNextLineInRightTurn::updatePosition()
{
    _position.turnRight();
}

void FindNextLineInRightTurn::changeMotion()
{
    _pilot.changeMotion( MotionName::followLine );
}
