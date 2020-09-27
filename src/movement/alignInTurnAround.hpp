#ifndef ALIGN_IN_TURN_AROUND_H
#define ALIGN_IN_TURN_AROUND_H

#include "motion.hpp"

class Pilot;
class Timer;
class Motor;

class AlignInTurnAround: public Motion
{
private:
    Pilot& _pilot;
    Timer& _timer;
    Motor& _motor;
    unsigned long _alignmentPeriod { 200 };
    bool _started { false };
    unsigned long _startingTime;

    void setStartingTime();
    void turnRightToLineAfterAlignmentPeriod();

public:
    AlignInTurnAround(Pilot& pilot, Timer& timer, Motor& motor);
    void move() override;
    void setAlignmentPeriod(unsigned long period) { _alignmentPeriod = period; }
};

#endif
