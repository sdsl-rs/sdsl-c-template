#include "wt_int.hpp"
#include <iterator>
#include <vector>

WtInt *FN(wt_int_create, WT_INT_ID)()
{
    return reinterpret_cast<WtInt *>(
        new sdsl::wt_int<WT_INT_TEMPLATE>());
}

WtInt *FN(wt_int_from_file, WT_INT_ID)(const char *const file, uint8_t num_bytes)
{
    auto wt_ptr = reinterpret_cast<WtInt *>(
        new sdsl::wt_int<WT_INT_TEMPLATE>());
    auto &wt = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE> *>(wt_ptr);
    std::string file_str(file);
    auto config = sdsl::cache_config{};
    sdsl::construct(wt, file_str, config, num_bytes);
    return wt_ptr;
}

WtInt *FN(wt_int_from_string, WT_INT_ID)(const char *const data)
{
    auto wt_ptr = reinterpret_cast<WtInt *>(
        new sdsl::wt_int<WT_INT_TEMPLATE>());
    auto &wt = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE> *>(wt_ptr);
    sdsl::construct_im(wt, data, 'd');
    return wt_ptr;
}

WtInt *FN(wt_int_from_int_vector, WT_INT_ID)(IntVector *iv_ptr)
{
    auto wt_ptr = reinterpret_cast<WtInt *>(
        new sdsl::wt_int<WT_INT_TEMPLATE>());
    auto &wt = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE> *>(wt_ptr);
    auto &iv = *reinterpret_cast<sdsl::int_vector<> *>(iv_ptr);
    sdsl::construct_im(wt, iv, 0);
    return wt_ptr;
}

WtInt *FN(wt_int_from_bit_vector, WT_INT_ID)(BitVector *bv_ptr)
{
    auto wt_ptr = reinterpret_cast<WtInt *>(
        new sdsl::wt_int<WT_INT_TEMPLATE>());
    auto &wt = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE> *>(wt_ptr);
    auto &bv = *reinterpret_cast<sdsl::bit_vector *>(bv_ptr);
    sdsl::construct_im(wt, bv, 0);
    return wt_ptr;
}

WtInt *FN(wt_int_copy, WT_INT_ID)(WtInt *x)
{
    const auto &wt = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE> *>(x);
    return reinterpret_cast<WtInt *>(
        new sdsl::wt_int<WT_INT_TEMPLATE>(wt));
}

void FN(wt_int_destroy, WT_INT_ID)(WtInt *x)
{
    auto &wt = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE> *>(x);
    delete &wt;
}

wt_int_size_type FN(wt_int_size, WT_INT_ID)(WtInt *x)
{
    const auto &wt = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE> *>(x);
    return wt.size();
}

bool FN(wt_int_empty, WT_INT_ID)(WtInt *x)
{
    const auto &wt = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE> *>(x);
    return wt.empty();
}

wt_int_value_type FN(wt_int_get_element, WT_INT_ID)(WtInt *x, const wt_int_size_type index)
{
    const auto &wt = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE> *>(x);
    return wt[index];
}

wt_int_size_type FN(wt_int_rank, WT_INT_ID)(WtInt *x, const wt_int_size_type index,
                                            const wt_int_value_type symbol)
{
    const auto &wt = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE> *>(x);
    return wt.rank(index, symbol);
}

ResultInverseSelect FN(wt_int_inverse_select, WT_INT_ID)(WtInt *x, wt_int_size_type index)
{
    const auto &wt = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE> *>(x);
    wt_int_size_type rank;
    wt_int_value_type symbol;
    std::tie(rank, symbol) = wt.inverse_select(index);
    return ResultInverseSelect{rank, symbol};
}

wt_int_size_type FN(wt_int_select, WT_INT_ID)(WtInt *x, wt_int_size_type index, wt_int_value_type symbol)
{
    auto &wt = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE> *>(x);
    return wt.select(index, symbol);
}

