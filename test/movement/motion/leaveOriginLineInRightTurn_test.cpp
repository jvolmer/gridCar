#include "src/movement/pilot.hpp"
#include "src/movement/tracker/tracker.hpp"
#include "src/movement/tracker/roadLayout.hpp"
#include "src/movement/tracker/roadLayout.hpp"
#include "src/movement/motor/motor.hpp"
#include "src/movement/motion/motionName.hpp"
#include "src/movement/motion/leaveOriginLineInRightTurn.hpp"
#include <boost/test/unit_test.hpp>
#include <turtle/mock.hpp>

BOOST_AUTO_TEST_SUITE( LeaveOriginLineInRightTurnTest )

MOCK_BASE_CLASS( MockPilot, Pilot )
{
    MOCK_METHOD( move, 0 );
    MOCK_METHOD( changeMotion, 1 );
};

MOCK_BASE_CLASS( MockTracker, Tracker )
{
    MOCK_METHOD( roadLayout, 0 );
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


BOOST_AUTO_TEST_CASE( turns_right_when_close_to_line )
{
    MockPilot pilot;
    MockTracker tracker;
    MockMotor motor;
    LeaveOriginLineInRightTurn leaveOriginLineInRightTurn(pilot, tracker, motor);
    MOCK_EXPECT( tracker.roadLayout ).returns( RoadLayout::none );
    
    MOCK_EXPECT( motor.turnRight ).once();

    leaveOriginLineInRightTurn.move();
}

BOOST_AUTO_TEST_CASE( changes_to_find_next_line_in_right_turn_motion_tracking_line_on_the_left )
{
    MockPilot pilot;
    MockTracker tracker;
    MockMotor motor;
    LeaveOriginLineInRightTurn leaveOriginLineInRightTurn(pilot, tracker, motor);
    MOCK_EXPECT( tracker.roadLayout ).returns( RoadLayout::sharpLeft );
    MOCK_EXPECT( motor.turnRight );

    MOCK_EXPECT( pilot.changeMotion ).once().with( MotionName::findNextLineInRightTurn );

    leaveOriginLineInRightTurn.move();
}

BOOST_AUTO_TEST_SUITE_END()
