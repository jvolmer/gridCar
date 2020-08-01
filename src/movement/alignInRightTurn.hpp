#ifndef ALIGN_IN_RIGHT_TURN_H
#define ALIGN_IN_RIGHT_TURN_H

#include "motion.hpp"

class Pilot;
class Timer;
class Motor;

class AlignInRightTurn: public Motion
{
private:
    Pilot& _pilot;
    Timer& _timer;
    Motor& _motor;
    const unsigned long _shortPeriod { 300 };
    bool _started { false };
    unsigned long _startingTime;

    void startTimer();
    void turnRightToLineAfterAShortPeriod();

public:
    AlignInRightTurn(Pilot& pilot, Timer& timer, Motor& motor);
    void move() override;
};

#endif
