#include "../common.hpp"

#include <sdsl/construct.hpp>
#include <sdsl/config.hpp>
#include <sdsl/sdsl_concepts.hpp>
#include <sdsl/int_vector.hpp>
#include <sdsl/wt_int.hpp>

#ifndef SDSL_C_WT_INT_HPP
#define SDSL_C_WT_INT_HPP

#define WT_INT_ID _id
#define WT_INT_TEMPLATE sdsl::bit_vector, sdsl::bit_vector::rank_1_type, sdsl::bit_vector::select_1_type, sdsl::bit_vector::select_0_type

extern "C"
{
    struct WtInt;
    typedef struct WtInt WtInt;
    typedef void IntVector;
    typedef void BitVector;
    typedef sdsl::int_vector<>::value_type wt_int_value_type;
    typedef sdsl::int_vector<>::size_type wt_int_size_type;

    WtInt *FN(wt_int_create, WT_INT_ID)();
    WtInt *FN(wt_int_from_file, WT_INT_ID)(const char *const file, uint8_t num_bytes);
    WtInt *FN(wt_int_from_string, WT_INT_ID)(const char *const data);
    WtInt *FN(wt_int_from_int_vector, WT_INT_ID)(IntVector *iv_ptr);
    WtInt *FN(wt_int_from_bit_vector, WT_INT_ID)(BitVector *bv_ptr);
    WtInt *FN(wt_int_copy, WT_INT_ID)(WtInt *x);
    void FN(wt_int_destroy, WT_INT_ID)(WtInt *x);

    wt_int_size_type FN(wt_int_size, WT_INT_ID)(WtInt *x);
    bool FN(wt_int_empty, WT_INT_ID)(WtInt *x);
    wt_int_value_type FN(wt_int_get_element, WT_INT_ID)(WtInt *x, wt_int_size_type index);
    wt_int_size_type FN(wt_int_rank, WT_INT_ID)(WtInt *x, wt_int_size_type index, wt_int_value_type symbol);

    struct ResultInverseSelect
    {
        wt_int_size_type rank;
        wt_int_value_type symbol;
    };
    ResultInverseSelect FN(wt_int_inverse_select, WT_INT_ID)(WtInt *x, wt_int_size_type index);

    wt_int_size_type FN(wt_int_select, WT_INT_ID)(WtInt *x, wt_int_size_type index, wt_int_value_type symbol);

    struct ResultIntervalSymbols
    {
        wt_int_size_type interval_alphabet_size;

        wt_int_size_type length;
        wt_int_value_type *cs;
        wt_int_size_type *rank_c_i;
        wt_int_size_type *rank_c_j;
    };
    ResultIntervalSymbols FN(wt_int_interval_symbols, WT_INT_ID)(
        WtInt *x,
        wt_int_size_type start_index,
        wt_int_size_type end_index);

    void FN(wt_int_free_result_interval_symbols, WT_INT_ID)(wt_int_value_type *cs,
                                                            wt_int_size_type *rank_c_i,
                                                            wt_int_size_type *rank_c_j);

    struct ResultLexCount
    {
        wt_int_size_type rank;
        wt_int_size_type count_smaller_symbols;
        wt_int_size_type count_greater_symbols;
    };
    ResultLexCount FN(wt_int_lex_count, WT_INT_ID)(WtInt *x,
                                                   wt_int_size_type start_index,
                                                   wt_int_size_type end_index,
                                                   wt_int_value_type symbol);

    struct ResultLexSmallerCount
    {
        wt_int_size_type rank;
        wt_int_size_type count_smaller_symbols;
    };
    ResultLexSmallerCount FN(wt_int_lex_smaller_count, WT_INT_ID)(WtInt *x, wt_int_size_type index, wt_int_value_type symbol);

    struct ResultRangeSearch2d
    {
        wt_int_size_type count_found_points;
        wt_int_size_type *point_indexes;
        wt_int_value_type *point_values;
    };
    ResultRangeSearch2d FN(wt_int_range_search_2d, WT_INT_ID)(WtInt *x,
                                                              wt_int_size_type lb,
                                                              wt_int_size_type rb,
                                                              wt_int_value_type vlb,
                                                              wt_int_value_type vrb,
                                                              bool report);

    void FN(wt_int_free_result_range_search_2d, WT_INT_ID)(wt_int_value_type *point_values,
                                                           wt_int_size_type *point_indexes);

    wt_int_size_type FN(wt_int_alphabet_size, WT_INT_ID)(WtInt *x);
}

#endif //SDSL_C_WT_INT_HPP
