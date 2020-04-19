#ifndef MOTOR_H
#define MOTOR_H

class Motor
{
public:
    virtual void setup() = 0;
    virtual void run(int speedL, int speedR) = 0;
};

class ArduinoMotor: public Motor
{
    ArduinoMotor();
    ArduinoMotor(const int pinDirectionLeft,
                 const int pinMotorLeft,
                 const int pinDirectionRight,
                 const int pinMotorRight);
    void setup() override;
    void run(int speedL, int speedR) override;
};
    
#endif
