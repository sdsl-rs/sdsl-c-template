#include "common.hpp"
#include "bit_vector.hpp"
#include <sdsl/select_support_mcl.hpp>

#ifndef SDSL_C_SELECT_SUPPORT_MCL_HPP
#define SDSL_C_SELECT_SUPPORT_MCL_HPP

#define SELECT_SUPPORT_MCL_ID _id
#define SELECT_SUPPORT_MCL_TEMPLATE 1, 1

extern "C"
{
    struct SelectSupportMcl;
    typedef struct SelectSupportMcl SelectSupportMcl;
    typedef uint64_t select_support_mcl_value_type;
    typedef uint64_t select_support_mcl_size_type;

    SelectSupportMcl *FN(select_support_mcl_create, SELECT_SUPPORT_MCL_ID)(BitVector *v);
    void FN(select_support_mcl_destroy, SELECT_SUPPORT_MCL_ID)(SelectSupportMcl *x);
    select_support_mcl_size_type FN(select_support_mcl_select, SELECT_SUPPORT_MCL_ID)(SelectSupportMcl *x, select_support_mcl_size_type index);
}

#endif //SDSL_C_SELECT_SUPPORT_MCL_HPP
