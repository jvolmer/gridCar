#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_mover

#include "controller/mover.hpp"
#include "model/motor.hpp"
#include "model/tracker.hpp"
#include "entity/coordinate.hpp"
#include "entity/direction.hpp"
#include "test/entity/operatorOverloading.hpp"
#include <boost/test/unit_test.hpp>
#include <turtle/mock.hpp>


MOCK_BASE_CLASS( MockMotor, Motor )
{
    MOCK_METHOD( run, 2 );
    MOCK_METHOD( setup, 0 );
};

MOCK_BASE_CLASS( MockTracker, Tracker )
{
    MOCK_METHOD( checkSensors, 0 );
    MOCK_METHOD( setup, 0 );
};

BOOST_AUTO_TEST_CASE( turnRight_resultsInNoPositionChangeAndNegativeYOrientation_givenOrientationIsPositiveX)
{
    Coordinate startPosition = Coordinate(0,0);
    Direction startDirection{ Direction::positiveX};

    MockMotor motor;
    MockTracker tracker;
    Mover mover(motor, tracker, startPosition, startDirection);
    MOCK_EXPECT( tracker.checkSensors ).returns( 7 );

    MOCK_EXPECT( motor.run ).at_least(1);

    mover.turnRightAtCrossing();
    
    BOOST_TEST( mover.getPosition() == startPosition );
    BOOST_TEST( mover.getDirection() == Direction::negativeY );
}

BOOST_AUTO_TEST_CASE( turnLeft_resultsInNoPositionChangeAndPositiveYOrientation_givenOrientationIsPositiveX)
{
    Coordinate startPosition = Coordinate(0,0);
    Direction startDirection{ Direction::positiveX};
    
    MockMotor motor;
    MockTracker tracker;
    Mover mover(motor, tracker, startPosition, startDirection);
    MOCK_EXPECT( tracker.checkSensors ).returns( 7 );

    MOCK_EXPECT( motor.run ).at_least(1);

    mover.turnLeftAtCrossing();
    
    BOOST_TEST( mover.getPosition() == startPosition );
    BOOST_TEST( mover.getDirection() == Direction::positiveY );
}
