#ifndef TRACKER_H
#define TRACKER_H

#include "entity/roadLayout.hpp"

class Tracker
{
public:
    virtual void setup() = 0;
    virtual RoadLayout checkRoad() = 0;
};

class ArduinoTracker: public Tracker
{
private:
    const int _pinTrackingLeft;
    const int _pinTrackingMiddle;
    const int _pinTrackingRight;
    RoadLayout _roadLayout { RoadLayout::none };

public:
    ArduinoTracker();
    ArduinoTracker(const int pinTrackingLeft,
                   const int pinTrackingMiddle,
                   const int pinTrackingRight);
    void setup() override;
    RoadLayout checkRoad() override;
};

#endif
