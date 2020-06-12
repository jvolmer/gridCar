#include "direction.hpp"

Direction operator+(const Direction& direction, const int number)
{
    return (Direction)(((int)direction + number) % 4);
}

Direction operator-(const Direction& direction, const int number)
{
    int sum = (int)direction - number;
    if (sum < 0) {
        int integerQuotienOfSumDevidedBy4 = (int)(-sum / 4);
        return (Direction)(sum + 4*(integerQuotienOfSumDevidedBy4+1));
    } else {
        return (Direction)sum;
    }
}
