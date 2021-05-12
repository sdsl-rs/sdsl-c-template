#include <sdsl/util.hpp>
#include <sdsl/int_vector.hpp>

#include "common.hpp"

#ifndef SDSL_C_UTIL_H
#define SDSL_C_UTIL_H

#define UTIL_ID _id
#define STRUCTURE sdsl::int_vector<0>

extern "C"
{
    typedef void Structure;
    typedef uint64_t size_type;

    void FN(set_to_value, UTIL_ID)(Structure *v, uint64_t k);
    void FN(set_to_id, UTIL_ID)(Structure *v);
    void FN(set_random_bits, UTIL_ID)(Structure *v);
    void FN(mod, UTIL_ID)(Structure *v, size_type m);
    void FN(bit_compress, UTIL_ID)(Structure *v);
    void FN(expand_width, UTIL_ID)(Structure *v, uint8_t new_width);
}

#endif //SDSL_C_UTIL_H