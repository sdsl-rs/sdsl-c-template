#include <iostream>
#include "gtest/gtest.h"
#include "bit_vector.hpp"
#include "wt_huff.hpp"

TEST(WtHuff, FromBitVector)
{
    BitVector *bv_ptr = FN(bit_vector_create, BIT_VECTOR_ID)(64, 0);
    FN(bit_vector_set_element, BIT_VECTOR_ID)
    (bv_ptr, 2, 1);
    WtHuff *wt_ptr = FN(wt_huff_from_bit_vector, WT_HUFF_ID)(bv_ptr);

    // Inspect first byte.
    auto result = FN(wt_huff_get_element, WT_HUFF_ID)(wt_ptr, 0);
    auto expected = 4;
    ASSERT_EQ(result, expected);
}

TEST(WtHuff, FromString)
{
    char const *data = "5 2 3 89";
    WtHuff *wt_ptr = FN(wt_huff_from_string, WT_HUFF_ID)(data);

    auto result = FN(wt_huff_get_element, WT_HUFF_ID)(wt_ptr, 3);
    auto expected = 89;
    ASSERT_EQ(result, expected);
}

TEST(WtHuff, Rank)
{
    BitVector *bv_ptr = FN(bit_vector_create, BIT_VECTOR_ID)(64, 0);
    FN(bit_vector_set_element, BIT_VECTOR_ID)
    (bv_ptr, 2, 1);
    WtHuff *wt_ptr = FN(wt_huff_from_bit_vector, WT_HUFF_ID)(bv_ptr);

    // Inspect first byte.
    auto result = FN(wt_huff_rank, WT_HUFF_ID)(wt_ptr, 3, 4);
    auto expected = 1;
    ASSERT_EQ(result, expected);
}