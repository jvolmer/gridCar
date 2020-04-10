#ifndef COMMUNICATOR_HEADQUATERS_H
#define COMMUNICATOR_HEADQUATERS_H

#include "radio.hpp"
#include "package.hpp"

class CommunicatorHeadquaters
{
private:
    Radio& radio;
    PackageToCar dataReceived;
    PackageFromCar dataToSend;
public:
    CommunicatorHeadquaters(Radio& radio);
    PackageToCar& getReceivedData(){ return dataReceived; }
    void setDataToSend(PackageFromCar& package){ dataToSend = package; }
    void receive();
    void reply();
    void loop();
};

#endif
