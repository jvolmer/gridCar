#ifndef TRACKER_H
#define TRACKER_H

#include "roadLayout.hpp"

class Tracker
{
public:
    virtual void setup() = 0;
    virtual RoadLayout roadLayout() = 0;
};

#endif
