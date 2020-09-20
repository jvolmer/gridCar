#ifndef TURN_AROUND_H
#define TURN_AROUND_H

#include "motion.hpp"

class Pilot;
class Position;
class Tracker;
class Motor;

class TurnAround: public Motion
{
private:
    Pilot& _pilot;
    Position& _position;
    Tracker& _tracker;
    Motor& _motor;
    bool _turnedOverCrossing{ false };

public:
    TurnAround(Pilot& pilot, Position& position, Tracker& tracker, Motor& motor);
    void move() override;    
};

#endif
