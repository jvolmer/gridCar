#include "src/communication/messageOut.hpp"
#include "src/communication/transmitter.hpp"
#include "src/communication/coordinateBroadcaster.hpp"
#include "src/movement/position/coordinate.hpp"
#include "test/movement/position/coordinate_ostream.hpp"
#include <boost/test/unit_test.hpp>
#include <turtle/mock.hpp>

BOOST_AUTO_TEST_SUITE( MessageOutTest )

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
    MessageOut message{ transmitter};
    Coordinate coordinate{ 1, 3 };
    message.update(coordinate);
    
    MOCK_EXPECT( transmitter.setReply ).once();

    Coordinate sent = message.supplyForNextReception();

    BOOST_TEST( sent == coordinate );
}

BOOST_AUTO_TEST_CASE( listens_to_broadcaster )
{
    MockTransmitter transmitter;
    MessageOut message{ transmitter };
    MockLocationBroadcaster broadcaster;
    
    MOCK_EXPECT( broadcaster.subscribe ).once();

    message.listenTo( broadcaster );
}

BOOST_AUTO_TEST_SUITE_END()
