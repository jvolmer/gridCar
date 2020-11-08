#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_dispenser

#include "src/dispenser.hpp"
#include "src/beverage/beverage.hpp"

#include <boost/test/unit_test.hpp>
#include <turtle/mock.hpp>


MOCK_BASE_CLASS(MockBeverage, Beverage)
{
    MOCK_METHOD( pour, 0 );
    MOCK_METHOD( setPouringDurationInSeconds, 1 );
};

BOOST_AUTO_TEST_CASE( sets_pouring_duration_for_specified_beverage_when_adding_filling )
{
    MockBeverage beverage1;
    MockBeverage beverage2;
    MockBeverage beverage3;
    MockBeverage beverage4;
    Dispenser dispenser{ beverage1, beverage2, beverage3, beverage4 };

    MOCK_EXPECT( beverage2.setPouringDurationInSeconds ).once().with( 20 );

    dispenser.addFilling(2, 20);
}
