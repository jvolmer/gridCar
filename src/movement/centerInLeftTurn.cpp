#include "center.hpp"
#include "pilot.hpp"
#include "motor/motor.hpp"
#include "motionName.hpp"
#include "centerInLeftTurn.hpp"

class Timer;

CenterInLeftTurn::CenterInLeftTurn(Pilot& pilot, Timer& timer, Motor& motor) :
    Center { timer },
    _pilot { pilot },
    _motor { motor }
{}

void CenterInLeftTurn::align()
{
    _motor.goStraight();
}

void CenterInLeftTurn::changeMotion()
{
    _pilot.changeMotion( MotionName::leaveOriginLineInLeftTurn );
}
