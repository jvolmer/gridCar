#ifndef FOLLOW_LINE_H
#define FOLLOW_LINE_H

#include "motion.hpp"

class FollowLine: public Motion
{
private:
    Pilot& _pilot;
    Position& _position;
    Motor& _motor;

public:
    FollowLine(Pilot& pilot, Position& position, Motor& motor);
    void move() override;
};

#endif
