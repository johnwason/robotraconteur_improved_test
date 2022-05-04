#include "robotraconteur_test_old_seqgen_cpp.h"

namespace RobotRaconteur
{
namespace test
{

#define SCALAR_READ(ctype,seqtype) \
    size_t rr_len; \
    if (!robotraconteur_test_old_seqgen_len(name.c_str(),&rr_len)) \
    { \
        throw std::runtime_error("Invalid old seqgen name: " + name); \
    } \
    \
    if (rr_len != 1) \
    { \
        throw std::runtime_error("Invalid old seqgen scalar: " + name); \
    } \
    \
    ctype val; \
    if (!robotraconteur_test_old_seqgen_ ## seqtype ## _array(name.c_str(), &val, 1)) \
    { \
        throw std::runtime_error("Invalid old seqgen double: " + name); \
    } \
    return val;

#define ARRAY_READ(ctype,seqtype) \
    size_t rr_len; \
    if (!robotraconteur_test_old_seqgen_len(name.c_str(),&rr_len)) \
    { \
        throw std::runtime_error("Invalid old seqgen name: " + name); \
    } \
    RR_INTRUSIVE_PTR<RRArray<ctype> > ret=AllocateRRArray<ctype>(rr_len); \
    if (!robotraconteur_test_old_seqgen_ ## seqtype ## _array(name.c_str(), ret->data(), ret->size())) \
    { \
        throw std::runtime_error("Invalid old seqgen double: " + name); \
    } \
    return ret;

    double OldDouble(const std::string& name)
    {
        SCALAR_READ(double,double)
    }

    RR_INTRUSIVE_PTR<RRArray<double> > OldDoubles(const std::string& name)
    {
        ARRAY_READ(double,double)
    }   

    RR_INTRUSIVE_PTR<RRMultiDimArray<double> > OldMDoubles(const std::string& name)
    {
        RR_INTRUSIVE_PTR<RRArray<double> > arr = OldDoubles(name);
        RR_INTRUSIVE_PTR<RRArray<uint32_t> > dims = OldUInt32s(name + "_dims");

        return AllocateRRMultiDimArray<double>(dims, arr);
    }

    RR_INTRUSIVE_PTR<RRArray<uint32_t> > OldUInt32s(const std::string& name)
    {
        ARRAY_READ(uint32_t, uint32)
    }   
}
}