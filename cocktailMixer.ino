#include "src/timer/arduinoTimer.hpp"
#include "src/movement/tracker/arduinoTracker.hpp"
#include "src/movement/motor/arduinoMotor.hpp"
#include "src/movement/position/gridPosition.hpp"
#include "src/movement/position/coordinate.hpp"
#include "src/movement/motion/motionName.hpp"
#include "src/movement/linePilot.hpp"
#include "src/movement/gridGoal.hpp"
#include "src/communication/arduinoTransmitter.hpp"
#include "src/communication/messageIn.hpp"
#include "src/communication/messageOut.hpp"
#include <SPI.h>
#include <RF24.h>

ArduinoTracker tracker{A1, A2, A3};
ArduinoTimer timer{};
ArduinoMotor motor{4, 6, 3, 5};

RF24 radio{9, 10};
const unsigned char address[5] = {'C', 'a', 'r', '0', '1'};
ArduinoTransmitter transmitter{ address, radio };
MessageOut messageOut{ transmitter };
MessageIn messageIn{ transmitter };

GridPosition position;
GridGoal goal{ Coordinate(3, 2) };
LinePilot pilot(goal, position, tracker, timer, motor);

void setup() {
    transmitter.setup();
    tracker.setup();
    motor.setup();

    motor.setDefaultSpeed( 100 );
    pilot.setAlignmentPeriodInTurn( 100 );

    position.setLocation( Coordinate(0, 0) );
    position.setDirection( Direction::positiveY );
    goal.set( Coordinate(2, 1) );
    pilot.changeMotion( MotionName::stop );
    
    goal.listenTo( messageIn );
    messageOut.listenTo( position );
}

void loop() {
    messageIn.receive();
    pilot.move();
    messageOut.supplyForNextReception();
}
