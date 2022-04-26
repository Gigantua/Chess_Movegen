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

namespace Chess_Lookup::GeneticObstructionDiffV2
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
        constexpr Ray6(int sq) 
        {
            uint64_t lo = (1ull << sq) - 1;
            uint64_t up = (0xFFFFFFFFFFFFFFFE << sq);
            ho = dir_HO(sq); 
            ve = dir_VE(sq); 
            d1 = dir_D1(sq); 
            d2 = dir_D2(sq);

            ho_lo = ho & lo | 1; ho_up = ho & up;
            ve_lo = ve & lo | 1; ve_up = ve & up;
            d1_lo = d1 & lo | 1; d1_up = d1 & up;
            d2_lo = d2 & lo | 1; d2_up = d2 & up;

            ho ^= (1ull << sq); ve ^= (1ull << sq);
            d1 ^= (1ull << sq); d2 ^= (1ull << sq);
        }
        uint64_t ho_lo; uint64_t ho_up; uint64_t ho;
        uint64_t ve_lo; uint64_t ve_up; uint64_t ve;
        uint64_t d1_lo; uint64_t d1_up; uint64_t d1;
        uint64_t d2_lo; uint64_t d2_up; uint64_t d2;
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

    static constexpr uint64_t line_attack(uint64_t lower, uint64_t upper, uint64_t mask)
    {
        const uint64_t msb = 0x8000000000000000ull >> std::countl_zero(lower);
        return (mask & (upper ^ (upper - msb)));
    }


    //Daniel.infuehr@live.de
    //Improvement 20.04.2022 - removal of square masking by smarter mask constants  
    //Improvement 25.04.2022 - removal of lower | 1 by adding this to the compiletime mask constants
    static constexpr uint64_t Rook(int sq, uint64_t occ)
    {
        occ |= 1;
        const auto& r = rays[sq];
        return line_attack(occ & r.ho_lo, occ & r.ho_up, r.ho) |
               line_attack(occ & r.ve_lo, occ & r.ve_up, r.ve);
    }

    static constexpr uint64_t Bishop(int sq, uint64_t occ)
    {
        occ |= 1;
        const auto& r = rays[sq];
        return line_attack(occ & r.d1_lo, occ & r.d1_up, r.d1) |
               line_attack(occ & r.d2_lo, occ & r.d2_up, r.d2);
    }

    static  uint64_t Queen(int sq, uint64_t occ)
    {
        occ |= 1;
        const auto& r = rays[sq];
        return line_attack(occ & r.ho_lo, occ & r.ho_up, r.ho) | line_attack(occ & r.ve_lo, occ & r.ve_up, r.ve) |
               line_attack(occ & r.d1_lo, occ & r.d1_up, r.d1) | line_attack(occ & r.d2_lo, occ & r.d2_up, r.d2);
    }

#undef GetLower
#undef GetUpper
#undef dir_HO
#undef dir_VE
#undef dir_D1
#undef dir_D2
}