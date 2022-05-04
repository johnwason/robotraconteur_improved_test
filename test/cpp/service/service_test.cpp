#include <boost/shared_array.hpp>

#include <gtest/gtest.h>
#include <RobotRaconteur/ServiceDefinition.h>
#include <RobotRaconteur/RobotRaconteurNode.h>

#include "com__robotraconteur__testing__TestService1.h"
#include "com__robotraconteur__testing__TestService1_stubskel.h"

#include "ServiceTestClient.h"
#include "robotraconteur_generated.h"

using namespace RobotRaconteur;
//using namespace RobotRaconteur::test;
using namespace RobotRaconteurTest;


TEST(RobotRaconteurService,PropertyTest)
{
    RobotRaconteurNode::s()->SetLogLevel(RobotRaconteur_LogLevel_Debug);

    ServiceTestClient c;
    ASSERT_NO_THROW(c.ConnectService("rr+tcp://127.0.0.1:22222?service=RobotRaconteurTestService"));
    ASSERT_NO_THROW(c.TestProperties());
    ASSERT_NO_THROW(c.DisconnectService());
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);

    ClientNodeSetup setup(ROBOTRACONTEUR_SERVICE_TYPES,argc,argv);

    int ret = RUN_ALL_TESTS();

    return ret;
}