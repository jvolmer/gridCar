#ifndef PUMP_H
#define PUMP_H

class Pump
{
public:
    virtual void setup() = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
};

#endif
