#pragma once
// Datum  : 16.01.2022
// Author : Daniel Infuehr
// Content: Translation of a bitboard attack getter by Michael Hoffmann for demo purposes.
//          The code can be further "minimized!" because a real application
//          alread includes bitoard masks and some of the functionality.
//          These components are commented accordingly.

#include <stdint.h>
#include <array>

namespace Chess_Lookup::ObstructionDiffInline {
#define FileOf(S) ((S) & 7)
#define GetLower(S) ((1ull << S) - 1)
#define GetUpper(S) (0xFFFFFFFFFFFFFFFF << (S))

    template<uint64_t bb>
    static constexpr uint64_t mask_shift(int ranks) {
        return ranks > 0 ? bb >> (ranks << 3) : bb << -(ranks << 3);
    }
    template<int dir>
    static constexpr uint64_t mask(int square) {
        int rank = square >> 3;
        int file = square & 7;

        if constexpr (dir == 0)
            return 0xFFull << (square & 56); //HORIZONTAL
        else if constexpr (dir == 1)
            return 0x0101010101010101ull << (square & 7); //VERTICAL
        else if constexpr (dir == 2)
            return mask_shift<0x8040201008040201ull>(file - rank); //Diagonal
        else {
            return mask_shift<0x0102040810204080ull>(7 - file - rank); //Antidiagonal
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
            const uint64_t loup = mask<dir>(sq);
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


    template<int dir, int sq>
    static constexpr uint64_t line_attack(uint64_t occ)
    {
        constexpr lineEx line(sq, mask<dir>(sq));

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


    template<int sq>
    static constexpr uint64_t Bishop(uint64_t occ)
    {
        return line_attack<2, sq>(occ) | line_attack<3, sq>(occ);
    }

    template<int sq>
    static constexpr uint64_t Rook(uint64_t occ)
    {
        return line_attack<0, sq>(occ) | line_attack<1, sq>(occ);
    }

    template<int sq>
    static constexpr uint64_t Queen(uint64_t occ)
    {
        return Bishop<sq>(occ) | Rook<sq>(occ);
    }


#undef FileOf
#undef GetLower
#undef GetUpper
}