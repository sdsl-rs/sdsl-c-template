#include "csa_wt.hpp"

CSA_WT *csa_wt_create()
{
    return reinterpret_cast<CSA_WT *>(
        new sdsl::csa_wt<CSA_WT_TEMPLATE>());
}
