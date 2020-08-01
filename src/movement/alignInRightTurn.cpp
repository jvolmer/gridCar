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
    startTimer();

    _motor.goStraight();

    turnRightToLineAfterAShortPeriod();
}

void AlignInRightTurn::startTimer()
{
    if ( !_started )
    {
        _startingTime = _timer.moment();
        _started = true;
    }
}

void AlignInRightTurn::turnRightToLineAfterAShortPeriod()
{
    if ( _timer.moment() - _startingTime >= _shortPeriod )
    {
        _started = false;;
        _pilot.changeMotion( MotionName::turnRightToLine );
    }
}
