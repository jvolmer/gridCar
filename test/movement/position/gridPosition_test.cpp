#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_gridPosition

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

namespace data = boost::unit_test::data;

MOCK_BASE_CLASS( MockLocationListener, CoordinateListener )
{
    MOCK_METHOD( listenTo, 1 );
    MOCK_METHOD( update, 1 );
};

BOOST_AUTO_TEST_SUITE( relative_direction )

BOOST_AUTO_TEST_CASE( position_is_at_coordinate )
{
    GridPosition position = GridPosition(Coordinate(1,1), Direction::positiveX);
    Coordinate coordinate{ 1, 1 };

    RelativeDirection direction = position.relativeDirectionToReach( coordinate );

    BOOST_TEST( direction == RelativeDirection::at );
}

BOOST_DATA_TEST_CASE( coordinate_in_forward_180_degrees_without_boundaries_is_in_front_of_position,
                      data::make({Coordinate(1, -1),
                                  Coordinate(1, 0),
                                  Coordinate(1, 1)}),
                      coordinate )
{
    GridPosition position = GridPosition(Coordinate(0,0), Direction::positiveX);

    RelativeDirection direction = position.relativeDirectionToReach( coordinate );

    BOOST_TEST( direction == RelativeDirection::inFront );
}

BOOST_DATA_TEST_CASE( coordinate_in_back_left_90_degrees_with_left_boundary_is_on_the_left_of_position,
                      data::make({Coordinate(0, 1),
                                  Coordinate(-1, 1),
                                  Coordinate(-2, 1)}),
                      coordinate )
{
    GridPosition position = GridPosition(Coordinate(0,0), Direction::positiveX);

    RelativeDirection direction = position.relativeDirectionToReach( coordinate );

    BOOST_TEST( direction == RelativeDirection::onTheLeft );
}

BOOST_DATA_TEST_CASE( coordinate_in_back_right_90_degrees_with_right_boundary_is_on_the_right_of_position,
                      data::make({Coordinate(-2, -1),
                                  Coordinate(-1, -1),
                                  Coordinate(0, -1)}),
                      coordinate )
{
    GridPosition position = GridPosition(Coordinate(0,0), Direction::positiveX);

    RelativeDirection direction = position.relativeDirectionToReach( coordinate );

    BOOST_TEST( direction == RelativeDirection::onTheRight );
}

BOOST_DATA_TEST_CASE( coordinate_is_exctly_behind_position,
                      data::make({Coordinate(-1, 0),
                                  Coordinate(-2, 0),
                                  Coordinate(-10, 0)}),
                      coordinate )
{
    GridPosition position = GridPosition(Coordinate(0,0), Direction::positiveX);

    RelativeDirection direction = position.relativeDirectionToReach( coordinate );

    BOOST_TEST( direction == RelativeDirection::exactlyBehind );
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
