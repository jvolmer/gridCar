#ifndef SHORT_STRAIGHT_H
#define SHORT_STRAIGHT_H

#include "motion.hpp"

class Pilot;
class Timer;
class Motor;

class ShortStraight: public Motion
{
private:
    Pilot& _pilot;
    Timer& _timer;
    Motor& _motor;
    const unsigned long _shortPeriodInMillis { 200 };
    bool _started { false };
    unsigned long _startingTime;

    void startTimer();
    void turnToLineAfterAShortPeriod();

public:
    ShortStraight(Pilot& pilot, Timer& timer, Motor& motor);
    void move() override;
};

#endif
