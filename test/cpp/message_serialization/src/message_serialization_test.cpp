#include "message_test_util.h"

#include <boost/shared_array.hpp>
#include <RobotRaconteur/IOUtils.h>

#include <gtest/gtest.h>

using namespace RobotRaconteur;
using namespace RobotRaconteur::test;


TEST(MessageSerializationUnit,RandomTest)
{
    size_t iterations = 100;
    LFSRSeqGen rng((uint32_t)std::time(0), "message_serialization_random_test");
    
    for (size_t i = 0; i < iterations; i++)
    {
        RR_INTRUSIVE_PTR<Message> m = NewRandomTestMessage(rng);

        //Write to stream and read back
        size_t message_size = m->ComputeSize();
        boost::shared_array<uint8_t> buf(new uint8_t[message_size]);
        ArrayBinaryWriter w(buf.get(), 0, message_size);
        m->Write(w);

        ASSERT_EQ(w.Position(),m->ComputeSize());

        ArrayBinaryReader r(buf.get(), 0, message_size);

        RR_INTRUSIVE_PTR<Message> m2 = CreateMessage();
        m2->Read(r);

        CompareMessage(m, m2);
    }


}
	
TEST(MessageSerializationUnit,Test)
{
    RR_INTRUSIVE_PTR<Message> m = NewTestMessage();

    //Write to stream and read back
    size_t message_size=m->ComputeSize();
    boost::shared_array<uint8_t> buf(new uint8_t[message_size]);
    ArrayBinaryWriter w(buf.get(),0,message_size); 
    m->Write(w);

    ASSERT_EQ(w.Position(), m->ComputeSize());

    ArrayBinaryReader r(buf.get(),0,message_size);

    RR_INTRUSIVE_PTR<Message> m2 = CreateMessage();
    m2->Read(r);		

    //Check to make sure the messages match
    CompareMessage(m, m2);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
