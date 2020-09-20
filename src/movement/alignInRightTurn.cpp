#include "pilot.hpp"
#include "../timer/timer.hpp"
#include "motor/motor.hpp"
#include "motionName.hpp"
#include "alignInRightTurn.hpp"

AlignInRightTurn::AlignInRightTurn(Pilot& pilot, Timer& timer, Motor& motor) :
    _pilot { pilot },
    _timer { timer },
    _motor { motor }
{}

void AlignInRightTurn::move()
{
    setStartingTime();

    _motor.goStraight();

    turnRightToLineAfterAlignmentPeriod();
}

void AlignInRightTurn::setStartingTime()
{
    if ( !_started )
    {
        _startingTime = _timer.moment();
        _started = true;
    }
}

void AlignInRightTurn::turnRightToLineAfterAlignmentPeriod()
{
    if ( _timer.moment() - _startingTime >= _alignmentPeriod )
    {
        _started = false;;
        _pilot.changeMotion( MotionName::turnRightToLine );
    }
}
