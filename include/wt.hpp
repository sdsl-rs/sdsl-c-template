#include <sdsl/wt_algorithm.hpp>
#include <sdsl/wt_int.hpp>
#include <sdsl/int_vector.hpp>
#include <sdsl/construct.hpp>
#include "common.hpp"


#ifndef SDSL_C_WT_HPP
#define SDSL_C_WT_HPP

#define WT_ID _id
#define WT_TYPE sdsl::wt_int
#define WT_TEMPLATE //sdsl::bit_vector, sdsl::rank_support_v5<>
#define WT_CONSTRUCT_DATA_TYPE sdsl::int_vector<>

extern "C"
{

struct WT;
typedef struct WT WT;

struct ConstructDataType;
typedef struct ConstructDataType ConstructDataType;

//long unsigned int
typedef uint64_t wt_value_type;
typedef uint64_t wt_size_type;

WT *FN(wt_data_construct, WT_ID)(ConstructDataType *data, uint8_t num_bytes);

void FN(wt_destroy, WT_ID)(WT *x);

typedef struct IntersectResult {
    wt_size_type _num_results;
    wt_value_type *_values;
    wt_size_type *_frequencies;
} IntersectResults;

IntersectResult FN(wt_intersect, WT_ID)(WT *x,
                                        wt_size_type num_ranges,
                                        wt_size_type *start_ranges,
                                        wt_size_type *end_ranges);

void FN(wt_dealloc_intersect_result, WT_ID)(IntersectResult *result);

typedef struct IntervalSymbolsResults {
    wt_size_type num_symbols_in_range;
    wt_value_type *_symbols_in_range;
    wt_size_type *_rank_start_index;
    wt_size_type *_rank_end_index;
} IntervalSymbolsResults;

IntervalSymbolsResults FN(wt_interval_symbols, WT_ID)(WT *x, wt_size_type start_index,
                                                      wt_size_type end_index);

void FN(wt_dealloc_interval_symbols_result, WT_ID)(IntervalSymbolsResults *results);

}

#endif //SDSL_C_WT_HPP
