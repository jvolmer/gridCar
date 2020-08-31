#include "arduinoTransmitter.hpp"
#include <SPI.h>
#include <RF24.h>
#include "Arduino.h"

class Message;

ArduinoTransmitter::ArduinoTransmitter(const unsigned char* address,
                                       RF24& radio):
    _address { address },
    _radio { radio }
{}

void ArduinoTransmitter::setup()
{
    _radio.begin();
    _radio.setDataRate( RF24_250KBPS );
    _radio.openReadingPipe(_listeningChannel, _address);
    _radio.enableAckPayload();
    _radio.startListening();
}

void ArduinoTransmitter::setReply(const Coordinate& message)
{
    _radio.writeAckPayload(_listeningChannel, &message, sizeof(message));
}

const Coordinate& ArduinoTransmitter::replyToReception(const Coordinate& message)
{
    if ( _radio.available() ) {
        _radio.read(&message, sizeof(message));
    }
    return message;
}
