#include <sdsl/io.hpp>
#include <sdsl/int_vector.hpp>
#include "common.hpp"

#ifndef SDSL_C_IO_H
#define SDSL_C_IO_H

#define IO_ID _id
#define STRUCTURE sdsl::int_vector<0>

extern "C"
{
    struct Structure;
    typedef struct Structure Structure;

    bool FN(store_to_file, IO_ID)(const Structure *const v,
                                  const char *const file,
                                  bool write_fixed_as_variable);
    bool FN(load_from_file, IO_ID)(Structure *v, const char *const file);
}

#endif //SDSL_C_IO_H