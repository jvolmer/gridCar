#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_gridGoal

#include "src/communication/coordinateBroadcaster.hpp"
#include "src/movement/position/coordinate.hpp"
#include "test/movement/position/coordinate_ostream.hpp"
#include "src/movement/gridGoal.hpp"
#include <boost/test/unit_test.hpp>
#include <turtle/mock.hpp>

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
