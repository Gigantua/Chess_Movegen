/* M42 - A small library for Bitboard attack mask generation, by Syed Fahad
 *
 * Usage: Just include this file as a normal header, and m42.cpp into your
 * source code, and then call M42::init() at your program startup.
 * THIS IS IMPORTANT, you've to call M42::init() in the main() function of
 * your program, to use this library.
 * Read the documentation to know what every function does.
 *
 * Developer contact: sydfhd at gmail dot com
 *
 * License: MIT License (see https://mit-license.org/)
 */

// Datum  : 28.01.2022
// Author : Constexpr SBAMG Version: Daniel Infuehr

#pragma once
#include <stdint.h>
#include <array>

namespace Chess_Lookup::SBAMG 
{
    template<uint64_t bb>
    static constexpr uint64_t mask_shift(int ranks) {
        return ranks > 0 ? bb >> (ranks << 3) : bb << -(ranks << 3);
    }
    template<int dir>
    static constexpr uint64_t dirMask(unsigned int square) {
        int rank = square >> 3;
        int file = square & 7;

        if (dir == 0)
            return 0xFFull << (square & 56); //HORIZONTAL
        else if (dir == 1)
            return 0x0101010101010101ull << (square & 7); //VERTICAL
        else if (dir == 2)
            return mask_shift<0x8040201008040201ull>(file - rank); //Diagonal
        else {
            return mask_shift<0x0102040810204080ull>(7 - file - rank); //Antidiagonal
        }
    }

    static constexpr uint64_t OuterSquares_Ranks[64] = {
      0x0000000000000081ULL, 0x0000000000000081ULL, 0x0000000000000081ULL,
      0x0000000000000081ULL, 0x0000000000000081ULL, 0x0000000000000081ULL,
      0x0000000000000081ULL, 0x0000000000000001ULL, 0x0000000000008000ULL,
      0x0000000000008100ULL, 0x0000000000008100ULL, 0x0000000000008100ULL,
      0x0000000000008100ULL, 0x0000000000008100ULL, 0x0000000000008100ULL,
      0x0000000000000100ULL, 0x0000000000800000ULL, 0x0000000000810000ULL,
      0x0000000000810000ULL, 0x0000000000810000ULL, 0x0000000000810000ULL,
      0x0000000000810000ULL, 0x0000000000810000ULL, 0x0000000000010000ULL,
      0x0000000080000000ULL, 0x0000000081000000ULL, 0x0000000081000000ULL,
      0x0000000081000000ULL, 0x0000000081000000ULL, 0x0000000081000000ULL,
      0x0000000081000000ULL, 0x0000000001000000ULL, 0x0000008000000000ULL,
      0x0000008100000000ULL, 0x0000008100000000ULL, 0x0000008100000000ULL,
      0x0000008100000000ULL, 0x0000008100000000ULL, 0x0000008100000000ULL,
      0x0000000100000000ULL, 0x0000800000000000ULL, 0x0000810000000000ULL,
      0x0000810000000000ULL, 0x0000810000000000ULL, 0x0000810000000000ULL,
      0x0000810000000000ULL, 0x0000810000000000ULL, 0x0000010000000000ULL,
      0x0080000000000000ULL, 0x0081000000000000ULL, 0x0081000000000000ULL,
      0x0081000000000000ULL, 0x0081000000000000ULL, 0x0081000000000000ULL,
      0x0081000000000000ULL, 0x0001000000000000ULL, 0x8000000000000000ULL,
      0x8100000000000000ULL, 0x8100000000000000ULL, 0x8100000000000000ULL,
      0x8100000000000000ULL, 0x8100000000000000ULL, 0x8100000000000000ULL,
      0x0100000000000000ULL
    };

