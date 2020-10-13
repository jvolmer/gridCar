#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_centerInRightTurn

#include "src/timer/timer.hpp"
#include "src/movement/pilot.hpp"
#include "src/movement/motor/motor.hpp"
#include "src/movement/motion/motionName.hpp"
#include "src/movement/motion/centerInRightTurn.hpp"

#include <boost/test/unit_test.hpp>
#include <turtle/mock.hpp>

MOCK_BASE_CLASS( MockPilot, Pilot )
{
    MOCK_METHOD( move, 0 );
    MOCK_METHOD( changeMotion, 1 );
};

MOCK_BASE_CLASS( MockMotor, Motor )
{
    MOCK_METHOD( setup, 0 );
    MOCK_METHOD( turnRight, 0 );
    MOCK_METHOD( turnLeft, 0 );
    MOCK_METHOD( goStraight, 0 );
    MOCK_METHOD( stop, 0 );
};

MOCK_BASE_CLASS( MockTimer, Timer )
{
    MOCK_METHOD( moment, 0 );
};

BOOST_AUTO_TEST_CASE( goes_straight_for_a_short_period )
{
    MockPilot pilot;
    MockTimer timer;
    MockMotor motor;
    CenterInRightTurn centerInRightTurn(pilot, timer, motor);
    mock::sequence s;
    MOCK_EXPECT( timer.moment ).once().in(s).returns( 0 );
    MOCK_EXPECT( timer.moment ).once().in(s).returns( 1 );

    MOCK_EXPECT( motor.goStraight ).once();

    centerInRightTurn.move();
}

BOOST_AUTO_TEST_CASE( changes_to_leave_origin_line_in_right_turn_after_a_short_period )
{
    MockPilot pilot;
    MockTimer timer;
    MockMotor motor;
    CenterInRightTurn centerInRightTurn(pilot, timer, motor);
    mock::sequence s;
    MOCK_EXPECT( timer.moment ).once().in(s).returns( 0 );
    MOCK_EXPECT( timer.moment ).once().in(s).returns( 3000 );

    MOCK_EXPECT( motor.goStraight );

    MOCK_EXPECT( pilot.changeMotion ).once().with( MotionName::leaveOriginLineInRightTurn );
    
    centerInRightTurn.move();
}
