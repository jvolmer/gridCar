#ifndef CENTER_IN_TURN_AROUND_H
#define CENTER_IN_TURN_AROUND_H

#include "center.hpp"
#include "motionName.hpp"

class Pilot;
class Timer;
class Motor;

class CenterInTurnAround : public Center
{
private:
    Pilot& _pilot;
    Motor& _motor;

public:
    CenterInTurnAround(Pilot& pilot, Timer& timer, Motor& motor);
    void align() override;
    void changeMotion() override;
};

#endif