    static constexpr uint64_t OuterSquares_Files[64] = {
      0x0100000000000000ULL, 0x0200000000000000ULL, 0x0400000000000000ULL,
      0x0800000000000000ULL, 0x1000000000000000ULL, 0x2000000000000000ULL,
      0x4000000000000000ULL, 0x8000000000000000ULL, 0x0100000000000001ULL,
      0x0200000000000002ULL, 0x0400000000000004ULL, 0x0800000000000008ULL,
      0x1000000000000010ULL, 0x2000000000000020ULL, 0x4000000000000040ULL,
      0x8000000000000080ULL, 0x0100000000000001ULL, 0x0200000000000002ULL,
      0x0400000000000004ULL, 0x0800000000000008ULL, 0x1000000000000010ULL,
      0x2000000000000020ULL, 0x4000000000000040ULL, 0x8000000000000080ULL,
      0x0100000000000001ULL, 0x0200000000000002ULL, 0x0400000000000004ULL,
      0x0800000000000008ULL, 0x1000000000000010ULL, 0x2000000000000020ULL,
      0x4000000000000040ULL, 0x8000000000000080ULL, 0x0100000000000001ULL,
      0x0200000000000002ULL, 0x0400000000000004ULL, 0x0800000000000008ULL,
      0x1000000000000010ULL, 0x2000000000000020ULL, 0x4000000000000040ULL,
      0x8000000000000080ULL, 0x0100000000000001ULL, 0x0200000000000002ULL,
      0x0400000000000004ULL, 0x0800000000000008ULL, 0x1000000000000010ULL,
      0x2000000000000020ULL, 0x4000000000000040ULL, 0x8000000000000080ULL,
      0x0100000000000001ULL, 0x0200000000000002ULL, 0x0400000000000004ULL,
      0x0800000000000008ULL, 0x1000000000000010ULL, 0x2000000000000020ULL,
      0x4000000000000040ULL, 0x8000000000000080ULL, 0x0000000000000001ULL,
      0x0000000000000002ULL, 0x0000000000000004ULL, 0x0000000000000008ULL,
      0x0000000000000010ULL, 0x0000000000000020ULL, 0x0000000000000040ULL,
      0x0000000000000080ULL
    };

    static constexpr std::array<uint64_t, 64> SquareMask = []()
    {
        std::array<uint64_t, 64> ret_SquareMask = {};
        for (uint64_t sq = 0; sq < 64; sq++)
        {
            ret_SquareMask[sq] = 1ULL << sq;
        }
        return ret_SquareMask;
    }();
    static constexpr std::array<uint64_t, 64> ThisAndNextSq = []()
    {
        std::array<uint64_t, 64> ret_ThisAndNextSq = {};
        for (uint64_t sq = 0; sq < 64; sq++)
        {
            ret_ThisAndNextSq[sq] = 3ULL << sq;
        }
        return ret_ThisAndNextSq;
    }();
    static constexpr std::array<uint64_t, 64> PrevSquares = []()
    {
        std::array<uint64_t, 64> ret_PrevSquares = {};
        for (int sq = 0; sq < 64; sq++)
        {
            ret_PrevSquares[sq] = ((1ULL << sq) - 1) + (sq == 0);
        }
        return ret_PrevSquares;
    }();
    static constexpr std::array<uint64_t, 64> RankMaskEx = []()
    {
        std::array<uint64_t, 64> ret_RankMaskEx = {};
        for (int sq = 0; sq < 64; sq++)
        {
            ret_RankMaskEx[sq] = dirMask<0>(sq) & ~SquareMask[sq];
        }
        return ret_RankMaskEx;
    }();
    static constexpr std::array<uint64_t, 64> FileMaskEx = []()
    {
        std::array<uint64_t, 64> ret_FileMaskEx = {};
        for (int sq = 0; sq < 64; sq++)
        {
            ret_FileMaskEx[sq] = dirMask<1>(sq) & ~SquareMask[sq];
        }
        return ret_FileMaskEx;
    }();
    static constexpr std::array<uint64_t, 64> DiagMaskEx = []()
    {
        std::array<uint64_t, 64> ret_DiagMaskEx = {};
        for (int sq = 0; sq < 64; sq++)
        {
            ret_DiagMaskEx[sq] = dirMask<2>(sq) & ~SquareMask[sq];
        }
        return ret_DiagMaskEx;
    }();
    static constexpr std::array<uint64_t, 64> ADiagMaskEx = []()
    {
        std::array<uint64_t, 64> ret_ADiagMaskEx = {};
        for (int sq = 0; sq < 64; sq++)
        {
            ret_ADiagMaskEx[sq] = dirMask<3>(sq) & ~SquareMask[sq];
        }
        return ret_ADiagMaskEx;
    }();




    constexpr auto Size = 9 * 64 * sizeof(uint64_t);

    static constexpr uint64_t msb(uint64_t value)
    {
        return 63ull - std::countl_zero(value | 1);
    }

