#include <boost/shared_array.hpp>

#include <gtest/gtest.h>
#include <RobotRaconteur/ServiceDefinition.h>
#include <RobotRaconteur/RobotRaconteurNode.h>

#include "ServiceTestClient3.h"
#include "robotraconteur_generated.h"

using namespace RobotRaconteur;
//using namespace RobotRaconteur::test;
using namespace RobotRaconteurTest;


static std::string service3_url = "rr+tcp://127.0.0.1:22222?service=RobotRaconteurTestService3";


TEST(RobotRaconteurService,Properties3Test)
{
    RobotRaconteurNode::s()->SetLogLevelFromEnvVariable();

    ServiceTestClient3 c;
    ASSERT_NO_THROW(c.Connect(service3_url));
    ASSERT_NO_THROW(c.TestProperties());
    ASSERT_NO_THROW(c.Disconnect());
}

TEST(RobotRaconteurService,Functions3Test)
{
    RobotRaconteurNode::s()->SetLogLevelFromEnvVariable();

    ServiceTestClient3 c;
    ASSERT_NO_THROW(c.Connect(service3_url));
    ASSERT_NO_THROW(c.TestProperties());
    ASSERT_NO_THROW(c.Disconnect());
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);

    ClientNodeSetup setup(ROBOTRACONTEUR_SERVICE_TYPES,argc,argv);

    int ret = RUN_ALL_TESTS();

    return ret;
}