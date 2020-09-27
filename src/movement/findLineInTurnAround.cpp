#include "pilot.hpp"
#include "position/position.hpp"
#include "motor/motor.hpp"
#include "tracker/tracker.hpp"
#include "tracker/roadLayout.hpp"
#include "motionName.hpp"
#include "findLineInTurnAround.hpp"

FindLineInTurnAround::FindLineInTurnAround(Pilot& pilot, Position& position, Tracker& tracker, Motor& motor) :
    _pilot { pilot },
    _position { position },
    _tracker { tracker },
    _motor { motor }
{}

void FindLineInTurnAround::move()
{
    _motor.turnRight();
    if ( _tracker.checkRoad() == RoadLayout::straight )
    {
        _position.turnRight();
        _pilot.changeMotion( MotionName::leaveFirstLineInTurnAround );
    }
}
