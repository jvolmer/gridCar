#include "pilot.hpp"
#include "../timer/timer.hpp"
#include "motor/motor.hpp"
#include "motionName.hpp"
#include "alignInLeftTurn.hpp"

AlignInLeftTurn::AlignInLeftTurn(Pilot& pilot, Timer& timer, Motor& motor) :
    _pilot { pilot },
    _timer { timer },
    _motor { motor }
{}

void AlignInLeftTurn::move()
{
    setStartingTime();

    _motor.goStraight();

    turnLeftToLineAfterAlignmentPeriod();
}

void AlignInLeftTurn::setStartingTime()
{
    if ( !_started )
    {
        _startingTime = _timer.moment();
        _started = true;
    }
}

void AlignInLeftTurn::turnLeftToLineAfterAlignmentPeriod()
{
    if (_timer.moment() - _startingTime >= _alignmentPeriod)
    {
        _started = false;
        _pilot.changeMotion( MotionName::findLineInLeftTurn );
    }
}
