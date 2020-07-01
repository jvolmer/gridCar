#include "motor/motor.hpp"
#include "tracker/tracker.hpp"
#include "tracker/roadLayout.hpp"
#include "position/position.hpp"
#include "position/coordinate.hpp"
#include "lineSteering.hpp"

LineSteering::LineSteering(Position& position, Motor& motor, Tracker& tracker) :
    _position { position },
    _motor { motor },
    _tracker { tracker }
{}

void LineSteering::turnRightUpToNextCrossLine()
{
    _motor.turnRight();
    if (_tracker.checkRoad() == RoadLayout::blocked) {
        _motor.stop();
        _position.turnRight();
    }
}

RoadLayout LineSteering::turnLeftUpToNextCrossLine()
{
    RoadLayout road = _tracker.checkRoad();
    switch( road )
    {
    case RoadLayout::none:
    case RoadLayout::blocked:
    case RoadLayout::sharpRight:
    case RoadLayout::right:
    case RoadLayout::straight:
    case RoadLayout::enclosed:
        _motor.turnLeft();
        break;
    case RoadLayout::sharpLeft:
    case RoadLayout::left:
        _motor.stop();
        break;
    default:
        break;
    }
    return road;
    // _motor.turnLeft();
    // if (_tracker.checkRoad() == RoadLayout::blocked) {
    //     _motor.stop();
    //     _position.turnLeft();;
    // }
}

RoadLayout LineSteering::followLine()
{
    RoadLayout road = _tracker.checkRoad();
    switch( road )
    {
    case RoadLayout::none:
    case RoadLayout::blocked:
        _motor.stop();
        break;
    case RoadLayout::sharpRight:
    case RoadLayout::right:
        _motor.turnRight();
        break;
    case RoadLayout::straight:
    case RoadLayout::enclosed:
        _motor.goStraight();
        break;
    case RoadLayout::sharpLeft:
    case RoadLayout::left:
        _motor.turnLeft();
        break;
    default:
        break;
    }
    return road;
}

RoadLayout LineSteering::goStraightToNextLine()
{
    RoadLayout road = _tracker.checkRoad();
    switch( road )
    {
    case RoadLayout::none:
        _motor.goStraight();
    case RoadLayout::blocked:
    case RoadLayout::sharpRight:
    case RoadLayout::right:
    case RoadLayout::straight:
    case RoadLayout::enclosed:
    case RoadLayout::sharpLeft:
    case RoadLayout::left:
        _motor.stop();
        break;
    default:
        break;
    }
    return road;
}

void LineSteering::followLineUpTo(const Coordinate& coordinate)
{
    followLine();
    if (_tracker.checkRoad() == RoadLayout::blocked) {
        _position.moveForward();
        // if ( _position.isLocatedAt(coordinate) )
        // {
        //     _motor.stop();
        // }
        // else
        // {
        //     _motor.goStraight();
        // }
    }
}

void LineSteering::navigateOnLineTo(const Coordinate& coordinate)
{
    switch ( _position.getTurnTrendToReach(coordinate) )
    {
    case -1:
        turnLeftUpToNextCrossLine();
        break;
    case 1:
        turnRightUpToNextCrossLine();
        break;
    default:
        break;
    }

    // TODO: what happens when coordinate is not on line?
    //       right now: goes on forever
    //       better: if x or y is same as coordinate
    followLineUpTo(coordinate);
}
