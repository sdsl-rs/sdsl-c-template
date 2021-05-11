#include "common.hpp"

#ifndef SDSL_C_RANK_SUPPORT_V5_HPP
#define SDSL_C_RANK_SUPPORT_V5_HPP

#define RANK_SUPPORT_V5_ID _id_42
#define RANK_SUPPORT_V5_TEMPLATE // 1 COMMA 1

extern "C"
{
    struct RankSupportV5;
    typedef struct RankSupportV5 RankSupportV5;

    RankSupportV5 *FN(rank_support_v5_create, RANK_SUPPORT_V5_ID)();
    void FN(rank_support_v5_destroy, RANK_SUPPORT_V5_ID)(RankSupportV5 *x);
}

#endif //SDSL_C_RANK_SUPPORT_V5_HPP
