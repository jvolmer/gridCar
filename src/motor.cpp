#include "motor.hpp"

ArduinoMotor::ArduinoMotor(const int pinDirectionLeft,
                           const int pinMotorLeft,
                           const int pinDirectionRight,
                           const int pinMotorRight) :
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
    pinMode(pinDirectionLeft, OUTPUT);
    pinMode(pinMotorLeft, OUTPUT);
    pinMode(pinDirectionRight, OUTPUT);
    pinMode(pinMotorRight, OUTPUT);

}

void ArduinoMotor::run(int speedl, int speedr)
{
  int dirL = 0, dirR = 0;
  if (speedl > 0) {
    dirL = 0;
  }
  else {
    dirL = 1;
    speedl = -speedl;
  }
  if (speedr > 0) {
    dirR = 1;
  }
  else {
    dirR = 0;
    speedr = -speedr;
  }
  digitalWrite(pinDirectionLeft, dirL);
  digitalWrite(pinDirectionRight, dirR);
  analogWrite(pinMotorLeft, speedl);
  analogWrite(pinMotorRight, speedr);
}
