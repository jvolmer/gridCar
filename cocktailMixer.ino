#include "src/movement/tracker/arduinoTracker.hpp"
#include "src/movement/motor/arduinoMotor.hpp"
#include "src/movement/arduinoMover.hpp"

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
