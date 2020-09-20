#include "coordinateListener.hpp"
#include "coordinateBroadcaster.hpp"

void CoordinateBroadcaster::subscribe(CoordinateListener* listener) {
    _listener = listener;
}

void CoordinateBroadcaster::broadcast(const Coordinate& coordinate) const {
    if (_listener)
    {
        _listener->update(coordinate);
    }
}
