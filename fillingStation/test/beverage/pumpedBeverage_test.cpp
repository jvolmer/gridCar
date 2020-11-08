#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_pumpedBeverage

#include "src/timer/timer.hpp"
#include "src/pump/pump.hpp"
#include "src/beverage/pumpedBeverage.hpp"

#include <boost/test/unit_test.hpp>
#include <turtle/mock.hpp>

MOCK_BASE_CLASS(MockPump, Pump)
{
    MOCK_METHOD( setup, 0 );
    MOCK_METHOD( start, 0 );
    MOCK_METHOD( stop, 0 );
};

MOCK_BASE_CLASS(MockTimer, Timer)
{
    MOCK_METHOD( moment, 0 );
};

BOOST_AUTO_TEST_CASE( starts_pump_when_pouring )
{
    MockPump pump;
    MockTimer timer;
    PumpedBeverage beverage{ pump, timer };
    beverage.setPouringDurationInSeconds( 5 );
    mock::sequence s;
    MOCK_EXPECT( timer.moment ).once().in(s).returns(0);
    MOCK_EXPECT( timer.moment ).once().in(s).returns(1);
    
    MOCK_EXPECT( pump.start ).once();
    
    beverage.pour();
}

BOOST_AUTO_TEST_CASE( not_starts_pump_when_pouring_duration_is_not_set )
{
    MockPump pump;
    MockTimer timer;
    PumpedBeverage beverage{ pump, timer };
    
    MOCK_EXPECT( pump.start ).never();
    
    beverage.pour();
}

BOOST_AUTO_TEST_CASE( stops_pump_after_pouring_duration )
{
    MockPump pump;
    MockTimer timer;
    PumpedBeverage beverage{ pump, timer };
    beverage.setPouringDurationInSeconds( 5 );
    mock::sequence s;
    MOCK_EXPECT( timer.moment ).once().in(s).returns(1000);
    MOCK_EXPECT( timer.moment ).once().in(s).returns(6000);
    MOCK_EXPECT( pump.start );
    
    MOCK_EXPECT( pump.stop ).once();
    
    beverage.pour();
}
