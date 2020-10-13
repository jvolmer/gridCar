#include <SPI.h>
#include <RF24.h>


#define CE_PIN   9
#define CSN_PIN 10


struct Coordinate{
    int x;
    int y;
};

RF24 radio(CE_PIN, CSN_PIN);

const byte car_address[5] = {'C','a','r','0','1'};
Coordinate goal_for_car = {0, 0};
Coordinate boundary = {2,3};

const unsigned long tx_interval_millis = 100; // send once per second
unsigned long prev_millis = 0;

const byte numChars = 10;
char receivedChars[numChars];

//===============

void setup() {

    Serial.begin(9600);

    radio.begin();
    radio.setPALevel(RF24_PA_MAX);
    // radio.setDataRate(RF24_1MBPS);
    radio.setDataRate(RF24_250KBPS);
  
    radio.enableAckPayload();

    radio.setRetries(5,5); // delay, count
}

void loop() {
    unsigned long current_millis;
    current_millis = millis();

    bool receivedNewGoal = receiveGoalFromSerialInput();
    if (receivedNewGoal == true){
        Coordinate goalFromInput = parseInput(receivedChars);
        if (coordinateIsInsideBoundary(goalFromInput)) {
            goal_for_car = goalFromInput;
        }
    }
    
    if (current_millis - prev_millis >= tx_interval_millis) {
        send_and_receive();
        prev_millis = current_millis;
    }
}

//================

Coordinate old_car_reply = {44,44};
Coordinate old_goal_for_car = {48,11};

void send_and_receive() {
    unsigned long before_transmission;
    unsigned long duration_of_one_transmission;
    Coordinate car_reply_raw, car_reply;
    radio.openWritingPipe(car_address);
        
    bool delivered_data_successfully;
    delivered_data_successfully = radio.write( &goal_for_car, sizeof(goal_for_car) );
    
    if (delivered_data_successfully) {
        if ( radio.isAckPayloadAvailable() ) {
            
            radio.read(&car_reply_raw, sizeof(car_reply_raw));
            if (coordinateIsInsideBoundary(car_reply_raw)) {
                car_reply = car_reply_raw;
            }
            
            if (car_reply.x != old_car_reply.x ||
                car_reply.y != old_car_reply.y ) {
                printMessageFromCar(car_reply);
            }
            old_car_reply = car_reply;
            
        }
        else {
            Serial.println("  No reply");
        }
    }
    else {
        // Serial.println("  Sending failed");
    }

    if (goal_for_car.x != old_goal_for_car.x ||
        goal_for_car.y != old_goal_for_car.y) {
        printMessageToCar(goal_for_car);
    }
    old_goal_for_car = goal_for_car;

    
}


//=================

void printMessageToCar(Coordinate message){
    Serial.print("  Position sent: (");
    Serial.print(message.x);
    Serial.print(", ");
    Serial.print(message.y);
    Serial.println(")");
}

void printMessageFromCar(Coordinate message){
    Serial.print("  Position received: (");
    Serial.print(message.x);
    Serial.print(", ");
    Serial.print(message.y);
    Serial.println(")");
}

bool coordinateIsInsideBoundary(Coordinate coordinate){
    return
        coordinate.x <= boundary.x &&
        coordinate.y <= boundary.y &&
        coordinate.x >= 0 &&
        coordinate.y >= 0;
}

//=================

bool receiveGoalFromSerialInput() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '(';
    char endMarker = ')';
    char rc;

    if (Serial.available() > 0) {
        rc = Serial.read();

        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                return true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
    return false;
}

Coordinate parseInput(const char* data) {

    Coordinate coordinate;
    char * strtokIndx;
    char tempChars[numChars];
    strcpy(tempChars, data);
            // this temporary copy is necessary to protect the original data
            //   because strtok() used in parseData() replaces the
            //   commas with \0
    
    strtokIndx = strtok(tempChars,",");
    coordinate.x = atoi(strtokIndx);

    strtokIndx = strtok(NULL, ",");
    coordinate.y = atoi(strtokIndx);
    
    return coordinate;
}
