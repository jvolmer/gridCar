#ifndef CENTER_IN_LEFT_TURN_H
#define CENTER_IN_LEFT_TURN_H

#include "center.hpp"
#include "motionName.hpp"

class Pilot;
class Timer;
class Motor;

class CenterInLeftTurn: public Center
{
private:
    Pilot& _pilot;
    Motor& _motor;

public:
    CenterInLeftTurn(Pilot& pilot, Timer& timer, Motor& motor);
    void align() override;
    void changeMotion() override;
};

#endif
