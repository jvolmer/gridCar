#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_linePilot

#include "src/movement/linePilot.hpp"
#include "src/movement/position/position.hpp"
#include "src/movement/position/gridPosition.hpp"
#include "src/movement/goal.hpp"
#include "src/movement/gridGoal.hpp"
#include "src/movement/motor/motor.hpp"
#include "src/movement/tracker/tracker.hpp"
#include "src/movement/tracker/roadLayout.hpp"
#include "src/movement/position/coordinate.hpp"
#include "src/movement/position/direction.hpp"
#include "src/movement/position/relativeDirection.hpp"
#include "src/timer/timer.hpp"
#include "test/movement/position/gridPosition_ostream.hpp"

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

MOCK_BASE_CLASS( MockTracker, Tracker )
{
    MOCK_METHOD( checkRoad, 0 );
    MOCK_METHOD( setup, 0 );
};

MOCK_BASE_CLASS( MockGoal, Goal )
{
    MOCK_METHOD( set, 1 );
    MOCK_METHOD( get, 0 );
    MOCK_METHOD( turningDirectionFrom, 1 );
};

MOCK_BASE_CLASS( MockTimer, Timer )
{
    MOCK_METHOD( moment, 0 );
};

BOOST_AUTO_TEST_CASE( starts_in_stop_motion )
{
    MockGoal goal;
    MockPosition position;
    MockTracker tracker;
    MockTimer timer;
    MockMotor motor;
    LinePilot pilot(goal, position, tracker, timer, motor);
    MOCK_EXPECT( goal.turningDirectionFrom ).returns( RelativeDirection::at );
    MOCK_EXPECT( tracker.checkRoad ).returns( RoadLayout::straight );

    MOCK_EXPECT( motor.stop ).once();

    pilot.move();
}

BOOST_AUTO_TEST_CASE( moves_to_goal_in_front_and_to_the_right )
{
    GridGoal goal{ Coordinate(3,3) };
    GridPosition position{ Coordinate(0,0), Direction::positiveY };
    MockTracker tracker;
    MockTimer timer;
    MockMotor motor;
    LinePilot pilot(goal, position, tracker, timer, motor);
    MOCK_EXPECT( motor.goStraight );
    MOCK_EXPECT( motor.turnRight );
    MOCK_EXPECT( motor.stop );
    
    Coordinate goalCoordinate{ Coordinate(2,1) };
    goal.set( goalCoordinate );

    pilot.move();    
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::straight );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::blocked );
    pilot.move();

    BOOST_TEST( position == GridPosition(Coordinate(0,1), Direction::positiveY ));

    pilot.move();
    mock::sequence s;
    MOCK_EXPECT( timer.moment ).once().in(s).returns( 0 );
    MOCK_EXPECT( timer.moment ).once().in(s).returns( 3040 );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::sharpLeft );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::straight );
    pilot.move();

    BOOST_TEST( position == GridPosition(Coordinate(0,1), Direction::positiveX ));    

    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::straight );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::blocked );
    pilot.move();

    BOOST_TEST( position == GridPosition(Coordinate(1,1), Direction::positiveX ));

    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::straight );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::blocked );
    pilot.move();
    
    BOOST_TEST( position == GridPosition(goalCoordinate, Direction::positiveX ));
}

BOOST_AUTO_TEST_CASE( moves_to_goal_in_front_and_to_the_left )
{
    GridGoal goal{ Coordinate(3,3) };
    GridPosition position{ Coordinate(0,0), Direction::positiveX };
    MockTracker tracker;
    MockTimer timer;
    MockMotor motor;
    LinePilot pilot(goal, position, tracker, timer, motor);
    MOCK_EXPECT( motor.goStraight );
    MOCK_EXPECT( motor.turnLeft );
    MOCK_EXPECT( motor.stop );

    Coordinate goalCoordinate{ Coordinate(2,1) };
    goal.set( goalCoordinate );

    pilot.move();    
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::straight );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::blocked );
    pilot.move();

    BOOST_TEST( position == GridPosition(Coordinate(1,0), Direction::positiveX ));

    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::straight );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::blocked );
    pilot.move();

    BOOST_TEST( position == GridPosition(Coordinate(2,0), Direction::positiveX ));

    pilot.move();
    mock::sequence s;
    MOCK_EXPECT( timer.moment ).once().in(s).returns( 0 );
    MOCK_EXPECT( timer.moment ).once().in(s).returns( 3040 );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::sharpRight );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::straight );
    pilot.move();

    BOOST_TEST( position == GridPosition(Coordinate(2,0), Direction::positiveY ));    

    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::straight );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::blocked );
    pilot.move();

    BOOST_TEST( position == GridPosition(goalCoordinate, Direction::positiveY ));
}

