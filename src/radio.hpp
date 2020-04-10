#ifndef RADIO_H
#define RADIO_H

#include "package.hpp"

class Radio
{
public:
    virtual bool isAvailable() = 0;
    virtual PackageToCar receive() = 0;
    virtual void replyWith(PackageFromCar& package) = 0;
};

#endif
