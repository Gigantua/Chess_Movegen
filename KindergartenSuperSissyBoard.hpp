#pragma once
// Datum  : 21.01.2023
// Author : Michael J Sherwin 2023
// Content: The name is Kindergarten Super SISSY Bitboards - https://www.talkchess.com/forum3/viewtopic.php?f=7&t=81234&start=30
//          The code can be further minimized according to the author
//			C++20 constexpr port by Daniel Infuehr

#include <stdint.h>

namespace Chess_Lookup::KGSSB
{
    static uint64_t hMask[64];
    static uint64_t dMask[64];
    static uint64_t aMask[64];
    static uint64_t vSubset[64][64];
    static uint64_t hSubset[64][64];
    static uint64_t dSubset[64][64];
    static uint64_t aSubset[64][64];
    static unsigned int shift_horizontal_table[64]; // new lookup table for shifts in calculation of hIndex

    static constexpr uint64_t Size = (64 * 64 * 4 + 64 * 4) * sizeof(uint64_t) + 64 * sizeof(unsigned int);

    enum { FILEa = 0, FILEh = 7 };
    enum { RANK1 = 0, RANK8 = 7 };

    static void InitSquare(int sq)
    {
        int ts, dx, dy;
        uint64_t occ, index;
        int x = sq % 8;
        int y = sq / 8;

        // Initialize Kindergarten Super SISSY Bitboards
        // diagonals
        for (ts = sq + 9, dx = x + 1, dy = y + 1; dx < FILEh && dy < RANK8; dMask[sq] |= 1ull << ts, ts += 9, dx++, dy++);
        for (ts = sq - 9, dx = x - 1, dy = y - 1; dx > FILEa && dy > RANK1; dMask[sq] |= 1ull << ts, ts -= 9, dx--, dy--);

        // anti diagonals
        for (ts = sq + 7, dx = x - 1, dy = y + 1; dx > FILEa && dy < RANK8; aMask[sq] |= 1ull << ts, ts += 7, dx--, dy++);
        for (ts = sq - 7, dx = x + 1, dy = y - 1; dx < FILEh && dy > RANK1; aMask[sq] |= 1ull << ts, ts -= 7, dx++, dy--);

        // diagonal indexes
        for (index = 0; index < 64; index++)
        {
            dSubset[sq][index] = 0;
            occ = index << 1;
            if ((sq & 7) != FILEh && (sq >> 3) != RANK8)
            {
                for (ts = sq + 9; ; ts += 9)
                {
                    dSubset[sq][index] |= (1ull << ts);
                    if (occ & (1ull << (ts & 7))) break;
                    if ((ts & 7) == FILEh || (ts >> 3) == RANK8) break;
                }
            }
            if ((sq & 7) != FILEa && (sq >> 3) != RANK1)
            {
                for (ts = sq - 9; ; ts -= 9)
                {
                    dSubset[sq][index] |= (1ull << ts);
                    if (occ & (1ull << (ts & 7))) break;
                    if ((ts & 7) == FILEa || (ts >> 3) == RANK1) break;
                }
            }
        }

        // anti diagonal indexes
        for (index = 0; index < 64; index++)
        {
            aSubset[sq][index] = 0;
            occ = index << 1;
            if ((sq & 7) != FILEa && (sq >> 3) != RANK8)
            {
                for (ts = sq + 7; ; ts += 7) {
                    aSubset[sq][index] |= (1ull << ts);
                    if (occ & (1ull << (ts & 7))) break;
                    if ((ts & 7) == FILEa || (ts >> 3) == RANK8) break;
                }
            }
            if ((sq & 7) != FILEh && (sq >> 3) != RANK1)
            {
                for (ts = sq - 7; ; ts -= 7)
                {
                    aSubset[sq][index] |= (1ull << ts);
                    if (occ & (1ull << (ts & 7))) break;
                    if ((ts & 7) == FILEh || (ts >> 3) == RANK1) break;
                }
            }
        }

        // horizontal lines
        for (ts = sq + 1, dx = x + 1; dx < FILEh; hMask[sq] |= 1ull << ts, ts += 1, dx++);
        for (ts = sq - 1, dx = x - 1; dx > FILEa; hMask[sq] |= 1ull << ts, ts -= 1, dx--);

        // vertical indexes
        for (index = 0; index < 64; index++) {
            vSubset[sq][index] = 0;
            uint64_t blockers = 0;
            for (int i = 0; i <= 5; i++) {
                if (index & (1ull << i)) {
                    blockers |= (1ull << (((5 - i) << 3) + 8));
                }
            }
            if ((sq >> 3) != RANK8) {
                for (ts = sq + 8; ; ts += 8) {
                    vSubset[sq][index] |= (1ull << ts);
                    if (blockers & (1ull << (ts - (ts & 7)))) break;
                    if ((ts >> 3) == RANK8) break;
                }
            }
            if ((sq >> 3) != RANK1) {
                for (ts = sq - 8; ; ts -= 8) {
                    vSubset[sq][index] |= (1ull << ts);
                    if (blockers & (1ull << (ts - (ts & 7)))) break;
                    if ((ts >> 3) == RANK1) break;
                }
            }
        }

        // horizontal indexes
        for (index = 0; index < 64; index++) {
            hSubset[sq][index] = 0;
            occ = index << 1;
            if ((sq & 7) != FILEh) {
                for (ts = sq + 1; ; ts += 1) {
                    hSubset[sq][index] |= (1ull << ts);
                    if (occ & (1ull << (ts & 7))) break;
                    if ((ts & 7) == FILEh) break;
                }
            }
            if ((sq & 7) != FILEa) {
                for (ts = sq - 1; ; ts -= 1) {
                    hSubset[sq][index] |= (1ull << ts);
                    if (occ & (1ull << (ts & 7))) break;
                    if ((ts & 7) == FILEa) break;
                }
            }
        }
    }

