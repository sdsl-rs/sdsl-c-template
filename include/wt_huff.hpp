#include "common.hpp"
#include "bit_vector.hpp"
#include "int_vector.hpp"
#include "byte_tree.hpp"

#include <sdsl/construct.hpp>
#include <sdsl/config.hpp>
#include <sdsl/sdsl_concepts.hpp>
#include <sdsl/wt_huff.hpp>

#ifndef SDSL_C_WT_HUFF_HPP
#define SDSL_C_WT_HUFF_HPP

#define WT_HUFF_ID _id
#define WT_HUFF_TEMPLATE sdsl::bit_vector, sdsl::bit_vector::rank_1_type, sdsl::bit_vector::select_1_type, sdsl::bit_vector::select_0_type, sdsl::byte_tree<>

extern "C"
{
    struct WtHuff;
    typedef struct WtHuff WtHuff;
    typedef int64_t wt_huff_value_type;
    typedef uint64_t wt_huff_size_type;

    WtHuff *FN(wt_huff_create, WT_HUFF_ID)();
    WtHuff *FN(wt_huff_from_file, WT_HUFF_ID)(const char *const file, uint8_t num_bytes);
    WtHuff *FN(wt_huff_from_string, WT_HUFF_ID)(const char *const data);
    WtHuff *FN(wt_huff_from_int_vector, WT_HUFF_ID)(IntVector *iv_ptr);
    WtHuff *FN(wt_huff_from_bit_vector, WT_HUFF_ID)(BitVector *bv_ptr);
    WtHuff *FN(wt_huff_copy, WT_HUFF_ID)(WtHuff *x);
    void FN(wt_huff_destroy, WT_HUFF_ID)(WtHuff *x);

    wt_huff_size_type FN(wt_huff_size, WT_HUFF_ID)(WtHuff *x);
    bool FN(wt_huff_empty, WT_HUFF_ID)(WtHuff *x);
    wt_huff_value_type FN(wt_huff_get_element, WT_HUFF_ID)(WtHuff *x, wt_huff_size_type index);
    wt_huff_size_type FN(wt_huff_rank, WT_HUFF_ID)(WtHuff *x, wt_huff_size_type index, wt_huff_value_type symbol);

    struct ResultInverseSelect
    {
        wt_huff_size_type rank;
        wt_huff_value_type symbol;
    };
    ResultInverseSelect FN(wt_huff_inverse_select, WT_HUFF_ID)(WtHuff *x, wt_huff_size_type index);

    wt_huff_size_type FN(wt_huff_select, WT_HUFF_ID)(WtHuff *x, wt_huff_size_type index, wt_huff_value_type symbol);

    void FN(wt_huff_interval_symbols, WT_HUFF_ID)(
        WtHuff *x,
        wt_huff_size_type start_index,
        wt_huff_size_type end_index,
        wt_huff_size_type *interval_alphabet_size,
        wt_huff_value_type *rank_c_i,
        wt_huff_value_type *rank_c_j);

    struct ResultLexCount
    {
        bool lex_ordered;
        wt_huff_size_type rank;
        wt_huff_value_type count_smaller_symbols;
        wt_huff_value_type count_greater_symbols;
    };
    ResultLexCount FN(wt_huff_lex_count, WT_HUFF_ID)(WtHuff *x, wt_huff_size_type start_index,
                                                     wt_huff_size_type end_index, wt_huff_value_type symbol);

    struct ResultLexSmallerCount
    {
        bool lex_ordered;
        wt_huff_size_type rank;
        wt_huff_size_type count_smaller_symbols;
    };
    ResultLexSmallerCount FN(wt_huff_lex_smaller_count, WT_HUFF_ID)(WtHuff *x, wt_huff_size_type index, wt_huff_value_type symbol);

    struct ResultSymbolGte
    {
        bool found;
        wt_huff_value_type symbol;
    };
    ResultSymbolGte FN(wt_huff_symbol_gte, WT_HUFF_ID)(WtHuff *x, wt_huff_value_type symbol);

    struct ResultSymbolLte
    {
        bool found;
        wt_huff_value_type symbol;
    };
    ResultSymbolLte FN(wt_huff_symbol_lte, WT_HUFF_ID)(WtHuff *x, wt_huff_value_type symbol);
}

#endif //SDSL_C_WT_HUFF_HPP
