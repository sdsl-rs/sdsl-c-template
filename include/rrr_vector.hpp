#include <sdsl/rrr_vector.hpp>
#include "bit_vector.hpp"
#include "common.hpp"

#ifndef SDSL_C_RRR_VECTOR_H
#define SDSL_C_RRR_VECTOR_H

#define RRR_VECTOR_ID _id
#define RRR_VECTOR_TEMPLATE 63, sdsl::int_vector<>, 32

extern "C"
{
    typedef void RrrVector;
    typedef uint64_t rrr_vector_value_type;
    typedef uint64_t rrr_vector_size_type;

    RrrVector *FN(rrr_vector_create, RRR_VECTOR_ID)(BitVector *v);
    void FN(rrr_vector_destroy, RRR_VECTOR_ID)(RrrVector *v);

    RrrVector *FN(rrr_vector_copy, RRR_VECTOR_ID)(RrrVector *v);
    rrr_vector_size_type FN(rrr_vector_size, RRR_VECTOR_ID)(RrrVector *v);
    bit_vector_value_type FN(rrr_vector_get_bv_element, RRR_VECTOR_ID)(RrrVector *v, const rrr_vector_size_type index);
    uint64_t FN(rrr_vector_get_int, RRR_VECTOR_ID)(RrrVector *v, const rrr_vector_size_type index, uint8_t len);
}

#endif //SDSL_C_RRR_VECTOR_H