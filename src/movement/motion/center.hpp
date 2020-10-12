#ifndef CENTER_H
#define CENTER_H

#include "motion.hpp"
#include "motionName.hpp"

class Timer;

class Center: public Motion
{
private:
    Timer& _timer;
    unsigned long _alignmentPeriod { 100 };
    bool _started { false };
    unsigned long _startingTime;

    void setStartingTime();
    void changeMotionAfterAlignmentPeriod();

public:
    Center(Timer& timer);
    virtual void move() override;
    virtual void align() = 0;
    virtual void changeMotion() = 0;
    void setAlignmentPeriod(unsigned long period) { _alignmentPeriod = period; }
};

#endif
