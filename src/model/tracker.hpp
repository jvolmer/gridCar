#ifndef TRACKER_H
#define TRACKER_H

class Tracker
{
public:
    virtual void setup() = 0;
    virtual unsigned char checkSensors() = 0;
};

class ArduinoTracker: public Tracker
{
private:
    const int _pinTrackingLeft;
    const int _pinTrackingMiddle;
    const int _pinTrackingRight;
    unsigned char _sensorValue;

public:
    ArduinoTracker();
    ArduinoTracker(const int pinTrackingLeft,
                   const int pinTrackingMiddle,
                   const int pinTrackingRight);
    void setup() override;
    unsigned char checkSensors() override;
};

#endif
