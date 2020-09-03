#include "src/communication/arduinoTransmitter.hpp"
#include "src/communication/messageToCar.hpp"
#include "src/communication/messageFromCar.hpp"
#include "src/movement/position/coordinate.hpp"
#include <SPI.h>
#include <RF24.h>

RF24 radio{9, 10};
const unsigned char address[5] = {'C', 'a', 'r', '0', '1'};
ArduinoTransmitter transmitter{ address, radio };

Coordinate send{ 1, 0 };
Coordinate received{ 0, 0 };

MessageFromCar messageOut{ transmitter };
MessageToCar messageIn{ transmitter };

void setup() {
    Serial.begin(9600);
    transmitter.setup();
}

void loop() {
    messageOut.updateLocation( send );
    messageOut.supplyForNextReception();
    received = messageIn.receive();
    
    Serial.print(received.getx());
    Serial.print(", ");
    Serial.print(received.gety());
    Serial.println();

}
