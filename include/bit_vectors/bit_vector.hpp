#include "common.hpp"
#include <sdsl/int_vector.hpp>

#ifndef SDSL_C_BIT_VECTOR_HPP
#define SDSL_C_BIT_VECTOR_HPP

#define BIT_VECTOR_ID _id

extern "C"
{
    typedef void BitVector;
    typedef uint64_t bit_vector_value_type;
    typedef uint64_t size_type;

    BitVector *FN(bit_vector_create, BIT_VECTOR_ID)(size_type size, bit_vector_value_type default_value);
    void FN(bit_vector_destroy, BIT_VECTOR_ID)(BitVector *v);
    BitVector *FN(bit_vector_copy, BIT_VECTOR_ID)(BitVector *v);
    bool FN(bit_vector_empty, BIT_VECTOR_ID)(BitVector *v);

    void FN(bit_vector_resize, BIT_VECTOR_ID)(BitVector *v, const size_type size);
    size_type FN(bit_vector_size, BIT_VECTOR_ID)(BitVector *v);
    size_type FN(bit_vector_max_size, BIT_VECTOR_ID)(BitVector *v);
    size_type FN(bit_vector_bit_size, BIT_VECTOR_ID)(BitVector *v);
    size_type FN(bit_vector_capacity, BIT_VECTOR_ID)(BitVector *v);

    const uint64_t *FN(bit_vector_data, BIT_VECTOR_ID)(BitVector *v);

    bit_vector_value_type FN(bit_vector_get_int, BIT_VECTOR_ID)(BitVector *v, const size_type index, const uint8_t len);
    void FN(bit_vector_set_int, BIT_VECTOR_ID)(BitVector *v, const size_type index, const bit_vector_value_type value, const uint8_t len);

    bit_vector_value_type FN(bit_vector_get_element, BIT_VECTOR_ID)(BitVector *v, const size_type index);
    void FN(bit_vector_set_element, BIT_VECTOR_ID)(BitVector *v, const size_type index, const bit_vector_value_type value);

    void FN(bit_vector_flip, BIT_VECTOR_ID)(BitVector *v);

    bool FN(bit_vector_equality_operator, BIT_VECTOR_ID)(BitVector *v, BitVector *other);
}

#endif //SDSL_C_BIT_VECTOR_HPP
