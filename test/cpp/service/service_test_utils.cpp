#include "service_test_utils.h"

#include <boost/algorithm/string.hpp>

namespace RobotRaconteur
{
namespace test
{

GTestThreadLocalListener::GTestThreadLocalListener()
{
    failure_count = 0;
    thread_id = boost::this_thread::get_id();
}
void GTestThreadLocalListener::OnTestPartResult(const testing::TestPartResult& test_part_result)
{
    if (!test_part_result.failed())
    {
        return;
    }
    if (boost::this_thread::get_id() != thread_id)
    {
        return;
    }

    failure_count++;

    std::string msg(test_part_result.message());
    boost::replace_all(msg, "\n", "\\n");
    msg += (" " + std::string(test_part_result.file_name()) + "(" + boost::lexical_cast<std::string>(test_part_result.line_number()) + ")");

    failures_msg += "\\n\\n" + msg;
}
uint32_t GTestThreadLocalListener::FailureCount()
{
    return failure_count;
}
std::string GTestThreadLocalListener::FailuresMessage()
{
    return failures_msg;
}
GTestThreadLocalListener::~GTestThreadLocalListener()
{

}

ThrowIfFailures::ThrowIfFailures()
{
    gtest_listener = RR_MAKE_SHARED<GTestThreadLocalListener>();

    testing::TestEventListeners& listeners = testing::UnitTest::GetInstance()->listeners();
    listeners.Append(gtest_listener.get());

}   

uint32_t ThrowIfFailures::FailureCount()
{
    if (!gtest_listener) return 0;
    return gtest_listener->FailureCount();
}

std::string ThrowIfFailures::FailuresMessage()
{
    if (!gtest_listener) return "";
    return gtest_listener->FailuresMessage();
}

void ThrowIfFailures::Throw()
{
    if (FailureCount() > 0)
    {
        std::string msg = FailuresMessage();
        if (msg.size() > 256)
        {
            msg = msg.substr(0,253) + "...";
        }
        throw std::runtime_error("Test failures occurred: " + FailuresMessage());
    }

}

ThrowIfFailures::~ThrowIfFailures()
{
    testing::TestEventListeners& listeners = testing::UnitTest::GetInstance()->listeners();
    listeners.Release(gtest_listener.get());
}

}
}