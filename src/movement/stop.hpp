#ifndef STOP_H
#define STOP_H

#include "motion.hpp"

class Pilot;
class Motor;

class Stop: public Motion
{
private:
    Pilot& _pilot;
    Motor& _motor;
    
public:
    Stop(Pilot& pilot, Motor& motor);
    void move() override;
};

#endif
