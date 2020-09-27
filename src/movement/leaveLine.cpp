#include "leaveLine.hpp"

LeaveLine::LeaveLine()
{}

void LeaveLine::move()
{
    turn();
    if ( hasLeft() )
    {
        changeMotion();
    }
}
