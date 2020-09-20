#ifndef ARDUINO_TRACKER_H
#define ARDUINO_TRACKER_H

#include "roadLayout.hpp"
#include "tracker.hpp"
#include "Arduino.h"

class ArduinoTracker: public Tracker
{
private:
    const byte _pinTrackingLeft;
    const byte _pinTrackingMiddle;
    const byte _pinTrackingRight;

public:
    ArduinoTracker();
    ArduinoTracker(const byte pinTrackingLeft,
                   const byte pinTrackingMiddle,
                   const byte pinTrackingRight);
    void setup() override;
    RoadLayout checkRoad() override;
};

#endif
