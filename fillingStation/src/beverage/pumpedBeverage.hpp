#ifndef H_PUMPED_BEVERAGE
#define H_PUMPED_BEVERAGE

#include "beverage.hpp"

class Pump;

class PumpedBeverage : public Beverage {
private:
    Pump& _pump;
public:
    PumpedBeverage(Pump& pump);
    void pour() override;
};

#endif
