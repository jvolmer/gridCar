#ifndef LINE_PILOT_H
#define LINE_PILOT_H

#include "pilot.hpp"
#include "motion.hpp"
#include "stop.hpp"

class Motor;
class Stop;

class LinePilot: public Pilot
{
private:
    Stop _stop;
    Motion* _motion;

public:
    LinePilot(Motor& motor);
    void move() override { _motion->move(); }
    void changeMotion(Motion* motion) override { _motion = motion; }
};

#endif
