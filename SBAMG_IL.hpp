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

 // Datum  : 29.01.2022
 // Author : Constexpr Inlined SBAMG Version: Daniel Infuehr

#pragma once
#include <stdint.h>
#include <array>

namespace Chess_Lookup::SBAMGInline
{
    template<uint64_t bb>
    static constexpr uint64_t mask_shift(int ranks) {
        return ranks > 0 ? bb >> (ranks << 3) : bb << -(ranks << 3);
    }
    template<int dir>
    static constexpr uint64_t dirMask(int square) {
        int rank = square >> 3;
        int file = square & 7;

        if constexpr (dir == 0)
            return (0xFFull << (square & 56)) ^ (1ull << square); //HORIZONTAL
        else if constexpr (dir == 1)
            return (0x0101010101010101ull << (square & 7)) ^ (1ull << square); //VERTICAL
        else if constexpr (dir == 2)
            return (mask_shift<0x8040201008040201ull>(file - rank)) ^ (1ull << square); //Diagonal
        else {
            return (mask_shift<0x0102040810204080ull>(7 - file - rank)) ^ (1ull << square); //Antidiagonal
        }
    }

    static constexpr uint64_t outersquare(int square) {
        return (0x81ull << (square & 56)) &~ (1ull << square) | (square == 0); //Probably can be optimised - 2ull << (square >> 1) === (1ull << (square)) - (square == 0)
    }

    static constexpr uint64_t outersquare_file(int square) {
        return (0x0100000000000001ULL << (square & 7)) &~ (1ull << square); //VERTICAL
    }

    static std::string _map(uint64_t value)
    {
        static std::string str(64 + 8, 'o');
        for (uint64_t i = 0, c = 0; i < 64; i++)
        {
            uint64_t bitmask = (1ull) << i;

            if ((bitmask & value) != 0) str[c++] = 'X';
            else str[c++] = '.';

            if ((i + 1) % 8 == 0) str[c++] = '\n';
        }
        return str;
    }

    static constexpr uint64_t ThisAndNextSq(int sq)
    {
        return 3ULL << sq;
    };
    static constexpr uint64_t PrevSquares(int sq)
    {
        return ((1ULL << sq) - 1) | (sq == 0);
    };

    constexpr auto Size = 0;

    static constexpr int msb(uint64_t value)
    {
        return 63 - std::countl_zero(value | 1);
    }

    static constexpr uint64_t rank_attacks(int sq, uint64_t occ)
    {
        const auto rankmask = dirMask<0>(sq);
        occ = (occ & rankmask) | outersquare(sq);
        return ((occ - ThisAndNextSq(msb(occ & PrevSquares(sq)))) ^ occ)
            & rankmask;
    }

    static constexpr uint64_t file_attacks(int sq, uint64_t occ)
    {
        const auto filemask = dirMask<1>(sq);
        occ = (occ & filemask) | outersquare_file(sq);
        return ((occ - ThisAndNextSq(msb(occ & PrevSquares(sq)))) ^ occ)
            & filemask;
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
        const auto diagmask = dirMask<2>(sq);
        occ &= diagmask;
        return ((occ - (1ull << sq)) ^ byteswap(byteswap(occ) - (1ull << (sq^56))))
            & diagmask;
    }

    static constexpr uint64_t adiag_attacks(int sq, uint64_t occ)
    {
        const auto adiagmask = dirMask<3>(sq);
        occ &= adiagmask;
        return ((occ - (1ull << sq)) ^ byteswap(byteswap(occ) - (1ull << (sq^56))))
            & adiagmask;
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
        constexpr auto rankmask = dirMask<0>(sq);
        occ = (occ & rankmask) | outersquare(sq);
        return ((occ - ThisAndNextSq(msb(occ & PrevSquares(sq)))) ^ occ)
            & rankmask;
    }

    template<int sq>
    static constexpr uint64_t file_attacks(uint64_t occ)
    {
        constexpr auto filemask = dirMask<1>(sq);
        occ = (occ & filemask) | outersquare_file(sq);
        return ((occ - ThisAndNextSq(msb(occ & PrevSquares(sq)))) ^ occ)
            & filemask;
    }

    template<int sq>
    static constexpr uint64_t diag_attacks(uint64_t occ)
    {
        constexpr auto diagmask = dirMask<2>(sq);
        occ &= diagmask;
        return ((occ - (1ull << sq)) ^ byteswap(byteswap(occ) - (1ull << (sq^56))))
            & diagmask;
    }

    template<int sq>
    static constexpr uint64_t adiag_attacks(uint64_t occ)
    {
        constexpr auto adiagmask = dirMask<3>(sq);
        occ &= adiagmask;
        return ((occ - (1ull << sq)) ^ byteswap(byteswap(occ) - (1ull << (sq^56))))
            & adiagmask;
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