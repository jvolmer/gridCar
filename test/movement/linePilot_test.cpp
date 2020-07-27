#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_linePilot

#include "src/movement/linePilot.hpp"
#include "src/movement/motion.hpp"
#include "src/movement/stop.hpp"
#include "src/movement/followLine.hpp"
#include "src/movement/position/position.hpp"
#include "src/movement/motor/motor.hpp"
#include "src/movement/tracker/tracker.hpp"
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

MOCK_BASE_CLASS( MockTracker, Tracker )
{
    MOCK_METHOD( checkRoad, 0 );
    MOCK_METHOD( setup, 0 );
};

BOOST_AUTO_TEST_CASE( stops_in_stop_motion )
{
    MockMotor motor;
    LinePilot pilot(motor);
    Stop stop(pilot, motor);
    pilot.changeMotion(&stop);
   
    MOCK_EXPECT( motor.stop ).once();
    
    pilot.move();
}

BOOST_AUTO_TEST_CASE( goes_straight_in_follow_line_motion )
{
    MockMotor motor;
    LinePilot pilot(motor);
    MockPosition position;
    FollowLine followLine(pilot, position, motor);
    pilot.changeMotion(&followLine);

    MOCK_EXPECT( motor.goStraight ).once();
    
    pilot.move();
}
