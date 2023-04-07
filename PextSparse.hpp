#include <cstdint>
#include <immintrin.h>
#include <bit>
#include "Switch.hpp"

//Translation from C# into C++20 07.04.2023 - daniel infuehr

namespace Chess_Lookup::PextSparse
{
    static uint64_t* Subset;

    const int FILE_A = 0;
    const int FILE_H = 7;
    const int RANK_1 = 0;
    const int RANK_8 = 7;

    static uint64_t DiagonalMask[64];
    static uint64_t AntiDiagonalMask[64];
    static uint64_t HorizontalMask[64];
    static uint64_t VerticalMask[64];

    static constexpr auto Size = 4*64*64*8 + 64*4*8; //Masks + Subset

    static void Init() {
        Subset = new uint64_t[4 * 64 * 64]; //16384
        //Init Masks
        for (int square = 0; square < 64; square++)
        {
            int x = square & 7;
            int y = square >> 3;

            //DiagonalMask
            for (int dx = x + 1, dy = y + 1; dx < FILE_H && dy < RANK_8; dx++, dy++)
                DiagonalMask[square] |= 1ull << dx + dy * 8;
            for (int dx = x - 1, dy = y - 1; dx > FILE_A && dy > RANK_1; dx--, dy--)
                DiagonalMask[square] |= 1ull << dx + dy * 8;

            //AntiDiagonalMask
            for (int dx = x - 1, dy = y + 1; dx > FILE_A && dy < RANK_8; dx--, dy++)
                AntiDiagonalMask[square] |= 1ull << dx + dy * 8;
            for (int dx = x + 1, dy = y - 1; dx < FILE_H && dy > RANK_1; dx++, dy--)
                AntiDiagonalMask[square] |= 1ull << dx + dy * 8;

            //HorizontalMask
            for (int dx = FILE_A + 1; dx < FILE_H; dx++)
                if (dx != x)
                    HorizontalMask[square] |= 1ull << dx + y * 8;

            //VerticalMask
            for (int dy = RANK_1 + 1; dy < RANK_8; dy++)
                if (dy != y)
                    VerticalMask[square] |= 1ull << x + dy * 8;
        }

        //Sparse Bishop-Subsets
        for (int square = 0; square < 64; square++)
        {
            uint64_t offset = (uint64_t)square * 128;
            uint64_t mask = DiagonalMask[square];
            uint64_t patterns = 1ull << std::popcount(mask);
            for (uint64_t i = 0; i < patterns; i++)
            {
                uint64_t occupation = _pdep_u64(i, mask); 
                Subset[offset + i] = Chess_Lookup::GetSliderD1Cond(square, occupation);
            }

            mask = AntiDiagonalMask[square];
            patterns = 1ull << std::popcount(mask);
            for (uint64_t i = 0; i < patterns; i++)
            {
                uint64_t occupation = _pdep_u64(i, mask);
                Subset[offset + 64 + i] = Chess_Lookup::GetSliderD2Cond(square, occupation);
            }
            
        }

        //Sparse Rook-Subsets
        for (int square = 0; square < 64; square++)
        {
            uint64_t offset = 8192 + (uint64_t)square * 128;
            uint64_t mask = HorizontalMask[square];
            uint64_t patterns = 1ull << std::popcount(mask);
            for (uint64_t i = 0; i < patterns; i++)
            {
                uint64_t occupation = _pdep_u64(i, mask);
                Subset[offset + i] = Chess_Lookup::GetSliderHCond(square, occupation);
            }

            mask = VerticalMask[square];
            patterns = 1ull << std::popcount(mask);
            for (uint64_t i = 0; i < patterns; i++)
            {
                uint64_t occupation = _pdep_u64(i, mask);
                Subset[offset + 64 + i] = Chess_Lookup::GetSliderVCond(occupation, square);
            }
        }
    }

    static inline uint64_t BishopAttacks(int square, uint64_t occupation)
    {
        int offset = square * 128;
        uint64_t dSub = Subset[offset + (int)_pext_u64(occupation, DiagonalMask[square])];
        uint64_t aSub = Subset[offset + 64 + (int)_pext_u64(occupation, AntiDiagonalMask[square])];
        return dSub | aSub;
    }

    static inline uint64_t RookAttacks(int square, uint64_t occupation)
    {
        int offset = 8192 + square * 128;
        uint64_t hSub = Subset[offset + (int)_pext_u64(occupation, HorizontalMask[square])];
        uint64_t vSub = Subset[offset + 64 + (int)_pext_u64(occupation, VerticalMask[square])];
        return hSub | vSub;
    }


	static inline uint64_t Queen(int sq, uint64_t occ) {
        return RookAttacks(sq, occ) | BishopAttacks(sq, occ);
	}
}