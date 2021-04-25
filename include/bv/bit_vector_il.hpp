#pragma once

#include <sdsl/bit_vector_il.hpp>
#include "../common.hpp"
#include "bit_vector.hpp"


#ifndef SDSL_C_BIT_VECTOR_IL_HPP
#define SDSL_C_BIT_VECTOR_IL_HPP

#define BIT_VECTOR_IL_ID _12345
#define BIT_VECTOR_IL_TEMPLATE 64

extern "C"
{
struct BitVectorIl;
typedef struct BitVectorIl BitVectorIl;

BitVectorIl *FN(bit_vector_il_create, BIT_VECTOR_IL_ID)(BitVector *v)
{
    const auto &vec = *reinterpret_cast<sdsl::bit_vector *>(v);
    return reinterpret_cast<BitVectorIl *>(
        new sdsl::bit_vector_il<BIT_VECTOR_IL_TEMPLATE>(vec));
};
void bit_vector_il_destroy(BitVectorIl *v)
{
    auto &vec = *reinterpret_cast<sdsl::bit_vector_il<BIT_VECTOR_IL_TEMPLATE> *>(v);
    delete &vec;
};
}

#endif //SDSL_C_BIT_VECTOR_IL_HPP
