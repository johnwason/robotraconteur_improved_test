#include "robotraconteur_test_old_seqgen_cpp.h"

namespace RobotRaconteur
{
namespace test
{

    double OldDouble(const std::string& name)
    {
        size_t rr_len;
        if (!robotraconteur_test_old_seqgen_len(name.c_str(),&rr_len))
        {
            throw std::runtime_error("Invalid old seqgen name: " + name);
        }

        if (rr_len != 1)
        {
            throw std::runtime_error("Invalid old seqgen scalar: " + name);
        }

        double val;
        if (!robotraconteur_test_old_seqgen_double_array(name.c_str(), &val, 1))
        {
            throw std::runtime_error("Invalid old seqgen double: " + name);
        }

        return val;
    }

    RR_INTRUSIVE_PTR<RRArray<double> > OldDoubles(const std::string& name)
    {
        size_t rr_len;
        if (!robotraconteur_test_old_seqgen_len(name.c_str(),&rr_len))
        {
            throw std::runtime_error("Invalid old seqgen name: " + name);
        }

        RR_INTRUSIVE_PTR<RRArray<double> > ret=AllocateRRArray<double>(rr_len);

        if (!robotraconteur_test_old_seqgen_double_array(name.c_str(), ret->data(), ret->size()))
        {
            throw std::runtime_error("Invalid old seqgen double: " + name);
        }

        return ret;
    }   
}
}