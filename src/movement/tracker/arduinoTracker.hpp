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

    bool detectsBlack(const byte pin) {
      return digitalRead(pin) == HIGH ? true : false;
    };

public:
    ArduinoTracker();
    ArduinoTracker(const byte pinTrackingLeft,
                   const byte pinTrackingMiddle,
                   const byte pinTrackingRight);
    void setup() override;
    RoadLayout roadLayout() override;
};

#endif
