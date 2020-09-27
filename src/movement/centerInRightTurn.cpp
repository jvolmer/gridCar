#include "center.hpp"
#include "pilot.hpp"
#include "motor/motor.hpp"
#include "motionName.hpp"
#include "centerInRightTurn.hpp"

class Timer;

CenterInRightTurn::CenterInRightTurn(Pilot& pilot, Timer& timer, Motor& motor) :
    Center { timer },
    _pilot { pilot },
    _motor { motor }
{}

void CenterInRightTurn::align()
{
    _motor.goStraight();
}

void CenterInRightTurn::changeMotion()
{
    _pilot.changeMotion( MotionName::leaveOriginLineInRightTurn );
}
