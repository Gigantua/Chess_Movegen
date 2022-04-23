/*
 This sliding lookup implementation is based on QBBEngine by Fabio Gobbato

 Small improvement by daniel infuehr (daniel.infuehr@live.de) compared to classical QBB in the final result calculation. 
 (Shifts instead of AND with 1 constant less)
*/
#pragma once
#include <stdint.h>
#include <bit>

namespace Chess_Lookup::GeneticQBB
{
    static constexpr uint64_t MSB(uint64_t value)
    {
        return 63ull - std::countl_zero(value);
    }

    static constexpr uint64_t LSB(uint64_t value)
    {
        return 63ull - std::countr_zero(value);
    }

    static constexpr uint64_t Size = 0;

    static constexpr uint64_t Rook(int sq, uint64_t occ)
    {
        occ ^= (1ull << sq);
        const int sr = 63 - sq;
        uint64_t msb_do = MSB((occ | 0x00000000000000FFULL) & (0x8080808080808080ULL >> sr));
        uint64_t msb_le = MSB((occ | 0x0101010101010101ULL) & (0xFF00000000000000ULL >> sr));
        uint64_t lsb_up = LSB((occ | 0xFF00000000000000ULL) & (0x0101010101010101ULL << sq));
        uint64_t lsb_ri = LSB((occ | 0x8080808080808080ULL) & (0x00000000000000FFULL << sq));
        //Comment daniel: The dependency chain here is longer than with vanilla QBB. The code is shorter! - but slower depending on the architectures. 
        return (((0x0101010101010101ULL << msb_do) << lsb_up) >> lsb_up) ^ 
               (((0x00000000000000FFULL << msb_le) << lsb_ri) >> lsb_ri);
    }

    static constexpr uint64_t Bishop(int sq, uint64_t occ)
    {
        occ ^= (1ull << sq);
        const int sr = 63 - sq;
        uint64_t msb_do = MSB((occ | 0x01010101010101FFULL) & (0x8040201008040201ULL >> sr));
        uint64_t msb_le = MSB((occ | 0x80808080808080FFULL) & (0x8102040810204081ULL >> sr));
        uint64_t lsb_up = LSB((occ | 0xFF80808080808080ULL) & (0x8040201008040201ULL << sq));
        uint64_t lsb_ri = LSB((occ | 0xFF01010101010101ULL) & (0x8102040810204081ULL << sq));
        return (((0x8040201008040201ULL << msb_do) << lsb_up) >> lsb_up) ^ 
               (((0x8102040810204081ULL << msb_le) << lsb_ri) >> lsb_ri);
    }

    static constexpr uint64_t Queen(int sq, uint64_t occupation) {
        return Rook(sq, occupation) | Bishop(sq, occupation);
    }
}