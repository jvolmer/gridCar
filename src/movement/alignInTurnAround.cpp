#include "pilot.hpp"
#include "../timer/timer.hpp"
#include "motor/motor.hpp"
#include "motionName.hpp"
#include "alignInTurnAround.hpp"

AlignInTurnAround::AlignInTurnAround(Pilot& pilot, Timer& timer, Motor& motor) :
    _pilot { pilot },
    _timer { timer },
    _motor { motor }
{}

void AlignInTurnAround::move()
{
    setStartingTime();

    _motor.goStraight();

    turnRightToLineAfterAlignmentPeriod();
}

void AlignInTurnAround::setStartingTime()
{
    if ( !_started )
    {
        _startingTime = _timer.moment();
        _started = true;
    }
}

void AlignInTurnAround::turnRightToLineAfterAlignmentPeriod()
{
    if ( _timer.moment() - _startingTime >= _alignmentPeriod )
    {
        _started = false;;
        _pilot.changeMotion( MotionName::startTurnAround );
    }
}
