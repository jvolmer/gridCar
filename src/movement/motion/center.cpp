#include "../../timer/timer.hpp"
#include "center.hpp"

Center::Center(Timer& timer) :
    _timer { timer }
{}

void Center::move()
{
    setStartingTime();
    align();
    changeMotionAfterAlignmentPeriod();
}

void Center::setStartingTime()
{
    if ( !_started )
    {
        _startingTime = _timer.moment();
        _started = true;
    }
}

void Center::changeMotionAfterAlignmentPeriod()
{
    if ( _timer.moment() - _startingTime >= _alignmentPeriod )
    {
        _started = false;
        changeMotion();
    }
}
