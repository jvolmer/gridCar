#include "src/timer/arduinoTimer.hpp"
#include "src/movement/tracker/arduinoTracker.hpp"
#include "src/movement/motor/arduinoMotor.hpp"
#include "src/movement/position/arduinoGridPosition.hpp"
#include "src/movement/position/coordinate.hpp"
#include "src/movement/motionName.hpp"
#include "src/movement/linePilot.hpp"

ArduinoTracker tracker{A1, A2, A3};
ArduinoTimer timer{};
ArduinoMotor motor{4, 6, 3, 5};
ArduinoGridPosition position(Coordinate( 3, 1), Direction::negativeX);
Coordinate goal{ 1, 0 };
LinePilot pilot(goal, position, tracker, timer, motor);

void setup() {
    tracker.setup();
    motor.setup();
    pilot.changeMotion( MotionName::followLine );
}

void loop() {
    pilot.move();
}
