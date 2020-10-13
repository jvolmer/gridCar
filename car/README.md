# Car Code

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

Compile the program with entry point car.ino to bin/car.hex
```bash
make
```

(Compile and) Upload the program to Arduino:
```bash
make upload
```
