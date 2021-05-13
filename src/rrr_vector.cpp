#include "rrr_vector.hpp"

RrrVector *FN(rrr_vector_create, RRR_VECTOR_ID)(BitVector *v)
{
    const auto &bv = *reinterpret_cast<sdsl::bit_vector *>(v);
    return reinterpret_cast<RrrVector *>(new sdsl::rrr_vector<RRR_VECTOR_TEMPLATE>(bv));
}

void FN(rrr_vector_destroy, RRR_VECTOR_ID)(RrrVector *v)
{
    auto &vec = *reinterpret_cast<sdsl::rrr_vector<RRR_VECTOR_TEMPLATE> *>(v);
    delete &vec;
}

RrrVector *FN(rrr_vector_copy, RRR_VECTOR_ID)(RrrVector *v)
{
    const auto &vec = *reinterpret_cast<sdsl::rrr_vector<RRR_VECTOR_TEMPLATE> *>(v);
    return reinterpret_cast<RrrVector *>(
        new sdsl::rrr_vector<RRR_VECTOR_TEMPLATE>(vec));
}

rrr_vector_size_type FN(rrr_vector_size, RRR_VECTOR_ID)(RrrVector *v)
{
    const auto &vec = *reinterpret_cast<sdsl::rrr_vector<RRR_VECTOR_TEMPLATE> *>(v);
    return vec.size();
}

bit_vector_value_type FN(rrr_vector_get_bv_element, RRR_VECTOR_ID)(RrrVector *v, const rrr_vector_size_type index)
{
    const auto &vec = *reinterpret_cast<sdsl::rrr_vector<RRR_VECTOR_TEMPLATE> *>(v);
    return vec[index];
}

uint64_t FN(rrr_vector_get_int, RRR_VECTOR_ID)(RrrVector *v, const rrr_vector_size_type index, uint8_t len)
{
    const auto &vec = *reinterpret_cast<sdsl::rrr_vector<RRR_VECTOR_TEMPLATE> *>(v);
    return vec.get_int(index, len);
}
