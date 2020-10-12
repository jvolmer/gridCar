#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_gridGoal

#include "src/communication/coordinateBroadcaster.hpp"
#include "src/movement/position/coordinate.hpp"
#include "src/movement/position/position.hpp"
#include "src/movement/gridGoal.hpp"
#include "test/movement/position/coordinate_ostream.hpp"
#include "test/movement/position/relativeDirection_ostream.hpp"

#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <turtle/mock.hpp>

namespace data = boost::unit_test::data;

MOCK_BASE_CLASS( MockPosition, Position )
{
    MOCK_METHOD( setLocation, 1 );
    MOCK_METHOD( setDirection, 1 );
    MOCK_METHOD( turnLeft, 0 );
    MOCK_METHOD( turnRight, 0 );
    MOCK_METHOD( moveForward, 0 );
    MOCK_METHOD( isLocatedAt, 1 );
    MOCK_METHOD( turningAngleToReach, 1 );
};

MOCK_BASE_CLASS( MockGoalBroadcaster, CoordinateBroadcaster )
{
    MOCK_METHOD( broadcast, 1 );
    MOCK_METHOD( subscribe, 1 );
};


BOOST_AUTO_TEST_CASE( listens_to_broadcaster )
{
    GridGoal goal{ Coordinate(1, 1) };
    MockGoalBroadcaster broadcaster;

    MOCK_EXPECT( broadcaster.subscribe ).once();

    goal.listenTo( broadcaster );
}

BOOST_AUTO_TEST_CASE( sets_goal )
{
    GridGoal goal{ Coordinate(8, 5) };
    
    Coordinate newCoordinate{ 1, 4 };
    goal.set( newCoordinate );

    BOOST_TEST( goal.get() == newCoordinate );
}

BOOST_AUTO_TEST_CASE( does_not_set_goal_when_goal_is_outside_of_boundary )
{
    GridGoal goal{ Coordinate(8, 3) };
    Coordinate oldCoordinate = goal.get();
    
    goal.set( Coordinate(1, 4) );

    BOOST_TEST( goal.get() == oldCoordinate );
}

BOOST_AUTO_TEST_SUITE( relative_direction )

BOOST_AUTO_TEST_CASE( is_at_position )
{
    GridGoal goal{ Coordinate(1,1) };
    MockPosition position;
    MOCK_EXPECT( position.isLocatedAt ).returns( true );
    
    RelativeDirection direction = goal.turningDirectionFrom( position );

    BOOST_TEST( direction == RelativeDirection::at );
}

BOOST_DATA_TEST_CASE( is_in_front_of_location_in_forward_180_degrees,
                      data::make({-89., 0., 89.}),
                      relativeAngle )
{
    GridGoal goal{ Coordinate(1,1) };
    MockPosition position;
    MOCK_EXPECT( position.isLocatedAt ).returns( false);
    MOCK_EXPECT( position.turningAngleToReach ).returns( relativeAngle);
    
    RelativeDirection direction = goal.turningDirectionFrom( position );

    BOOST_TEST( direction == RelativeDirection::inFront );
}

BOOST_DATA_TEST_CASE( is_on_the_left_of_location_in_back_left_90_degrees,
                      data::make({90., 135., 179.}),
                      relativeAngle )
{
    GridGoal goal{ Coordinate(1,1) };
    MockPosition position;
    MOCK_EXPECT( position.isLocatedAt ).returns( false);
    MOCK_EXPECT( position.turningAngleToReach ).returns( relativeAngle);
    
    RelativeDirection direction = goal.turningDirectionFrom( position );

    BOOST_TEST( direction == RelativeDirection::onTheLeft );
}

BOOST_DATA_TEST_CASE( is_on_the_right_of_location_in_back_right_90_degrees,
                      data::make({-90., -135., -179.}),
                      relativeAngle )
{
    GridGoal goal{ Coordinate(1,1) };
    MockPosition position;
    MOCK_EXPECT( position.isLocatedAt ).returns( false);
    MOCK_EXPECT( position.turningAngleToReach ).returns( relativeAngle);
    
    RelativeDirection direction = goal.turningDirectionFrom( position );

    BOOST_TEST( direction == RelativeDirection::onTheRight );
}

BOOST_DATA_TEST_CASE( is_exactly_behind_location,
                      data::make({180., -180.}),
                      relativeAngle )
{
    GridGoal goal{ Coordinate(1,1) };
    MockPosition position;
    MOCK_EXPECT( position.isLocatedAt ).returns( false);
    MOCK_EXPECT( position.turningAngleToReach ).returns( relativeAngle);
    
    RelativeDirection direction = goal.turningDirectionFrom( position );

    BOOST_TEST( direction == RelativeDirection::exactlyBehind );
}

BOOST_AUTO_TEST_SUITE_END()
