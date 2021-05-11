#include "wt.hpp"

WT *FN(wt_data_construct, WT_ID)(ConstructDataType *data, uint8_t num_bytes)
{
    WT_TYPE<WT_TEMPLATE> *x = new WT_TYPE<WT_TEMPLATE>();
    auto &d = *reinterpret_cast<WT_CONSTRUCT_DATA_TYPE *>(data);
    sdsl::construct_im(*x, d, num_bytes);
    return reinterpret_cast<WT *>(x);
}

void FN(wt_destroy, WT_ID)(WT *x)
{
    auto &i = *reinterpret_cast<WT_TYPE<WT_TEMPLATE> *>(x);
    delete &i;
}

IntersectResults FN(wt_intersect, WT_ID)(WT *x,
                                         wt_size_type num_ranges,
                                         wt_size_type *start_ranges,
                                         wt_size_type *end_ranges)
{
    auto &wt = *reinterpret_cast<WT_TYPE<WT_TEMPLATE> *>(x);

    using range_type = std::array<wt_size_type, 2>;
    std::vector<range_type> ranges;
    ranges.reserve(num_ranges);

    for (wt_size_type i = 0; i < num_ranges; ++i)
    {
        auto &start_range = start_ranges[i];
        auto &end_range = end_ranges[i];
        range_type range = {(wt_size_type)start_range, (wt_size_type)end_range};
        ranges.emplace_back(range);
    }

    const auto intersect_result = sdsl::intersect(wt, ranges, num_ranges);

    IntersectResults results;
    results._num_results = intersect_result.size();

    results._values = (wt_value_type *)malloc(results._num_results * sizeof(wt_value_type));
    results._frequencies = (wt_size_type *)malloc(
        results._num_results * sizeof(wt_size_type));

    for (wt_size_type i = 0; i < results._num_results; ++i)
    {
        results._values[i] = (int)intersect_result[i].first;
        results._frequencies[i] = (int)intersect_result[i].second;
    }

    return results;
}

void FN(wt_dealloc_intersect_result, WT_ID)(IntersectResults *results)
{
    free(results->_values);
    free(results->_frequencies);
}

IntervalSymbolsResults FN(wt_interval_symbols, WT_ID)(WT *x, wt_size_type start_index, wt_size_type end_index)
{

    auto &wt = *reinterpret_cast<WT_TYPE<WT_TEMPLATE> *>(x);
    wt_size_type interval_size = end_index - start_index;

    wt_size_type k;
    std::vector<wt_value_type> cs;
    std::vector<wt_size_type> rank_c_i;
    std::vector<wt_size_type> rank_c_j;

    cs.reserve(interval_size);
    rank_c_i.reserve(interval_size);
    rank_c_j.reserve(interval_size);

    wt.interval_symbols(start_index, end_index,
                        k, cs, rank_c_i, rank_c_j);

    IntervalSymbolsResults results;
    results.num_symbols_in_range = k;

    results._symbols_in_range = (wt_value_type *)malloc(results.num_symbols_in_range * sizeof(wt_value_type));
    for (auto i = 0; i < results.num_symbols_in_range; ++i)
        results._symbols_in_range[i] = cs[i];

    results._rank_start_index = (wt_size_type *)malloc(results.num_symbols_in_range * sizeof(wt_size_type));
    for (auto i = 0; i < results.num_symbols_in_range; ++i)
        results._rank_start_index[i] = rank_c_i[i];

    results._rank_end_index = (wt_size_type *)malloc(results.num_symbols_in_range * sizeof(wt_size_type));
    for (auto i = 0; i < results.num_symbols_in_range; ++i)
        results._rank_end_index[i] = rank_c_j[i];

    return results;
}

void FN(wt_dealloc_interval_symbols_result, WT_ID)(IntervalSymbolsResults *results)
{
    free(results->_symbols_in_range);
    free(results->_rank_start_index);
    free(results->_rank_end_index);
}
