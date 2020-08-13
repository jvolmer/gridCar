#ifndef TRANSMITTER_H
#define TRANSMITTER_H

class Coordinate;
class Message;

class Transmitter
{
public:
    virtual void receive(const Message& message) = 0;
    virtual void replyWith(const Coordinate& message) = 0;
};

#endif
