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

namespace Lookup = Chess_Lookup::Lookup_Hyper;

Lookup::Prepare(occ);

uint64_t attacks = Lookup::Queen(sq);



