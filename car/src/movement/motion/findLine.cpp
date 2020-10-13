#include "findLine.hpp"

FindLine::FindLine()
{}

void FindLine::move()
{
    turn();
    if ( hasFound() )
    {
        updatePosition();
        changeMotion();
    }
}
