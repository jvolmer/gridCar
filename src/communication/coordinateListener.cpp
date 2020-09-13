#include "coordinateBroadcaster.hpp"
#include "coordinateListener.hpp"

void CoordinateListener::listenTo(CoordinateBroadcaster& broadcaster)
{
    broadcaster.subscribe( this );
}
