#pragma once
// Datum  : 16.01.2022
// Author : Daniel Infuehr
// Content: Translation of a bitboard attack getter by Michael Hoffmann for demo purposes.
//          The code can be further "minimized!" because a real application
//          alread includes bitoard masks and some of the functionality.
//          These components are commented accordingly.

#include <stdint.h>
#include <array>
#include <bit>

namespace Chess_Lookup::ObstructionDiff {
    #define FileOf(S) ((S) & 7)
    #define GetLower(S) ((1ull << S) - 1)
    #define GetUpper(S) (0xFFFFFFFFFFFFFFFF << (S))
    consteval uint64_t init_rank(int s)
    {
        return 0xFFull << (s & 56);
    }

    consteval uint64_t init_file(int s)
    {
        return 0x0101010101010101ull << FileOf(s);
    }

    consteval uint64_t init_diag(int sq)
    {
        int d = 8 * FileOf(sq) - (sq & 56);
        int n = -d & (d >> 31);
        int s = d & (-d >> 31);
        return (0x8040201008040201ull >> s) << n;
    }

    consteval uint64_t init_anti(int sq)
    {
        int d = 56 - 8 * FileOf(sq) - (sq & 56);
        int n = -d & (d >> 31);
        int s = d & (-d >> 31);
        return (0x0102040810204080ull >> s) << n;
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
    };

    consteval std::array<lineEx, 256> Init()
    {
        std::array<lineEx, 256> lines{};
        for (int i = 0; i < 64; i++) {
            lines[i * 4 + 0] = lineEx(i, init_rank(i));
            lines[i * 4 + 1] = lineEx(i, init_file(i));
            lines[i * 4 + 2] = lineEx(i, init_diag(i));
            lines[i * 4 + 3] = lineEx(i, init_anti(i));
        }
        return lines;
    }

    static constexpr std::array<lineEx, 256> lines = Init();
    constexpr auto Size = sizeof(lines);

    #pragma warning(push)
    #pragma warning(disable: 4146)
    static constexpr uint64_t line_attack(int sq, uint64_t occ, int dir)
    {
        const lineEx& line = lines[4 * sq + dir];
        uint64_t lower = (line.lower & occ) | 1;
        uint64_t upper = line.upper & occ;
        uint64_t msb = (1ull << 63ull) >> std::countl_zero(lower);  //Extract Highest Set Isolated Bit
        uint64_t lsb = upper & -upper;                              //Extract Lowest Set Isolated Bit
        uint64_t oDif = lsb * 2 - msb;
        return line.uni & oDif;
    }
    #pragma warning(pop)

    static constexpr uint64_t Bishop(int sq, uint64_t occ)
    {
        return line_attack(sq, occ, 2) | line_attack(sq, occ, 3);
    }

    static constexpr uint64_t Rook(int sq, uint64_t occ)
    {
        return line_attack(sq, occ, 0) | line_attack(sq, occ, 1);
    }

    static constexpr uint64_t Queen(int sq, uint64_t occ)
    {
        return Bishop(sq, occ) | Rook(sq, occ);
    }

   //NO HEADACHE - 30MOPs (4x slower than reference)
   /*
    static const uint64_t BB_AF = 0x0101010101010101;
    static const uint64_t BB_BF = 0x0202020202020202;
    static const uint64_t BB_CF = 0x0404040404040404;
    static const uint64_t BB_DF = 0x0808080808080808;
    static const uint64_t BB_EF = 0x1010101010101010;
    static const uint64_t BB_FF = 0x2020202020202020;
    static const uint64_t BB_GF = 0x4040404040404040;
    static const uint64_t BB_HF = 0x8080808080808080;

    static const uint64_t BB_R1 = 0x00000000000000FF;
    static const uint64_t BB_R2 = 0x000000000000FF00;
    static const uint64_t BB_R3 = 0x0000000000FF0000;
    static const uint64_t BB_R4 = 0x00000000FF000000;
    static const uint64_t BB_R5 = 0x000000FF00000000;
    static const uint64_t BB_R6 = 0x0000FF0000000000;
    static const uint64_t BB_R7 = 0x00FF000000000000;
    static const uint64_t BB_R8 = 0xFF00000000000000;

   static constexpr uint64_t Bishop(int s, uint64_t o)
   {
       uint64_t tmp, att = 0;
       o &= ~(1ull << s);
       tmp = 1ull << s; while ((tmp & (o | BB_HF | BB_R8)) == 0) { att |= tmp <<= 9; }
       tmp = 1ull << s; while ((tmp & (o | BB_AF | BB_R8)) == 0) { att |= tmp <<= 7; }
       tmp = 1ull << s; while ((tmp & (o | BB_AF | BB_R1)) == 0) { att |= tmp >>= 9; }
       tmp = 1ull << s; while ((tmp & (o | BB_HF | BB_R1)) == 0) { att |= tmp >>= 7; }
       return att;
   }
   
   static constexpr uint64_t Rook(int s, uint64_t o)
   {
       uint64_t tmp, att = 0;
       o &= ~(1ull << s);
       tmp = 1ull << s; while ((tmp & (o | BB_HF)) == 0) { att |= tmp <<= 1; }
       tmp = 1ull << s; while ((tmp & (o | BB_AF)) == 0) { att |= tmp >>= 1; }
       tmp = 1ull << s; while ((tmp & (o | BB_R8)) == 0) { att |= tmp <<= 8; }
       tmp = 1ull << s; while ((tmp & (o | BB_R1)) == 0) { att |= tmp >>= 8; }
       return att;
   }
   static constexpr uint64_t Queen(int s, uint64_t o)
   {
       return Bishop(s, o) | Rook(s, o);
   }
   */

    #undef FileOf
    #undef GetLower
    #undef GetUpper
}