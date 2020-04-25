#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate
{
private:
    float _x_in_mm;
    float _y_in_mm;

public:
    Coordinate(float x_in_mm, float y_in_mm);

    Coordinate& operator= (const Coordinate& point);
    float getx() const { return _x_in_mm; }
    float gety() const { return _y_in_mm; }
};

    
#endif
