#ifndef TRANSMITTER_H
#define TRANSMITTER_H

class Coordinate;
class Message;

class Transmitter
{
public:
    virtual void setup() = 0;
    virtual const Coordinate& replyToReception(Coordinate& message) = 0;
    virtual void setReply(const Coordinate& message) = 0;
};

#endif
