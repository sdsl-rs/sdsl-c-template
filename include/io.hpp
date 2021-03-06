#include <sdsl/io.hpp>
#include <sdsl/bit_vectors.hpp>
#include <sdsl/rank_support.hpp>
#include <sdsl/select_support.hpp>
#include <sdsl/wavelet_trees.hpp>
#include "common.hpp"

#ifndef SDSL_C_IO_H
#define SDSL_C_IO_H

#define IO_ID _id
#define STRUCTURE sdsl::int_vector<0>
#define INT_VECTOR_STRUCTURE sdsl::int_vector<0>

extern "C"
{
    typedef void Structure;

    bool FN(store_to_file, IO_ID)(const Structure *const v,
                                  const char *const file);
    bool FN(store_int_vector_to_file, IO_ID)(const Structure *const v,
                                             const char *const file,
                                             bool write_fixed_as_variable);
    bool FN(load_from_file, IO_ID)(Structure *v, const char *const file);
}

#endif //SDSL_C_IO_H