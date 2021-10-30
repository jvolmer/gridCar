#ifndef STOP_FINALLY_H
#define STOP_FINALLY_H

#include "motion.hpp"

class Motor;


// Final stop: Does not change the state afterwards.

class StopFinally: public Motion
{
private:
    Motor& _motor;
    
public:
    StopFinally(Motor& motor);
    void move() override;
};

#endif
