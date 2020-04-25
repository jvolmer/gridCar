#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>

class Coordinate
{
private:
    float x_in_mm;
    float y_in_mm;

public:
    Coordinate(float x_in_mm, float y_in_mm);
    void print() const;

    Coordinate& operator= (const Coordinate& point);
    friend bool operator== (const Coordinate& lhs, const Coordinate& rhs);
    friend std::ostream& operator<< (std::ostream& out, const Coordinate& point);
    float getx() const { return x_in_mm; }
    float gety() const { return y_in_mm; }
};

    
#endif
