# Cocktail-Mixer Code

This is code for the cocktail-mixer.

Right now this includes the code for the self-driving Freenove-4WD-Car that is controlled by an Arduino. This car is supposed to transport a cocktail glass and to drive between filling stations to fill the glas. The car gets its commands via radio from another Arduino board.

## Setting prerequisites:
- the floor on which the car travels is a perpendicular grid of black lines. The car gets its travel commands in the form of points on that grid.

## Software - Prerequisites:
- Arduino-IDE

or

- Arduino-Tools (installing the Arduino-IDE will install all of this)
- [GNU make](https://www.gnu.org/software/make/manual/make.html)
- g++ Compiler (for at least c++14)
- Precompiled Arduino Core Library (can be done by yourself using the Arduino-Tools, I will upload a Makefile in a short while)

For tests to work:
- [Boost.Test](https://www.boost.org/doc/libs/1_66_0/libs/test/doc/html/index.html)
- [Turtle](http://turtle.sourceforge.net)

## Usage when not using the IDE:
Run tests:
```bash
make test
```

Compile the program with entry point cocktailMixer.ino to bin/cocktailMixer.hex
```bash
make
```

(Compile and) Upload the program to Arduino:
```bash
make upload
```
