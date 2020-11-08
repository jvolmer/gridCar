#include "beverage/beverage.hpp"
#include "dispenser.hpp"

Dispenser::Dispenser(Beverage& beverage1, Beverage& beverage2, Beverage& beverage3, Beverage& beverage4) :
    _beverage1 { beverage1 },
    _beverage2 { beverage2 },
    _beverage3 { beverage3 },
    _beverage4 { beverage4 }
{}

void Dispenser::addFilling(int beverageId, int durationInSeconds)
{
    getBeverage(beverageId).setPouringDurationInSeconds(durationInSeconds);
}

void Dispenser::fill()
{

}

Beverage& Dispenser::getBeverage(int beverageId)
{
    switch (beverageId)
    {
    case 1:
        return _beverage1;
    case 2:
        return _beverage2;
    case 3:
        return _beverage3;
    case 4:
        return _beverage4;
    }
}
