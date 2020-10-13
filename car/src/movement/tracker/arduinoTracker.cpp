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

RoadLayout ArduinoTracker::checkRoad()
{
    byte sensorValue = 0;
    sensorValue =
        (digitalRead(_pinTrackingLeft) == 1 ? 1 : 0) << 2 |
        (digitalRead(_pinTrackingMiddle) == 1 ? 1 : 0) << 1 |
        (digitalRead(_pinTrackingRight) == 1 ? 1 : 0) << 0;
    return static_cast<RoadLayout>(sensorValue);
}
