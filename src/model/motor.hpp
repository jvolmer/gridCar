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
private:
    const int _pinDirectionLeft;
    const int _pinDirectionRight;
    const int _pinMotorLeft;
    const int _pinMotorRight;

public:
    ArduinoMotor();
    ArduinoMotor(const int pinDirectionLeft,
                 const int pinMotorLeft,
                 const int pinDirectionRight,
                 const int pinMotorRight);
    void setup() override;
    void run(int speedL, int speedR) override;
};
    
#endif
