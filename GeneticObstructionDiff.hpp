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
#include <bit>

namespace Chess_Lookup::GeneticObstructionDiff
{

#define GetLower(S) ((1ull << S) - 1)
#define GetUpper(S) (0xFFFFFFFFFFFFFFFF << (S))
#define dir_HO(X) (0xFFull << (X & 56))
#define dir_VE(X) (0x0101010101010101ull << (X & 7))
#define dir_D1(X) (mask_shift(0x8040201008040201ull, (X & 7) - (X >> 3)))
#define dir_D2(X) (mask_shift(0x0102040810204080ull, 7 - (X & 7) - (X >> 3)))

    static constexpr uint64_t mask_shift(uint64_t bb, int ranks)
    {
        if (ranks > 0) return bb >> (ranks << 3);
        else return bb << -(ranks << 3);
    }

    struct Ray6
    {
        constexpr Ray6() = default;
        constexpr Ray6(int sq) : lower(((1ull << sq) - 1)), upper((0xFFFFFFFFFFFFFFFE << sq)), ho(dir_HO(sq)), ve(dir_VE(sq)), d1(dir_D1(sq)), d2(dir_D2(sq))
        {

        }
        uint64_t lower; uint64_t upper;
        uint64_t ho;    uint64_t ve;
        uint64_t d1;    uint64_t d2;
    };

    constexpr std::array<Ray6, 64> rays = []()
    {
        std::array<Ray6, 64> q = {};
        for (int sq = 0; sq < 64; sq++)
        {
            q[sq] = Ray6(sq);
        }
        return q;
    }();
    constexpr auto Size = sizeof(rays);
    constexpr std::array<uint64_t, 65> msbs = []() 
    {
        std::array<uint64_t, 65> q = {};
        for (int sq = 0; sq < 64; sq++)
        {
            q[sq] = 0x8000000000000000ull >> sq;
        }
        q[64] = 0x8000000000000000ull >> 63;
        return q;
    }();

    static constexpr uint64_t line_attack(uint64_t lower, uint64_t upper, uint64_t mask)
    {
        const uint64_t msb = 0x8000000000000000ull >> std::countl_zero(lower | 1);
        return (mask & (upper ^ (upper - msb)));
    }


    //Daniel.infuehr@live.de
    //Improvement 20.04.2022 - removal of square masks by smarter shift constant (implicit masking) and XOR instruction
    //https://godbolt.org/z/a9K4x8919
    static constexpr uint64_t Rook(int sq, uint64_t occ)
    {
        const uint64_t lower = occ & rays[sq].lower;
        const uint64_t upper = occ & rays[sq].upper;
        const uint64_t ho = rays[sq].ho;
        const uint64_t ve = rays[sq].ve;

        return line_attack(ho & lower, ho & upper, ho) ^ //Removal of upper rook mask
               line_attack(ve & lower, ve & upper, ve);
    }

    static constexpr uint64_t Bishop(int sq, uint64_t occ)
    {
        const uint64_t lower = occ & rays[sq].lower;
        const uint64_t upper = occ & rays[sq].upper;
        const uint64_t ho = rays[sq].d1;
        const uint64_t ve = rays[sq].d2;

        return line_attack(ho & lower, ho & upper, ho) ^
               line_attack(ve & lower, ve & upper, ve);
    }

    static  uint64_t Queen(int sq, uint64_t occ)
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