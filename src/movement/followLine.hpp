#ifndef FOLLOW_LINE_H
#define FOLLOW_LINE_H

#include "motion.hpp"
#include "stop.hpp"
#include "motionName.hpp"

class Pilot;
class Position;
class Motor;
class Coordinate;

class FollowLine: public Motion
{
private:
    Pilot& _pilot;
    Coordinate& _goal;
    Position& _position;
    Motor& _motor;

public:
    FollowLine(Pilot& pilot, Coordinate& goal, Position& position, Motor& motor);
    void move() override;
};

#endif
