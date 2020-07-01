#include "arduinoMotor.hpp"
#include "Arduino.h"

ArduinoMotor::ArduinoMotor(const byte pinDirectionLeft,
                           const byte pinMotorLeft,
                           const byte pinDirectionRight,
                           const byte pinMotorRight) :
    _pinDirectionLeft { pinDirectionLeft },
    _pinMotorLeft { pinMotorLeft },
    _pinDirectionRight { pinDirectionRight },
    _pinMotorRight { pinMotorRight }
{}

ArduinoMotor::ArduinoMotor() :
    ArduinoMotor(0, 0, 0, 0)
{}

void ArduinoMotor::setup()
{
    pinMode(_pinDirectionLeft, OUTPUT);
    pinMode(_pinMotorLeft, OUTPUT);
    pinMode(_pinDirectionRight, OUTPUT);
    pinMode(_pinMotorRight, OUTPUT);

}

void ArduinoMotor::run(int speedl, int speedr)
{
    
    bool backwardsLeft = false, forwardsRight = false;
    if (speedl > 0)
    {
        backwardsLeft = false;
    }
    else
    {
        backwardsLeft = true;
        speedl = -speedl;
    }
    if (speedr > 0)
    {
        forwardsRight = true;
    }
    else
    {
        forwardsRight = false;
        speedr = -speedr;
    }
    digitalWrite(_pinDirectionLeft, backwardsLeft);
    digitalWrite(_pinDirectionRight, forwardsRight);
    analogWrite(_pinMotorLeft, speedl);
    analogWrite(_pinMotorRight, speedr);
}

void ArduinoMotor::turnRight()
{
    run(_averageSpeed, -_averageSpeed);
}

void ArduinoMotor::turnLeft()
{
    run(-_averageSpeed, _averageSpeed);
}

void ArduinoMotor::goStraight()
{
    run(_averageSpeed, _averageSpeed);
}

void ArduinoMotor::stop()
{
    run(0, 0);
}

void ArduinoMotor::print()
{
    Serial.print("Motor | left speed: ");
    Serial.print(_leftSpeed);
    Serial.print(", right speed: ");
    Serial.print(_rightSpeed);
    Serial.println();
}
