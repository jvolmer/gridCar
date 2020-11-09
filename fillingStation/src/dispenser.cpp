#include "beverage/beverage.hpp"
#include "dispenser.hpp"

Dispenser::Dispenser(Beverage& beverage0, Beverage& beverage1, Beverage& beverage2, Beverage& beverage3) :
    _beverage0 { beverage0 },
    _beverage1 { beverage1 },
    _beverage2 { beverage2 },
    _beverage3 { beverage3 }
{}

void Dispenser::selectBeverageForDuration(unsigned int beverageId, unsigned int durationInSeconds)
{
    Beverage* selectedBeverage = getBeverage(beverageId);
    if (selectedBeverage)
    {
        selectedBeverage->setPouringDurationInSeconds(durationInSeconds);
    }
}

void Dispenser::draw() {
    for (unsigned int i=0; i<_numberOfBeverages; i++)
    {
        getBeverage(i)->pour();
    }
}

Beverage* Dispenser::getBeverage(unsigned int beverageId)
{
    
    switch (beverageId)
    {
    case 0:
        return &_beverage0;
    case 1:
        return &_beverage1;
    case 2:
        return &_beverage2;
    case 3:
        return &_beverage3;
    default:
        return nullptr;
    }
}
