#ifndef FIND_NEXT_TO_NEXT_LINE_IN_TURN_AROUND_H
#define FIND_NEXT_TO_NEXT_LINE_IN_TURN_AROUND_H

#include "findLine.hpp"

class Pilot;
class Position;
class Tracker;
class Motor;

class FindNextToNextLineInTurnAround: public FindLine
{
private:
    Pilot& _pilot;
    Position& _position;
    Tracker& _tracker;
    Motor& _motor;

public:
    FindNextToNextLineInTurnAround(Pilot& pilot, Position& position, Tracker& tracker, Motor& motor);
    void turn();
    bool hasFound();
    void updatePosition();
    void changeMotion();
};

#endif