    static constexpr uint64_t rank_attacks(int sq, uint64_t occ)
    {
        occ = (occ & RankMaskEx[sq]) | OuterSquares_Ranks[sq];
        return ((occ - ThisAndNextSq[msb(occ & PrevSquares[sq])]) ^ occ)
            & RankMaskEx[sq];
    }
    
    static constexpr uint64_t file_attacks(int sq, uint64_t occ)
    {

        occ = (occ & FileMaskEx[sq]) | OuterSquares_Files[sq];
        return ((occ - ThisAndNextSq[msb(occ & PrevSquares[sq])]) ^ occ)
            & FileMaskEx[sq];
    }
    
    static constexpr uint64_t byteswap_constexpr(uint64_t b) {
        b = ((b >> 8) & 0x00FF00FF00FF00FFULL) | ((b & 0x00FF00FF00FF00FFULL) << 8);
        b = ((b >> 16) & 0x0000FFFF0000FFFFULL) | ((b & 0x0000FFFF0000FFFFULL) << 16);
        return (b >> 32) | (b << 32);
        return b;
    }
    
    static constexpr uint64_t byteswap(uint64_t b) {
        if (std::is_constant_evaluated()) { return byteswap_constexpr(b); }
        #if defined(_MSC_VER)
            return _byteswap_uint64(b);
        #elif defined(__GNUC__)
            return __builtin_bswap64(b);
        #else
            return byteswap_constexpr(b);
        #endif
    }
    
    // NORMAL VERSION
    static constexpr uint64_t diag_attacks(int sq, uint64_t occ)
    {
        occ &= DiagMaskEx[sq];
        return ((occ - SquareMask[sq]) ^ byteswap(byteswap(occ) - SquareMask[sq ^ 56]))
            & DiagMaskEx[sq];
    }
    
    static constexpr uint64_t adiag_attacks(int sq, uint64_t occ)
    {
        occ &= ADiagMaskEx[sq];
        return ((occ - SquareMask[sq]) ^ byteswap(byteswap(occ) - SquareMask[sq ^ 56]))
            & ADiagMaskEx[sq];
    }
    
    static constexpr uint64_t Bishop(int sq, uint64_t occ)
    {
        return diag_attacks(sq, occ) | adiag_attacks(sq, occ);
    }
    
    static constexpr uint64_t Rook(int sq, uint64_t occ)
    {
        return file_attacks(sq, occ) | rank_attacks(sq, occ);
    }

    static constexpr uint64_t Queen(int sq, uint64_t occ)
    {
        return Bishop(sq, occ) | Rook(sq, occ);
    }


    // TEMPLATE VERSION
    template<int sq>
    static constexpr uint64_t rank_attacks(uint64_t occ)
    {
        occ = (occ & RankMaskEx[sq]) | OuterSquares_Ranks[sq];
        return ((occ - ThisAndNextSq[msb(occ & PrevSquares[sq])]) ^ occ)
            & RankMaskEx[sq];
    }

    template<int sq>
    static constexpr uint64_t file_attacks(uint64_t occ)
    {

        occ = (occ & FileMaskEx[sq]) | OuterSquares_Files[sq];
        return ((occ - ThisAndNextSq[msb(occ & PrevSquares[sq])]) ^ occ)
            & FileMaskEx[sq];
    }

    template<int sq>
    static constexpr uint64_t diag_attacks(uint64_t occ)
    {
        occ &= DiagMaskEx[sq];
        return ((occ - SquareMask[sq]) ^ byteswap(byteswap(occ) - SquareMask[sq ^ 56]))
            & DiagMaskEx[sq];
    }

    template<int sq>
    static constexpr uint64_t adiag_attacks(uint64_t occ)
    {
        occ &= ADiagMaskEx[sq];
        return ((occ - SquareMask[sq]) ^ byteswap(byteswap(occ) - SquareMask[sq ^ 56]))
            & ADiagMaskEx[sq];
    }
    template<int sq>
    static constexpr uint64_t Rook(uint64_t occ) {
        return file_attacks<sq>(occ) | rank_attacks<sq>(occ);
    }

    template<int sq>
    static constexpr uint64_t Bishop(uint64_t occ) {
        return diag_attacks<sq>(occ) | adiag_attacks<sq>(occ);
    }

    template<int sq>
    static constexpr uint64_t Queen(uint64_t occ) {
        return Rook<sq>(occ) | Bishop<sq>(occ);
    }
}