BOOST_AUTO_TEST_CASE( moves_to_goal_directly_in_the_back )
{
    GridGoal goal{ Coordinate(3,3) };
    GridPosition position{ Coordinate(0,0), Direction::negativeY };
    MockTracker tracker;
    MockTimer timer;
    MockMotor motor;
    LinePilot pilot(goal, position, tracker, timer, motor);
    MOCK_EXPECT( motor.goStraight );
    MOCK_EXPECT( motor.turnRight );
    MOCK_EXPECT( motor.stop );

    Coordinate goalCoordinate{ Coordinate(0,2) };
    goal.set( goalCoordinate );

    pilot.move();

    mock::sequence s;
    MOCK_EXPECT( timer.moment ).once().in(s).returns( 0 );
    MOCK_EXPECT( timer.moment ).once().in(s).returns( 3040 );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::sharpLeft );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::straight );
    pilot.move();

    BOOST_TEST( position == GridPosition(Coordinate(0,0), Direction::negativeX ));

    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::sharpLeft );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::straight );
    pilot.move();

    BOOST_TEST( position == GridPosition(Coordinate(0,0), Direction::positiveY ));

    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::straight );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::blocked );
    pilot.move();

    BOOST_TEST( position == GridPosition(Coordinate(0,1), Direction::positiveY ));    

    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::straight );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::blocked );
    pilot.move();

    BOOST_TEST( position == GridPosition(goalCoordinate, Direction::positiveY ));
}

BOOST_AUTO_TEST_CASE( moves_to_goal_in_back_and_to_the_right )
{
    GridGoal goal{ Coordinate(3,3) };
    GridPosition position{ Coordinate(0,0), Direction::negativeX };
    MockTracker tracker;
    MockTimer timer;
    MockMotor motor;
    LinePilot pilot(goal, position, tracker, timer, motor);
    MOCK_EXPECT( motor.goStraight );
    MOCK_EXPECT( motor.turnRight );
    MOCK_EXPECT( motor.stop );

    Coordinate goalCoordinate{ Coordinate(2,1) };
    goal.set( goalCoordinate );
    
    pilot.move();    

    mock::sequence s1;
    MOCK_EXPECT( timer.moment ).once().in(s1).returns( 0 );
    MOCK_EXPECT( timer.moment ).once().in(s1).returns( 3040 );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::sharpLeft );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::straight );
    pilot.move();

    BOOST_TEST( position == GridPosition(Coordinate(0,0), Direction::positiveY ));    

    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::straight );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::blocked );
    pilot.move();

    BOOST_TEST( position == GridPosition(Coordinate(0,1), Direction::positiveY ));

    pilot.move();
    mock::sequence s2;
    MOCK_EXPECT( timer.moment ).once().in(s2).returns( 0 );
    MOCK_EXPECT( timer.moment ).once().in(s2).returns( 3040 );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::sharpLeft );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::straight );
    pilot.move();

    BOOST_TEST( position == GridPosition(Coordinate(0,1), Direction::positiveX ));    

    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::straight );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::blocked );
    pilot.move();

    BOOST_TEST( position == GridPosition(Coordinate(1,1), Direction::positiveX ));

    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::straight );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::blocked );
    pilot.move();
    
    BOOST_TEST( position == GridPosition(goalCoordinate, Direction::positiveX ));
}

BOOST_AUTO_TEST_CASE( moves_to_goal_in_back_and_to_the_left )
{
    GridGoal goal{ Coordinate(3,3) };
    GridPosition position{ Coordinate(0,0), Direction::negativeY };
    MockTracker tracker;
    MockTimer timer;
    MockMotor motor;
    LinePilot pilot(goal, position, tracker, timer, motor);
    MOCK_EXPECT( motor.goStraight );
    MOCK_EXPECT( motor.turnLeft );
    MOCK_EXPECT( motor.stop );

    Coordinate goalCoordinate{ Coordinate(2,1) };
    goal.set( goalCoordinate );

    pilot.move();    
    mock::sequence s1;
    MOCK_EXPECT( timer.moment ).once().in(s1).returns( 0 );
    MOCK_EXPECT( timer.moment ).once().in(s1).returns( 3040 );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::sharpRight );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::straight );
    pilot.move();

    BOOST_TEST( position == GridPosition(Coordinate(0,0), Direction::positiveX ));    

    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::straight );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::blocked );
    pilot.move();

    BOOST_TEST( position == GridPosition(Coordinate(1,0), Direction::positiveX ));

    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::straight );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::blocked );
    pilot.move();

    BOOST_TEST( position == GridPosition(Coordinate(2,0), Direction::positiveX ));    

    pilot.move();
    mock::sequence s2;
    MOCK_EXPECT( timer.moment ).once().in(s2).returns( 0 );
    MOCK_EXPECT( timer.moment ).once().in(s2).returns( 3040 );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::sharpRight );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::straight );
    pilot.move();

    BOOST_TEST( position == GridPosition(Coordinate(2,0), Direction::positiveY ));    

    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::straight );
    pilot.move();
    MOCK_EXPECT( tracker.checkRoad ).once().returns( RoadLayout::blocked );
    pilot.move();

    BOOST_TEST( position == GridPosition(goalCoordinate, Direction::positiveY ));
}

