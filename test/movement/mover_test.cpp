#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_mover

#include "src/movement/mover.hpp"
#include "src/movement/motor/motor.hpp"
#include "src/movement/tracker/tracker.hpp"
#include "src/movement/coordinate.hpp"
#include "src/movement/direction.hpp"
#include "src/movement/tracker/roadLayout.hpp"
#include "test/movement/coordinate_ostream.hpp"
#include "test/movement/direction_ostream.hpp"
#include <boost/test/unit_test.hpp>
#include <turtle/mock.hpp>


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

BOOST_AUTO_TEST_CASE( turnsRight )
{
    Coordinate startPosition = Coordinate(0,0);
    Direction startDirection{ Direction::positiveX};

    MockMotor motor;
    MockTracker tracker;
    Mover mover(motor, tracker);
    mover.setPosition( startPosition );
    mover.setDirection( startDirection );
    
    mock::sequence sequence;
    MOCK_EXPECT( motor.turnRight ).at_least(1).in(sequence);
    MOCK_EXPECT( tracker.checkRoad ).in(sequence).returns( RoadLayout::blocked );
    MOCK_EXPECT( motor.stop ).in(sequence);

    mover.turnRightAtCrossing();
    
    BOOST_TEST( mover.getPosition() == startPosition );
    BOOST_TEST( mover.getDirection() == Direction::negativeY );
}

BOOST_AUTO_TEST_CASE( turnsLeft )
{
    Coordinate startPosition = Coordinate(0,0);
    Direction startDirection{ Direction::positiveX };
    
    MockMotor motor;
    MockTracker tracker;
    Mover mover(motor, tracker);
    mover.setPosition( startPosition );
    mover.setDirection( startDirection );

    mock::sequence sequence;
    MOCK_EXPECT( motor.turnLeft ).at_least(1).in(sequence);
    MOCK_EXPECT( tracker.checkRoad ).in(sequence).returns( RoadLayout::blocked );
    MOCK_EXPECT( motor.stop ).in(sequence);

    mover.turnLeftAtCrossing();
    
    BOOST_TEST( mover.getPosition() == startPosition );
    BOOST_TEST( mover.getDirection() == Direction::positiveY );
}

BOOST_AUTO_TEST_CASE( turnsLeftWhenFollowsLineAndIsTooFarRight )
{
    MockMotor motor;
    MockTracker tracker;
    Mover mover(motor, tracker);

    mock::sequence sequence;
    MOCK_EXPECT( tracker.checkRoad ).in(sequence).returns( RoadLayout::sharpLeft );
    MOCK_EXPECT( motor.turnLeft ).once().in(sequence);
    
    mover.followLine();    
}

BOOST_AUTO_TEST_CASE( stopsWhenFollowsLineAndNoLineIsThere )
{
    MockMotor motor;
    MockTracker tracker;
    Mover mover(motor, tracker);

    mock::sequence sequence;
    MOCK_EXPECT( tracker.checkRoad ).in(sequence).returns( RoadLayout::none );
    MOCK_EXPECT( motor.stop ).at_least(1).in(sequence);

    mover.followLine();
}

BOOST_AUTO_TEST_CASE( followsLineUntilNextCrossing )
{
    Coordinate startPosition = Coordinate(0,0);
    Direction startDirection{ Direction::positiveX };

    MockMotor motor;
    MockTracker tracker;
    Mover mover(motor, tracker);
    mover.setPosition( startPosition );
    mover.setDirection( startDirection );

    mock::sequence sequence;
    MOCK_EXPECT( motor.goStraight ).once().in(sequence);
    MOCK_EXPECT( tracker.checkRoad ).once().in(sequence).returns( RoadLayout::left );
    MOCK_EXPECT( motor.turnLeft ).once().in(sequence);
    MOCK_EXPECT( tracker.checkRoad ).at_least(1).in(sequence).returns( RoadLayout::blocked );
    MOCK_EXPECT( motor.stop ).in(sequence);

    mover.followLineUntilCrossing();
    
    BOOST_TEST( mover.getPosition() == Coordinate(1,0) );
    BOOST_TEST( mover.getDirection() == startDirection );
}

BOOST_AUTO_TEST_CASE( followsLineFor2Crossings )
{
    Coordinate startPosition = Coordinate(0,0);
    Direction startDirection{ Direction::positiveX };

    MockMotor motor;
    MockTracker tracker;
    Mover mover(motor, tracker);
    mover.setPosition( startPosition );
    mover.setDirection( startDirection );

    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::blocked );
    MOCK_EXPECT( motor.goStraight ).exactly(2);    
    MOCK_EXPECT( motor.stop );

    mover.followLineUntilCrossingCount(2);
    
    BOOST_TEST( mover.getPosition() == Coordinate(2,0) );
    BOOST_TEST( mover.getDirection() == startDirection );
}

BOOST_AUTO_TEST_CASE( directs_towards_first_quadrant_coordinate_when_positions_at_origin_right )
{
    Coordinate startPosition = Coordinate(0,0);
    Direction startDirection{ Direction::positiveX };
    Coordinate newCoordinate = Coordinate(2,5);        
    MockMotor motor;
    MockTracker tracker;
    Mover mover(motor, tracker);
    mover.setPosition( startPosition );
    mover.setDirection( startDirection );

    bool directsTowardsCoordinate = mover.directsTowards( newCoordinate );

    BOOST_TEST( directsTowardsCoordinate == true );
}

BOOST_AUTO_TEST_CASE( directs_towards_second_quadrant_coordinate_when_positions_at_origin_top )
{
    Coordinate startPosition = Coordinate(0,0);
    Direction startDirection{ Direction::positiveY };
    Coordinate newCoordinate = Coordinate(-2,5);        
    MockMotor motor;
    MockTracker tracker;
    Mover mover(motor, tracker);
    mover.setPosition( startPosition );
    mover.setDirection( startDirection );

    bool directsTowardsCoordinate = mover.directsTowards( newCoordinate );

    BOOST_TEST( directsTowardsCoordinate == true );
}

BOOST_AUTO_TEST_CASE( directs_towards_third_quadrant_coordinate_when_positions_at_origin_left )
{
    Coordinate startPosition = Coordinate(0,0);
    Direction startDirection{ Direction::negativeX };
    Coordinate newCoordinate = Coordinate(-2,-5);        
    MockMotor motor;
    MockTracker tracker;
    Mover mover(motor, tracker);
    mover.setPosition( startPosition );
    mover.setDirection( startDirection );

    bool directsTowardsCoordinate = mover.directsTowards( newCoordinate );

    BOOST_TEST( directsTowardsCoordinate == true );
}

BOOST_AUTO_TEST_CASE( directs_towards_fourth_quadrant_coordinate_when_positions_at_origin_down )
{
    Coordinate startPosition = Coordinate(0,0);
    Direction startDirection{ Direction::negativeY };
    Coordinate newCoordinate = Coordinate(-2,-5);        
    MockMotor motor;
    MockTracker tracker;
    Mover mover(motor, tracker);
    mover.setPosition( startPosition );
    mover.setDirection( startDirection );

    bool directsTowardsCoordinate = mover.directsTowards( newCoordinate );

    BOOST_TEST( directsTowardsCoordinate == true );
}
