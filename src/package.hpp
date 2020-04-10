#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>

class Point
{
private:
    float x_in_mm;
    float y_in_mm;
    
public:
    Point(float x, float y);
    void print() const;

    Point& operator= (const Point& point);
    friend bool operator== (const Point& lhs, const Point& rhs);
    friend std::ostream& operator<< (std::ostream& out, const Point& point);
    float getx() const { return x_in_mm; }
    float gety() const { return y_in_mm; }
};

class PackageToCar
{
private:
    Point goal;

public:
    PackageToCar();
    PackageToCar(Point goal);
    Point* getGoal() { return &goal; };
    friend bool operator== (const PackageToCar& lhs, const PackageToCar& rhs);
    friend std::ostream& operator<< (std::ostream& out, const PackageToCar& package);
};

class PackageFromCar
{
private:
    Point position;
    float scale_value_in_g;
    float battery_charge_in_percent;

public:
    PackageFromCar();
    PackageFromCar(const Point& position, float scale, float battery_charge);
    void print() const;
    friend bool operator== (const PackageFromCar& lhs, const PackageFromCar& rhs);
};
    

#endif
