#ifndef STOP_H
#define STOP_H

#include "motion.hpp"

class Pilot;
class Goal;
class Position;
class Motor;

class Stop: public Motion
{
private:
    Pilot& _pilot;
    Goal& _goal;
    Position& _position;
    Motor& _motor;
    
public:
    Stop(Pilot& pilot, Goal& goal, Position& position, Motor& motor);
    void move() override;
};

#endif
