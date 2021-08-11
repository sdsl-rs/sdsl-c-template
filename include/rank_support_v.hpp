#include "common.hpp"
#include "bit_vectors/bit_vector.hpp"
#include <sdsl/rank_support_v.hpp>

#ifndef SDSL_C_RANK_SUPPORT_V_HPP
#define SDSL_C_RANK_SUPPORT_V_HPP

#define RANK_SUPPORT_V_ID _id
#define RANK_SUPPORT_V_TEMPLATE 1, 1

extern "C"
{
    struct RankSupportV;
    typedef struct RankSupportV RankSupportV;
    typedef uint64_t rank_support_v_value_type;
    typedef uint64_t rank_support_v_size_type;

    RankSupportV *FN(rank_support_v_create, RANK_SUPPORT_V_ID)(BitVector *v);
    void FN(rank_support_v_destroy, RANK_SUPPORT_V_ID)(RankSupportV *x);
    rank_support_v_size_type FN(rank_support_v_rank, RANK_SUPPORT_V_ID)(RankSupportV *x, rank_support_v_size_type index);
    rank_support_v_size_type FN(rank_support_v_size, RANK_SUPPORT_V_ID)(RankSupportV *x);
}

#endif //SDSL_C_RANK_SUPPORT_V_HPP
