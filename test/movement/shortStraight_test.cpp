#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_shortStraight

#include "src/timer/timer.hpp"
#include "src/movement/pilot.hpp"
#include "src/movement/motor/motor.hpp"
#include "src/movement/motionName.hpp"
#include "src/movement/shortStraight.hpp"
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
    MOCK_METHOD( millis, 0 );
};

BOOST_AUTO_TEST_CASE( goes_straight_for_a_short_period )
{
    MockPilot pilot;
    MockTimer timer;
    MockMotor motor;
    ShortStraight shortStraight(pilot, timer, motor);
    mock::sequence s;
    MOCK_EXPECT( timer.millis ).once().in(s).returns( 0 );
    MOCK_EXPECT( timer.millis ).once().in(s).returns( 2 );

    MOCK_EXPECT( motor.goStraight ).once();

    shortStraight.move();
}

BOOST_AUTO_TEST_CASE( changes_to_turn_to_line_when_gone_straight_for_more_than_200_milli_seconds )
{
    MockPilot pilot;
    MockTimer timer;
    MockMotor motor;
    ShortStraight shortStraight(pilot, timer, motor);
    mock::sequence s;
    MOCK_EXPECT( timer.millis ).once().in(s).returns( 0 );
    MOCK_EXPECT( timer.millis ).once().in(s).returns( 210 );
    MOCK_EXPECT( motor.goStraight );

    MOCK_EXPECT( pilot.changeMotion ).once().with( MotionName::turnToLine );
    
    shortStraight.move();
}
