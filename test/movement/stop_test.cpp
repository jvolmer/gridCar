#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_stop

#include "src/movement/pilot.hpp"
#include "src/movement/position/coordinate.hpp"
#include "src/movement/position/position.hpp"
#include "src/movement/motor/motor.hpp"
#include "src/movement/stop.hpp"

#include <boost/test/unit_test.hpp>
#include <turtle/mock.hpp>

MOCK_BASE_CLASS( MockPosition, Position )
{
    MOCK_METHOD( turnLeft, 0 );
    MOCK_METHOD( turnRight, 0 );
    MOCK_METHOD( moveForward, 0 );
    MOCK_METHOD( isLocatedAt, 1 );
    MOCK_METHOD( relativeDirectionToReach, 1 );
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

BOOST_AUTO_TEST_CASE( stops )
{
    MockPilot pilot;
    Coordinate goal{ 0 , 1 };
    MockPosition position;
    MockMotor motor;
    Stop stop(pilot, goal, position, motor);
    MOCK_EXPECT( position.isLocatedAt ).returns( true );
    
    MOCK_EXPECT( motor.stop ).once();
    
    stop.move();
}

BOOST_AUTO_TEST_CASE( changes_to_follow_line_motion_when_position_is_not_equal_to_goal )
{
    MockPilot pilot;
    Coordinate goal{ 0 , 1 };
    MockPosition position;
    MockMotor motor;
    Stop stop(pilot, goal, position, motor);
    MOCK_EXPECT( position.isLocatedAt ).returns( false );
    MOCK_EXPECT( motor.stop );

    MOCK_EXPECT( pilot.changeMotion ).once().with( MotionName::followLine );
    
    stop.move();
}

