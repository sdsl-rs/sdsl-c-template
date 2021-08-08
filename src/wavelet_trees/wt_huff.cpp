#include "wavelet_trees/wt_huff.hpp"
#include <iterator>
#include <vector>

WtHuff *FN(wt_huff_create, WT_HUFF_ID)()
{
    return reinterpret_cast<WtHuff *>(
        new sdsl::wt_huff<WT_HUFF_TEMPLATE>());
}

WtHuff *FN(wt_huff_from_file, WT_HUFF_ID)(const char *const file, uint8_t num_bytes)
{
    auto wt_ptr = reinterpret_cast<WtHuff *>(
        new sdsl::wt_huff<WT_HUFF_TEMPLATE>());
    auto &wt = *reinterpret_cast<sdsl::wt_huff<WT_HUFF_TEMPLATE> *>(wt_ptr);
    std::string file_str(file);
    auto config = sdsl::cache_config{};
    sdsl::construct(wt, file_str, config, num_bytes);
    return wt_ptr;
}

WtHuff *FN(wt_huff_from_string, WT_HUFF_ID)(const char *const data)
{
    auto wt_ptr = reinterpret_cast<WtHuff *>(
        new sdsl::wt_huff<WT_HUFF_TEMPLATE>());
    auto &wt = *reinterpret_cast<sdsl::wt_huff<WT_HUFF_TEMPLATE> *>(wt_ptr);
    sdsl::construct_im(wt, data, 'd');
    return wt_ptr;
}

WtHuff *FN(wt_huff_from_int_vector, WT_HUFF_ID)(IntVector *iv_ptr)
{
    auto wt_ptr = reinterpret_cast<WtHuff *>(
        new sdsl::wt_huff<WT_HUFF_TEMPLATE>());
    auto &wt = *reinterpret_cast<sdsl::wt_huff<WT_HUFF_TEMPLATE> *>(wt_ptr);
    auto &iv = *reinterpret_cast<sdsl::int_vector<> *>(iv_ptr);
    sdsl::construct_im(wt, iv, 0);
    return wt_ptr;
}

WtHuff *FN(wt_huff_from_bit_vector, WT_HUFF_ID)(BitVector *bv_ptr)
{
    auto wt_ptr = reinterpret_cast<WtHuff *>(
        new sdsl::wt_huff<WT_HUFF_TEMPLATE>());
    auto &wt = *reinterpret_cast<sdsl::wt_huff<WT_HUFF_TEMPLATE> *>(wt_ptr);
    auto &bv = *reinterpret_cast<sdsl::bit_vector *>(bv_ptr);
    sdsl::construct_im(wt, bv, 0);
    return wt_ptr;
}

WtHuff *FN(wt_huff_copy, WT_HUFF_ID)(WtHuff *x)
{
    const auto &wt = *reinterpret_cast<sdsl::wt_huff<WT_HUFF_TEMPLATE> *>(x);
    return reinterpret_cast<WtHuff *>(
        new sdsl::wt_huff<WT_HUFF_TEMPLATE>(wt));
}

void FN(wt_huff_destroy, WT_HUFF_ID)(WtHuff *x)
{
    auto &wt = *reinterpret_cast<sdsl::wt_huff<WT_HUFF_TEMPLATE> *>(x);
    delete &wt;
}

wt_huff_size_type FN(wt_huff_size, WT_HUFF_ID)(WtHuff *x)
{
    const auto &wt = *reinterpret_cast<sdsl::wt_huff<WT_HUFF_TEMPLATE> *>(x);
    return wt.size();
}

bool FN(wt_huff_empty, WT_HUFF_ID)(WtHuff *x)
{
    const auto &wt = *reinterpret_cast<sdsl::wt_huff<WT_HUFF_TEMPLATE> *>(x);
    return wt.empty();
}

wt_huff_value_type FN(wt_huff_get_element, WT_HUFF_ID)(WtHuff *x, const wt_huff_size_type index)
{
    const auto &wt = *reinterpret_cast<sdsl::wt_huff<WT_HUFF_TEMPLATE> *>(x);
    return wt[index];
}

wt_huff_size_type FN(wt_huff_rank, WT_HUFF_ID)(WtHuff *x, const wt_huff_size_type index,
                                               const wt_huff_value_type symbol)
{
    const auto &wt = *reinterpret_cast<sdsl::wt_huff<WT_HUFF_TEMPLATE> *>(x);
    return wt.rank(index, symbol);
}

ResultInverseSelect FN(wt_huff_inverse_select, WT_HUFF_ID)(WtHuff *x, wt_huff_size_type index)
{
    const auto &wt = *reinterpret_cast<sdsl::wt_huff<WT_HUFF_TEMPLATE> *>(x);
    wt_huff_size_type rank;
    wt_huff_value_type symbol;
    std::tie(rank, symbol) = wt.inverse_select(index);
    return ResultInverseSelect{rank, symbol};
}

