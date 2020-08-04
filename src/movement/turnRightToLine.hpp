#ifndef TURN_RIGHT_TO_LINE_H
#define TURN_RIGHT_TO_LINE_H

#include "motion.hpp"

class Pilot;
class Position;
class Tracker;
class Motor;

class TurnRightToLine: public Motion
{
private:
    Pilot& _pilot;
    Position& _position;
    Tracker& _tracker;
    Motor& _motor;

public:
    TurnRightToLine(Pilot& pilot, Position& position, Tracker& tracker, Motor& motor);
    void move() override;    
};

#endif
