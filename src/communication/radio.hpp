#ifndef RADIO_H
#define RADIO_H

#include "transmission.hpp"

class Radio
{
public:
    virtual bool isAvailable() = 0;
    virtual TransmissionToCar receive() = 0;
    virtual void replyWith(TransmissionFromCar& data) = 0;
};

#endif
