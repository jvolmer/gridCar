#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_mover

#include "src/movement/position/position.hpp"
#include "src/movement/motor/motor.hpp"
#include "src/movement/tracker/tracker.hpp"
#include "src/movement/tracker/roadLayout.hpp"
#include "src/movement/lineSteering.hpp"
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <turtle/mock.hpp>

namespace data = boost::unit_test::data;

MOCK_BASE_CLASS( MockPosition, Position )
{
    MOCK_METHOD( turnLeft, 0 );
    MOCK_METHOD( turnRight, 0 );
    MOCK_METHOD( moveForward, 0 );
    MOCK_METHOD( isLocatedAt, 1 );
    MOCK_METHOD( getTurnTrendToReach, 1 );
};

MOCK_BASE_CLASS( MockMotor, Motor )
{
    MOCK_METHOD( setup, 0 );
    MOCK_METHOD( turnRight, 0 );
    MOCK_METHOD( turnLeft, 0 );
    MOCK_METHOD( goStraight, 0 );
    MOCK_METHOD( stop, 0 );
};

MOCK_BASE_CLASS( MockTracker, Tracker )
{
    MOCK_METHOD( checkRoad, 0 );
    MOCK_METHOD( setup, 0 );
};

BOOST_AUTO_TEST_CASE( turns_right_up_to_next_cross_line )
{
    MockPosition position;
    MockMotor motor;
    MockTracker tracker;
    LineSteering mover(position, motor, tracker);
    
    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::blocked );
    MOCK_EXPECT( motor.turnRight ).once();
    MOCK_EXPECT( motor.stop ).once();
    MOCK_EXPECT( position.turnRight ).once();
    
    mover.turnRightUpToNextCrossLine();
}

BOOST_AUTO_TEST_CASE( turns_left_up_to_next_cross_line )
{
    MockPosition position;
    MockMotor motor;
    MockTracker tracker;
    LineSteering mover(position, motor, tracker);
    
    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::blocked );
    MOCK_EXPECT( motor.turnLeft ).once();
    MOCK_EXPECT( motor.stop ).once();
    MOCK_EXPECT( position.turnLeft ).once();

    mover.turnLeftUpToNextCrossLine();
}

BOOST_AUTO_TEST_SUITE( followsLine )

// BOOST_DATA_TEST_CASE( turns_left_when_is_too_far_right,,
//                       data::make({Direction::positiveX, Direction::negativeY, Direction::negativeX, Direction::positiveY}) ^
//                       data::make({Direction::negativeY, Direction::negativeX, Direction::positiveY, Direction::positiveX}),
//                       directionIn,
//                       directionOut )
BOOST_AUTO_TEST_CASE( turns_left_when_is_too_far_right )
{
    MockPosition position;
    MockMotor motor;
    MockTracker tracker;
    LineSteering mover(position, motor, tracker);

    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::sharpLeft );
    MOCK_EXPECT( motor.turnLeft ).once();
    
    mover.followLine();    
}

BOOST_AUTO_TEST_CASE( stops_when_no_line_is_there )
{
    MockPosition position;
    MockMotor motor;
    MockTracker tracker;
    LineSteering mover(position, motor, tracker);

    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::none );
    MOCK_EXPECT( motor.stop ).once();

    mover.followLine();
}

BOOST_AUTO_TEST_SUITE_END()
    
BOOST_AUTO_TEST_SUITE( follows_line_up_to_given_coordinate )

BOOST_AUTO_TEST_CASE( stops_at_given_coordinate )
{
    Coordinate givenCrossing = Coordinate(1,0);
    
    MockPosition position;
    MockMotor motor;
    MockTracker tracker;
    LineSteering mover(position, motor, tracker);

    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::blocked );
    MOCK_EXPECT( position.moveForward ).once();
    MOCK_EXPECT( position.isLocatedAt ).returns( true );
    MOCK_EXPECT( motor.stop ).at_least( 1 );

    mover.followLineUpTo( givenCrossing );
}


