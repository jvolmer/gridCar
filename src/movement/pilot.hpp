#ifndef PILOT_H
#define PILOT_H

#include "motionName.hpp"

class Pilot
{
public:
    virtual void move() = 0;
    virtual void changeMotion(MotionName name) = 0;
};

#endif