wt_huff_size_type FN(wt_huff_select, WT_HUFF_ID)(WtHuff *x, wt_huff_size_type index, wt_huff_value_type symbol)
{
    auto &wt = *reinterpret_cast<sdsl::wt_huff<WT_HUFF_TEMPLATE> *>(x);
    return wt.select(index, symbol);
}

ResultIntervalSymbols FN(wt_huff_interval_symbols, WT_HUFF_ID)(WtHuff *x,
                                                               wt_huff_size_type start_index,
                                                               wt_huff_size_type end_index)
{
    auto &wt = *reinterpret_cast<sdsl::wt_huff<WT_HUFF_TEMPLATE> *>(x);
    auto alphabet = wt.sigma;
    std::vector<wt_huff_value_type> cs_vec(alphabet);
    std::vector<wt_huff_size_type> rank_c_i_vec(alphabet);
    std::vector<wt_huff_size_type> rank_c_j_vec(alphabet);
    wt_huff_size_type interval_alphabet_size;
    wt.interval_symbols(start_index, end_index, interval_alphabet_size, cs_vec, rank_c_i_vec, rank_c_j_vec);

    wt_huff_value_type *cs = (wt_huff_value_type *)malloc(alphabet * sizeof(wt_huff_value_type));
    std::copy(cs_vec.begin(), cs_vec.end(), cs);

    wt_huff_size_type *rank_c_i = (wt_huff_size_type *)malloc(alphabet * sizeof(wt_huff_size_type));
    std::copy(rank_c_i_vec.begin(), rank_c_i_vec.end(), rank_c_i);

    wt_huff_size_type *rank_c_j = (wt_huff_size_type *)malloc(alphabet * sizeof(wt_huff_size_type));
    std::copy(rank_c_j_vec.begin(), rank_c_j_vec.end(), rank_c_j);

    return ResultIntervalSymbols{
        interval_alphabet_size,
        alphabet,
        cs,
        rank_c_i,
        rank_c_j};
}

void FN(wt_huff_free_result_interval_symbols, WT_HUFF_ID)(wt_huff_value_type *cs,
                                                          wt_huff_size_type *rank_c_i,
                                                          wt_huff_size_type *rank_c_j)
{
    free(cs);
    free(rank_c_i);
    free(rank_c_j);
}

ResultLexCount FN(wt_huff_lex_count, WT_HUFF_ID)(WtHuff *x,
                                                 wt_huff_size_type start_index,
                                                 wt_huff_size_type end_index,
                                                 wt_huff_value_type symbol)
{
    const auto &wt = *reinterpret_cast<sdsl::wt_huff<WT_HUFF_TEMPLATE> *>(x);
    ResultLexCount result;

#if LEX_ORDERED
    std::tie(result.rank,
             result.count_smaller_symbols,
             result.count_greater_symbols) = wt.lex_count(start_index, end_index, symbol);
#endif
    return result;
}

ResultLexSmallerCount FN(wt_huff_lex_smaller_count, WT_HUFF_ID)(WtHuff *x, wt_huff_size_type index, wt_huff_value_type symbol)
{
    const auto &wt = *reinterpret_cast<sdsl::wt_huff<WT_HUFF_TEMPLATE> *>(x);
    ResultLexSmallerCount result;
#if LEX_ORDERED
    std::tie(result.rank,
             result.count_smaller_symbols) = wt.lex_smaller_count(index, symbol);
#endif
    return result;
}

ResultSymbolGte FN(wt_huff_symbol_gte, WT_HUFF_ID)(WtHuff *x, wt_huff_value_type symbol)
{
    const auto &wt = *reinterpret_cast<sdsl::wt_huff<WT_HUFF_TEMPLATE> *>(x);
    ResultSymbolGte results;
    std::tie(results.found,
             results.symbol) = wt.symbol_gte(symbol);
    return results;
}

ResultSymbolLte FN(wt_huff_symbol_lte, WT_HUFF_ID)(WtHuff *x, wt_huff_value_type symbol)
{
    const auto &wt = *reinterpret_cast<sdsl::wt_huff<WT_HUFF_TEMPLATE> *>(x);
    ResultSymbolLte results;
    std::tie(results.found,
             results.symbol) = wt.symbol_lte(symbol);
    return results;
}

wt_huff_size_type FN(wt_huff_alphabet_size, WT_HUFF_ID)(WtHuff *x) {
    const auto &wt = *reinterpret_cast<sdsl::wt_huff<WT_HUFF_TEMPLATE> *>(x);
    return wt.sigma;
}
