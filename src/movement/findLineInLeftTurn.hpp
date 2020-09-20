#ifndef FIND_LINE_IN_LEFT_TURN_H
#define FIND_LINE_IN_LEFT_TURN_H

#include "motion.hpp"

class Pilot;
class Position;
class Tracker;
class Motor;

class FindLineInLeftTurn: public Motion
{
private:
    Pilot& _pilot;
    Position& _position;
    Tracker& _tracker;
    Motor& _motor;

public:
    FindLineInLeftTurn(Pilot& pilot, Position& position, Tracker& tracker, Motor& motor);
    void move() override;    
};

#endif
