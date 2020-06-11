#ifndef COMMUNICATOR_HEADQUATERS_H
#define COMMUNICATOR_HEADQUATERS_H

#include "radio.hpp"
#include "transmission.hpp"

class CommunicatorHeadquaters
{
private:
    Radio& _radio;
    TransmissionToCar _dataReceived;
    TransmissionFromCar _dataToSend;
public:
    CommunicatorHeadquaters(Radio& radio);
    const TransmissionToCar& getReceivedData() const { return _dataReceived; }
    void setDataToSend(const TransmissionFromCar& data){ _dataToSend = data; }
    void receive();
    void reply();
    void loop();
};

#endif
