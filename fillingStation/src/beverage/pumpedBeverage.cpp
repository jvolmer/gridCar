#include "../pump/pump.hpp"
#include "pumpedBeverage.hpp"

PumpedBeverage::PumpedBeverage(Pump& pump) :
    _pump { pump }
{}

void PumpedBeverage::pour()
{
    _pump.start();
}
