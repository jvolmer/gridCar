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
    byte _averageSpeed { 90 };
    byte _leftSpeed { 0 };
    byte _rightSpeed { 0 };

public:
    ArduinoMotor();
    ArduinoMotor(const byte pinDirectionLeft,
                 const byte pinMotorLeft,
                 const byte pinDirectionRight,
                 const byte pinMotorRight);
    void setup() override;
    void run(byte speedL, byte speedR);
    void turnRight() override;
    void turnLeft() override;
    void goStraight() override;
    void stop() override;
    void print();

    void setAverageSpeed(byte speed){ _averageSpeed = speed; }
    byte getLeftSpeed(){ return _leftSpeed; }
    byte getRightSpeed(){ return _rightSpeed; }
};

#endif
