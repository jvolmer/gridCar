#include "../pilot.hpp"
#include "../position/position.hpp"
#include "../motor/motor.hpp"
#include "../tracker/tracker.hpp"
#include "../tracker/roadLayout.hpp"
#include "motionName.hpp"
#include "findLine.hpp"
#include "findNextLineInLeftTurn.hpp"

FindNextLineInLeftTurn::FindNextLineInLeftTurn(Pilot& pilot, Position& position, Tracker& tracker, Motor& motor) :
    FindLine {},
    _pilot { pilot },
    _position { position },
    _tracker { tracker },
    _motor { motor }
{}

void FindNextLineInLeftTurn::turn()
{
    _motor.turnLeft();
}

bool FindNextLineInLeftTurn::hasFound()
{
    return _tracker.roadLayout() == RoadLayout::straight;
}

void FindNextLineInLeftTurn::updatePosition()
{
    _position.turnLeft();
}

void FindNextLineInLeftTurn::changeMotion()
{
    _pilot.changeMotion( MotionName::followLine );
}
