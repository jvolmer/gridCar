#include "roadLayout.hpp"
#include "arduinoTracker.hpp"
#include "Arduino.h"

ArduinoTracker::ArduinoTracker(const byte pinTrackingLeft,
                               const byte pinTrackingMiddle,
                               const byte pinTrackingRight) :
    _pinTrackingLeft { pinTrackingLeft },
    _pinTrackingMiddle {pinTrackingMiddle },
    _pinTrackingRight { pinTrackingRight }
{}

ArduinoTracker::ArduinoTracker() :
    ArduinoTracker(0, 0, 0)
{}

void ArduinoTracker::setup()
{
    pinMode(_pinTrackingLeft, INPUT);
    pinMode(_pinTrackingMiddle, INPUT);
    pinMode(_pinTrackingRight, INPUT);
}

RoadLayout ArduinoTracker::roadLayout()
{
    byte sensorValue =
      detectsBlack(_pinTrackingLeft) << 2 |
      detectsBlack(_pinTrackingMiddle) << 1 |
      detectsBlack(_pinTrackingRight) << 0;
    return static_cast<RoadLayout>(sensorValue);
}
