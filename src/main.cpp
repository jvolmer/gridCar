#include "model/arduinoTracker.hpp"
#include "model/arduinoMotor.hpp"
#include "controller/arduinoMover.hpp"

ArduinoTracker tracker(A1, A2, A3);
ArduinoMotor motor(4, 6, 3, 5);
ArduinoMover mover(motor, tracker);

void setup() {
    tracker.setup();
    motor.setup();
}

void loop() {
    mover.followLine();
    tracker.print();
    motor.print();
    mover.print();    
}
