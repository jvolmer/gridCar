#ifndef MOTOR_H
#define MOTOR_H

class Motor
{
public:
    virtual void setup() = 0;
    virtual void turnRight() = 0;
    virtual void turnLeft() = 0;
    virtual void goStraight() = 0;
    virtual void stop() = 0;
};
    
#endif
