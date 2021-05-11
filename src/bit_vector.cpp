#include <sdsl/int_vector.hpp>
#include "bit_vector.hpp"

BitVector *FN(bit_vector_create, BIT_VECTOR_ID)(size_type size, value_type default_value)
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

size_type FN(bit_vector_size, BIT_VECTOR_ID)(BitVector *v)
{
    const auto &vec = *reinterpret_cast<sdsl::bit_vector *>(v);
    return vec.size();
}

value_type FN(bit_vector_get_bit, BIT_VECTOR_ID)(BitVector *v, const size_type index)
{
    const auto &vec = *reinterpret_cast<sdsl::bit_vector *>(v);
    return vec[index];
}

void FN(bit_vector_set_bit, BIT_VECTOR_ID)(BitVector *v, const size_type index, const value_type value)
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

void FN(bit_vector_swap, BIT_VECTOR_ID)(BitVector *v_primary, BitVector *v_secondary)
{
    auto &vec_primary = *reinterpret_cast<sdsl::bit_vector *>(v_primary);
    auto &vec_secondary = *reinterpret_cast<sdsl::bit_vector *>(v_secondary);
    vec_primary.swap(vec_secondary);
}

void FN(bit_vector_bit_resize, BIT_VECTOR_ID)(BitVector *v, const size_type size)
{
    auto &vec = *reinterpret_cast<sdsl::bit_vector *>(v);
    vec.bit_resize(size);
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

bool FN(bit_vector_store_to_file, BIT_VECTOR_ID)(const BitVector *const v,
                                                 const char *const file,
                                                 bool write_fixed_as_variable)
{
    const auto &vec = *reinterpret_cast<const sdsl::bit_vector *>(v);
    return sdsl::store_to_file(vec, file, write_fixed_as_variable);
}

bool FN(bit_vector_load_from_file, BIT_VECTOR_ID)(BitVector *v, const char *const file)
{
    auto &vec = *reinterpret_cast<sdsl::bit_vector *>(v);
    return sdsl::load_from_file(vec, file);
}
