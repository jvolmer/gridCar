#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_coordinate

#include "src/movement/coordinate.hpp"
#include "src/movement/direction.hpp"
#include "test/movement/coordinate_ostream.hpp"
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE( createsCoordinateOutOfADirection )
{
    BOOST_TEST( Coordinate(Direction::positiveX) == Coordinate(1,0) );
    BOOST_TEST( Coordinate(Direction::positiveY) == Coordinate(0,1) );
    BOOST_TEST( Coordinate(Direction::negativeX) == Coordinate(-1,0) );
    BOOST_TEST( Coordinate(Direction::negativeY) == Coordinate(0,-1) );
}

BOOST_AUTO_TEST_CASE( addsCoordinates )
{
    BOOST_TEST( Coordinate(1,0) + Coordinate(3,-1) == Coordinate(4,-1) );
}

BOOST_AUTO_TEST_CASE( subtractsCoordinates )
{
    BOOST_TEST( Coordinate(3,6) - Coordinate(2,1) == Coordinate(1,5) );
}
