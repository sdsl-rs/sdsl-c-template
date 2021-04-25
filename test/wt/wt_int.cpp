#include "gtest/gtest.h"
#include "wt/wt_int.hpp"


TEST(WT_Int, Create) {
    WT_Int *x = FN(wt_int_create, WT_INT_ID)();
    FN(wt_int_destroy, WT_INT_ID)(x);
}


TEST(WT_Int, DataConstruct) {
    WT_INT_CONSTRUCT_DATA_TYPE vector_data = {1, 2, 2, 4, 5, 3, 2, 4, 5, 3, 2, 4,
                                              7, 4, 2, 52, 7, 4, 2, 1, 5, 74, 3};
    ConstructDataType *data = reinterpret_cast<ConstructDataType *>(&vector_data);
    WT_Int *x = FN(wt_int_data_construct, WT_INT_ID)(data, 0);
    FN(wt_int_destroy, WT_INT_ID)(x);
}


TEST(WT_Int, Copy_NewCopyOfWT) {
    WT_Int *x = FN(wt_int_create, WT_INT_ID)();
    WT_Int *new_x = FN(wt_int_copy, WT_INT_ID)(x);
    ASSERT_NE(&x, &new_x);

    FN(wt_int_destroy, WT_INT_ID)(x);
    FN(wt_int_destroy, WT_INT_ID)(new_x);
}

TEST(WT_Int, LexCount_CorrectRank_CorrectNumSymbolsSmaller_CorrectNumSymbolsGreater) {
    WT_INT_CONSTRUCT_DATA_TYPE vector_data = {1, 2,
                                              2, 4, 5, 3, 2, 4,
                                              5, 5, 3, 2};
    ConstructDataType *data = reinterpret_cast<ConstructDataType *>(&vector_data);
    WT_Int *x = FN(wt_int_data_construct, WT_INT_ID)(data, 0);

    auto results = FN(wt_int_lex_count, WT_INT_ID)(x, 2, 8, 2);

    ASSERT_EQ(results.rank, 1);
    ASSERT_EQ(results.num_symbols_smaller, 0);
    ASSERT_EQ(results.num_symbols_greater, 4);
}

TEST(WT_Int, LexSmallerCount_CorrectRank_CorrectNumSymbolsSmaller) {
    WT_INT_CONSTRUCT_DATA_TYPE vector_data = {1, 2, 2, 4,
                                              5, 3, 2, 4, 5, 5, 3, 2};
    ConstructDataType *data = reinterpret_cast<ConstructDataType *>(&vector_data);
    WT_Int *x = FN(wt_int_data_construct, WT_INT_ID)(data, 0);

    auto results = FN(wt_int_lex_smaller_count, WT_INT_ID)(x, 4, 2);

    ASSERT_EQ(results.rank, 2);
    ASSERT_EQ(results.num_symbols_smaller, 1);
}

TEST(WT_Int, RangeSearch2D_CorrectIndexes_CorrectSymbols) {
    WT_INT_CONSTRUCT_DATA_TYPE vector_data = {1, 2,
                                              2, 4, 5, 3, 2, 4, 5,
                                              5, 3, 2};

    ConstructDataType *data = reinterpret_cast<ConstructDataType *>(&vector_data);
    WT_Int *x = FN(wt_int_data_construct, WT_INT_ID)(data, 0);

    auto results = FN(wt_int_range_search_2d, WT_INT_ID)(x, 2, 8, 3, 5, true);

    const std::vector<wt_int_size_type> expected_indexes = {3, 4, 4, 5, 5};
    const std::vector<wt_int_value_type> expected_symbols = {5, 3, 7, 4, 8};

    for (auto i = 0; i < results.num_found_points; ++i) {
        ASSERT_EQ(results._point_indexes[i], expected_indexes[i]);
        ASSERT_EQ(results._point_symbols[i], expected_symbols[i]);
    }
    FN(wt_int_dealloc_range_search_2d_result, WT_INT_ID)(&results);
}
