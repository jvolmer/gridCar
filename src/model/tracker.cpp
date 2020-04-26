#include "entity/roadLayout.hpp"
#include "tracker.hpp"

ArduinoTracker::ArduinoTracker(const int pinTrackingLeft,
                               const int pinTrackingMiddle,
                               const int pinTrackingRight) :
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
    unsigned char sensorValue = 0;
    sensorValue =
        (digitalRead(_pinTrackingLeft) == 1 ? 1 : 0) << 2 |
        (digitalRead(_pinTrackingMiddle) == 1 ? 1 : 0) << 1 |
        (digitalRead(_pinTrackingRight) == 1 ? 1 : 0) << 0;
    _roadLayout = static_cast<RoadLayout>(sensorValue);
    return _roadLayout;
}
