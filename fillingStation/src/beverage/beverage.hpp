#ifndef BEVERAGE_H
#define BEVERAGE_h

class Beverage
{
public:
    virtual void pour() = 0;
    virtual void setPouringDurationInSeconds(unsigned long seconds) = 0;
};

#endif
