#include <iostream>
#include "gtest/gtest.h"

#include "bv/bit_vector.hpp"


TEST(BitVector, SizeMethod_CorrectSizeReturned) {
    BitVector *v = FN(bit_vector_create, BIT_VECTOR_ID)(42, 0);
    auto result = FN(bit_vector_size, BIT_VECTOR_ID)(v);
    int expected = 42;
    ASSERT_EQ(result, expected);
    FN(bit_vector_destroy, BIT_VECTOR_ID)(v);
}


TEST(BitVector, GetBit_ReturnFourthElement) {
    BitVector *v = FN(bit_vector_create, BIT_VECTOR_ID)(10, 0);
    FN(bit_vector_set_bit, BIT_VECTOR_ID)(v, 3, 1);
    auto result = FN(bit_vector_get_bit, BIT_VECTOR_ID)(v, 3);
    auto expected = 1;
    ASSERT_EQ(result, expected);
    FN(bit_vector_destroy, BIT_VECTOR_ID)(v);
}


TEST(BitVector, SetBit_SecondElementChanged) {
    BitVector *v = FN(bit_vector_create, BIT_VECTOR_ID)(10, 0);
    auto result = FN(bit_vector_get_bit, BIT_VECTOR_ID)(v, 1);
    auto expected = 0;
    ASSERT_EQ(result, expected);

    FN(bit_vector_set_bit, BIT_VECTOR_ID)(v, 1, 1);
    result = FN(bit_vector_get_bit, BIT_VECTOR_ID)(v, 1);
    expected = 1;
    ASSERT_EQ(result, expected);
    FN(bit_vector_destroy, BIT_VECTOR_ID)(v);
}


TEST(BitVector, NotEmpty_EmptyReturnsFalse) {
    BitVector *v = FN(bit_vector_create, BIT_VECTOR_ID)(10, 0);
    auto result = FN(bit_vector_empty, BIT_VECTOR_ID)(v);
    auto expected = false;
    ASSERT_EQ(result, expected);
    FN(bit_vector_destroy, BIT_VECTOR_ID)(v);
}


TEST(BitVector, Empty_WithElementsReturnsTrue) {
    BitVector *v = FN(bit_vector_create, BIT_VECTOR_ID)(10, 0);
    FN(bit_vector_resize, BIT_VECTOR_ID)(v, 0);
    auto result = FN(bit_vector_empty, BIT_VECTOR_ID)(v);
    auto expected = true;
    ASSERT_EQ(result, expected);
    FN(bit_vector_destroy, BIT_VECTOR_ID)(v);
}

TEST(BitVector, SwapTwoVectors) {
    BitVector *v_primary = FN(bit_vector_create, BIT_VECTOR_ID)(10, 0);
    FN(bit_vector_set_bit, BIT_VECTOR_ID)(v_primary, 1, 1);
    BitVector *v_secondary = FN(bit_vector_create, BIT_VECTOR_ID)(10, 0);

    FN(bit_vector_swap, BIT_VECTOR_ID)(v_primary, v_secondary);

    auto result = FN(bit_vector_get_bit, BIT_VECTOR_ID)(v_primary, 1);
    auto expected = 0;
    ASSERT_EQ(result, expected);

    result = FN(bit_vector_get_bit, BIT_VECTOR_ID)(v_secondary, 1);
    expected = 1;
    ASSERT_EQ(result, expected);

    FN(bit_vector_destroy, BIT_VECTOR_ID)(v_primary);
    FN(bit_vector_destroy, BIT_VECTOR_ID)(v_secondary);
}


TEST(BitVector, BitResize_BeforeAndAfter) {
    BitVector *v = FN(bit_vector_create, BIT_VECTOR_ID)(10, 0);
    auto result = FN(bit_vector_bit_size, BIT_VECTOR_ID)(v);
    auto expected = 10;
    ASSERT_EQ(result, expected);

    FN(bit_vector_bit_resize, BIT_VECTOR_ID)(v, 20);
     result = FN(bit_vector_bit_size, BIT_VECTOR_ID)(v);
    expected = 20;
    ASSERT_EQ(result, expected);

    FN(bit_vector_destroy, BIT_VECTOR_ID)(v);
}


TEST(BitVector, BitSize_NumElementsTimesElemSize) {
    BitVector *v = FN(bit_vector_create, BIT_VECTOR_ID)(10, 0);
    auto result = FN(bit_vector_bit_size, BIT_VECTOR_ID)(v);
    auto expected = 10;
    ASSERT_EQ(result, expected);
    FN(bit_vector_destroy, BIT_VECTOR_ID)(v);
}


TEST(BitVector, Data_PointerToCorrectValue) {
    BitVector *v = FN(bit_vector_create, BIT_VECTOR_ID)(10, 0);
    FN(bit_vector_set_bit, BIT_VECTOR_ID)(v, 0, 1);
    auto result = FN(bit_vector_data, BIT_VECTOR_ID)(v);
    auto expected = 1;
    ASSERT_EQ(*result, expected);
    FN(bit_vector_destroy, BIT_VECTOR_ID)(v);
}


TEST(BitVector, StoreToFile_LoadFromFile) {
    const char * const fname = "bit_vector_tmp.sdsl";

    BitVector *output_v = FN(bit_vector_create, BIT_VECTOR_ID)(10, 0);
    FN(bit_vector_set_bit, BIT_VECTOR_ID)(output_v, 3, 1);
    bool write_fixed_as_variable = false;
    FN(bit_vector_store_to_file, BIT_VECTOR_ID)(output_v, fname, write_fixed_as_variable);

    BitVector *readin_v = FN(bit_vector_create, BIT_VECTOR_ID)(10, 0);
    FN(bit_vector_load_from_file, BIT_VECTOR_ID)(readin_v, fname);
    auto result = FN(bit_vector_get_bit, BIT_VECTOR_ID)(readin_v, 3);
    auto expected = 1;
    ASSERT_EQ(result, expected);

    FN(bit_vector_destroy, BIT_VECTOR_ID)(output_v);
    FN(bit_vector_destroy, BIT_VECTOR_ID)(readin_v);
    std::remove(fname);
}
