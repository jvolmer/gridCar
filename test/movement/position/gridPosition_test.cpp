#include "src/movement/position/direction.hpp"
#include "src/movement/position/coordinate.hpp"
#include "src/movement/position/gridPosition.hpp"
#include "src/movement/position/relativeDirection.hpp"
#include "src/communication/coordinateListener.hpp"
#include "direction_ostream.hpp"
#include "relativeDirection_ostream.hpp"
#include "coordinate_ostream.hpp"
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <turtle/mock.hpp>

BOOST_AUTO_TEST_SUITE( GridPositionTest )

namespace data = boost::unit_test::data;

MOCK_BASE_CLASS( MockLocationListener, CoordinateListener )
{
    MOCK_METHOD( listenTo, 1 );
    MOCK_METHOD( update, 1 );
};

BOOST_AUTO_TEST_SUITE( relative_angle )

BOOST_DATA_TEST_CASE( gives_relative_turning_angle_to_reach_coordinate,
                      data::make({Coordinate(0, 1), Coordinate(1, 0), Coordinate(0, -1), Coordinate(-1, 0)}) ^
                      data::make({0., -90., -180., 90.}),
                      coordinate, expectedAngle )
{
    GridPosition position = GridPosition(Coordinate(0,0), Direction::positiveY);

    double angle = position.turningAngleToReach( coordinate );

    BOOST_TEST( angle == expectedAngle);
}

BOOST_AUTO_TEST_SUITE_END()



BOOST_AUTO_TEST_SUITE( communication )

BOOST_AUTO_TEST_CASE( broadcasts_current_position_to_subscriber_when_subscribing )
{
    Coordinate currentPosition{ 4, 5 };
    GridPosition position = GridPosition(currentPosition, Direction::positiveX);
    MockLocationListener listener;
 
    MOCK_EXPECT( listener.update ).once().with( currentPosition );

    position.subscribe( &listener );
}

BOOST_AUTO_TEST_CASE( broadcasts_new_location_to_subscriber_after_moving_forward )
{
    Coordinate initialLocation{ 1, 2 };
    GridPosition position = GridPosition(initialLocation, Direction::positiveX);
    MockLocationListener listener;
    MOCK_EXPECT( listener.update ).once();
    position.subscribe( &listener );

    Coordinate newLocation{ 2, 2 };
    MOCK_EXPECT( listener.update ).once().with( newLocation );
    
    position.moveForward();
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
