#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_message_to_car

#include <iostream>

#include "src/communication/messageToCar.hpp"
#include "src/communication/transmitter.hpp"
#include "src/communication/coordinateListener.hpp"
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

MOCK_BASE_CLASS( MockGoalListener, CoordinateListener )
{
    MOCK_METHOD( listenTo, 1 );
    MOCK_METHOD( update, 1 );
};

BOOST_AUTO_TEST_CASE( receives_a_coordinate_from_transmitter )
{
    MockTransmitter transmitter;
    MessageToCar message{ transmitter };    
    Coordinate coordinate{ 1, 3 };
    MOCK_EXPECT( transmitter.replyToReception ).returns( coordinate );
    
    Coordinate received = message.receive();
    
    BOOST_TEST( received == coordinate );
}

BOOST_AUTO_TEST_CASE( broadcasts_goal_to_subscriber_when_receiving )
{
    MockTransmitter transmitter;
    MessageToCar message{ transmitter };
    MockGoalListener listener;
    message.subscribe( &listener );
    Coordinate coordinate{ 1, 3 };
    MOCK_EXPECT( transmitter.replyToReception ).returns( coordinate );
    
    MOCK_EXPECT( listener.update ).once().with( coordinate );

    message.receive();
}
