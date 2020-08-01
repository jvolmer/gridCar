#include "pilot.hpp"
#include "../timer/timer.hpp"
#include "motor/motor.hpp"
#include "motionName.hpp"
#include "shortStraight.hpp"

ShortStraight::ShortStraight(Pilot& pilot, Timer& timer, Motor& motor) :
    _pilot { pilot },
    _timer { timer },
    _motor { motor }
{}

void ShortStraight::move()
{
    startTimer();

    _motor.goStraight();

    turnToLineAfterAShortPeriod();
}

void ShortStraight::startTimer()
{
    if ( !_started )
    {
        _startingTime = _timer.millis();
        _started = true;
    }
}

void ShortStraight::turnToLineAfterAShortPeriod()
{
    if (_timer.millis() - _startingTime >= _shortPeriodInMillis)
    {
        _pilot.changeMotion( MotionName::turnToLine );
        _started = false;;
    }
}
