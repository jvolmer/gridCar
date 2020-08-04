#ifndef ALIGN_IN_LEFT_TURN_H
#define ALIGN_IN_LEFT_TURN_H

#include "motion.hpp"

class Pilot;
class Timer;
class Motor;

class AlignInLeftTurn: public Motion
{
private:
    Pilot& _pilot;
    Timer& _timer;
    Motor& _motor;
    const unsigned long _shortPeriod { 100 };
    bool _started { false };
    unsigned long _startingTime;

    void startTimer();
    void turnLeftToLineAfterAShortPeriod();

public:
    AlignInLeftTurn(Pilot& pilot, Timer& timer, Motor& motor);
    void move() override;
};

#endif
