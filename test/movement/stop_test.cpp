#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_stop

#include "src/movement/pilot.hpp"
#include "src/movement/motor/motor.hpp"
#include "src/movement/stop.hpp"
#include <boost/test/unit_test.hpp>
#include <turtle/mock.hpp>

MOCK_BASE_CLASS( MockMotor, Motor )
{
    MOCK_METHOD( setup, 0 );
    MOCK_METHOD( turnRight, 0 );
    MOCK_METHOD( turnLeft, 0 );
    MOCK_METHOD( goStraight, 0 );
    MOCK_METHOD( stop, 0 );
};

MOCK_BASE_CLASS( MockPilot, Pilot )
{
    MOCK_METHOD( move, 0 );
    MOCK_METHOD( changeMotion, 1 );
};

BOOST_AUTO_TEST_CASE( stops )
{
    MockPilot pilot;
    MockMotor motor;
    Stop stop(pilot, motor);
    
    MOCK_EXPECT( motor.stop ).once();
    
    stop.move();
}
