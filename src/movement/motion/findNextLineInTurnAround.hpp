#ifndef FIND_NEXT_LINE_IN_TURN_AROUND_H
#define FIND_NEXT_LINE_IN_TURN_AROUND_H

#include "findLine.hpp"

class Pilot;
class Position;
class Tracker;
class Motor;

class FindNextLineInTurnAround: public FindLine
{
private:
    Pilot& _pilot;
    Position& _position;
    Tracker& _tracker;
    Motor& _motor;

public:
    FindNextLineInTurnAround(Pilot& pilot, Position& position, Tracker& tracker, Motor& motor);
    void turn();
    bool hasFound();
    void updatePosition();
    void changeMotion();
};

#endif