BOOST_AUTO_TEST_CASE( goes_on_at_crossing_when_given_coordinate_not_reached_yet ) 
{
    Coordinate givenCrossing = Coordinate(1,0);
    
    MockPosition position;
    MockMotor motor;
    MockTracker tracker;
    LineSteering mover(position, motor, tracker);

    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::blocked );
    MOCK_EXPECT( position.moveForward ).once();
    MOCK_EXPECT( position.isLocatedAt ).returns( false );
    mock::sequence sequence;
    MOCK_EXPECT( motor.stop ).in( sequence );
    MOCK_EXPECT( motor.goStraight ).once().in( sequence );

    mover.followLineUpTo( givenCrossing );
}

BOOST_AUTO_TEST_SUITE_END()
    
BOOST_AUTO_TEST_SUITE( navigates_on_line_to_given_coordinate )

BOOST_AUTO_TEST_CASE( turns_when_not_heading_towards_coordinate )
{
    Coordinate givenCrossing = Coordinate(1,0);
    
    MockPosition position;
    MockMotor motor;
    MockTracker tracker;
    LineSteering mover(position, motor, tracker);

    MOCK_EXPECT( position.getTurnTrendToReach ).returns( -1 );
    MOCK_EXPECT( position.turnLeft ).once();
    MOCK_EXPECT( motor.turnLeft ).once();

    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::blocked );
    MOCK_EXPECT( position.isLocatedAt ).returns(false);
    MOCK_EXPECT( motor.stop );
    MOCK_EXPECT( motor.goStraight );
    MOCK_EXPECT( position.moveForward );
    
    mover.navigateOnLineTo( givenCrossing );    
}

BOOST_AUTO_TEST_CASE( does_not_turn_when_already_heading_towards_coordinate )
{
    Coordinate givenCrossing = Coordinate(1,0);
    
    MockPosition position;
    MockMotor motor;
    MockTracker tracker;
    LineSteering mover(position, motor, tracker);

    MOCK_EXPECT( position.getTurnTrendToReach ).returns( 0 );
    MOCK_EXPECT( position.turnLeft ).never();
    MOCK_EXPECT( motor.turnLeft ).never();
    
    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::blocked );
    MOCK_EXPECT( position.isLocatedAt ).returns(false);
    MOCK_EXPECT( motor.stop );
    MOCK_EXPECT( motor.goStraight );
    MOCK_EXPECT( position.moveForward );
    
    mover.navigateOnLineTo( givenCrossing );    
}

BOOST_AUTO_TEST_CASE( moves_forward_when_not_reached_coordinate_yet )
{
    Coordinate givenCrossing = Coordinate(1,0);
    
    MockPosition position;
    MockMotor motor;
    MockTracker tracker;
    LineSteering mover(position, motor, tracker);

    MOCK_EXPECT( position.getTurnTrendToReach ).returns( 0 );
    MOCK_EXPECT( position.isLocatedAt ).returns(false);
    MOCK_EXPECT( motor.goStraight ).once();
    MOCK_EXPECT( position.moveForward ).once();

    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::blocked );
    MOCK_EXPECT( motor.stop );
    
    mover.navigateOnLineTo( givenCrossing );    
}

BOOST_AUTO_TEST_CASE( stops_when_reached_coordinate )
{
    Coordinate givenCrossing = Coordinate(1,0);
    
    MockPosition position;
    MockMotor motor;
    MockTracker tracker;
    LineSteering mover(position, motor, tracker);

    MOCK_EXPECT( position.getTurnTrendToReach ).returns( 0 );
    MOCK_EXPECT( position.isLocatedAt ).returns( true );
    MOCK_EXPECT( motor.stop ).at_least(1);

    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::blocked );
    MOCK_EXPECT( position.moveForward );
    
    mover.navigateOnLineTo( givenCrossing );    
}

BOOST_AUTO_TEST_SUITE_END()
