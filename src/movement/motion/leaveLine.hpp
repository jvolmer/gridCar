#ifndef LEAVE_LINE_H
#define LEAVE_LINE_H

#include "motion.hpp"


// Starts turning away from a line until it has left the line.
// This motion ensures that car really turns
// before it looks for a line in the next (find line) motion.

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
