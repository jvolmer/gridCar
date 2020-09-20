#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_findLineInRightTurn

#include "src/movement/pilot.hpp"
#include "src/movement/position/position.hpp"
#include "src/movement/tracker/tracker.hpp"
#include "src/movement/tracker/roadLayout.hpp"
#include "src/movement/motor/motor.hpp"
#include "src/movement/motionName.hpp"
#include "src/movement/tracker/roadLayout.hpp"
#include "src/movement/findLineInRightTurn.hpp"
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


BOOST_AUTO_TEST_CASE( turns_right )
{
    MockPilot pilot;
    MockPosition position;
    MockTracker tracker;
    MockMotor motor;
    FindLineInRightTurn findLineInRightTurn(pilot, position, tracker, motor);
    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::none );
    MOCK_EXPECT( position.turnRight );
    
    MOCK_EXPECT( motor.turnRight ).once();

    findLineInRightTurn.move();
}

BOOST_AUTO_TEST_CASE( turns_position_right_when_arriving_at_a_line )
{
    MockPilot pilot;
    MockPosition position;
    MockTracker tracker;
    MockMotor motor;
    FindLineInRightTurn findLineInRightTurn(pilot, position, tracker, motor);
    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::straight );
    MOCK_EXPECT( motor.turnRight );
    MOCK_EXPECT( pilot.changeMotion );
    
    MOCK_EXPECT( position.turnRight ).once();

    findLineInRightTurn.move();
}

BOOST_AUTO_TEST_CASE( changes_to_follow_line_motion_when_arriving_at_a_line )
{
    MockPilot pilot;
    MockPosition position;
    MockTracker tracker;
    MockMotor motor;
    FindLineInRightTurn findLineInRightTurn(pilot, position, tracker, motor);
    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::straight );
    MOCK_EXPECT( motor.turnRight );
    MOCK_EXPECT( position.turnRight );

    MOCK_EXPECT( pilot.changeMotion ).once().with( MotionName::followLine );
    
    findLineInRightTurn.move();
}
