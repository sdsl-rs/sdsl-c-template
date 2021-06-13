# C interface for SDSL

<details>
  <summary>Full Structures Status List</summary>

### Integer vectors

* [x] IntVector

### Bit vectors

* [x] BitVector (plain bit vector)
* [ ] BitVectorIl (interleaved bit vector)
* [x] RrrVector (H<sub>0</sub> compressed bit vector)
* [ ] SdVector (sparse bit vector)
* [ ] HybVector (hybrid bit vector)

### Rank Supports

* [x] RankSupportV
* [ ] RankSupportV5
* [ ] RankSupportScan
* [ ] RankSupportIl
* [ ] RankSupportRrr
* [ ] RankSupportSd
* [ ] RankSupportHyb

### Select Supports

* [x] SelectSupportMcl
* [ ] SelectSupportScan
* [ ] SelectSupportIl
* [ ] SelectSupportRrr
* [ ] SelectSupportSd

### Wavelet Trees

* [x] WtHuff
* [ ] WtRlmn
* [ ] WtGmr
* [ ] WtAp
* [ ] WmInt
* [ ] WtBlcd
* [ ] WtHutu
* [ ] WtInt

### Compressed Suffix Arrays

* [ ] CsaBitcompressed
* [ ] CsaSada
* [ ] CsaWt

### Longest Common Prefix Arrays

* [ ] LcpBitcompressed
* [ ] LcpDac
* [ ] LcpByte
* [ ] LcpWt
* [ ] LcpVlc
* [ ] LcpSupportSada
* [ ] LcpSupportTree
* [ ] LcpSupportTree2

### Balanced Parentheses Supports

* [ ] BpSupportG
* [ ] BpSupportGg
* [ ] BpSupportSada

### Compressed Suffix Trees

* [ ] CstSada
* [ ] CstSct3

### Range Min/Max Query

* [ ] RmqSupportSparseTable
* [ ] RmqSuccintSada
* [ ] RmqSuccintSct

</details>

## Dependencies

libdivsufsort

libgtest-dev (for tests)