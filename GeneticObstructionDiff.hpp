/**
 * GeneticObstructionDiff.hpp
 *
 * Copyright © 2022 Daniel Inführ
 *
 * This file is under MIT licence and may be used in any piece of code if you keep this unedited header in the sourcefile 
 * Created by C++ Abstract Sytax Tree Sifting - improvement of ObstructionDifference
 * For Questions and contact under daniel.infuehr(@)live.de
 *
 * Maintained by Daniel Inführ, 2022
 *
 * @file GeneticObstructionDiff.hpp
 * @author Daniel Inführ
 * @copyright 2022
 * @section License
 */

#pragma once

#include <stdint.h>
#include <array>

namespace Chess_Lookup::GeneticObstructionDiff
{

#define GetLower(S) ((1ull << S) - 1)
#define GetUpper(S) (0xFFFFFFFFFFFFFFFF << (S))
#define dir_HO(X) (0xFFull << (X & 56))
#define dir_VE(X) (0x0101010101010101ull << (X & 7))
#define dir_D1(X) (mask_shift<0x8040201008040201ull>((X & 7) - (X >> 3)))
#define dir_D2(X) (mask_shift<0x0102040810204080ull>(7 - (X & 7) - (X >> 3)))

    constexpr auto Size = 0; //0 kb version

    template<uint64_t bb>
    static constexpr uint64_t mask_shift(int ranks) {
        return ranks > 0 ? bb >> (ranks << 3) : bb << -(ranks << 3);
    }

    static constexpr uint64_t line_attack(uint64_t lower, uint64_t upper, uint64_t mask)
    {
        const uint64_t msb = 0x8000000000000000ull >> std::countl_zero(lower | 1);
        return (mask & (upper ^ (upper - msb)));
    }

    static constexpr uint64_t Bishop(int sq, uint64_t occ)
    {
        const uint64_t m = (1ull << sq); //Bitboard native candidate. (no more square)
        const uint64_t lower = occ &  (m - 1);
        const uint64_t upper = occ & ~(m - 1);
        const uint64_t ho = dir_HO(sq) ^ m;
        const uint64_t ve = dir_VE(sq) ^ m;

        return line_attack(ho & lower, ho & upper, ho) | 
               line_attack(ve & lower, ve & upper, ve);
    }

    static constexpr uint64_t Rook(int sq, uint64_t occ)
    {
        const uint64_t m = (1ull << sq);
        const uint64_t lower = occ & (m - 1);
        const uint64_t upper = occ & ~(m - 1);
        const uint64_t ho = dir_D1(sq) ^ m;
        const uint64_t ve = dir_D2(sq) ^ m;

        return line_attack(ho & lower, ho & upper, ho) | 
               line_attack(ve & lower, ve & upper, ve);
    }

    static constexpr uint64_t Queen(int sq, uint64_t occ)
    {
        return Bishop(sq, occ) | Rook(sq, occ);
    }


    template<int sq>
    static constexpr uint64_t Bishop(uint64_t occ)
    {
        const uint64_t m = (1ull << sq);
        const uint64_t lower = occ & (m - 1);
        const uint64_t upper = occ & ~(m - 1);
        const uint64_t ho = dir_HO(sq) ^ m;
        const uint64_t ve = dir_VE(sq) ^ m;

        return line_attack(ho & lower, ho & upper, ho) |
            line_attack(ve & lower, ve & upper, ve);
    }

    template<int sq>
    static constexpr uint64_t Rook(uint64_t occ)
    {
        const uint64_t m = (1ull << sq);
        const uint64_t lower = occ & (m - 1);
        const uint64_t upper = occ & ~(m - 1);
        const uint64_t ho = dir_D1(sq) ^ m;
        const uint64_t ve = dir_D2(sq) ^ m;

        return line_attack(ho & lower, ho & upper, ho) |
            line_attack(ve & lower, ve & upper, ve);
    }

    template<int sq>
    static constexpr uint64_t Queen(uint64_t occ)
    {
        return Bishop<sq>(occ) | Rook<sq>(occ);
    }


#undef GetLower
#undef GetUpper
#undef dir_HO
#undef dir_VE
#undef dir_D1
#undef dir_D2
}