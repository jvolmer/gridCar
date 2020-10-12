#ifndef FOLLOW_LINE_H
#define FOLLOW_LINE_H

#include "motion.hpp"
#include "stop.hpp"
#include "motionName.hpp"

class Pilot;
class Position;
class Tracker;
class Motor;

class FollowLine: public Motion
{
private:
    Pilot& _pilot;
    Position& _position;
    Tracker& _tracker;
    Motor& _motor;
    bool isAtCrossing{ false };

    void followLine();
    
public:
    FollowLine(Pilot& pilot, Position& position, Tracker& tracker, Motor& motor);
    void move() override;
};

#endif
