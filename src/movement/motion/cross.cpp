#include "../pilot.hpp"
#include "../tracker/tracker.hpp"
#include "../tracker/roadLayout.hpp"
#include "../motor/motor.hpp"
#include "../position/position.hpp"
#include "../goal.hpp"
#include "motionName.hpp"
#include "cross.hpp"

class Coordinate;

Cross::Cross(Pilot &pilot, Goal &goal, Position &position, Tracker &tracker, Motor &motor):
    _pilot{ pilot },
    _goal{ goal },
    _position{ position },
    _tracker{ tracker },
    _motor{ motor }
{}

void Cross::move()
{
    switch( _goal.turningDirectionFrom(_position))
    {
        case RelativeDirection::at :
	    _motor.stop();
            break;
        case RelativeDirection::inFront :
	    // Ensure that crossing is left before following the line.
	    // Otherwise follow line recognizes the same crossing again.
 	    _motor.goStraight();
            if (leftCrossing()) {
              _pilot.changeMotion(MotionName::followLine);
            }
            break;
        case RelativeDirection::onTheRight :
            _pilot.changeMotion( MotionName::centerInRightTurn );
            break;
        case RelativeDirection::onTheLeft :
            _pilot.changeMotion( MotionName::centerInLeftTurn );
            break;
        case RelativeDirection::exactlyBehind :
            _pilot.changeMotion( MotionName::centerInTurnAround );
            break;
        default:
            break;
    }
}

bool Cross::leftCrossing() const
{
    return _tracker.roadLayout() != RoadLayout::blocked;
}