    static void Init()
    {
        for (int i = 0; i < 64; i++) {
            InitSquare(i);
        }

        for (int i = 0; i < 64; i++) {
            shift_horizontal_table[i] = (i & 56) + 1;
        }
    }

    static constexpr uint64_t file_b2_b7 = 0x0002020202020200ull;
    static constexpr uint64_t file_a2_a7 = 0x0001010101010100ull;
    static constexpr uint64_t diag_c2h7 = 0x0080402010080400ull;

    static uint64_t Bishop(int sq, uint64_t occ)
    {
        return  dSubset[sq][(((occ & dMask[sq]) * file_b2_b7) >> 58)] +
            aSubset[sq][(((occ & aMask[sq]) * file_b2_b7) >> 58)];
    }

    static uint64_t Rook(int sq, uint64_t occ)
    {
        return hSubset[sq][(occ >> shift_horizontal_table[sq]) & 63] +
            vSubset[sq][((((occ >> (sq & 7)) & file_a2_a7) * diag_c2h7) >> 58)];
    }

    static uint64_t Queen(int sq, uint64_t occ)
    {
        return Rook(sq, occ) | Bishop(sq, occ);
    }
}


//This namespace implements Mike Sherwin's Kindergarten Super SISSY Bitboards where SISSY stands for Split Index Sub Set Yielding
//...henceforth we shall abreviate it as KiSS <3

