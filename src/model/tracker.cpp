#include "tracker.hpp"

ArduinoTracker::ArduinoTracker(const int pinTrackingLeft,
                               const int pinTrackingMiddle,
                               const int pinTrackingRight) :
    _pinTrackingLeft { pinTrackingLeft },
    _pinTrackingMiddle {pinTrackingMiddle },
    _pinTrackingRight { pinTrackingRight },
    _sensorValue { 0 }
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

unsigned char ArduinoTracker::checkSensors()
{
    unsigned char trackingSensorVal = 0;
    trackingSensorVal =
        (digitalRead(_pinTrackingLeft) == 1 ? 1 : 0) << 2 |
        (digitalRead(_pinTrackingMiddle) == 1 ? 1 : 0) << 1 |
        (digitalRead(_pinTrackingRight) == 1 ? 1 : 0) << 0;
    _sensorValue = trackingSensorVal;
    return trackingSensorVal;
}
