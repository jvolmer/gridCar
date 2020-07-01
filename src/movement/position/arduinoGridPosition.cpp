#include "coordinate.hpp"
#include "direction.hpp"
#include "arduinoGridPosition.hpp"
#include "Arduino.h"

ArduinoGridPosition::ArduinoGridPosition(const Coordinate& location, const Direction& direction) :
    GridPosition { location, direction }
{}

ArduinoGridPosition::ArduinoGridPosition() :
    GridPosition { Coordinate(0,0), Direction::positiveY }
{}

void ArduinoGridPosition::print()
{
    Serial.print("GridPosition | ");
    
    Serial.print("coordinate: (");
    Serial.print("(");
    Serial.print(getLocation().getx());
    Serial.print(", ");
    Serial.print(getLocation().gety());
    Serial.print(")");

    Serial.print(", direction: ");    
    switch(getForwardDirection())
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
