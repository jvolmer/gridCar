#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_followLine

#include "src/movement/pilot.hpp"
#include "src/movement/position/position.hpp"
#include "src/movement/motor/motor.hpp"
#include "src/movement/position/coordinate.hpp"
#include "src/movement/followLine.hpp"
#include "src/movement/stop.hpp"
#include <boost/test/unit_test.hpp>
#include <turtle/mock.hpp>

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

MOCK_BASE_CLASS( MockPilot, Pilot )
{
    MOCK_METHOD( move, 0 );
    MOCK_METHOD( changeMotion, 1 );
};

BOOST_AUTO_TEST_CASE( goes_straight_when_goal_is_not_reached )
{
    MockPilot pilot;
    MockPosition position;
    MockMotor motor;
    Coordinate goal{ 1, 0 };
    FollowLine followLine(pilot, goal, position, motor);
    
    MOCK_EXPECT( position.isLocatedAt ).returns( false );
    MOCK_EXPECT( motor.goStraight ).once();
    
    followLine.move();
}

BOOST_AUTO_TEST_CASE( changes_motion_when_goal_is_reached )
{
    MockPilot pilot;
    MockPosition position;
    MockMotor motor;
    Coordinate goal{ 1, 0 };
    FollowLine followLine(pilot, goal, position, motor);

    MOCK_EXPECT( motor.goStraight );
    MOCK_EXPECT( position.isLocatedAt ).returns( true );
    Stop stop(pilot, motor);
    MOCK_EXPECT( pilot.changeMotion ).once();
    
    followLine.move();
}
