#include <sdsl/int_vector.hpp>
#include "int_vector.hpp"

IntVector *FN(int_vector_create, INT_VECTOR_ID)(int_vector_size_type size, int_vector_value_type default_value, uint8_t t_width)
{
    return reinterpret_cast<IntVector *>(
        new sdsl::int_vector<INT_VECTOR_TEMPLATE>(size, default_value, t_width));
}

void FN(int_vector_destroy, INT_VECTOR_ID)(IntVector *v)
{
    auto &vec = *reinterpret_cast<sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    delete &vec;
}

IntVector *FN(int_vector_copy, INT_VECTOR_ID)(IntVector *v)
{
    auto &vec = *reinterpret_cast<sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    return reinterpret_cast<IntVector *>(
        new sdsl::int_vector<INT_VECTOR_TEMPLATE>(vec));
}

bool FN(int_vector_empty, INT_VECTOR_ID)(IntVector *v)
{
    const auto &vec = *reinterpret_cast<sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    return vec.empty();
}

void FN(int_vector_resize, INT_VECTOR_ID)(IntVector *v, const int_vector_size_type size)
{
    auto &vec = *reinterpret_cast<sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    vec.resize(size);
}

void FN(int_vector_bit_resize, INT_VECTOR_ID)(IntVector *v, const int_vector_size_type size)
{
    auto &vec = *reinterpret_cast<sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    vec.bit_resize(size);
}

int_vector_size_type FN(int_vector_size, INT_VECTOR_ID)(IntVector *v)
{
    const auto &vec = *reinterpret_cast<sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    return vec.size();
}

int_vector_size_type FN(int_vector_max_size, INT_VECTOR_ID)(IntVector *v)
{
    const auto &vec = *reinterpret_cast<sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    return vec.max_size();
}

int_vector_size_type FN(int_vector_bit_size, INT_VECTOR_ID)(IntVector *v)
{
    const auto &vec = *reinterpret_cast<sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    return vec.bit_size();
}

int_vector_size_type FN(int_vector_capacity, INT_VECTOR_ID)(IntVector *v)
{
    const auto &vec = *reinterpret_cast<sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    return vec.capacity();
}

const uint64_t *FN(int_vector_data, INT_VECTOR_ID)(IntVector *v)
{
    const auto &vec = *reinterpret_cast<sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    return vec.data();
}

uint8_t FN(int_vector_width, INT_VECTOR_ID)(IntVector *v)
{
    const auto &vec = *reinterpret_cast<sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    return vec.width();
}

void FN(int_vector_set_width, INT_VECTOR_ID)(IntVector *v, uint8_t new_width)
{
    auto &vec = *reinterpret_cast<sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    vec.width(new_width);
}

int_vector_value_type FN(int_vector_get_int, INT_VECTOR_ID)(IntVector *v, const int_vector_size_type index, const uint8_t len)
{
    const auto &vec = *reinterpret_cast<sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    return vec.get_int(index, len);
}

void FN(int_vector_set_int, INT_VECTOR_ID)(IntVector *v, const int_vector_size_type index, const int_vector_value_type value, const uint8_t len)
{
    auto &vec = *reinterpret_cast<sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    vec.set_int(index, value, len);
}

uint64_t FN(int_vector_get_element, INT_VECTOR_ID)(IntVector *v, const int_vector_size_type index)
{
    const auto &vec = *reinterpret_cast<sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    return vec[index];
}

void FN(int_vector_set_element, INT_VECTOR_ID)(IntVector *v, const int_vector_size_type index, const int_vector_value_type value)
{
    auto &vec = *reinterpret_cast<sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    vec[index] = value;
}
