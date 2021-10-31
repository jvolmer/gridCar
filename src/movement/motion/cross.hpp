#ifndef CROSS_H
#define CROSS_H

#include "motion.hpp"

class Pilot;
class Goal;
class Position;
class Tracker;
class Motor;


// Cross a line.
// Next motion is chosen depending on relative position of goal.

class Cross: public Motion
{
private:
    Pilot& _pilot;
    Goal& _goal;
    Position& _position;
    Tracker& _tracker;
    Motor& _motor;

    bool leftCrossing() const;
  
public:
    Cross(Pilot& pilot, Goal& goal, Position& position, Tracker& tracker, Motor& motor);
    void move() override;
};

#endif
