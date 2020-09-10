#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_gridPosition

#include "src/movement/position/direction.hpp"
#include "src/movement/position/coordinate.hpp"
#include "src/movement/position/gridPosition.hpp"
#include "src/communication/coordinateListener.hpp"
#include "direction_ostream.hpp"
#include "coordinate_ostream.hpp"
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <turtle/mock.hpp>

namespace data = boost::unit_test::data;

MOCK_BASE_CLASS( MockLocationListener, CoordinateListener )
{
    MOCK_METHOD( update, 1 );
};

BOOST_AUTO_TEST_SUITE( turn_trend_for_location_at_origin )

BOOST_AUTO_TEST_SUITE( forward_direction_is_positve_X )

BOOST_AUTO_TEST_CASE( gives_turn_trend_zero_when_coordinate_is_on_position )
{
    GridPosition position = GridPosition(Coordinate(1,1), Direction::positiveX);
    Coordinate coordinate{ 1, 1 };

    int trend = position.getTurnTrendToReach( coordinate );

    BOOST_TEST( trend == 0 );
}

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


BOOST_AUTO_TEST_SUITE( turning_point )

BOOST_DATA_TEST_CASE( reached_when_moving_in_x_direction_and_having_same_x_value_as_coordinate,
                      data::make({Coordinate(1, 4),
                                  Coordinate(1, 1),
                                  Coordinate(1, -1)}),
                          coordinate )
{
    GridPosition position = GridPosition(Coordinate(1,0), Direction::positiveX);

    bool atTurningPoint = position.isAtTurningPointToReach( coordinate );

    BOOST_TEST( atTurningPoint == true );
}

BOOST_DATA_TEST_CASE( reached_when_moving_in_y_direction_and_having_same_y_value_as_coordinate,
                      data::make({Coordinate(7, 3),
                                  Coordinate(1, 3),
                                  Coordinate(0, 3),
                                  Coordinate(-2, 3)}),
                          coordinate )
{
    GridPosition position = GridPosition(Coordinate(0,3), Direction::negativeY);

    bool atTurningPoint = position.isAtTurningPointToReach( coordinate );

    BOOST_TEST( atTurningPoint == true );
}

BOOST_DATA_TEST_CASE( not_reached,
                      data::make({Coordinate(7, 2),
                                  Coordinate(1, 1),
                                  Coordinate(0, 0),
                                  Coordinate(-2, -1)}),
                          coordinate )
{
    GridPosition position = GridPosition(Coordinate(2,3), Direction::positiveX);

    bool atTurningPoint = position.isAtTurningPointToReach( coordinate );

    BOOST_TEST( atTurningPoint == false );
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE( broadcasting )

BOOST_AUTO_TEST_CASE( broadcasts_location_to_subscriber_when_moving_forward )
{
    GridPosition position = GridPosition(Coordinate(1,2), Direction::positiveX);
    MockLocationListener listener;
    position.subscribe(&listener);
    
    position.broadcast();

    MOCK_EXPECT( listener.update );
}

BOOST_AUTO_TEST_SUITE_END()
