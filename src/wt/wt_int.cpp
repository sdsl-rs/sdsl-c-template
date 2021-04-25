#include <sdsl/wt_int.hpp>
#include <sdsl/wt_algorithm.hpp>
#include <sdsl/construct.hpp>
#include "wt/wt_int.hpp"


extern "C" { bool FN(wt_int_id, WT_INT_ID) = true; }

WT_Int *FN(wt_int_create, WT_INT_ID)() {
    return reinterpret_cast<WT_Int *>(
            new sdsl::wt_int<WT_INT_TEMPLATE >());
}

WT_Int *FN(wt_int_data_construct, WT_INT_ID)(ConstructDataType *data, uint8_t num_bytes) {
    sdsl::wt_int<WT_INT_TEMPLATE > *x = new sdsl::wt_int<WT_INT_TEMPLATE >();
    auto &d = *reinterpret_cast<WT_INT_CONSTRUCT_DATA_TYPE *>(data);
    sdsl::construct_im(*x, d, num_bytes);
    return reinterpret_cast<WT_Int *>(x);
}

void FN(wt_int_destroy, WT_INT_ID)(WT_Int *x) {
    auto &i = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE > *>(x);
    delete &i;
}

WT_Int *FN(wt_int_copy, WT_INT_ID)(WT_Int *x) {
    auto &i = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE > *>(x);
    return reinterpret_cast<WT_Int *>(
            new sdsl::wt_int<WT_INT_TEMPLATE >(i));
}

wt_int_size_type FN(wt_int_size, WT_INT_ID)(WT_Int *x) {
    auto &i = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE > *>(x);
    return i.size();
}

bool FN(wt_int_empty, WT_INT_ID)(WT_Int *x) {
    auto &i = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE > *>(x);
    return i.empty();
}

wt_int_value_type FN(wt_int_get_element, WT_INT_ID)(WT_Int *x, const wt_int_size_type index) {
    auto &i = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE > *>(x);
    return i[index];
}

wt_int_size_type FN(wt_int_rank, WT_INT_ID)(WT_Int *x, const wt_int_size_type index,
                                            const wt_int_value_type symbol) {
    auto &i = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE > *>(x);
    return i.rank(index, symbol);
}

InverseSelectPair FN(wt_int_inverse_select, WT_INT_ID)(WT_Int *x, wt_int_size_type index) {
    auto &i = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE > *>(x);
    wt_int_size_type rank;
    wt_int_value_type symbol;
    std::tie(rank, symbol) = i.inverse_select(index);
    InverseSelectPair pair = {rank, symbol};
    return pair;
}

wt_int_size_type FN(wt_int_select, WT_INT_ID)
        (WT_Int *x, wt_int_size_type occurrence, wt_int_value_type symbol) {
    auto &wt = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE > *>(x);
    return wt.select(occurrence, symbol);
}

LexCountResults FN(wt_int_lex_count, WT_INT_ID)
        (WT_Int *x, wt_int_size_type start_index, wt_int_size_type end_index,
         wt_int_value_type symbol) {

    auto &wt = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE > *>(x);

    LexCountResults results;
    std::tie(results.rank,
             results.num_symbols_smaller,
             results.num_symbols_greater) = wt.lex_count(start_index, end_index, symbol);

    return results;
}

LexSmallerCountResults FN(wt_int_lex_smaller_count, WT_INT_ID)
        (WT_Int *x, wt_int_size_type index, wt_int_value_type symbol) {
    auto &wt = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE > *>(x);

    LexSmallerCountResults results;
    std::tie(results.rank,
             results.num_symbols_smaller) = wt.lex_smaller_count(index, symbol);
    return results;
}

RangeSearch2DResult FN(wt_int_range_search_2d, WT_INT_ID)
        (WT_Int *x, wt_int_size_type index_left_bound, wt_int_size_type index_right_bound,
         wt_int_value_type value_left_bound, wt_int_value_type value_right_bound,
         bool matching_points_report) {

    const auto &wt = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE > *>(x);

    const auto search_results = wt.range_search_2d(index_left_bound, index_right_bound,
                                                   value_left_bound, value_right_bound,
                                                   matching_points_report);

    RangeSearch2DResult results;
    results.num_found_points = search_results.first;
    results._point_symbols = (wt_int_value_type *) malloc(results.num_found_points
                                                          * sizeof(wt_int_value_type));
    results._point_indexes = (wt_int_size_type *) malloc(results.num_found_points
                                                         * sizeof(wt_int_size_type));

    const auto &points_vec = search_results.second;
    for (auto i = 0; i < points_vec.size(); ++i) {
        const auto &point = points_vec[i];
        results._point_symbols[i] = point.first;
        results._point_indexes[i] = point.second;
    }
    return results;
}

void FN(wt_int_dealloc_range_search_2d_result, WT_INT_ID)(RangeSearch2DResult *results) {
    free(results->_point_symbols);
    free(results->_point_indexes);
}
