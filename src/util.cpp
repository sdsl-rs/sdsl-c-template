#include "util.hpp"

void FN(set_to_value, UTIL_ID)(Structure *v, uint64_t k)
{
    auto &vec = *reinterpret_cast<STRUCTURE *>(v);
    sdsl::util::set_to_value(vec, k);
}

void FN(set_to_id, UTIL_ID)(Structure *v)
{
    auto &vec = *reinterpret_cast<STRUCTURE *>(v);
    sdsl::util::set_to_id(vec);
}

void FN(set_random_bits, UTIL_ID)(Structure *v)
{
    auto &vec = *reinterpret_cast<STRUCTURE *>(v);
    sdsl::util::set_random_bits(vec);
}

void FN(mod, UTIL_ID)(Structure *v, size_type m)
{
    auto &vec = *reinterpret_cast<STRUCTURE *>(v);
    sdsl::util::mod(vec, m);
}

void FN(bit_compress, UTIL_ID)(Structure *v)
{
    auto &vec = *reinterpret_cast<STRUCTURE *>(v);
    sdsl::util::bit_compress(vec);
}

void FN(expand_width, UTIL_ID)(Structure *v, uint8_t new_width)
{
    auto &vec = *reinterpret_cast<STRUCTURE *>(v);
    sdsl::util::expand_width(vec, new_width);
}