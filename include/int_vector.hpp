#include "common.hpp"

#ifndef SDSL_C_INT_VECTOR_H
#define SDSL_C_INT_VECTOR_H

#define INT_VECTOR_ID _id
#define INT_VECTOR_TEMPLATE

extern "C"
{
    struct IntVector;
    typedef struct IntVector IntVector;
    typedef uint64_t int_vector_value_type;
    typedef uint64_t int_vector_size_type;

    IntVector *FN(int_vector_create, INT_VECTOR_ID)(int_vector_size_type size, int_vector_value_type default_value, uint8_t t_width);
    void FN(int_vector_destroy, INT_VECTOR_ID)(IntVector *v);
    IntVector *FN(int_vector_copy, INT_VECTOR_ID)(IntVector *v);
    int_vector_size_type FN(int_vector_size, INT_VECTOR_ID)(IntVector *v);
    uint64_t FN(int_vector_get_element, INT_VECTOR_ID)(IntVector *v, const int_vector_size_type index);
    void FN(int_vector_set_element, INT_VECTOR_ID)(IntVector *v, const int_vector_size_type index, const int_vector_value_type value);
    bool FN(int_vector_empty, INT_VECTOR_ID)(IntVector *v);
    void FN(int_vector_resize, INT_VECTOR_ID)(IntVector *v, const int_vector_size_type size);
    void FN(int_vector_bit_resize, INT_VECTOR_ID)(IntVector *v, const int_vector_size_type size);
    int_vector_size_type FN(int_vector_bit_size, INT_VECTOR_ID)(IntVector *v);
    int_vector_size_type FN(int_vector_capacity, INT_VECTOR_ID)(IntVector *v);
    const uint64_t *FN(int_vector_data, INT_VECTOR_ID)(IntVector *v);
    uint8_t FN(int_vector_width, INT_VECTOR_ID)(IntVector *v);
    void FN(int_vector_set_width, INT_VECTOR_ID)(IntVector *v, uint8_t new_width);
    bool FN(int_vector_store_to_file, INT_VECTOR_ID)(const IntVector *const v,
                                                     const char *const file,
                                                     bool write_fixed_as_variable);
    bool FN(int_vector_load_from_file, INT_VECTOR_ID)(IntVector *v, const char *const file);

    void FN(set_to_value, INT_VECTOR_ID)(IntVector *v, uint64_t k);
    void FN(set_to_id, INT_VECTOR_ID)(IntVector *v);
    void FN(set_random_bits, INT_VECTOR_ID)(IntVector *v);
    void FN(mod, INT_VECTOR_ID)(IntVector *v, int_vector_size_type m);
    void FN(bit_compress, INT_VECTOR_ID)(IntVector *v);
    void FN(expand_width, INT_VECTOR_ID)(IntVector *v, uint8_t new_width);
}

#endif //SDSL_C_INT_VECTOR_H