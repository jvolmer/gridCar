#include "src/communication/arduinoTransmitter.hpp"
#include "src/movement/position/coordinate.hpp"
#include <SPI.h>
#include <RF24.h>

RF24 radio{9, 10};
const unsigned char address[5] = {'C', 'a', 'r', '0', '1'};
ArduinoTransmitter transmitter{ address, radio };

Coordinate coordinate{ 1, 0 };
Coordinate received{0, 0};

void setup() {
    Serial.begin(9600);
    transmitter.setup();
}

void loop() {
    transmitter.setReply(coordinate);
    transmitter.replyToReception(received);
    Serial.print(coordinate.getx());
    Serial.print(", ");
    Serial.print(coordinate.gety());
    Serial.println();

}
