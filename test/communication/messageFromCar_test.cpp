#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_message_from_car

#include <iostream>

#include "src/communication/messageFromCar.hpp"
#include "src/communication/transmitter.hpp"
#include "src/communication/coordinateBroadcaster.hpp"
#include "src/movement/position/coordinate.hpp"
#include "test/movement/position/coordinate_ostream.hpp"
#include <boost/test/unit_test.hpp>
#include <turtle/mock.hpp>

MOCK_BASE_CLASS( MockTransmitter, Transmitter )
{
    MOCK_METHOD( setup, 0 );
    MOCK_METHOD( replyToReception, 1 );
    MOCK_METHOD( setReply, 1 );
};

MOCK_BASE_CLASS( MockLocationBroadcaster, CoordinateBroadcaster )
{
    MOCK_METHOD( broadcast, 1 );
    MOCK_METHOD( subscribe, 1 );
};

BOOST_AUTO_TEST_CASE( supplies_a_coordinate_to_transmitter )
{
    MockTransmitter transmitter;
    MockLocationBroadcaster broadcaster;
    MOCK_EXPECT( broadcaster.subscribe );
    MessageFromCar message{ transmitter, broadcaster };
    Coordinate coordinate{ 1, 3 };
    message.update(coordinate);
    
    MOCK_EXPECT( transmitter.setReply ).once();

    Coordinate sent = message.supplyForNextReception();

    BOOST_TEST( sent == coordinate );
}

BOOST_AUTO_TEST_CASE( starts_listening_to_location_broadcaster_when_created )
{
    MockTransmitter transmitter;
    MockLocationBroadcaster broadcaster;
    
    MOCK_EXPECT( broadcaster.subscribe ).once();

    MessageFromCar message{ transmitter, broadcaster };
}
