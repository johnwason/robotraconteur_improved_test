#pragma once

#include "robotraconteur_test_old_seqgen.h"

#ifdef __cplusplus
#include <RobotRaconteur/DataTypes.h>

namespace RobotRaconteur
{
namespace test
{
    ROBOTRACONTEUR_TEST_OLD_SEQGEN_API double OldDouble(const std::string& name);
    ROBOTRACONTEUR_TEST_OLD_SEQGEN_API RR_INTRUSIVE_PTR<RRArray<double> > OldDoubles(const std::string& name);
}
}

#endif