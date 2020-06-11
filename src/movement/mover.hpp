#ifndef MOVER_H
#define MOVER_H

#include "motor/motor.hpp"
#include "tracker/tracker.hpp"
#include "coordinate.hpp"
#include "direction.hpp"

class LineFollower
{
public:
    virtual void followLine() = 0;
};
    
class Mover: public LineFollower
{
private:
    Motor& _motor;
    Tracker& _tracker;
    Coordinate _position { Coordinate(0,0) };
    Direction _direction { Direction::positiveX };
    
public:
    Mover(Motor& motor, Tracker& tracker);
    void setPosition(const Coordinate& position) { _position = position; }
    void setDirection(const Direction& direction) { _direction = direction; }
    void setPosition(Coordinate&& position) { _position = position; }
    void setDirection(Direction&& direction) { _direction = direction; }
    const Coordinate& getPosition() const { return _position; }
    const Direction& getDirection() const { return _direction; }

    void followLine() override;
    void followLineUntilCrossing();
    void followLineUntilCrossingCount(int count);
    void turnRightAtCrossing();
    void turnLeftAtCrossing();
};

#endif
