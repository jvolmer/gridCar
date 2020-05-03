#ifndef ARDUINO_TRACKER_H
#define ARDUINO_TRACKER_H

#include "model/tracker.hpp"
#include "entity/roadLayout.hpp"

class ArduinoTracker: public Tracker
{
private:
    const byte _pinTrackingLeft;
    const byte _pinTrackingMiddle;
    const byte _pinTrackingRight;
    RoadLayout _roadLayout { RoadLayout::none };

public:
    ArduinoTracker();
    ArduinoTracker(const byte pinTrackingLeft,
                   const byte pinTrackingMiddle,
                   const byte pinTrackingRight);
    void setup() override;
    RoadLayout checkRoad() override;
    void print();

    RoadLayout getRoadLayout(){ return _roadLayout; }
};

#endif
