#ifndef DIRECTION_H
#define DIRECTION_H

enum class Direction
{
    positiveX = 0,
    negativeY = 1,
    negativeX = 2,
    positiveY = 3
};

Direction operator+(const Direction& direction, const int number);
Direction operator-(const Direction& direction, const int number);

#endif
