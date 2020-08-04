#ifndef TURN_LEFT_TO_LINE_H
#define TURN_LEFT_TO_LINE_H

#include "motion.hpp"

class Pilot;
class Position;
class Tracker;
class Motor;

class TurnLeftToLine: public Motion
{
private:
    Pilot& _pilot;
    Position& _position;
    Tracker& _tracker;
    Motor& _motor;

public:
    TurnLeftToLine(Pilot& pilot, Position& position, Tracker& tracker, Motor& motor);
    void move() override;    
};

#endif
