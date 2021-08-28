#ifndef FIND_NEXT_LINE_IN_RIGHT_TURN_H
#define FIND_NEXT_LINE_IN_RIGHT_TURN_H

#include "findLine.hpp"

class Pilot;
class Position;
class Tracker;
class Motor;

class FindNextLineInRightTurn: public FindLine
{
private:
    Pilot& _pilot;
    Position& _position;
    Tracker& _tracker;
    Motor& _motor;

public:
    FindNextLineInRightTurn(Pilot& pilot, Position& position, Tracker& tracker, Motor& motor);
    void turn();
    bool hasFound();
    void updatePosition();
    void changeMotion();
};

#endif
