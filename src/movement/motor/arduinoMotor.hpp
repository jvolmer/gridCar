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
    int _defaultSpeed { 100 };
    void run(int speedL, int speedR);

public:
    ArduinoMotor();
    ArduinoMotor(const byte pinDirectionLeft,
                 const byte pinMotorLeft,
                 const byte pinDirectionRight,
                 const byte pinMotorRight);
    void setDefaultSpeed(int speed){ _defaultSpeed = speed; }

    void setup() override;
    void turnRight() override { run(_defaultSpeed, -_defaultSpeed); }
    void turnLeft() override { run(-_defaultSpeed, _defaultSpeed); }
    void goStraight() override { run(_defaultSpeed, _defaultSpeed); }
    void stop() override { run(0, 0); }

};

#endif
