#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_linePilot

#include "src/timer/timer.hpp"
#include "src/communication/coordinateBroadcaster.hpp"
#include "src/movement/linePilot.hpp"
#include "src/movement/motion.hpp"
#include "src/movement/stop.hpp"
#include "src/movement/followLine.hpp"
#include "src/movement/position/position.hpp"
#include "src/movement/motor/motor.hpp"
#include "src/movement/tracker/tracker.hpp"
#include "src/movement/tracker/roadLayout.hpp"
#include "src/movement/position/coordinate.hpp"
#include "test/movement/position/coordinate_ostream.hpp"
#include "src/movement/goal.hpp"
#include "src/movement/motionName.hpp"
#include <boost/test/unit_test.hpp>
#include <turtle/mock.hpp>

MOCK_BASE_CLASS( MockPosition, Position )
{
    MOCK_METHOD( setLocation, 1 );
    MOCK_METHOD( setDirection, 1 );
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

MOCK_BASE_CLASS( MockTracker, Tracker )
{
    MOCK_METHOD( checkRoad, 0 );
    MOCK_METHOD( setup, 0 );
};

MOCK_BASE_CLASS( MockGoal, Goal )
{
    MOCK_METHOD( set, 1 );
    MOCK_METHOD( get, 0 );
};

MOCK_BASE_CLASS( MockTimer, Timer )
{
    MOCK_METHOD( moment, 0 );
};

// MOCK_BASE_CLASS( MockGoalBroadcaster, CoordinateBroadcaster )
// {
//     MOCK_METHOD( broadcast, 1 );
//     MOCK_METHOD( subscribe, 1 );
// };


BOOST_AUTO_TEST_CASE( starts_in_follow_line_motion )
{
    // MockGoal goal;
    // MockPosition position;
    // MockTracker tracker;
    // MockTimer timer;
    // MockMotor motor;
    // LinePilot pilot(goal, position, tracker, timer, motor);
    // MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::straight );

    // MOCK_EXPECT( motor.goStraight ).once();

    // pilot.move();
}

// BOOST_AUTO_TEST_CASE( listens_to_broadcaster )
// {
//     Coordinate goal{ 0, 0 };
//     MockPosition position;
//     MockTracker tracker;
//     MockTimer timer;
//     MockMotor motor;
//     LinePilot pilot(goal, position, tracker, timer, motor);
//     MockGoalBroadcaster broadcaster;

//     MOCK_EXPECT( broadcaster.subscribe ).once();

//     pilot.listenTo( broadcaster );
// }

// BOOST_AUTO_TEST_CASE( updates_goal )
// {
//     Coordinate goal{ 0, 0 };
//     MockPosition position;
//     MockTracker tracker;
//     MockTimer timer;
//     MockMotor motor;
//     LinePilot pilot(goal, position, tracker, timer, motor);   

//     Coordinate newGoal{ 1, 4 };
//     pilot.update( newGoal );

//     BOOST_TEST( goal == newGoal );
// }