ResultIntervalSymbols FN(wt_int_interval_symbols, WT_INT_ID)(WtInt *x,
                                                             wt_int_size_type start_index,
                                                             wt_int_size_type end_index)
{
    auto &wt = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE> *>(x);
    auto alphabet = wt.sigma;
    std::vector<wt_int_value_type> cs_vec(alphabet);
    std::vector<wt_int_size_type> rank_c_i_vec(alphabet);
    std::vector<wt_int_size_type> rank_c_j_vec(alphabet);
    wt_int_size_type interval_alphabet_size;
    wt.interval_symbols(start_index, end_index, interval_alphabet_size, cs_vec, rank_c_i_vec, rank_c_j_vec);

    wt_int_value_type *cs = (wt_int_value_type *)malloc(alphabet * sizeof(wt_int_value_type));
    std::copy(cs_vec.begin(), cs_vec.end(), cs);

    wt_int_size_type *rank_c_i = (wt_int_size_type *)malloc(alphabet * sizeof(wt_int_size_type));
    std::copy(rank_c_i_vec.begin(), rank_c_i_vec.end(), rank_c_i);

    wt_int_size_type *rank_c_j = (wt_int_size_type *)malloc(alphabet * sizeof(wt_int_size_type));
    std::copy(rank_c_j_vec.begin(), rank_c_j_vec.end(), rank_c_j);

    return ResultIntervalSymbols{
        interval_alphabet_size,
        alphabet,
        cs,
        rank_c_i,
        rank_c_j};
}

void FN(wt_int_free_result_interval_symbols, WT_INT_ID)(wt_int_value_type *cs,
                                                        wt_int_size_type *rank_c_i,
                                                        wt_int_size_type *rank_c_j)
{
    free(cs);
    free(rank_c_i);
    free(rank_c_j);
}

ResultLexCount FN(wt_int_lex_count, WT_INT_ID)(WtInt *x,
                                               wt_int_size_type start_index,
                                               wt_int_size_type end_index,
                                               wt_int_value_type symbol)
{
    const auto &wt = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE> *>(x);
    ResultLexCount result;
    std::tie(result.rank,
             result.count_smaller_symbols,
             result.count_greater_symbols) = wt.lex_count(start_index, end_index, symbol);
    return result;
}

ResultLexSmallerCount FN(wt_int_lex_smaller_count, WT_INT_ID)(WtInt *x, wt_int_size_type index, wt_int_value_type symbol)
{
    const auto &wt = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE> *>(x);
    ResultLexSmallerCount result;
    std::tie(result.rank,
             result.count_smaller_symbols) = wt.lex_smaller_count(index, symbol);
    return result;
}

ResultRangeSearch2d FN(wt_int_range_search_2d, WT_INT_ID)(WtInt *x,
                                                          wt_int_size_type lb,
                                                          wt_int_size_type rb,
                                                          wt_int_value_type vlb,
                                                          wt_int_value_type vrb,
                                                          bool report)
{
    const auto &wt = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE> *>(x);

    ResultRangeSearch2d result;
    std::vector<std::pair<wt_int_value_type, wt_int_size_type>> points;

    std::tie(result.count_found_points,
             points) = wt.range_search_2d(lb, rb, vlb, vrb, report);

    result.point_values = (wt_int_value_type *)malloc(points.size() * sizeof(wt_int_value_type));
    result.point_indexes = (wt_int_size_type *)malloc(points.size() * sizeof(wt_int_size_type));

    for (int i = 0; i < points.size(); i++)
    {
        const auto &point = points[i];
        std::tie(result.point_values[i],
                 result.point_indexes[i]) = point;
    }

    return result;
}

void FN(wt_int_free_result_range_search_2d, WT_INT_ID)(wt_int_value_type *point_values,
                                                       wt_int_size_type *point_indexes)
{
    free(point_values);
    free(point_indexes);
}

wt_int_size_type FN(wt_int_alphabet_size, WT_INT_ID)(WtInt *x)
{
    const auto &wt = *reinterpret_cast<sdsl::wt_int<WT_INT_TEMPLATE> *>(x);
    return wt.sigma;
}
