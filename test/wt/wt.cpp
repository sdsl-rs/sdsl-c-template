#include "gtest/gtest.h"
#include "wt/wt.hpp"


TEST(WT, IntersectOverTwoRanges_CorrectNumIntersectValues) {
    WT_CONSTRUCT_DATA_TYPE vector_data = {1, 2, 2, 4, 5, 3, 2,
                                          4, 5, 3, 2, 4, 7, 9};
    ConstructDataType *data = reinterpret_cast<ConstructDataType *>(&vector_data);
    WT *x = FN(wt_data_construct, WT_ID)(data, 0);

    wt_size_type num_ranges = 2;
    wt_size_type start_ranges[] = {0, 7};
    wt_size_type end_ranges[] = {3, 10};
    IntersectResults intersect_results = FN(wt_intersect, WT_ID)(x, num_ranges,
                                                                         start_ranges, end_ranges);

    auto result = intersect_results._num_results;
    wt_size_type expected = 2;
    ASSERT_EQ(result, expected);

    FN(wt_dealloc_intersect_result, WT_ID)(&intersect_results);
    FN(wt_destroy, WT_ID)(x);
}

TEST(WT, IntersectOverTwoRanges_CorrectIntersectValuesCorrectOrdering) {
    WT_CONSTRUCT_DATA_TYPE vector_data = {1, 2, 2, 4, 5, 3, 2,
                                          4, 5, 1, 2, 4, 7, 10};
    ConstructDataType *data = reinterpret_cast<ConstructDataType *>(&vector_data);
    WT *x = FN(wt_data_construct, WT_ID)(data, 0);

    wt_size_type num_ranges = 2;
    wt_size_type start_ranges[] = {0, 7};
    wt_size_type end_ranges[] = {3, 10};
    IntersectResults intersect_results = FN(wt_intersect, WT_ID)(x, num_ranges,
                                                                         start_ranges, end_ranges);

    auto result = intersect_results._values;
    wt_size_type expected[] = {1, 2, 4};

    for (auto i = 0; i < intersect_results._num_results; ++i)
        ASSERT_EQ(result[i], expected[i]);

    FN(wt_dealloc_intersect_result, WT_ID)(&intersect_results);
    FN(wt_destroy, WT_ID)(x);
}

TEST(WT, IntersectOverTwoRanges_CorrectValueFrequenciesCorrectOrdering) {
    WT_CONSTRUCT_DATA_TYPE vector_data = {1, 2, 2, 4, 5, 3, 2, 4, 5, 5, 3, 2};
    ConstructDataType *data = reinterpret_cast<ConstructDataType *>(&vector_data);
    WT *x = FN(wt_data_construct, WT_ID)(data, 0);

    wt_size_type num_ranges = 2;
    wt_size_type start_ranges[] = {3, 8};
    wt_size_type end_ranges[] = {4, 10};
    IntersectResults intersect_results = FN(wt_intersect, WT_ID)(x, num_ranges,
                                                                         start_ranges, end_ranges);

    auto result = intersect_results._frequencies;
    wt_size_type expected[] = {3};

    for (auto i = 0; i < intersect_results._num_results; ++i)
        ASSERT_EQ(result[i], expected[i]);

    FN(wt_dealloc_intersect_result, WT_ID)(&intersect_results);
    FN(wt_destroy, WT_ID)(x);
}

TEST(WT_Int, IntervalSymbols_OrderedUniqueSymbols_RankFromStartIndex_RankFromEndIndex) {
    WT_CONSTRUCT_DATA_TYPE vector_data = {1, 2,
                                              2, 4, 5, 3, 2, 4,
                                              5, 5, 3, 2};
    ConstructDataType *data = reinterpret_cast<ConstructDataType *>(&vector_data);
    WT *x = FN(wt_data_construct, WT_ID)(data, 0);

    wt_size_type start_index = 2;
    wt_size_type end_index = 8;
    auto results = FN(wt_interval_symbols, WT_ID)(x, start_index, end_index);

    std::vector<wt_value_type> expected_cs = {2, 3, 4, 5};
    for (auto i = 0; i < results.num_symbols_in_range; ++i)
        ASSERT_EQ(results._symbols_in_range[i], expected_cs[i]);

    std::vector<wt_size_type> expected_rank_start_index = {1, 0, 0, 0};
    for (auto i = 0; i < results.num_symbols_in_range; ++i)
        ASSERT_EQ(results._rank_start_index[i], expected_rank_start_index[i]);

    std::vector<wt_size_type> expected_rank_end_index = {3, 1, 2, 1};
    for (auto i = 0; i < results.num_symbols_in_range; ++i)
        ASSERT_EQ(results._rank_end_index[i], expected_rank_end_index[i]);

    FN(wt_dealloc_interval_symbols_result, WT_ID)(&results);
}
