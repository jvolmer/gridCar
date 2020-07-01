#ifndef MOVER_H
#define MOVER_H

#include "motor/motor.hpp"
#include "tracker/tracker.hpp"
#include "position/position.hpp"
#include "position/coordinate.hpp"

class LineFollower
{
public:
    virtual RoadLayout followLine() = 0;
};
    
class LineSteering : public LineFollower
{
private:
    Position& _position;
    Motor& _motor;
    Tracker& _tracker;
    
public:
    LineSteering(Position& position, Motor& motor, Tracker& tracker);

    RoadLayout followLine() override;
    void followLineUpTo(const Coordinate& coordinate);
    void turnRightUpToNextCrossLine();
    RoadLayout turnLeftUpToNextCrossLine();
    void navigateOnLineTo(const Coordinate& coordinate);

    RoadLayout goStraightToNextLine();
};

#endif
