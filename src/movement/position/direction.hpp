#ifndef DIRECTION_H
#define DIRECTION_H

enum class Direction
{
    positiveX = 0,
    positiveY = 1,
    negativeX = 2,
    negativeY = 3
};

Direction operator+(const Direction& direction, const int number);
Direction operator-(const Direction& direction, const int number);

#endif
