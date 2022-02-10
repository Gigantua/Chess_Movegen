#pragma once
// Datum  : 18.01.2022
// Author : Thomas Jahn
// Content: A C++ port of the code used in my engine https://github.com/lithander/Leorik
//          In this implementation the diagonals ant antidiagonals are looked up from a table.
#include <stdint.h>
#include <bit>

namespace Chess_Lookup::Leorik
{
    static constexpr uint64_t Diagonals[64] =
    {
        0x8040201008040201UL, 0x0080402010080402UL, 0x0000804020100804UL, 0x0000008040201008UL,
        0x0000000080402010UL, 0x0000000000804020UL, 0x0000000000008040UL, 0x0000000000000080UL,
        0x4020100804020100UL, 0x8040201008040201UL, 0x0080402010080402UL, 0x0000804020100804UL,
        0x0000008040201008UL, 0x0000000080402010UL, 0x0000000000804020UL, 0x0000000000008040UL,
        0x2010080402010000UL, 0x4020100804020100UL, 0x8040201008040201UL, 0x0080402010080402UL,
        0x0000804020100804UL, 0x0000008040201008UL, 0x0000000080402010UL, 0x0000000000804020UL,
        0x1008040201000000UL, 0x2010080402010000UL, 0x4020100804020100UL, 0x8040201008040201UL,
        0x0080402010080402UL, 0x0000804020100804UL, 0x0000008040201008UL, 0x0000000080402010UL,
        0x0804020100000000UL, 0x1008040201000000UL, 0x2010080402010000UL, 0x4020100804020100UL,
        0x8040201008040201UL, 0x0080402010080402UL, 0x0000804020100804UL, 0x0000008040201008UL,
        0x0402010000000000UL, 0x0804020100000000UL, 0x1008040201000000UL, 0x2010080402010000UL,
        0x4020100804020100UL, 0x8040201008040201UL, 0x0080402010080402UL, 0x0000804020100804UL,
        0x0201000000000000UL, 0x0402010000000000UL, 0x0804020100000000UL, 0x1008040201000000UL,
        0x2010080402010000UL, 0x4020100804020100UL, 0x8040201008040201UL, 0x0080402010080402UL,
        0x0100000000000000UL, 0x0201000000000000UL, 0x0402010000000000UL, 0x0804020100000000UL,
        0x1008040201000000UL, 0x2010080402010000UL, 0x4020100804020100UL, 0x8040201008040201UL,
    };

    static constexpr uint64_t Antiagonals[64] =
    {
        0x0000000000000001UL, 0x0000000000000102UL, 0x0000000000010204UL, 0x0000000001020408UL,
        0x0000000102040810UL, 0x0000010204081020UL, 0x0001020408102040UL, 0x0102040810204080UL,
        0x0000000000000102UL, 0x0000000000010204UL, 0x0000000001020408UL, 0x0000000102040810UL,
        0x0000010204081020UL, 0x0001020408102040UL, 0x0102040810204080UL, 0x0204081020408000UL,
        0x0000000000010204UL, 0x0000000001020408UL, 0x0000000102040810UL, 0x0000010204081020UL,
        0x0001020408102040UL, 0x0102040810204080UL, 0x0204081020408000UL, 0x0408102040800000UL,
        0x0000000001020408UL, 0x0000000102040810UL, 0x0000010204081020UL, 0x0001020408102040UL,
        0x0102040810204080UL, 0x0204081020408000UL, 0x0408102040800000UL, 0x0810204080000000UL,
        0x0000000102040810UL, 0x0000010204081020UL, 0x0001020408102040UL, 0x0102040810204080UL,
        0x0204081020408000UL, 0x0408102040800000UL, 0x0810204080000000UL, 0x1020408000000000UL,
        0x0000010204081020UL, 0x0001020408102040UL, 0x0102040810204080UL, 0x0204081020408000UL,
        0x0408102040800000UL, 0x0810204080000000UL, 0x1020408000000000UL, 0x2040800000000000UL,
        0x0001020408102040UL, 0x0102040810204080UL, 0x0204081020408000UL, 0x0408102040800000UL,
        0x0810204080000000UL, 0x1020408000000000UL, 0x2040800000000000UL, 0x4080000000000000UL,
        0x0102040810204080UL, 0x0204081020408000UL, 0x0408102040800000UL, 0x0810204080000000UL,
        0x1020408000000000UL, 0x2040800000000000UL, 0x4080000000000000UL, 0x8000000000000000UL
    };

    static constexpr auto Size = sizeof(Diagonals) + sizeof(Antiagonals);

    const uint64_t HORIZONTAL = 0x00000000000000FFUL;
    const uint64_t VERTICAL = 0x0101010101010101UL;

    //identify the highest set bit and shift a mask so the bits below are set and the rest are zeroed
    static constexpr uint64_t MaskHigh(uint64_t bb)
    {
        return 0x7FFFFFFFFFFFFFFFUL >> std::countl_zero(bb | 1);
    }

    //identify the lowest set bit and set all bits below while zeroing the rest
    static constexpr uint64_t MaskLow(uint64_t bb)
    {
        return bb ^ (bb - 1);
    }

    static constexpr uint64_t GenLine(uint64_t bbLine, uint64_t bbBlocker, uint64_t bbBelow)
    {
        //MaskLow sets all low bits up to and including the lowest blocker above orgin, the rest are zeroed out.
        //MaskHigh sets all low bits up to and including the highest blocker below origin, the rest are zerored out.
        //The bits of the line that are different between the two masks are the valid targets (including the first blockers on each side)
        return (MaskLow(bbBlocker & ~bbBelow) ^ MaskHigh(bbBlocker & bbBelow)) & bbLine;
    }

    static constexpr uint64_t GenLines(uint64_t bbLineA, uint64_t bbLineB, uint64_t bbBlocker, uint64_t bbBelow) {
        return GenLine(bbLineA, bbBlocker & bbLineA, bbBelow) |
            GenLine(bbLineB, bbBlocker & bbLineB, bbBelow);
    }

    //return the bitboard with the rook targets
    static constexpr uint64_t Rook(int square, uint64_t occupation)
    {
        uint64_t bbPiece = 1ULL << square;
        uint64_t bbBlocker = occupation & ~bbPiece;
        //mask the bits below bbPiece
        uint64_t bbBelow = bbPiece - 1;
        //horizontal line through square
        uint64_t bbHorizontal = HORIZONTAL << (square & 56);
        //vertical line through square
        uint64_t bbVertical = VERTICAL << (square & 7);
        return GenLines(bbHorizontal, bbVertical, bbBlocker, bbBelow) & ~bbPiece;
    }

    //return the bitboard with the bishops targets
    static constexpr uint64_t Bishop(int square, uint64_t occupation)
    {
        uint64_t bbPiece = 1ULL << square;
        uint64_t bbBlocker = occupation & ~bbPiece;
        //mask the bits below bbPiece
        uint64_t bbBelow = bbPiece - 1;
        return GenLines(Diagonals[square], Antiagonals[square], bbBlocker, bbBelow) & ~bbPiece;
    }

    static uint64_t Queen(int sq, uint64_t occupation) {
        return Rook(sq, occupation) | Bishop(sq, occupation);
    }
}   