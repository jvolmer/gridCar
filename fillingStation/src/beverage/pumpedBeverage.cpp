#include "../pump/pump.hpp"
#include "pumpedBeverage.hpp"
#include "../timer/timer.hpp"

PumpedBeverage::PumpedBeverage(Pump& pump, Timer& timer) :
    _pump { pump },
    _timer { timer }
{}

void PumpedBeverage::pour()
{
    if ( _pouringDurationInSeconds > 0 )
    {
        startPouring();

        stopPouring();
    }
}

void PumpedBeverage::startPouring()
{
    if ( !_started )
    {
        _pump.start();
        _startingTime = _timer.moment();
        _started = true;
    }
}

void PumpedBeverage::stopPouring()
{
    if ( _started && _timer.moment() - _startingTime >= _pouringDurationInSeconds * 1000 )
    {
        _pump.stop();
        _started = false;
        _pouringDurationInSeconds = 0;
    }
}
