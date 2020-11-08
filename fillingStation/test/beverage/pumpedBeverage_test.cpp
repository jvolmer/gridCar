#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_pumpedBeverage

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

BOOST_AUTO_TEST_CASE( starts_pump_when_pouring )
{
    MockPump pump;
    PumpedBeverage beverage{ pump };
    
    MOCK_EXPECT( pump.start ).once();
    
    beverage.pour();
}
