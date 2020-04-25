#include "model/radio.hpp"
#include "entity/transmission.hpp"
#include "communicatorHeadquaters.hpp"

CommunicatorHeadquaters::CommunicatorHeadquaters(Radio& radio) :
    _radio { radio }
{}

void CommunicatorHeadquaters::receive()
{
    if (_radio.isAvailable())
        _dataReceived = _radio.receive();
}

void CommunicatorHeadquaters::reply()
{
    _radio.replyWith(_dataToSend);
}

void CommunicatorHeadquaters::loop()
{
    receive();
    reply();
}
