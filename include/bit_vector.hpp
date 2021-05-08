#include "common.hpp"

#ifndef SDSL_C_BIT_VECTOR_HPP
#define SDSL_C_BIT_VECTOR_HPP

#define BIT_VECTOR_ID _tmp_id
#define BIT_VECTOR_TEMPLATE

extern "C"
{
struct BitVector;
typedef struct BitVector BitVector;
typedef uint64_t value_type;
typedef uint64_t size_type;

BitVector *FN(bit_vector_create, BIT_VECTOR_ID)(size_type size, value_type default_value);
void FN(bit_vector_destroy, BIT_VECTOR_ID)(BitVector *v);
size_type FN(bit_vector_size, BIT_VECTOR_ID)(BitVector *v);
value_type FN(bit_vector_get_bit, BIT_VECTOR_ID)(BitVector *v, const size_type index);
void FN(bit_vector_set_bit, BIT_VECTOR_ID)(BitVector *v, const size_type index, const value_type value);
bool FN(bit_vector_empty, BIT_VECTOR_ID)(BitVector *v);
void FN(bit_vector_resize, BIT_VECTOR_ID)(BitVector *v, const size_type size);
void FN(bit_vector_swap, BIT_VECTOR_ID)(BitVector *v_primary, BitVector *v_secondary);
void FN(bit_vector_bit_resize, BIT_VECTOR_ID)(BitVector *v, const size_type size);
size_type FN(bit_vector_bit_size, BIT_VECTOR_ID)(BitVector *v);
size_type FN(bit_vector_capacity, BIT_VECTOR_ID)(BitVector *v);
const uint64_t *FN(bit_vector_data, BIT_VECTOR_ID)(BitVector *v);
void FN(bit_vector_set_width, BIT_VECTOR_ID)(BitVector *v, uint8_t new_width);
bool FN(bit_vector_store_to_file, BIT_VECTOR_ID)(const BitVector * const v,
                              const char * const file,
                              bool write_fixed_as_variable);
bool FN(bit_vector_load_from_file, BIT_VECTOR_ID)(BitVector *v, const char *const file);
}


#endif //SDSL_C_BIT_VECTOR_HPP
