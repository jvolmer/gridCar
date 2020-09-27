#ifndef FIND_SECOND_LINE_IN_TURN_AROUND_H
#define FIND_SECOND_LINE_IN_TURN_AROUND_H

#include "motion.hpp"

class Pilot;
class Position;
class Tracker;
class Motor;

class FindSecondLineInTurnAround: public Motion
{
private:
    Pilot& _pilot;
    Position& _position;
    Tracker& _tracker;
    Motor& _motor;

public:
    FindSecondLineInTurnAround(Pilot& pilot, Position& position, Tracker& tracker, Motor& motor);
    void move() override;    
};

#endif
