#include <iostream>
#include "gtest/gtest.h"

#include "util.hpp"
#include "io.hpp"
#include "int_vector.hpp"


TEST(IntVector, Copy_NewCopyOfVector) {
    IntVector *v = FN(int_vector_create, INT_VECTOR_ID)(42, 0, 64);
    FN(int_vector_set_element, INT_VECTOR_ID)(v, 2, 42);

    IntVector *new_v = FN(int_vector_copy, INT_VECTOR_ID)(v);
    auto result = FN(int_vector_get_element, INT_VECTOR_ID)(new_v, 2);
    auto expected = 42;
    ASSERT_EQ(result, expected);

    FN(int_vector_set_element, INT_VECTOR_ID)(v, 2, 12);
    result = FN(int_vector_get_element, INT_VECTOR_ID)(new_v, 2);
    expected = 42;
    ASSERT_EQ(result, expected);

    FN(int_vector_destroy, INT_VECTOR_ID)(v);
    FN(int_vector_destroy, INT_VECTOR_ID)(new_v);
}


TEST(IntVector, SizeMethod_CorrectSizeReturned) {
    IntVector *v = FN(int_vector_create, INT_VECTOR_ID)(42, 0, 64);
    auto result = FN(int_vector_size, INT_VECTOR_ID)(v);
    int expected = 42;
    ASSERT_EQ(result, expected);
    FN(int_vector_destroy, INT_VECTOR_ID)(v);
}


TEST(IntVector, GetElement_ReturnFourthElement) {
    IntVector *v = FN(int_vector_create, INT_VECTOR_ID)(10, 0, 64);
    FN(int_vector_set_element, INT_VECTOR_ID)(v, 3, 42);
    auto result = FN(int_vector_get_element, INT_VECTOR_ID)(v, 3);
    auto expected = 42;
    ASSERT_EQ(result, expected);
    FN(int_vector_destroy, INT_VECTOR_ID)(v);
}


TEST(IntVector, SetElement_SecondElementChanged) {
    IntVector *v = FN(int_vector_create, INT_VECTOR_ID)(10, 0, 64);
    auto result = FN(int_vector_get_element, INT_VECTOR_ID)(v, 1);
    auto expected = 0;
    ASSERT_EQ(result, expected);

    FN(int_vector_set_element, INT_VECTOR_ID)(v, 1, 42);
    result = FN(int_vector_get_element, INT_VECTOR_ID)(v, 1);
    expected = 42;
    ASSERT_EQ(result, expected);
    FN(int_vector_destroy, INT_VECTOR_ID)(v);
}


TEST(IntVector, NotEmpty_EmptyReturnsFalse) {
    IntVector *v = FN(int_vector_create, INT_VECTOR_ID)(10, 0, 64);
    auto result = FN(int_vector_empty, INT_VECTOR_ID)(v);
    auto expected = false;
    ASSERT_EQ(result, expected);
    FN(int_vector_destroy, INT_VECTOR_ID)(v);
}


TEST(IntVector, Empty_WithoutElementsReturnsTrue) {
    IntVector *v = FN(int_vector_create, INT_VECTOR_ID)(10, 0, 64);
    FN(int_vector_bit_resize, INT_VECTOR_ID)(v, 0);
    auto result = FN(int_vector_empty, INT_VECTOR_ID)(v);
    auto expected = true;
    ASSERT_EQ(result, expected);
    FN(int_vector_destroy, INT_VECTOR_ID)(v);
}


TEST(IntVector, BitResize_BeforeAndAfter) {
    IntVector *v = FN(int_vector_create, INT_VECTOR_ID)(10, 0, 64);
    auto result = FN(int_vector_bit_size, INT_VECTOR_ID)(v);
    auto expected = 640;
    ASSERT_EQ(result, expected);

    FN(int_vector_bit_resize, INT_VECTOR_ID)(v, 20);
    result = FN(int_vector_bit_size, INT_VECTOR_ID)(v);
    expected = 20;
    ASSERT_EQ(result, expected);

    FN(int_vector_destroy, INT_VECTOR_ID)(v);
}


TEST(IntVector, BitSize_NumElementsTimesElemSize) {
    IntVector *v = FN(int_vector_create, INT_VECTOR_ID)(10, 0, 64);
    auto result = FN(int_vector_bit_size, INT_VECTOR_ID)(v);
    auto expected = 640;
    ASSERT_EQ(result, expected);
    FN(int_vector_destroy, INT_VECTOR_ID)(v);
}


TEST(IntVector, Capacity_NumberOfReservedBits) {
    IntVector *v = FN(int_vector_create, INT_VECTOR_ID)(10, 0, 64);
    auto result = FN(int_vector_capacity, INT_VECTOR_ID)(v);
    auto expected = 640;
    ASSERT_EQ(result, expected);
    FN(int_vector_destroy, INT_VECTOR_ID)(v);
}


TEST(IntVector, Data_PointerToCorrectValue) {
    IntVector *v = FN(int_vector_create, INT_VECTOR_ID)(10, 0, 64);
    FN(int_vector_set_element, INT_VECTOR_ID)(v, 0, 42);
    auto result = FN(int_vector_data, INT_VECTOR_ID)(v);
    auto expected = 42;
    ASSERT_EQ(*result, expected);
    FN(int_vector_destroy, INT_VECTOR_ID)(v);
}


