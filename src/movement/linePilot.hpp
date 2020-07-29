#ifndef LINE_PILOT_H
#define LINE_PILOT_H

#include "pilot.hpp"
#include "motion.hpp"
#include "stop.hpp"
#include "followLine.hpp"
#include "motionName.hpp"

class Coordinate;
class Position;
class Tracker;
class Motor;

class LinePilot: public Pilot
{
private:
    Stop _stop;
    FollowLine _followLine;
    Motion* _motion;

public:
    LinePilot(Coordinate& goal, Position& position, Tracker& tracker, Motor& motor);
    void move() override { _motion->move(); }
    void changeMotion(MotionName Name) override;
};

#endif
