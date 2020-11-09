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

BOOST_AUTO_TEST_CASE( selects_beverage_with_specified_pouring_duration )
{
    MockBeverage beverage0;
    MockBeverage beverage1;
    MockBeverage beverage2;
    MockBeverage beverage3;
    Dispenser dispenser{ beverage0, beverage1, beverage2, beverage3 };

    MOCK_EXPECT( beverage2.setPouringDurationInSeconds ).once().with( 20 );

    dispenser.selectBeverageForDuration(2, 20);
}

BOOST_AUTO_TEST_CASE( selects_no_beverage_for_invalid_beverage_id )
{
    MockBeverage beverage0;
    MockBeverage beverage1;
    MockBeverage beverage2;
    MockBeverage beverage3;
    Dispenser dispenser{ beverage0, beverage1, beverage2, beverage3 };

    MOCK_EXPECT( beverage0.setPouringDurationInSeconds ).never();
    MOCK_EXPECT( beverage1.setPouringDurationInSeconds ).never();
    MOCK_EXPECT( beverage2.setPouringDurationInSeconds ).never();
    MOCK_EXPECT( beverage3.setPouringDurationInSeconds ).never();

    dispenser.selectBeverageForDuration(4, 20);
}

BOOST_AUTO_TEST_CASE( draws_from_all_beverages )
{
    MockBeverage beverage0;
    MockBeverage beverage1;
    MockBeverage beverage2;
    MockBeverage beverage3;
    Dispenser dispenser{ beverage0, beverage1, beverage2, beverage3 };

    MOCK_EXPECT( beverage0.pour ).once();
    MOCK_EXPECT( beverage1.pour ).once();
    MOCK_EXPECT( beverage2.pour ).once();
    MOCK_EXPECT( beverage3.pour ).once();
    
    dispenser.draw();
}
