#include "array_compare.h"

#pragma once

namespace RobotRaconteur
{
namespace test
{

class GTestThreadLocalListener : public testing::EmptyTestEventListener
{
public:
    GTestThreadLocalListener();
    virtual void OnTestPartResult(const testing::TestPartResult& test_part_result);
    uint32_t FailureCount();
    std::string FailuresMessage();
    virtual ~GTestThreadLocalListener();

    boost::thread::id thread_id;
    uint32_t failure_count;
    std::string failures_msg;
};

class ThrowIfFailures
{
public:
    ThrowIfFailures();
    uint32_t FailureCount();
    std::string FailuresMessage();
    void Throw();
    virtual ~ThrowIfFailures();

    RR_SHARED_PTR<GTestThreadLocalListener> gtest_listener;
};

}
}