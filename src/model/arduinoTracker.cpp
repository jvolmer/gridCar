#include "../entity/roadLayout.hpp"
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
    _roadLayout = static_cast<RoadLayout>(sensorValue);
    return _roadLayout;
}

void ArduinoTracker::print()
{
    Serial.print("Tracker | road layout: ");
    switch(_roadLayout)
    {
    case RoadLayout::none:
        Serial.print("none");
        break;
    case RoadLayout::sharpRight:
        Serial.print("sharp right");
        break;
    case RoadLayout::straight:
        Serial.print("straight");
        break;
    case RoadLayout::right:
        Serial.print("right");
        break;
    case RoadLayout::sharpLeft:
        Serial.print("sharp left");
        break;
    case RoadLayout::enclosed:
        Serial.print("enclosed");
        break;
    case RoadLayout::left:
        Serial.print("left");
        break;
    case RoadLayout::blocked:
        Serial.print("blocked");
        break;
    }
    Serial.println();
}
