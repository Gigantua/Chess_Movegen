# Chess Movegen
State of the art comparison of chess sliding piece algorithms.
Prints memory consumption for each algorithm
Prints which operation needs to exist in hardware for maximum performance. Inline versions available (no lookup table used)

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
Megalooks Simulated Game/s:
AMD Ryzen 9 5950X 16-Core Processor

Megalooks Known Positions/s:
Exploading:     151.058MOps     6 kB    Optimal perf: imul64 templ:  no
Reference:      155.334MOps     0 kB    Optimal perf: none templ: yes
Pext Emulated:  99.2648MOps     843 kB  Optimal perf: none templ:  no
KoggeStone:     113.804MOps     0 kB    Optimal perf: none templ:  no
RotatedBoard:   69.8078MOps     14 kB   Optimal perf: none templ:  no
QBB Algo:       186.446MOps     0 kB    Optimal perf: countr_zero, countl_zero templ: yes
BobMike:        253.626MOps     8 kB    Optimal perf: countr_zero, countl_zero templ: yes
Leorik:         228.003MOps     1 kB    Optimal perf: countl_zero templ:  no
Leorik Lookup:  202.608MOps     0 kB    Optimal perf: countl_zero templ:  no
Obstr. Diff:    258.002MOps     6 kB    Optimal perf: countl_zero templ:  no
Obstr. Inline:  212.233MOps     0 kB    Optimal perf: countl_zero templ: yes
SlideArithm:    268.605MOps     2 kB    Optimal perf: bzhi_u64, blsmsk_u64 templ:  no
SlideA Inline:  193.436MOps     0 kB    Optimal perf: bzhi_u64, blsmsk_u64 templ:  no
Hyperbola Qsc:  316.284MOps     2 kB    Optimal perf: bswap templ:  no
Hyperb.Inline:  270.871MOps     0 kB    Optimal perf: bswap templ: yes
SISSY BB:       262.717MOps     1409 kB Optimal perf: none templ:  no
Hash Variable:  354.248MOps     729 kB  Optimal perf: imul64 templ: yes
Hash Plain:     1010.3MOps      2306 kB Optimal perf: imul64 templ:  no
Hash Fancy:     1199.83MOps     694 kB  Optimal perf: imul64 templ:  no
Pext  :         1824.13MOps     843 kB  Optimal perf: pext_u64 templ: yes
HyperCube:      329.147MOps     841 kB  Optimal perf: none templ: yes
```


