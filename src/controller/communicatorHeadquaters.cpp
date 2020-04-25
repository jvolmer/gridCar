#include "model/radio.hpp"
#include "entity/package.hpp"
#include "communicatorHeadquaters.hpp"

CommunicatorHeadquaters::CommunicatorHeadquaters(Radio& radio) :
    radio { radio }
{}

void CommunicatorHeadquaters::receive()
{
    if (radio.isAvailable())
        dataReceived = radio.receive();
}

void CommunicatorHeadquaters::reply()
{
    radio.replyWith(dataToSend);
}

void CommunicatorHeadquaters::loop()
{
    receive();
    reply();
}
