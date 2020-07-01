#ifndef ARDUINO_MOTOR_H
#define ARDUINO_MOTOR_H

#include "motor.hpp"
#include "Arduino.h"

class ArduinoMotor: public Motor
{
private:
    const byte _pinDirectionLeft;
    const byte _pinMotorLeft;
    const byte _pinDirectionRight;
    const byte _pinMotorRight;
    int _averageSpeed { 100 };
    int _leftSpeed { 0 };
    int _rightSpeed { 0 };

public:
    ArduinoMotor();
    ArduinoMotor(const byte pinDirectionLeft,
                 const byte pinMotorLeft,
                 const byte pinDirectionRight,
                 const byte pinMotorRight);
    void setup() override;
    void run(int speedL, int speedR);
    void turnRight() override;
    void turnLeft() override;
    void goStraight() override;
    void stop() override;
    void print();

    void setAverageSpeed(int speed){ _averageSpeed = speed; }
    byte getLeftSpeed(){ return _leftSpeed; }
    byte getRightSpeed(){ return _rightSpeed; }
};

#endif
