#ifndef PILOT_H
#define PILOT_H

class Motion;

class Pilot
{
public:
    virtual void move() = 0;
    virtual void changeMotion(Motion* motion) = 0;
};

#endif
