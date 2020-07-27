#include "pilot.hpp"
#include "position/position.hpp"
#include "motor/motor.hpp"
#include "followLine.hpp"

FollowLine::FollowLine(Pilot& pilot, Position& position, Motor& motor):
    _pilot { pilot },
    _position { position },
    _motor { motor }
{}

void FollowLine::move()
{
    _motor.goStraight();
}
