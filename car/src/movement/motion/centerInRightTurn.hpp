#ifndef CENTER_IN_RIGHT_TURN_H
#define CENTER_IN_RIGHT_TURN_H

#include "center.hpp"
#include "motionName.hpp"

class Pilot;
class Timer;
class Motor;

class CenterInRightTurn: public Center
{
private:
    Pilot& _pilot;
    Motor& _motor;

public:
    CenterInRightTurn(Pilot& pilot, Timer& timer, Motor& motor);
    void align() override;
    void changeMotion() override;
};

#endif
