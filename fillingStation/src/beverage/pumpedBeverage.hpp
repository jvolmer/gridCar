#ifndef PUMPED_BEVERAGE_H
#define PUMPED_BEVERAGE_H

#include "beverage.hpp"

class Pump;
class Timer;

class PumpedBeverage : public Beverage {
private:
    Pump& _pump;
    Timer& _timer;
    unsigned long _pouringDurationInSeconds { 0 };
    unsigned long _startingTime;
    bool _started { false };

    void startPouring();
    void stopPouring();
public:
    PumpedBeverage(Pump& pump, Timer& timer);
    void setPouringDurationInSeconds( unsigned long seconds) override { _pouringDurationInSeconds = seconds; }
    void pour() override;
};

#endif
