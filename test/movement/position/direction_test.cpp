#include "src/movement/position/direction.hpp"
#include "direction_ostream.hpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE( DirectionTest )

BOOST_AUTO_TEST_CASE( returnsValidDirectionWhenAddingInteger )
{
    BOOST_TEST( Direction::positiveX + 1 == Direction::positiveY );
    BOOST_TEST( Direction::positiveY + 3 == Direction::positiveX );
    BOOST_TEST( Direction::negativeY + 10 == Direction::positiveY );
}

BOOST_AUTO_TEST_CASE( returnsValidDirectionWhenSubtractingInteger )
{
    BOOST_TEST( Direction::positiveY - 1 == Direction::positiveX );
    BOOST_TEST( Direction::positiveX - 2 == Direction::negativeX );
    BOOST_TEST( Direction::negativeY - 8 == Direction::negativeY );
}

BOOST_AUTO_TEST_SUITE_END()
