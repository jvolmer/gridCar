#include "../pilot.hpp"
#include "../position/position.hpp"
#include "../motor/motor.hpp"
#include "../tracker/tracker.hpp"
#include "../tracker/roadLayout.hpp"
#include "motionName.hpp"
#include "findLine.hpp"
#include "findNextToNextLineInTurnAround.hpp"

FindNextToNextLineInTurnAround::FindNextToNextLineInTurnAround(Pilot& pilot, Position& position, Tracker& tracker, Motor& motor) :
    FindLine {},
    _pilot { pilot },
    _position { position },
    _tracker { tracker },
    _motor { motor }
{}

void FindNextToNextLineInTurnAround::turn()
{
    _motor.turnRight();
}

bool FindNextToNextLineInTurnAround::hasFound()
{
    return _tracker.roadLayout() == RoadLayout::straight;
}

void FindNextToNextLineInTurnAround::updatePosition()
{
    _position.turnRight();
}

void FindNextToNextLineInTurnAround::changeMotion()
{
    _pilot.changeMotion( MotionName::followLine );
}
