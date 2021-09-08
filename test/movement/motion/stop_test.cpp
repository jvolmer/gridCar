#include "src/movement/pilot.hpp"
#include "src/movement/position/position.hpp"
#include "src/movement/position/relativeDirection.hpp"
#include "src/movement/goal.hpp"
#include "src/movement/motor/motor.hpp"
#include "src/movement/motion/motionName.hpp"
#include "src/movement/motion/stop.hpp"
#include <boost/test/unit_test.hpp>
#include <turtle/mock.hpp>

BOOST_AUTO_TEST_SUITE( StopTest )

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

MOCK_BASE_CLASS( MockGoal, Goal )
{
    MOCK_METHOD( set, 1 );
    MOCK_METHOD( get, 0 );
    MOCK_METHOD( turningDirectionFrom, 1 );
};

BOOST_AUTO_TEST_CASE( stops )
{
    MockPilot pilot;
    MockGoal goal;
    MockPosition position;
    MockMotor motor;
    Stop stop(pilot, goal, position, motor);
    MOCK_EXPECT( goal.turningDirectionFrom ).returns( RelativeDirection::at );
    
    MOCK_EXPECT( motor.stop ).once();
    
    stop.move();
}

BOOST_AUTO_TEST_CASE( changes_to_follow_line_motion_when_goal_is_in_front )
{
    MockPilot pilot;
    MockGoal goal;
    MockPosition position;
    MockMotor motor;
    Stop stop(pilot, goal, position, motor);
    MOCK_EXPECT( goal.turningDirectionFrom ).returns( RelativeDirection::inFront );
    MOCK_EXPECT( motor.stop );

    MOCK_EXPECT( pilot.changeMotion ).once().with( MotionName::followLine );
    
    stop.move();
}

BOOST_AUTO_TEST_CASE( changes_to_turn_around_motion_at_crossing_when_goal_is_exactly_in_opposite_direction )
{
    MockPilot pilot;
    MockGoal goal;
    MockPosition position;
    MockMotor motor;
    Stop stop(pilot, goal, position, motor);
    MOCK_EXPECT( goal.turningDirectionFrom ).returns( RelativeDirection::exactlyBehind );
    MOCK_EXPECT( motor.stop );

    MOCK_EXPECT( pilot.changeMotion ).once().with( MotionName::centerInTurnAround );

    stop.move();
}

BOOST_AUTO_TEST_CASE( changes_to_start_right_turn_motion_at_crossing_when_goal_is_on_the_right )
{
    MockPilot pilot;
    MockGoal goal;
    MockPosition position;
    MockMotor motor;
    Stop stop(pilot, goal, position, motor);
    MOCK_EXPECT( goal.turningDirectionFrom ).returns( RelativeDirection::onTheRight );
    MOCK_EXPECT( motor.stop );

    MOCK_EXPECT( pilot.changeMotion ).once().with( MotionName::centerInRightTurn );

    stop.move();
}

BOOST_AUTO_TEST_CASE( changes_to_start_left_turn_motion_at_crossing_when_goal_is_on_the_left )
{
    MockPilot pilot;
    MockGoal goal;
    MockPosition position;
    MockMotor motor;
    Stop stop(pilot, goal, position, motor);
    MOCK_EXPECT( goal.turningDirectionFrom ).returns( RelativeDirection::onTheLeft );
    MOCK_EXPECT( motor.stop );

    MOCK_EXPECT( pilot.changeMotion ).once().with( MotionName::centerInLeftTurn );

    stop.move();
}

BOOST_AUTO_TEST_SUITE_END()