TEST(IntVector, Width_ReturnsStoredIntWidth) {
    IntVector *v = FN(int_vector_create, INT_VECTOR_ID)(10, 0, 64);
    auto result = FN(int_vector_width, INT_VECTOR_ID)(v);
    auto expected = 64;
    ASSERT_EQ(result, expected);
    FN(int_vector_destroy, INT_VECTOR_ID)(v);
}


TEST(IntVector, SetWidth_ReturnsNewModifiedIntWidth) {
    IntVector *v = FN(int_vector_create, INT_VECTOR_ID)(10, 0, 64);
    auto result = FN(int_vector_width, INT_VECTOR_ID)(v);
    auto expected = 64;
    ASSERT_EQ(result, expected);

    FN(int_vector_set_width, INT_VECTOR_ID)(v, 32);

    result = FN(int_vector_width, INT_VECTOR_ID)(v);
    expected = 32;
    ASSERT_EQ(result, expected);
    FN(int_vector_destroy, INT_VECTOR_ID)(v);
}


TEST(IntVector, StoreToFile_LoadFromFile) {
    const char * const fname = "int_vector_tmp.sdsl";

    IntVector *output_v = FN(int_vector_create, INT_VECTOR_ID)(10, 0, 64);
    FN(int_vector_set_element, INT_VECTOR_ID)(output_v, 3, 42);
    bool write_fixed_as_variable = true;
    FN(store_to_file, INT_VECTOR_ID)(output_v, fname, write_fixed_as_variable);

    IntVector *readin_v = FN(int_vector_create, INT_VECTOR_ID)(10, 0, 64);
    FN(load_from_file, INT_VECTOR_ID)(readin_v, fname);
    auto result = FN(int_vector_get_element, INT_VECTOR_ID)(readin_v, 3);
    auto expected = 42;
    ASSERT_EQ(result, expected);

    FN(int_vector_destroy, INT_VECTOR_ID)(output_v);
    FN(int_vector_destroy, INT_VECTOR_ID)(readin_v);
    std::remove(fname);
}


TEST(IntVector, SetToValue_AllValuesModified) {
    IntVector *v = FN(int_vector_create, INT_VECTOR_ID)(100, 123, 64);
    FN(set_to_value, INT_VECTOR_ID)(v, 42);
    auto result = FN(int_vector_get_element, INT_VECTOR_ID)(v, 50);
    int expected = 42;
    ASSERT_EQ(result, expected);
    FN(int_vector_destroy, INT_VECTOR_ID)(v);
}


TEST(IntVector, SetToId_ValuesSetToIndex) {
    IntVector *v = FN(int_vector_create, INT_VECTOR_ID)(100, 123, 64);
    FN(set_to_id, INT_VECTOR_ID)(v);
    auto result = FN(int_vector_get_element, INT_VECTOR_ID)(v, 50);
    int expected = 50;
    ASSERT_EQ(result, expected);
    FN(int_vector_destroy, INT_VECTOR_ID)(v);
}


TEST(IntVector, SetRandomBits_ValuesSetToIndex) {
    IntVector *v = FN(int_vector_create, INT_VECTOR_ID)(100, 123, 64);
    FN(set_random_bits, INT_VECTOR_ID)(v);
    auto result = FN(int_vector_get_element, INT_VECTOR_ID)(v, 50);
    int expected = 123;
    ASSERT_NE(result, expected);
    FN(int_vector_destroy, INT_VECTOR_ID)(v);
}


TEST(IntVector, Mod_ValuesSetToModulo) {
    IntVector *v = FN(int_vector_create, INT_VECTOR_ID)(100, 123, 64);
    FN(set_to_id, INT_VECTOR_ID)(v);
    FN(mod, INT_VECTOR_ID)(v, 2);

    auto result = FN(int_vector_get_element, INT_VECTOR_ID)(v, 4);
    int expected = 0;
    ASSERT_EQ(result, expected);

    result = FN(int_vector_get_element, INT_VECTOR_ID)(v, 3);
    expected = 0;
    ASSERT_NE(result, expected);

    FN(int_vector_destroy, INT_VECTOR_ID)(v);
}


TEST(IntVector, ExpandWidth) {
    IntVector *v = FN(int_vector_create, INT_VECTOR_ID)(100, 0, 64);
    auto size_before = FN(int_vector_bit_size, INT_VECTOR_ID)(v);
    int expected = 6400;
    ASSERT_EQ(size_before, expected);

    FN(expand_width, INT_VECTOR_ID)(v, 100);

    auto size_after = FN(int_vector_bit_size, INT_VECTOR_ID)(v);
    expected = 10000;
    ASSERT_EQ(size_after, expected);

    FN(int_vector_destroy, INT_VECTOR_ID)(v);
}


TEST(IntVector, BitCompress) {
    IntVector *v = FN(int_vector_create, INT_VECTOR_ID)(100, 0, 64);
    auto size_before = FN(int_vector_bit_size, INT_VECTOR_ID)(v);
    int expected = 6400;
    ASSERT_EQ(size_before, expected);

    FN(bit_compress, INT_VECTOR_ID)(v);

    auto size_after = FN(int_vector_bit_size, INT_VECTOR_ID)(v);
    expected = 100;
    ASSERT_EQ(size_after, expected);

    FN(int_vector_destroy, INT_VECTOR_ID)(v);
}
