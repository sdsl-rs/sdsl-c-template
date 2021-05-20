#include "io.hpp"

bool FN(store_to_file, IO_ID)(const Structure *const v,
                              const char *const file)
{
    const auto &vec = *reinterpret_cast<const STRUCTURE *>(v);
    return sdsl::store_to_file(vec, file);
}

bool FN(store_int_vector_to_file, IO_ID)(const Structure *const v,
                                         const char *const file,
                                         bool write_fixed_as_variable)
{
    const auto &vec = *reinterpret_cast<const INT_VECTOR_STRUCTURE *>(v);
    return sdsl::store_to_file(vec, file, write_fixed_as_variable);
}

bool FN(load_from_file, IO_ID)(Structure *v, const char *const file)
{
    auto &vec = *reinterpret_cast<STRUCTURE *>(v);
    return sdsl::load_from_file(vec, file);
}