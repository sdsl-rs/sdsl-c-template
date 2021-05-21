#include <sdsl/int_vector.hpp>
#include "bit_vector.hpp"

BitVector *FN(bit_vector_create, BIT_VECTOR_ID)(size_type size, bit_vector_value_type default_value)
{
    uint8_t t_width = 1;
    return reinterpret_cast<BitVector *>(
        new sdsl::bit_vector(size, default_value, t_width));
}

void FN(bit_vector_destroy, BIT_VECTOR_ID)(BitVector *v)
{
    auto &vec = *reinterpret_cast<sdsl::bit_vector *>(v);
    delete &vec;
}

BitVector *FN(bit_vector_copy, BIT_VECTOR_ID)(BitVector *v)
{
    auto &vec = *reinterpret_cast<sdsl::bit_vector *>(v);
    return reinterpret_cast<BitVector *>(
        new sdsl::bit_vector(vec));
}

size_type FN(bit_vector_size, BIT_VECTOR_ID)(BitVector *v)
{
    const auto &vec = *reinterpret_cast<sdsl::bit_vector *>(v);
    return vec.size();
}

bit_vector_value_type FN(bit_vector_get_element, BIT_VECTOR_ID)(BitVector *v, const size_type index)
{
    const auto &vec = *reinterpret_cast<sdsl::bit_vector *>(v);
    return vec[index];
}

void FN(bit_vector_set_element, BIT_VECTOR_ID)(BitVector *v, const size_type index, const bit_vector_value_type value)
{
    auto &vec = *reinterpret_cast<sdsl::bit_vector *>(v);
    vec[index] = value;
}

bool FN(bit_vector_empty, BIT_VECTOR_ID)(BitVector *v)
{
    const auto &vec = *reinterpret_cast<sdsl::bit_vector *>(v);
    return vec.empty();
}

void FN(bit_vector_resize, BIT_VECTOR_ID)(BitVector *v, const size_type size)
{
    auto &vec = *reinterpret_cast<sdsl::bit_vector *>(v);
    vec.resize(size);
}

size_type FN(bit_vector_capacity, BIT_VECTOR_ID)(BitVector *v)
{
    const auto &vec = *reinterpret_cast<sdsl::bit_vector *>(v);
    return vec.capacity();
}

const uint64_t *FN(bit_vector_data, BIT_VECTOR_ID)(BitVector *v)
{
    const auto &vec = *reinterpret_cast<const sdsl::bit_vector *>(v);
    return vec.data();
}
