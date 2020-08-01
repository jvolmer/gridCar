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
ArduinoGridPosition position(Coordinate(0,0), Direction::positiveY);
Coordinate goal{ 0, 2 };
LinePilot pilot(goal, position, tracker, timer, motor);

void setup() {
    tracker.setup();
    motor.setup();
    pilot.changeMotion( MotionName::turnRightFromLine );
    // tracker.print();
    // motor.print();
    // position.print();    

}

void loop() {
    pilot.move();
}

// Right turn
// enum class Mode
// {
//     follow,
//     turnRight1,
//     turnRight2,
//     turnRight3,
//     stop
// };
// Mode mode = Mode::follow;

// unsigned long startRight;
// void loop() {
//     switch (mode) {
//     case Mode::follow:
//         road = steering.followLine();
//         if ( road == RoadLayout::blocked ) {
//             mode = Mode::turnRight1;
//         }
//         break;
//     case Mode::turnRight1:
//         road = tracker.checkRoad();
//         if ( road == RoadLayout::sharpLeft ){
//             startRight = millis();
//             mode = Mode::turnRight2;
//         } else {
//             motor.turnRight();
//         }
//         break;
//     case Mode::turnRight2:
//         road = tracker.checkRoad();
//         if ( millis() - startRight >= 200 ){
//             mode = Mode::turnRight3;
//         } else {
//             motor.goStraight();
//         }
//         break;
//     case Mode::turnRight3:
//         road = tracker.checkRoad();
//         if (road == RoadLayout::straight){
//             mode = Mode::follow;
//         } else {
//             motor.turnRight();
//         }
//         break;
//     default:
//         break;
//     }    
// }

