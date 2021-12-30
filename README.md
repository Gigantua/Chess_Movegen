# Chess Movegen
State of the art comparison of chess sliding piece algorithms.
Prints memory consumption for each algorithm
Prints which operation needs to exist in hardware for maximum performance

## Currently implements:
- Pext Lookup
- Plain Hash
- Veriable Shift Hash
- Fancy Hash
- Exploding Bitboards
- Switch Lookup
- Rotated Bitboard
- Kogge Stone
- QBB Algorithm
- Bobs Lookup Method
- Slider Arithmetic
- Xorshift Lookup
- Hypercube Lookup

# Build
- Linux: make
- Windows: use Visual Studio Solution

# How to use
Just copy and paste the .hpp file you would like to use in your own chess engine. Now you are done. No initialisation etc. needed (happens during compiletime)
```
namespace Lookup = Chess_Lookup::Lookup_Hyper;
Lookup::Prepare(occ);
uint64_t attacks = Lookup::Queen(sq);
```
# Example Result:
```
AMD Ryzen 9 5950X 16-Core Processor
Megalooks Simulated Game/s:
Exploading:     150.06MOps      6 kB    Optimal perf: imul64
Reference:      67.46MOps       8 kB    Optimal perf: none
KoggeStone:     110.94MOps      0 kB    Optimal perf: none
RotatedBoard:   92.27MOps       14 kB   Optimal perf: none
QBB Algo:       172.01MOps      0 kB    Optimal perf: countr_zero, countl_zero
BobMike:        211.71MOps      8 kB    Optimal perf: countr_zero, countl_zero
SlideArithm:    255.75MOps      2 kB    Optimal perf: bzhi_u64, blsmsk_u64
XorRookSub:     296.32MOps      2 kB    Optimal perf: bswap
Hash Variable:  401.75MOps      729 kB  Optimal perf: imul64
Hash Plain:     531.46MOps      2306 kB Optimal perf: imul64
Hash Fancy:     600.66MOps      694 kB  Optimal perf: imul64
Pext  :         928.81MOps      843 kB  Optimal perf: pext_u64
HyperCube:      282.18MOps      841 kB  Optimal perf: none
```


