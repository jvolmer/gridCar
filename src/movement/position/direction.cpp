#include "direction.hpp"

Direction operator+(const Direction& direction, const int number)
{
    return (Direction)(((int)direction + number) % 4);
}

Direction operator-(const Direction& direction, const int number)
{
    int diff = (int)direction - number;
    if (diff < 0) {
        int negativeDiffQuaterInt = (int)(-diff / 4);
        return (Direction)(diff + 4 * (negativeDiffQuaterInt + 1));
    } else {
        return (Direction)diff;
    }
}
