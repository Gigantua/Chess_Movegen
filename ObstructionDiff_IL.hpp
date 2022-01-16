#pragma once
// Datum  : 09.01.2022
// Author : Michael Hoffmann
// Content: Implementation of a bitboard attack getter for demo purposes.
//          The code can be further "minimized!" because a real application
//          alread includes bitoard masks and some of the functionality.
//          These components are commented accordingly.

#include <stdint.h>
#include <array>

namespace Chess_Lookup::ObstructionDiffInline {
#define FileOf(S) ((S) & 7)
#define GetLower(S) ((1ull << S) - 1)
#define GetUpper(S) (0xFFFFFFFFFFFFFFFF << (S))
    static constexpr uint64_t init_rank(int s)
    {
        return 0xFFull << (s & 56);
    }

    static constexpr uint64_t init_file(int s)
    {
        return 0x0101010101010101ull << FileOf(s);
    }

    static constexpr uint64_t init_diag(int sq)
    {
        int d = 8 * FileOf(sq) - (sq & 56);
        int n = -d & (d >> 31);
        int s = d & (-d >> 31);
        return (0x8040201008040201ull >> s) << n;
    }

    static constexpr uint64_t init_anti(int sq)
    {
        int d = 56 - 8 * FileOf(sq) - (sq & 56);
        int n = -d & (d >> 31);
        int s = d & (-d >> 31);
        return (0x0102040810204080ull >> s) << n;
    }

    template<int dir>
    static constexpr uint64_t init_any(int sq) {
        if constexpr (dir == 0) {
            return init_rank(sq);
        }
        else if constexpr (dir == 1) {
            return init_file(sq);
        }
        else if constexpr (dir == 2) {
            return init_diag(sq);
        }
        else {
            return init_anti(sq);
        }
    }

    struct lineEx {
        uint64_t lower;
        uint64_t upper;
        uint64_t uni;

        constexpr uint64_t init_low(int sq, uint64_t line) {
            uint64_t lineEx = line ^ (1ull << sq);
            return GetLower(sq) & lineEx;
        }

        constexpr uint64_t init_up(int sq, uint64_t line) {
            uint64_t lineEx = line ^ (1ull << sq);
            return GetUpper(sq) & lineEx;
        }

        constexpr lineEx() : lower(0), upper(0), uni(0) {

        }

        constexpr lineEx(int sq, uint64_t line) : lower(init_low(sq, line)), upper(init_up(sq, line)), uni(init_low(sq, line) | init_up(sq, line))
        {

        }

        template<int dir>
        void fill(lineEx& line, int sq) {
            const uint64_t loup = init_any<dir>(sq);
            line.lower = init_low(sq, loup);
            line.upper = init_up(sq, loup);
            line.uni = line.lower | line.upper;
        }
    };

    constexpr auto Size = 0;

#pragma warning(push)
#pragma warning(disable: 4146)
    template<int dir>
    static constexpr uint64_t line_attack(int sq, uint64_t occ)
    {
        lineEx line;
        line.fill<dir>(line, sq);

        uint64_t lower = line.lower & occ;
        uint64_t upper = line.upper & occ;
        uint64_t msb = (1ull << 63ull) >> std::countl_zero(lower | 1);  //Extract Highest Set Isolated Bit
        uint64_t lsb = upper & -upper;                                  //Extract Lowest Set Isolated Bit
        uint64_t oDif = lsb * 2 - msb;
        return line.uni & oDif;
    }
#pragma warning(pop)

    static constexpr uint64_t Bishop(int sq, uint64_t occ)
    {
        return line_attack<2>(sq, occ) | line_attack<3>(sq, occ);
    }

    static constexpr uint64_t Rook(int sq, uint64_t occ)
    {
        return line_attack<0>(sq, occ) | line_attack<1>(sq, occ);
    }

    static constexpr uint64_t Queen(int sq, uint64_t occ)
    {
        return Bishop(sq, occ) | Rook(sq, occ);
    }
#undef FileOf
#undef GetLower
#undef GetUpper
}