#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_linePilot

#include "src/timer/timer.hpp"
#include "src/movement/linePilot.hpp"
#include "src/movement/motion.hpp"
#include "src/movement/stop.hpp"
#include "src/movement/followLine.hpp"
#include "src/movement/position/position.hpp"
#include "src/movement/motor/motor.hpp"
#include "src/movement/tracker/tracker.hpp"
#include "src/movement/tracker/roadLayout.hpp"
#include "src/movement/position/coordinate.hpp"
#include "src/movement/motionName.hpp"
#include <boost/test/unit_test.hpp>
#include <turtle/mock.hpp>

MOCK_BASE_CLASS( MockPosition, Position )
{
    MOCK_METHOD( turnLeft, 0 );
    MOCK_METHOD( turnRight, 0 );
    MOCK_METHOD( moveForward, 0 );
    MOCK_METHOD( isLocatedAt, 1 );
    MOCK_METHOD( getTurnTrendToReach, 1 );
    MOCK_METHOD( isAtTurningPointToReach, 1 );
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

MOCK_BASE_CLASS( MockTimer, Timer )
{
    MOCK_METHOD( moment, 0 );
};

BOOST_AUTO_TEST_CASE( starts_in_follow_line_motion )
{
    Coordinate goal{ 0, 0 };
    MockPosition position;
    MockTracker tracker;
    MockTimer timer;
    MockMotor motor;
    LinePilot pilot(goal, position, tracker, timer, motor);   
    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::straight );
    MOCK_EXPECT( position.isLocatedAt ).returns( false );
    MOCK_EXPECT( position.isAtTurningPointToReach ).returns(false);

    MOCK_EXPECT( motor.goStraight ).once();

    pilot.move();
}
