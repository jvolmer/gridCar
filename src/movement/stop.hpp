#ifndef STOP_H
#define STOP_H

#include "motion.hpp"

class Pilot;
class Coordinate;
class Position;
class Motor;

class Stop: public Motion
{
private:
    Pilot& _pilot;
    Coordinate& _goal;
    Position& _position;
    Motor& _motor;
    
public:
    Stop(Pilot& pilot, Coordinate& goal, Position& position, Motor& motor);
    void move() override;
};

#endif
