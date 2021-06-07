#include "select_support_mcl.hpp"

SelectSupportMcl *FN(select_support_mcl_create, SELECT_SUPPORT_MCL_ID)(BitVector *v)
{
    const auto &bv = *reinterpret_cast<sdsl::bit_vector *>(v);
    return reinterpret_cast<SelectSupportMcl *>(
        new sdsl::select_support_mcl<SELECT_SUPPORT_MCL_TEMPLATE>(&bv));
}

void FN(select_support_mcl_destroy, SELECT_SUPPORT_MCL_ID)(SelectSupportMcl *x)
{
    auto &ss = *reinterpret_cast<sdsl::select_support_mcl<SELECT_SUPPORT_MCL_TEMPLATE> *>(x);
    delete &ss;
}

select_support_mcl_size_type FN(select_support_mcl_select, SELECT_SUPPORT_MCL_ID)(SelectSupportMcl *x, select_support_mcl_size_type index)
{
    const auto &ss = *reinterpret_cast<sdsl::select_support_mcl<SELECT_SUPPORT_MCL_TEMPLATE> *>(x);
    return ss.select(index);
}
