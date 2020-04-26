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

class ArduinoMotor: public Motor
{
private:
    const int _pinDirectionLeft;
    const int _pinMotorLeft;
    const int _pinDirectionRight;
    const int _pinMotorRight;
    int _velocity;

public:
    ArduinoMotor();
    ArduinoMotor(const int pinDirectionLeft,
                 const int pinMotorLeft,
                 const int pinDirectionRight,
                 const int pinMotorRight,
                 int standardVelocity);
    void setup() override;
    void run(int speedL, int speedR);
    void turnRight() override;
    void turnLeft() override;
    void goStraight() override;
    void stop() override;
};
    
#endif
