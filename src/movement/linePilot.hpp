#ifndef LINE_PILOT_H
#define LINE_PILOT_H

#include "pilot.hpp"
#include "stop.hpp"

class Motion;
class Position;
class Motor;
class Tracker;

class LinePilot: public Pilot
{
private:
    Motion& _motion;
    Stop _stop;

public:
    LinePilot(Position& position, Motor& motor, Tracker& tracker);
    void move() override {_motion.move(); }
    void changeMotion(Motion& motion) override { _motion = motion; };
    Motion& getStopMotion() const { return _motion; }
};

#endif
