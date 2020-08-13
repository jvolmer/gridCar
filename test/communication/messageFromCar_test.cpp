#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_message_from_car

#include <iostream>

#include "src/communication/messageFromCar.hpp"
#include "src/communication/transmitter.hpp"
#include "src/movement/position/coordinate.hpp"
#include "test/movement/position/coordinate_ostream.hpp"
#include <boost/test/unit_test.hpp>
#include <turtle/mock.hpp>

MOCK_BASE_CLASS( MockTransmitter, Transmitter )
{
    MOCK_METHOD( receive, 1 );
    MOCK_METHOD( replyWith, 1 );
};

BOOST_AUTO_TEST_CASE( supplies_a_coordinate_to_transmitter )
{
    MockTransmitter transmitter;
    Coordinate coordinate{ 1, 3 };
    MessageFromCar message{ transmitter };
    message.set(coordinate);
    
    MOCK_EXPECT( transmitter.replyWith ).once();

    Coordinate sent = message.supply();
    BOOST_TEST( sent == coordinate );
}
