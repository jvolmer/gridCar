#ifndef LEAVE_LINE_H
#define LEAVE_LINE_H

#include "motion.hpp"

class LeaveLine: public Motion
{
public:
    LeaveLine();
    void move() override;
    virtual void turn() = 0;
    virtual bool hasLeft() = 0;
    virtual void changeMotion() = 0;
};

#endif
