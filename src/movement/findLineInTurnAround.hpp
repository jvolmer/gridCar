#ifndef FIND_LINE_IN_TURN_AROUND_H
#define FIND_LINE_IN_TURN_AROUND_H

#include "motion.hpp"

class Pilot;
class Position;
class Tracker;
class Motor;

class FindLineInTurnAround: public Motion
{
private:
    Pilot& _pilot;
    Position& _position;
    Tracker& _tracker;
    Motor& _motor;
    int _crossingCount{ 0 };

public:
    FindLineInTurnAround(Pilot& pilot, Position& position, Tracker& tracker, Motor& motor);
    void move() override;    
};

#endif
