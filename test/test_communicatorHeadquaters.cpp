#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_communication_with_headquaters

#include <iostream>

#include "communicatorHeadquaters.hpp"
#include "radio.hpp"
#include "package.hpp"
#include <boost/test/unit_test.hpp>
#include <turtle/mock.hpp>

MOCK_BASE_CLASS( MockRadio, Radio )
{
    MOCK_METHOD( isAvailable, 0 );
    MOCK_METHOD( receive, 0 );
    MOCK_METHOD( replyWith, 1 );
};

BOOST_AUTO_TEST_SUITE( carCommunication )

BOOST_AUTO_TEST_CASE( savesHeadquatersPackage_ifHeadquatersPackageIsReceived )
{
    PackageToCar package = PackageToCar(Point(14.2,111.1));

    MockRadio radio;
    CommunicatorHeadquaters communicator(radio);

    MOCK_EXPECT( radio.isAvailable ).returns( true );
    MOCK_EXPECT( radio.receive ).returns( package );

    communicator.receive();

    PackageToCar& communicatorPackage = communicator.getReceivedData();

    BOOST_TEST( communicatorPackage == package );
}

BOOST_AUTO_TEST_CASE( sendsPackageToHeadquaters_ifCommunicatorHasAValidPackage )
{
    // not yet finished! what should be tested in the end?
    PackageFromCar package = PackageFromCar(Point(14.2,111.1), 108, 33);

    MockRadio radio;
    CommunicatorHeadquaters communicator(radio);
    communicator.setDataToSend(package);
    
    MOCK_EXPECT( radio.replyWith ).once().with( package );

    communicator.reply();
}


BOOST_AUTO_TEST_SUITE_END()
