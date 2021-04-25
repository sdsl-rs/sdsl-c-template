#include "gtest/gtest.h"
#include "rank/rank_support_v5.hpp"


TEST(RankSupportV5, test) {
    RankSupportV5 *x = FN(rank_support_v5_create, RANK_SUPPORT_V5_ID)();
    FN(rank_support_v5_destroy, RANK_SUPPORT_V5_ID)(x);
}