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
    startTimer();

    _motor.goStraight();

    turnLeftToLineAfterAShortPeriod();
}

void AlignInLeftTurn::startTimer()
{
    if ( !_started )
    {
        _startingTime = _timer.moment();
        _started = true;
    }
}

void AlignInLeftTurn::turnLeftToLineAfterAShortPeriod()
{
    if (_timer.moment() - _startingTime >= _shortPeriod)
    {
        _started = false;
        _pilot.changeMotion( MotionName::turnLeftToLine );
    }
}
