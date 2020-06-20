#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_gridPosition

#include "src/movement/position/direction.hpp"
#include "src/movement/position/coordinate.hpp"
#include "src/movement/position/gridPosition.hpp"
#include "direction_ostream.hpp"
#include "coordinate_ostream.hpp"
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

namespace data = boost::unit_test::data;

BOOST_AUTO_TEST_SUITE( location_at_origin )

BOOST_AUTO_TEST_SUITE( forward_direction_is_positve_X )

BOOST_DATA_TEST_CASE( gives_turn_trend_zero_when_coordinate_is_in_front_cone,
                      data::make({Coordinate(2, -1),
                                  Coordinate(1, 0),
                                  Coordinate(2, 1)}),
                      coordinate )
{
    GridPosition position = GridPosition(Coordinate(0,0), Direction::positiveX);

    int trend = position.getTurnTrendToReach( coordinate );

    BOOST_TEST( trend == 0 );
}

BOOST_DATA_TEST_CASE( gives_negative_turn_trend_when_coordinate_is_in_left_half_but_not_front_cone,
                      data::make({Coordinate(1, 1),
                                  Coordinate(0, 1),
                                  Coordinate(-1, 1),
                                  Coordinate(-1, 0)}),
                      coordinate )
{
    GridPosition position = GridPosition(Coordinate(0,0), Direction::positiveX);

    int trend = position.getTurnTrendToReach( coordinate );

    BOOST_TEST( trend == -1 );
}

BOOST_DATA_TEST_CASE( gives_positive_turn_trend_when_coordinate_is_in_right_half_but_not_front_cone,
                      data::make({Coordinate(-2, -1),
                                  Coordinate(-1, -1),
                                  Coordinate(0, -1),
                                  Coordinate(1, -1)}),
                      coordinate )
{
    GridPosition position = GridPosition(Coordinate(0,0), Direction::positiveX);

    int trend = position.getTurnTrendToReach( coordinate );

    BOOST_TEST( trend == 1 );
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE( forward_direction_is_positve_Y )

BOOST_DATA_TEST_CASE( gives_turn_trend_zero_when_coordinate_is_in_front_cone,
                      data::make({Coordinate(1, 2),
                                  Coordinate(0, 1),
                                  Coordinate(-1, 2)}),
                      coordinate )
{
    GridPosition position = GridPosition(Coordinate(0,0), Direction::positiveY);

    int trend = position.getTurnTrendToReach( coordinate );

    BOOST_TEST( trend == 0 );
}

BOOST_DATA_TEST_CASE( gives_negative_turn_trend_when_coordinate_is_in_left_half_but_not_front_cone,
                      data::make({Coordinate(-1, 1),
                                  Coordinate(-1, 0),
                                  Coordinate(-1, -1),
                                  Coordinate(0, -1)
                                  }),
                      coordinate )
{
    GridPosition position = GridPosition(Coordinate(0,0), Direction::positiveY);

    int trend = position.getTurnTrendToReach( coordinate );

    BOOST_TEST( trend == -1 );
}

BOOST_DATA_TEST_CASE( gives_positive_turn_trend_when_coordinate_is_in_right_half_but_not_front_cone,
                      data::make({Coordinate(1, -2),
                                  Coordinate(1, -1),
                                  Coordinate(1, 0),
                                  Coordinate(1, 1)}),
                      coordinate )
{
    GridPosition position = GridPosition(Coordinate(0,0), Direction::positiveY);

    int trend = position.getTurnTrendToReach( coordinate );

    BOOST_TEST( trend == 1 );
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE( forward_direction_is_negative_X )

BOOST_DATA_TEST_CASE( gives_turn_trend_zero_when_coordinate_is_in_front_cone,
                      data::make({Coordinate(-2, 1),
                                  Coordinate(-1, 0),
                                  Coordinate(-2, -1)}),
                      coordinate )
{
    GridPosition position = GridPosition(Coordinate(0,0), Direction::negativeX);

    int trend = position.getTurnTrendToReach( coordinate );

    BOOST_TEST( trend == 0 );
}

BOOST_DATA_TEST_CASE( gives_negative_turn_trend_when_coordinate_is_in_left_half_but_not_front_cone,
                      data::make({Coordinate(-1, -1),
                                  Coordinate(0, -1),
                                  Coordinate(1, -1),
                                  Coordinate(1, 0)
                                  }),
                      coordinate )
{
    GridPosition position = GridPosition(Coordinate(0,0), Direction::negativeX);

    int trend = position.getTurnTrendToReach( coordinate );

    BOOST_TEST( trend == -1 );
}

BOOST_DATA_TEST_CASE( gives_positive_turn_trend_when_coordinate_is_in_right_half_but_not_front_cone,
                      data::make({Coordinate(2, 1),
                                  Coordinate(1, 1),
                                  Coordinate(0, 1),
                                  Coordinate(-1, 1)}),
                      coordinate )
{
    GridPosition position = GridPosition(Coordinate(0,0), Direction::negativeX);

    int trend = position.getTurnTrendToReach( coordinate );

    BOOST_TEST( trend == 1 );
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE( forward_direction_is_negative_Y )

BOOST_DATA_TEST_CASE( gives_turn_trend_zero_when_coordinate_is_in_front_cone,
                      data::make({Coordinate(-1, -2),
                                  Coordinate(0, -1),
                                  Coordinate(1, -2)}),
                      coordinate )
{
    GridPosition position = GridPosition(Coordinate(0,0), Direction::negativeY);

    int trend = position.getTurnTrendToReach( coordinate );

    BOOST_TEST( trend == 0 );
}

BOOST_DATA_TEST_CASE( gives_negative_turn_trend_when_coordinate_is_in_left_half_but_not_front_cone,
                      data::make({Coordinate(1, -1),
                                  Coordinate(1, 0),
                                  Coordinate(1, 1),
                                  Coordinate(0, 1)
                                  }),
                      coordinate )
{
    GridPosition position = GridPosition(Coordinate(0,0), Direction::negativeY);

    int trend = position.getTurnTrendToReach( coordinate );

    BOOST_TEST( trend == -1 );
}

BOOST_DATA_TEST_CASE( gives_positive_turn_trend_when_coordinate_is_in_right_half_but_not_front_cone,
                      data::make({Coordinate(-1, 2),
                                  Coordinate(-1, 1),
                                  Coordinate(-1, 0),
                                  Coordinate(-1, -1)}),
                      coordinate )
{
    GridPosition position = GridPosition(Coordinate(0,0), Direction::negativeY);

    int trend = position.getTurnTrendToReach( coordinate );

    BOOST_TEST( trend == 1 );
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
