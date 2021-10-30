#ifndef CENTER_H
#define CENTER_H

#include "motion.hpp"
#include "motionName.hpp"

class Timer;


// Centers at crossing after reaching a crossing and before a turn.
// To be able to turn at a crossing, car has to be positioned
// at its center. When reaching crossing, it first stops at start
// of crossing because tracking sensors are at the front of the car.
// Center position is reached by going straight
// for a tunable duration.

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
