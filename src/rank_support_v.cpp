#include "rank_support_v.hpp"

RankSupportV *FN(rank_support_v_create, RANK_SUPPORT_V_ID)(BitVector *v)
{
    const auto &bv = *reinterpret_cast<sdsl::bit_vector *>(v);
    return reinterpret_cast<RankSupportV *>(
        new sdsl::rank_support_v<RANK_SUPPORT_V_TEMPLATE>(&bv));
}

void FN(rank_support_v_destroy, RANK_SUPPORT_V_ID)(RankSupportV *x)
{
    auto &rs = *reinterpret_cast<sdsl::rank_support_v<RANK_SUPPORT_V_TEMPLATE> *>(x);
    delete &rs;
}

rank_support_v_size_type FN(rank_support_v_rank, RANK_SUPPORT_V_ID)(RankSupportV *x, rank_support_v_size_type index)
{
    const auto &rs = *reinterpret_cast<sdsl::rank_support_v<RANK_SUPPORT_V_TEMPLATE> *>(x);
    return rs.rank(index);
}

rank_support_v_size_type FN(rank_support_v_size, RANK_SUPPORT_V_ID)(RankSupportV *x) {
    const auto &rs = *reinterpret_cast<sdsl::rank_support_v<RANK_SUPPORT_V_TEMPLATE> *>(x);
    return rs.size();
}
