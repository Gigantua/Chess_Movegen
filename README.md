# Chess Movegen
State of the art comparison of chess sliding piece algorithms.
Prints memory consumption for each algorithm
Prints which operation needs to exist in hardware for maximum performance

## Currently implements:
- Pext Lookup
- Emulated Pext Lookup
- Kogge Stone
- Exploading Bitboards
- Hyperbola Quintessence
- Plain Hash
- Veriable Shift Hash
- Fancy Hash
- Exploding Bitboards
- Switch Lookup
- Rotated Bitboard
- QBB Algorithm
- Leorik Algorithm
- Bobs Lookup Method
- Slider Arithmetic
- Obstruction Difference
- Xorshift Lookup
- Hypercube Lookup

# Special Modes
Some of the above algorithms have 0kb lookup modes where values are calculated at runtime without any lookups at all.
Some of the above algorithms have a templated position parameter to have a forceinlined version of these lookups available.   


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
Exploading:     150.89MOps      6 kB    Optimal perf: imul64
Reference:      68.93MOps       8 kB    Optimal perf: none
KoggeStone:     111.98MOps      0 kB    Optimal perf: none
RotatedBoard:   92.37MOps       14 kB   Optimal perf: none
QBB Algo:       171.72MOps      0 kB    Optimal perf: countr_zero, countl_zero
BobMike:        211.32MOps      8 kB    Optimal perf: countr_zero, countl_zero
SlideArithm:    256.04MOps      2 kB    Optimal perf: bzhi_u64, blsmsk_u64
XorRookSub:     297.78MOps      2 kB    Optimal perf: bswap
Hash Variable:  399.36MOps      729 kB  Optimal perf: imul64
Hash Plain:     529.61MOps      2306 kB Optimal perf: imul64
Hash Fancy:     597.36MOps      694 kB  Optimal perf: imul64
Pext  :         925.24MOps      843 kB  Optimal perf: pext_u64
HyperCube:      310.30MOps      841 kB  Optimal perf: none
```


