#include "src/movement/tracker/arduinoTracker.hpp"
#include "src/movement/motor/arduinoMotor.hpp"
#include "src/movement/position/arduinoGridPosition.hpp"
#include "src/movement/lineSteering.hpp"

ArduinoTracker tracker{A1, A2, A3};
ArduinoMotor motor{4, 6, 3, 5};
ArduinoGridPosition position;
LineSteering steering(position, motor, tracker);

void setup() {
    tracker.setup();
    motor.setup();

    tracker.print();
    motor.print();
    position.print();    

}

void loop() {
    steering.followLine();

    tracker.print();
    motor.print();
    position.print();    
}
