#ifndef COMMUNICATOR_HEADQUATERS_H
#define COMMUNICATOR_HEADQUATERS_H

#include "model/radio.hpp"
#include "entity/transmission.hpp"

class CommunicatorHeadquaters
{
private:
    Radio& radio;
    TransmissionToCar dataReceived;
    TransmissionFromCar dataToSend;
public:
    CommunicatorHeadquaters(Radio& radio);
    TransmissionToCar& getReceivedData(){ return dataReceived; }
    void setDataToSend(TransmissionFromCar& data){ dataToSend = data; }
    void receive();
    void reply();
    void loop();
};

#endif
