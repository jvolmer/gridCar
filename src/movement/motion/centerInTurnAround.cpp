#include "center.hpp"
#include "../pilot.hpp"
#include "../motor/motor.hpp"
#include "motionName.hpp"
#include "centerInTurnAround.hpp"

class Timer;

CenterInTurnAround::CenterInTurnAround(Pilot& pilot, Timer& timer, Motor& motor) :
    Center { timer },
    _pilot { pilot },
    _motor { motor }
{}

void CenterInTurnAround::align()
{
    _motor.goStraight();
}

void CenterInTurnAround::changeMotion()
{
    _pilot.changeMotion( MotionName::leaveOriginLineInTurnAround );
}
