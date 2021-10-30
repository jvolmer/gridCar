#ifndef ARDUINO_TRANSMITTER_H
#define ARDUINO_TRANSMITTER_H

#include "transmitter.hpp"
#include "../movement/position/coordinate.hpp"
#include <SPI.h>
#include <RF24.h>
#include "Arduino.h"

class Message;


// Reads radio signals and directly replies
// with a coordinate that is set with setReply.

class ArduinoTransmitter: public Transmitter
{
private:
    const unsigned char* _address;
    RF24& _radio;
    const byte _listeningChannel = 0;
    
public:
    ArduinoTransmitter(const unsigned char* address,
                       RF24& radio);
    void setup() override;
    // Read radio signal and reply 
    const Coordinate& replyToReception(Coordinate& message) override;
    // Set reply value for next radio signal read
    void setReply(const Coordinate& message) override;
};

#endif
