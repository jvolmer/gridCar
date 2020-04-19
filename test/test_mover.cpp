#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_mover

#include <iostream>

#include "mover.hpp"
#include "package.hpp"
#include "direction.hpp"
#include "motor.hpp"
#include <boost/test/unit_test.hpp>
#include <turtle/mock.hpp>

std::ostream& operator<< (std::ostream& out, const Direction& direction)
{
    return out << (int)direction;
}

MOCK_BASE_CLASS( MockMotor, Motor )
{
    MOCK_METHOD( run, 2 );
    MOCK_METHOD( setup, 0 );
};

BOOST_AUTO_TEST_CASE( turnsRight_resultsInNoPositionChangeAndNegativeYOrientation_givenOrientationIsPositiveX)
{
    Point startPosition = Point(0,0);
    Direction startDirection{ Direction::positiveX};

    MockMotor motor;
    Mover mover(motor, startPosition, startDirection);

    MOCK_EXPECT( motor.run ).once();
    mover.turnRight();
    
    
    BOOST_TEST( mover.getPosition() == startPosition );
    BOOST_TEST( mover.getDirection() == Direction::negativeY );
}
