#include "src/timer/arduinoTimer.hpp"
#include "src/movement/tracker/arduinoTracker.hpp"
#include "src/movement/motor/arduinoMotor.hpp"
#include "src/movement/position/arduinoGridPosition.hpp"
#include "src/movement/position/coordinate.hpp"
#include "src/movement/motionName.hpp"
#include "src/movement/linePilot.hpp"
#include "src/communication/arduinoTransmitter.hpp"
#include "src/communication/messageToCar.hpp"
#include "src/communication/messageFromCar.hpp"
#include <SPI.h>
#include <RF24.h>

ArduinoTracker tracker{A1, A2, A3};
ArduinoTimer timer{};
ArduinoMotor motor{4, 6, 3, 5};
ArduinoGridPosition position(Coordinate( 0, 0), Direction::positiveY);
Coordinate goal{ 3, 1 };

RF24 radio{9, 10};
const unsigned char address[5] = {'C', 'a', 'r', '0', '1'};
ArduinoTransmitter transmitter{ address, radio };
MessageFromCar messageOut{ transmitter };
MessageToCar messageIn{ transmitter };

LinePilot pilot(goal, position, tracker, timer, motor);

void setup() {
    transmitter.setup();
    tracker.setup();
    motor.setup();
    messageOut.listenTo( position );
    pilot.listenTo( messageIn );
    pilot.changeMotion( MotionName::followLine );
}

Coordinate someCoordinate{ 0, 0 };
void loop() {
    messageIn.receive();
    pilot.move();
    messageOut.supplyForNextReception();
}
