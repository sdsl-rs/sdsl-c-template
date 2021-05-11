#include <sdsl/rank_support_v5.hpp>
#include "rank_support_v5.hpp"

RankSupportV5 *FN(rank_support_v5_create, RANK_SUPPORT_V5_ID)()
{
    return reinterpret_cast<RankSupportV5 *>(
        new sdsl::rank_support_v5<RANK_SUPPORT_V5_TEMPLATE>());
}

void FN(rank_support_v5_destroy, RANK_SUPPORT_V5_ID)(RankSupportV5 *x)
{
    auto &i = *reinterpret_cast<sdsl::rank_support_v5<RANK_SUPPORT_V5_TEMPLATE> *>(x);
    delete &i;
}
