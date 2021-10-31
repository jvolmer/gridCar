#ifndef MOTION_NAME_H
#define MOTION_NAME_H

enum class MotionName
{
    cross,
    followLine,
    centerInRightTurn,
    leaveOriginLineInRightTurn,
    findNextLineInRightTurn,
    centerInLeftTurn,
    leaveOriginLineInLeftTurn,
    findNextLineInLeftTurn,
    centerInTurnAround,
    leaveOriginLineInTurnAround,
    findNextLineInTurnAround,
    leaveNextLineInTurnAround,
    findNextToNextLineInTurnAround,
    stopFinally
};

#endif
