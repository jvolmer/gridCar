#ifndef TRACKER_H
#define TRACKER_H

#include "../entity/roadLayout.hpp"

class Tracker
{
public:
    virtual void setup() = 0;
    virtual RoadLayout checkRoad() = 0;
};

#endif
