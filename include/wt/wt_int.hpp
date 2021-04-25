#include <sdsl/int_vector.hpp>
#include "../common.hpp"


#ifndef SDSL_C_WT_INT_HPP
#define SDSL_C_WT_INT_HPP

#define WT_INT_ID _id
#define WT_INT_TEMPLATE sdsl::bit_vector, sdsl::rank_support_v5<>
#define WT_INT_CONSTRUCT_DATA_TYPE sdsl::int_vector<>

extern "C"
{
struct WT_Int;
typedef struct WT_Int WT_Int;

struct ConstructDataType;
typedef struct ConstructDataType ConstructDataType;

//long unsigned int
typedef uint64_t wt_int_value_type;
typedef uint64_t wt_int_size_type;

WT_Int *FN(wt_int_create, WT_INT_ID)();
WT_Int *FN(wt_int_data_construct, WT_INT_ID)(ConstructDataType *data, uint8_t num_bytes);
void FN(wt_int_destroy, WT_INT_ID)(WT_Int *x);

WT_Int *FN(wt_int_copy, WT_INT_ID)(WT_Int *x);
wt_int_size_type FN(wt_int_size, WT_INT_ID)(WT_Int *x);
bool FN(wt_int_empty, WT_INT_ID)(WT_Int *x);
wt_int_value_type FN(wt_int_get_element, WT_INT_ID)(WT_Int *x, const wt_int_size_type index);
wt_int_size_type FN(wt_int_rank, WT_INT_ID)(WT_Int *x, const wt_int_size_type index, const wt_int_value_type symbol);

typedef struct InverseSelectPair {
    wt_int_size_type rank;
    wt_int_value_type symbol;
} InverseSelectPair;

InverseSelectPair FN(wt_int_inverse_select, WT_INT_ID)(WT_Int *x, wt_int_size_type index);
wt_int_size_type FN(wt_int_select, WT_INT_ID)(WT_Int *x, wt_int_size_type occurrence, wt_int_value_type symbol);

typedef struct LexCountResults {
    wt_int_size_type rank;
    wt_int_size_type num_symbols_smaller;
    wt_int_size_type num_symbols_greater;
} LexCountResults;

LexCountResults FN(wt_int_lex_count, WT_INT_ID)(WT_Int *x, wt_int_size_type start_index, wt_int_size_type end_index,
                                                wt_int_value_type symbol);

typedef struct LexSmallerCountResults {
    wt_int_size_type rank;
    wt_int_size_type num_symbols_smaller;
} LexSmallerCountResults;

LexSmallerCountResults
FN(wt_int_lex_smaller_count, WT_INT_ID)(WT_Int *x, wt_int_size_type index, wt_int_value_type symbol);

typedef struct RangeSearch2DResult {
    wt_int_size_type num_found_points;

    wt_int_value_type *_point_symbols;
    wt_int_size_type *_point_indexes;
} RangeSearch2DResult;

RangeSearch2DResult FN(wt_int_range_search_2d, WT_INT_ID)(WT_Int *x,
                                                          wt_int_size_type index_left_bound,
                                                          wt_int_size_type index_right_bound,
                                                          wt_int_value_type value_left_bound,
                                                          wt_int_value_type value_right_bound,
                                                          bool matching_points_report);

void FN(wt_int_dealloc_range_search_2d_result, WT_INT_ID)(RangeSearch2DResult *results);

}


#endif //SDSL_C_WT_INT_HPP


/*
struct NodeType;
typedef struct NodeType NodeType;


bool FN(wt_int_node_is_leaf, WT_INT_ID)(WT_Int *x, NodeType *node);
wt_int_value_type FN(wt_int_node_symbol, WT_INT_ID)(WT_Int *x, NodeType *node);
bool FN(wt_int_node_empty, WT_INT_ID)(WT_Int *x, NodeType *node);
NodeType *FN(wt_int_root, WT_INT_ID)(WT_Int *x);

typedef struct NodeExpandResult {
    NodeType *left_node;
    NodeType *right_node;
} NodeExpandResult;
NodeExpandResult FN(wt_int_node_expand, WT_INT_ID)(WT_Int *x, NodeType *node);

*/
