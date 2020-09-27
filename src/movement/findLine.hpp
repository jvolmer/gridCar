#ifndef FIND_LINE_H
#define FIND_LINE_H

#include "motion.hpp"

class FindLine: public Motion
{
public:
    FindLine();
    void move() override;
    virtual void turn() = 0;
    virtual bool hasFound() = 0;
    virtual void updatePosition() = 0;
    virtual void changeMotion() = 0;
};

#endif
