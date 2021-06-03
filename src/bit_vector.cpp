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

size_type FN(bit_vector_size, BIT_VECTOR_ID)(BitVector *v)
{
    const auto &vec = *reinterpret_cast<sdsl::bit_vector *>(v);
    return vec.size();
}

size_type FN(bit_vector_max_size, BIT_VECTOR_ID)(BitVector *v)
{
    const auto &vec = *reinterpret_cast<sdsl::bit_vector *>(v);
    return vec.max_size();
}

size_type FN(bit_vector_bit_size, BIT_VECTOR_ID)(BitVector *v)
{
    const auto &vec = *reinterpret_cast<sdsl::bit_vector *>(v);
    return vec.bit_size();
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

bit_vector_value_type FN(bit_vector_get_int, BIT_VECTOR_ID)(BitVector *v, const size_type index, const uint8_t len)
{
    const auto &vec = *reinterpret_cast<sdsl::bit_vector *>(v);
    return vec.get_int(index, len);
}

void FN(bit_vector_set_int, BIT_VECTOR_ID)(BitVector *v, const size_type index, const bit_vector_value_type value, const uint8_t len)
{
    auto &vec = *reinterpret_cast<sdsl::bit_vector *>(v);
    vec.set_int(index, value, len);
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

bool FN(bit_vector_equality_operator, BIT_VECTOR_ID)(BitVector *v, BitVector *other)
{
    const auto &vec = *reinterpret_cast<sdsl::bit_vector *>(v);
    const auto &other_vec = *reinterpret_cast<sdsl::bit_vector *>(other);
    return vec == other_vec;
}

void FN(bit_vector_flip, BIT_VECTOR_ID)(BitVector *v)
{
    auto &vec = *reinterpret_cast<sdsl::bit_vector *>(v);
    vec.flip();
}
