#include <sdsl/int_vector.hpp>
#include "int_vector.hpp"

extern "C"
{
    bool FN(int_vector_id, INT_VECTOR_ID) = true;
}

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

int_vector_size_type FN(int_vector_size, INT_VECTOR_ID)(IntVector *v)
{
    const auto &vec = *reinterpret_cast<sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    return vec.size();
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

bool FN(int_vector_store_to_file, INT_VECTOR_ID)(const IntVector *const v,
                                                 const char *const file,
                                                 bool write_fixed_as_variable)
{
    const auto &vec = *reinterpret_cast<const sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    return sdsl::store_to_file(vec, file, write_fixed_as_variable);
}

bool FN(int_vector_load_from_file, INT_VECTOR_ID)(IntVector *v, const char *const file)
{
    auto &vec = *reinterpret_cast<sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    return sdsl::load_from_file(vec, file);
}

void FN(set_to_value, INT_VECTOR_ID)(IntVector *v, uint64_t k)
{
    auto &vec = *reinterpret_cast<sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    sdsl::util::set_to_value(vec, k);
}

void FN(set_to_id, INT_VECTOR_ID)(IntVector *v)
{
    auto &vec = *reinterpret_cast<sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    sdsl::util::set_to_id(vec);
}

void FN(set_random_bits, INT_VECTOR_ID)(IntVector *v)
{
    auto &vec = *reinterpret_cast<sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    sdsl::util::set_random_bits(vec);
}

void FN(mod, INT_VECTOR_ID)(IntVector *v, int_vector_size_type m)
{
    auto &vec = *reinterpret_cast<sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    sdsl::util::mod(vec, m);
}

void FN(bit_compress, INT_VECTOR_ID)(IntVector *v)
{
    auto &vec = *reinterpret_cast<sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    sdsl::util::bit_compress(vec);
}

void FN(expand_width, INT_VECTOR_ID)(IntVector *v, uint8_t new_width)
{
    auto &vec = *reinterpret_cast<sdsl::int_vector<INT_VECTOR_TEMPLATE> *>(v);
    sdsl::util::expand_width(vec, new_width);
}
