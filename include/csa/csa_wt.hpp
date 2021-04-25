#include <sdsl/suffix_arrays.hpp>
#include <sdsl/csa_wt.hpp>


#ifndef SDSL_C_CSA_WT_HPP
#define SDSL_C_CSA_WT_HPP

/*
using WavletTree = sdsl::wt_int<sdsl::bv, sdsl::rank_support_v5<>>;
using FM_Index = sdsl::csa_wt<WavletTree, 2, 16777216>;
 */


#define CSA_WT_TEMPLATE wt_huff<>, 32, 32, sa_order_sa_sampling<>, isa_sampling<>, succinct_byte_alphabet<>

extern "C"
{
struct CSA_WT;
typedef struct CSA_WT CSA_WT;
typedef bool csa_wt_value_type;
typedef uint64_t csa_wt_size_type;


csa_wt ()
Default constructor. More...

csa_wt (const csa_wt &csa)
Copy constructor. More...

csa_wt (cache_config &config)
Constructor taking a cache_config. More...

        size_type 	size () const
Number of elements in the $\CSA$. More...

bool 	empty () const
Returns if the data strucutre is empty. More...

void 	swap (csa_wt &csa)
Swap method for csa_wt. More...

        value_type 	operator[] (size_type i) const
[]-operator More...

csa_wt & 	operator= (const csa_wt &csa)
Assignment Operator. More...

        csa_wt & 	operator= (csa_wt &&csa)
Assignment Move Operator. More...

void 	load (std::istream &in)
Load from a stream. More...


static size_type 	max_size ()
Returns the largest size that csa_wt can ever have. More...

}


#endif //SDSL_C_CSA_WT_HPP
