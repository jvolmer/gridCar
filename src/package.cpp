#include "package.hpp"
#include <stdio.h>
#include <math.h>

Point::Point(float x, float y):
    x_in_mm { x },
    y_in_mm { y }
{
}

void Point::print() const
{
    printf("(%fmm, %fmm)\n", x_in_mm, y_in_mm);
}

Point& Point::operator= (const Point& point)
{
    if (this == &point)
        return *this;
    x_in_mm = point.x_in_mm;
    y_in_mm = point.y_in_mm;
    return *this;
}

std::ostream& operator<< (std::ostream& out, const Point& point)
{
    return out << "(" << point.x_in_mm << "mm, " << point.y_in_mm << "mm)";
}


bool operator== (const Point& lhs, const Point& rhs)
{
    return (fabs(lhs.x_in_mm - rhs.x_in_mm) < 1E-6)
        && (fabs(lhs.y_in_mm - rhs.y_in_mm) < 1E-6);
}


PackageToCar::PackageToCar(Point goal) :
    goal { goal }
{}

PackageToCar::PackageToCar() :
    goal {Point(0,0)}
{}

bool operator== (const PackageToCar& lhs, const PackageToCar& rhs)
{
    return (lhs.goal == rhs.goal);
}

std::ostream& operator<< (std::ostream& out, const PackageToCar& package)
{
    return out << package.goal;
}


PackageFromCar::PackageFromCar():
    position { Point(0,0) },
    scale_value_in_g { 0 },
    battery_charge_in_percent { 0 }
{}

PackageFromCar::PackageFromCar(const Point& position, float weight, float battery_charge):
    position { position },
    scale_value_in_g { weight },
    battery_charge_in_percent { battery_charge }
{
}

void PackageFromCar::print() const
{
    printf("[ (%fmm, %fmm), %fg, %f%% ]\n", position.getx(), position.gety(), scale_value_in_g, battery_charge_in_percent);
}

bool operator== (const PackageFromCar& lhs, const PackageFromCar& rhs)
{
    return (lhs.position == rhs.position)
        && (fabs(lhs.scale_value_in_g - rhs.scale_value_in_g) < 1E-6)
        && (fabs(lhs.battery_charge_in_percent - rhs.battery_charge_in_percent) < 1E-6);
}
