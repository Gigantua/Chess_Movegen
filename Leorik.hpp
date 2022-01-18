#pragma once
// Datum  : 18.01.2022
// Author : Thomas Jahn
// Content: A C++ port of the code used in my engine https://github.com/lithander/Leorik
//          In this implementation the diagonals ant antidiagonals are computed on the fly.
#include <stdint.h>
#include <type_traits>

namespace Chess_Lookup::Leorik
{
    static constexpr uint64_t Size = 0;

    const uint64_t HORIZONTAL = 0x00000000000000FFUL;
    const uint64_t VERTICAL = 0x0101010101010101UL;
    const uint64_t DIAGONAL = 0x8040201008040201UL;
    const uint64_t ANTIDIAGONAL = 0x0102040810204080UL;

    //identify the highest set bit and shift a mask so the bits below are set and the rest are zeroed
    static constexpr uint64_t MaskHigh(uint64_t bb) {
        return 0x7FFFFFFFFFFFFFFFUL >> std::countl_zero(bb | 1);
    }

    //identify the lowest set bit and set all bits below while zeroing the rest
    static constexpr uint64_t MaskLow(uint64_t bb)
    {
        return bb ^ (bb - 1);
    }

    //sign of 'ranks' decides between left shift or right shift. Then convert signed ranks to a positiver number of bits to shift by. Each rank has 8 bits e.g. 1 << 3 == 8
    static constexpr uint64_t VerticalShift(uint64_t bb, int ranks)
    {
        return ranks > 0 ? bb >> (ranks << 3) : bb << -(ranks << 3);
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
        //compute rank and file of square
        int rank = square >> 3;
        int file = square & 7;
        //diagonal line through square
        uint64_t bbDiagonal = VerticalShift(DIAGONAL, file - rank);
        //antidiagonal line through square
        uint64_t bbAntiDiagonal = VerticalShift(ANTIDIAGONAL, 7 - file - rank);
        return GenLines(bbDiagonal, bbAntiDiagonal, bbBlocker, bbBelow) & ~bbPiece;
    }

    static uint64_t Queen(int sq, uint64_t occupation) {
        return Rook(sq, occupation) | Bishop(sq, occupation);
    }
}