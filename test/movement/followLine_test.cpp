#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_followLine

#include "src/movement/pilot.hpp"
#include "src/movement/position/position.hpp"
#include "src/movement/tracker/tracker.hpp"
#include "src/movement/motor/motor.hpp"
#include "src/movement/position/coordinate.hpp"
#include "src/movement/followLine.hpp"
#include "src/movement/motionName.hpp"
#include "src/movement/tracker/roadLayout.hpp"
#include <boost/test/unit_test.hpp>
#include <turtle/mock.hpp>

MOCK_BASE_CLASS( MockPilot, Pilot )
{
    MOCK_METHOD( move, 0 );
    MOCK_METHOD( changeMotion, 1 );
};

MOCK_BASE_CLASS( MockPosition, Position )
{
    MOCK_METHOD( turnLeft, 0 );
    MOCK_METHOD( turnRight, 0 );
    MOCK_METHOD( moveForward, 0 );
    MOCK_METHOD( isLocatedAt, 1 );
    MOCK_METHOD( getTurnTrendToReach, 1 );
};

MOCK_BASE_CLASS( MockTracker, Tracker )
{
    MOCK_METHOD( checkRoad, 0 );
    MOCK_METHOD( setup, 0 );
};

MOCK_BASE_CLASS( MockMotor, Motor )
{
    MOCK_METHOD( setup, 0 );
    MOCK_METHOD( turnRight, 0 );
    MOCK_METHOD( turnLeft, 0 );
    MOCK_METHOD( goStraight, 0 );
    MOCK_METHOD( stop, 0 );
};


BOOST_AUTO_TEST_CASE( goes_straight_when_goal_is_not_reached )
{
    MockPilot pilot;
    Coordinate goal{ 1, 0 };
    MockPosition position;
    MockTracker tracker;
    MockMotor motor;
    FollowLine followLine(pilot, goal, position, tracker, motor);
    
    MOCK_EXPECT( position.isLocatedAt ).returns( false );
    MOCK_EXPECT( motor.goStraight ).once();
    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::straight );
    
    followLine.move();
}

BOOST_AUTO_TEST_CASE( changes_to_stop_motion_when_goal_is_reached )
{
    MockPilot pilot;
    Coordinate goal{ 1, 0 };
    MockPosition position;
    MockTracker tracker;
    MockMotor motor;
    FollowLine followLine(pilot, goal, position, tracker, motor);

    MOCK_EXPECT( position.isLocatedAt ).returns( true );
    MOCK_EXPECT( pilot.changeMotion ).once().with( MotionName::stop );
    MOCK_EXPECT( motor.goStraight );
    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::straight );
    
    followLine.move();
}

BOOST_AUTO_TEST_CASE( updates_position_at_crossing )
{
    MockPilot pilot;
    Coordinate goal{ 1, 0 };
    MockPosition position;
    MockTracker tracker;
    MockMotor motor;
    FollowLine followLine(pilot, goal, position, tracker, motor);

    MOCK_EXPECT( motor.goStraight );
    MOCK_EXPECT( position.isLocatedAt ).returns(false);
    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::blocked );
    MOCK_EXPECT( position.moveForward ).once();
    
    followLine.move();
}
