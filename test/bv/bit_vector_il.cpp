#include <iostream>
#include "gtest/gtest.h"

#include "bv/bit_vector.hpp"
#include "bv/bit_vector_il.hpp"


TEST(BitVectorIl, Blah) {
    BitVector *v = FN(bit_vector_create, BIT_VECTOR_ID)(42, 0);
    BitVectorIl *v_il = bit_vector_il_create_12345(v);

    FN(bit_vector_destroy, BIT_VECTOR_ID)(v);
    bit_vector_il_destroy(v_il);
}