//Alternative but slightly slower alternative ported from C#. 470mnps vs above 520mnps. 
/*
namespace Chess_Lookup::KISS
{
    static uint64_t* dSubset = new uint64_t[64 * 64];
    static uint64_t* aSubset = new uint64_t[64 * 64];
    static uint64_t* vSubset = new uint64_t[64 * 64];
    static uint64_t* hSubset = new uint64_t[64 * 64];

    static uint64_t DiagonalMask[64];
    static uint64_t AntiDiagonalMask[64];
    static uint64_t HorizontalMask[64];
    static uint64_t VerticalMask[64];

    static auto const Size = 64 * 64 * 4 * 8 + 64 * 4 * 8;

    const int FILE_A = 0;
    const int FILE_H = 7;
    const int RANK_1 = 0;
    const int RANK_8 = 7;
    const uint64_t FILE_A2_A7 = 0x0001010101010100;
    const uint64_t DIAGONAL_C2_H7 = 0x0080402010080400;

    static int Rank(int square) { return square >> 3; }
    static int File(int square) { return square & 7; }

    
    static inline uint64_t BishopAttacks(int square, uint64_t occupation)
    {
        uint64_t dIndex = (occupation & DiagonalMask[square]) * FILE_A2_A7 >> 57;
        uint64_t aIndex = (occupation & AntiDiagonalMask[square]) * FILE_A2_A7 >> 57;
        return dSubset[square * 64 + (int)dIndex] | aSubset[square * 64 + (int)aIndex];
    }

    static inline uint64_t RookAttacks(int square, uint64_t occupation)
    {
        uint64_t hIndex = occupation >> (square & 0b111000 | 1) & 63;
        uint64_t vIndex = (occupation >> (square & 0b000111) & FILE_A2_A7) * DIAGONAL_C2_H7 >> 58;
        return hSubset[square * 64 + (int)hIndex] | vSubset[square * 64 + (int)vIndex];
    }

    static inline uint64_t Queen(int sq, uint64_t occ) {
        return RookAttacks(sq, occ) | BishopAttacks(sq, occ);
    }


    static bool IsFree(uint64_t mask, int square) {
        return (mask & 1ull << File(square)) == 0;
    }
    static bool IsVerticalFree(uint64_t mask, int square) {
        return (mask & 1ull << square - File(square)) == 0;
    }

    static uint64_t GetBlockers(int square, int index) {
        return (uint64_t)(index << 1) & ~(1ull << File(square));
    }

    //Place the 6 'index' bits FEDCBA like this, leave standing square ZERO 
    //  - - - - - - - - 
    //  A - - - - - - - 
    //  B - - - - - - - 
    //  C - - - - - - - 
    //  D - - - - - - - 
    //  E - - - - - - - 
    //  F - - - - - - - 
    //  - - - - - - - - 
    static uint64_t GetVerticalBlockers(int square, int index)
    {
        uint64_t blockers = 0;
        for (int i = 0, shift = 48; i < 6; i++, shift -= 8)
            if ((index & 1 << i) > 0) //index bit is set?
                if (shift != square - File(square)) //don't block standing square
                    blockers |= 1ull << shift;
        return blockers;
    }
    static uint64_t GetDiagonalSubset(int square, int index)
    {
        uint64_t blockers = GetBlockers(square, index);
        uint64_t result = 0;
        for (int sq = square; IsFree(blockers, sq) && File(sq) < FILE_H && Rank(sq) < RANK_8; sq += 9)
            result |= 1ull << sq + 9;
        for (int sq = square; IsFree(blockers, sq) && File(sq) > FILE_A && Rank(sq) > RANK_1; sq -= 9)
            result |= 1ull << sq - 9;
        return result;
    }

    static uint64_t GetAntiDiagonalSubset(int square, int index)
    {
        uint64_t blockers = GetBlockers(square, index);
        uint64_t result = 0;
        for (int sq = square; IsFree(blockers, sq) && File(sq) > FILE_A && Rank(sq) < RANK_8; sq += 7)
            result |= 1ull << sq + 7;
        for (int sq = square; IsFree(blockers, sq) && File(sq) < FILE_H && Rank(sq) > RANK_1; sq -= 7)
            result |= 1ull << sq - 7;
        return result;
    }

    static uint64_t GetHorizontalSubset(int square, int index)
    {
        uint64_t blockers = GetBlockers(square, index);
        uint64_t result = 0;
        for (int sq = square; IsFree(blockers, sq) && File(sq) < FILE_H; sq++)
            result |= 1ull << sq + 1;
        for (int sq = square; IsFree(blockers, sq) && File(sq) > FILE_A; sq--)
            result |= 1ull << sq - 1;
        return result;
    }

    static uint64_t GetVerticalSubset(int square, int index)
    {
        uint64_t blockers = GetVerticalBlockers(square, index);
        uint64_t result = 0;
        for (int sq = square; IsVerticalFree(blockers, sq) && Rank(sq) < RANK_8; sq += 8)
            result |= 1ull << sq + 8;
        for (int sq = square; IsVerticalFree(blockers, sq) && Rank(sq) > RANK_1; sq -= 8)
            result |= 1ull << sq - 8;
        return result;
    }


    //Table initialization

    static void Init()
    {
        //Init Masks
        for (int square = 0; square < 64; square++)
        {
            int x = File(square);
            int y = Rank(square);

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
        //Init Subsets
        for (int square = 0; square < 64; square++)
            for (int index = 0; index < 64; index++)
            {
                dSubset[square * 64 + index] = GetDiagonalSubset(square, index);
                aSubset[square * 64 + index] = GetAntiDiagonalSubset(square, index);
                hSubset[square * 64 + index] = GetHorizontalSubset(square, index);
                vSubset[square * 64 + index] = GetVerticalSubset(square, index);
            }
    }
}
*/