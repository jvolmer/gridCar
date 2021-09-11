# GridCar [![Build](https://github.com/jvolmer/gridCar/actions/workflows/build.yml/badge.svg)](https://github.com/jvolmer/gridCar/actions/workflows/build.yml) [![Code Coverage](https://codecov.io/gh/jvolmer/gridCar/branch/main/graph/badge.svg)](https://codecov.io/gh/jvolmer/gridCar)

> Autonomous car navigates to any point on a grid

## Background

Exact localization in a small area of space can be difficult. This autonomous car orients itself on a grid of lines and can be send to any of the grid's line-crossings. It receives its destination via radio signal. It sends out its own location via radio signal as well.

Check out [this video](https://nc.nullteilerfrei.de/index.php/s/nyYEFXyPgEe5ZH5) to see the car in action.

This localization approach comes with some challenges:
* The car has no external reference points, it knows its location and direction only due to counting crossings and turns. Therefore this counting has to be done precisely. For that, I tuned parameters and made sure that the exectuation of any code-part does not block the car detectors from measuring frequently.
* Turning at a crossing involves several different car motions. I tried out several ideas before arriving at the best sequence of motions.

To make the implementation robust, the code is based on three design principles:
* Domain Driven Design: The code includes as many domain knowledge as possible to make the code easy and intuitive to read.
* Test Driven Design: All non Arduino-specific code is covered by unit tests and a few integration tests, to make sure that everything works as expected after changing something in the code.
* Design Patterns: Design patterns are used where appropriate to make the code more readable and effective: The _state pattern_ is used for the movements of the car (movement states are for example go straight, stopped or different turning states). With the _observer pattern_ the car listens to the incoming radio signals and notifies the car of changes, such that it can adapt its driving direction. The car also listens to changes in its own location. This change happens when the car arrives at a crossing. It then notifies its communication unit which sends this location via radio out.

## Code Structure

This repository includes code for two devices: 
1. the car,
2. the control which sends destinations to the car and receives the car's locations.

The main focus of this repository is the car, most of the code is writte for it and its main entry point is [gridCar.ino](gridCar.ino).

The control directory includes code for the control. This code has no structure and is written with the only purpose that the car code is working as intended.

## Hardware Setup

The code is written for Arduino Uno boards, one for the car, one for the control. 

For the car I used a Freenove-4WD-Car which is controlled by one of the Arduinos, but any other car can be used - with possibly slight modifications parameters and ping numbers. The Arduino is connected to an RF24 radio chip to be able to send and receive radio signals.

The control is an Arduino Uni board with an RF24 radio chip as well. You can connect this board to a computer and send destination coordinates via Serial input very easily from within the Arduino IDE.

## Usage

Then you can build the car executable with
```bash
cmake --build build/
```

Upload the car program to the Arduino via
```bash
cmake --build build/ --target upload
```

Upload the car code to the car and the control code to the control unit (with `cmake --build build/ --target upload_control`). Set the car onto a crossing point on the grid and switch it on. Now you can send coordinates via Serial input in the format `(x,y)` from the control to the car. Be aware that these coordinates are relative to the starting position of the car.

### Tests
All non Arduino-specific car code is covered by unit tests and a few integration tests. Run all tests with
```bash
cmake --build build/ --target test
```

## Install
### Prerequisites
These are the prerequisites you need to install in order to build the program:
* [Arduino CLI](https://arduino.github.io/arduino-cli/0.19/installation/)
* [Conan.io](https://docs.conan.io/en/latest/installation.html)
* [cmake 3.13+](https://cmake.org/download/)
* C++ compiler, e.g. GNU C++ Compiler g++

## Installation and Configuration
Inside the project directory, install the dependencies:
```bash
conan install -if build .
```

Configure the build system:
```bash
cmake -S . -B build
```

Configure Arduino (install required packages via the Arduino CLI)
```bash
 cmake --build build --target configure
 ```


