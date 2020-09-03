#ifndef ARDUINO_TRANSMITTER_H
#define ARDUINO_TRANSMITTER_H

#include "transmitter.hpp"
#include "../movement/position/coordinate.hpp"
#include <SPI.h>
#include <RF24.h>
#include "Arduino.h"

class Message;

class ArduinoTransmitter: public Transmitter
{
private:
    const unsigned char* _address; // = {'0', '0', '0', '1'};
    RF24& _radio;
    const byte _listeningChannel = 0;
    
public:
    ArduinoTransmitter(const unsigned char* address,
                       RF24& radio);
    void setup() override;
    const Coordinate& replyToReception(Coordinate& message) override;
    void setReply(const Coordinate& message) override;
};

#endif
