#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_direction

#include "entity/direction.hpp"
#include "test/entity/IOOperatorOverloading.hpp"
#include <boost/test/unit_test.hpp>

 
BOOST_AUTO_TEST_CASE( returnsValidDirectionWhenAddingInteger )
{
    BOOST_TEST( Direction::positiveX + 1 == Direction::negativeY );
    BOOST_TEST( Direction::positiveY + 3 == Direction::negativeX );
    BOOST_TEST( Direction::negativeY + 10 == Direction::positiveY );
}

BOOST_AUTO_TEST_CASE( returnsValidDirectionWhenSubtractingInteger )
{
    BOOST_TEST( Direction::positiveY - 1 == Direction::negativeX );
    BOOST_TEST( Direction::positiveX - 2 == Direction::negativeX );
    BOOST_TEST( Direction::negativeY - 8 == Direction::negativeY );
}
