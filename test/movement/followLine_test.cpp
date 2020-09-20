#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_followLine

#include "src/movement/pilot.hpp"
#include "src/movement/position/position.hpp"
#include "src/movement/tracker/tracker.hpp"
#include "src/movement/motor/motor.hpp"
#include "src/movement/position/coordinate.hpp"
#include "src/movement/position/relativeDirection.hpp"
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
    MOCK_METHOD( relativeDirectionToReach, 1 );
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


BOOST_AUTO_TEST_CASE( goes_straight_when_road_goes_straight )
{
    MockPilot pilot;
    Coordinate goal{ 1, 0 };
    MockPosition position;
    MockTracker tracker;
    MockMotor motor;
    FollowLine followLine(pilot, goal, position, tracker, motor);
    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::straight );

    MOCK_EXPECT( motor.goStraight ).once();

    followLine.move();
}

BOOST_AUTO_TEST_CASE( changes_to_stop_motion_at_crossing_when_goal_is_reached )
{
    MockPilot pilot;
    Coordinate goal{ 1, 0 };
    MockPosition position;
    MockTracker tracker;
    MockMotor motor;
    FollowLine followLine(pilot, goal, position, tracker, motor);
    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::blocked );
    MOCK_EXPECT( position.relativeDirectionToReach ).returns( RelativeDirection::at );
    MOCK_EXPECT( motor.goStraight );
    MOCK_EXPECT( position.moveForward );

    MOCK_EXPECT( pilot.changeMotion ).once().with( MotionName::stop );

    followLine.move();
}

BOOST_AUTO_TEST_CASE( updates_position_to_move_forward_at_crossing )
{
    MockPilot pilot;
    Coordinate goal{ 1, 0 };
    MockPosition position;
    MockTracker tracker;
    MockMotor motor;
    FollowLine followLine(pilot, goal, position, tracker, motor);
    MOCK_EXPECT( position.isLocatedAt ).returns(false);
    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::blocked );
    MOCK_EXPECT( position.relativeDirectionToReach ).returns( RelativeDirection::undefined );
    MOCK_EXPECT( motor.goStraight );
    
    MOCK_EXPECT( position.moveForward ).once();
    
    followLine.move();
}

BOOST_AUTO_TEST_CASE( changes_to_turn_around_motion_at_crossing_when_goal_is_exactly_in_opposite_direction )
{
    MockPilot pilot;
    Coordinate goal{ 1, 0 };
    MockPosition position;
    MockTracker tracker;
    MockMotor motor;
    FollowLine followLine(pilot, goal, position, tracker, motor);
    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::blocked );
    MOCK_EXPECT( position.relativeDirectionToReach ).returns( RelativeDirection::exactlyBehind );
    MOCK_EXPECT( motor.goStraight );
    MOCK_EXPECT( position.moveForward );

    MOCK_EXPECT( pilot.changeMotion ).once().with( MotionName::turnAround );

    followLine.move();
}

BOOST_AUTO_TEST_CASE( changes_to_start_right_turn_motion_at_crossing_when_goal_is_on_the_right )
{
    MockPilot pilot;
    Coordinate goal{ 1, 0 };
    MockPosition position;
    MockTracker tracker;
    MockMotor motor;
    FollowLine followLine(pilot, goal, position, tracker, motor);
    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::blocked );
    MOCK_EXPECT( position.relativeDirectionToReach ).returns( RelativeDirection::onTheRight );
    MOCK_EXPECT( motor.goStraight );
    MOCK_EXPECT( position.moveForward );

    MOCK_EXPECT( pilot.changeMotion ).once().with( MotionName::startRightTurn );

    followLine.move();
}

BOOST_AUTO_TEST_CASE( changes_to_start_left_turn_motion_at_crossing_when_goal_is_on_the_left )
{
    MockPilot pilot;
    Coordinate goal{ 1, 0 };
    MockPosition position;
    MockTracker tracker;
    MockMotor motor;
    FollowLine followLine(pilot, goal, position, tracker, motor);
    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::blocked );
    MOCK_EXPECT( position.relativeDirectionToReach ).returns( RelativeDirection::onTheLeft );
    MOCK_EXPECT( motor.goStraight );
    MOCK_EXPECT( position.moveForward );

    MOCK_EXPECT( pilot.changeMotion ).once().with( MotionName::startLeftTurn );

    followLine.move();
}
