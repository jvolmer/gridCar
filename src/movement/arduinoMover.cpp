#include "motor/motor.hpp"
#include "tracker/tracker.hpp"
#include "direction.hpp"
#include "arduinoMover.hpp"
#include "Arduino.h"

ArduinoMover::ArduinoMover(Motor& motor, Tracker& tracker) :
    Mover {motor, tracker}
{}

void ArduinoMover::print()
{
    Serial.print("Mover | ");
    
    Serial.print("coordinate: (");
    Serial.print("(");
    Serial.print(getPosition().getx());
    Serial.print(", ");
    Serial.print(getPosition().gety());
    Serial.print(")");

    Serial.print(", direction: ");    
    switch(getDirection())
    {
    case Direction::positiveX:
        Serial.print(">");
        break;
    case Direction::negativeY:
        Serial.print("v");
        break;
    case Direction::negativeX:
        Serial.print("<");
        break;
    case Direction::positiveY:
        Serial.print("^");
        break;
    }
    Serial.println();
}
