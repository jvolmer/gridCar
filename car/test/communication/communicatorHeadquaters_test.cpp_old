#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_communication_with_headquaters

#include <iostream>

#include "src/communication/communicatorHeadquaters.hpp"
#include "src/communication/radio.hpp"
#include "src/communication/transmission.hpp"
#include "src/movement/position/coordinate.hpp"
#include "test/communication/transmission_ostream.hpp"
#include <boost/test/unit_test.hpp>
#include <turtle/mock.hpp>

MOCK_BASE_CLASS( MockRadio, Radio )
{
    MOCK_METHOD( isAvailable, 0 );
    MOCK_METHOD( receive, 0 );
    MOCK_METHOD( replyWith, 1 );
};

BOOST_AUTO_TEST_SUITE( carCommunication )

BOOST_AUTO_TEST_CASE( savesHeadquatersTransmission_ifHeadquatersTransmissionIsReceived )
{
    TransmissionToCar package = TransmissionToCar(Coordinate(14.2,111.1));

    MockRadio radio;
    CommunicatorHeadquaters communicator(radio);

    MOCK_EXPECT( radio.isAvailable ).returns( true );
    MOCK_EXPECT( radio.receive ).returns( package );

    communicator.receive();

    const TransmissionToCar& communicatorTransmission = communicator.getReceivedData();

    BOOST_TEST( communicatorTransmission == package );
}

BOOST_AUTO_TEST_CASE( sendsTransmissionToHeadquaters_ifCommunicatorHasAValidTransmission )
{
    // not yet finished! what should be tested in the end?
    TransmissionFromCar package = TransmissionFromCar(Coordinate(14.2,111.1), 108, 33);

    MockRadio radio;
    CommunicatorHeadquaters communicator(radio);
    communicator.setDataToSend(package);
    
    MOCK_EXPECT( radio.replyWith ).once().with( package );

    communicator.reply();
}


BOOST_AUTO_TEST_SUITE_END()
