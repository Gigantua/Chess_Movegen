#pragma once
/*******************************************************************/
/*
The Kogge-Stone bitboard attacks
as part of the board structure.
The original code comes from Steffan Westcott.
With a Kogge-Stone method the move generation should be changed from
'for each slider do all directions' to 'for each direction do all sliders'.
I have not done this.

(c) 2006 Harald Lüßen
*/
/*******************************************************************/

/*******************************************************************/

/*
    directions and shifts
    +-----+-----+-----+
    |<<= 9|<<= 8|<<= 7|
    +-----+-----+-----+
    |<<= 1|     |>>= 1|
    +-----+-----+-----+
    |>>= 7|>>= 8|>>= 9|
    +-----+-----+-----+

    We use this mapping of the normal board squares to bitboard bits
    +-------------------------+
    | 63 62 61 60 59 58 57 56 | 8
    | 55 54 53 52 51 50 49 48 | 7
    | 47 46 45 44 43 42 41 40 | 6
    | 39 38 37 36 35 35 33 32 | 5
    | 31 30 29 28 27 26 25 24 | 4
    | 23 22 21 20 19 18 17 16 | 3
    | 15 14 13 12 11 10  9  8 | 2
    |  7  6  5  4  3  2  1  0 | 1
    +-------------------------+
       a  b  c  d  e  f  g  h
*/

namespace Chess_Lookup::KoggeStone {
    /*******************************************************************/
#include <stdint.h>
    typedef uint64_t C64;
    typedef uint64_t BitBoard;

    ///////////////////////////////////////////////////////////////////////////

    static constexpr BitBoard ShiftUp(BitBoard b) { return  b << 8; }
    static constexpr BitBoard ShiftDown(BitBoard b) { return  b >> 8; }
    static constexpr BitBoard ShiftLeft(BitBoard b) { return (b << 1) & C64(0xfefefefefefefefe); }
    static constexpr BitBoard ShiftRight(BitBoard b) { return (b >> 1) & C64(0x7f7f7f7f7f7f7f7f); }
    static constexpr BitBoard ShiftUpLeft(BitBoard b) { return (b << 9) & C64(0xfefefefefefefefe); }
    static constexpr BitBoard ShiftUpRight(BitBoard b) { return (b << 7) & C64(0x7f7f7f7f7f7f7f7f); }
    static constexpr BitBoard ShiftDownLeft(BitBoard b) { return (b >> 7) & C64(0xfefefefefefefefe); }
    static constexpr BitBoard ShiftDownRight(BitBoard b) { return (b >> 9) & C64(0x7f7f7f7f7f7f7f7f); }

    ///////////////////////////////////////////////////////////////////////////

    /**
    The routine FillUpOccluded() smears the set bits of bitboard g upwards, but only
    along set bits of p; a reset bit in p is enough to halt a smear. RookAttacksUp()
    uses this routine to find all squares rooks may occupy by either staying still
    or moving up along empty squares (no captures allowed). Shifting this last
    result up by 1 square gives the squares all rooks can attack by moving upwards
    (which _does_ include captures).
    */
    static constexpr BitBoard FillUpOccluded(BitBoard g, BitBoard p)
    {
        g |= p & (g << 8);
        p &= (p << 8);
        g |= p & (g << 16);
        p &= (p << 16);
        return g |= p & (g << 32);
    }

    static constexpr BitBoard FillDownOccluded(BitBoard g, BitBoard p)
    {
        g |= p & (g >> 8);
        p &= (p >> 8);
        g |= p & (g >> 16);
        p &= (p >> 16);
        return g |= p & (g >> 32);
    }

    static constexpr BitBoard FillLeftOccluded(BitBoard g, BitBoard p)
    {
        p &= C64(0xfefefefefefefefe);
        g |= p & (g << 1);
        p &= (p << 1);
        g |= p & (g << 2);
        p &= (p << 2);
        return g |= p & (g << 4);
    }

    static constexpr BitBoard FillRightOccluded(BitBoard g, BitBoard p)
    {
        p &= C64(0x7f7f7f7f7f7f7f7f);
        g |= p & (g >> 1);
        p &= (p >> 1);
        g |= p & (g >> 2);
        p &= (p >> 2);
        return g |= p & (g >> 4);
    }

    static constexpr BitBoard FillUpLeftOccluded(BitBoard g, BitBoard p)
    {
        p &= C64(0xfefefefefefefefe);
        g |= p & (g << 9);
        p &= (p << 9);
        g |= p & (g << 18);
        p &= (p << 18);
        return g |= p & (g << 36);
    }

    static constexpr BitBoard FillUpRightOccluded(BitBoard g, BitBoard p)
    {
        p &= C64(0x7f7f7f7f7f7f7f7f);
        g |= p & (g << 7);
        p &= (p << 7);
        g |= p & (g << 14);
        p &= (p << 14);
        return g |= p & (g << 28);
    }

    static constexpr BitBoard FillDownLeftOccluded(BitBoard g, BitBoard p)
    {
        p &= C64(0xfefefefefefefefe);
        g |= p & (g >> 7);
        p &= (p >> 7);
        g |= p & (g >> 14);
        p &= (p >> 14);
        return g |= p & (g >> 28);
    }

    static constexpr BitBoard FillDownRightOccluded(BitBoard g, BitBoard p)
    {
        p &= C64(0x7f7f7f7f7f7f7f7f);
        g |= p & (g >> 9);
        p &= (p >> 9);
        g |= p & (g >> 18);
        p &= (p >> 18);
        return g |= p & (g >> 36);
    }


    /*******************************************************************/

    /**
    Get a bitboard with all positions set to 1 which can be attacked
    from a bishop, rook or queen on the square moving in the direction.
    */
    static constexpr uint64_t direction_attacks(int square, int dir, uint64_t occ)
    {
        uint64_t seed = 1ull << square;
        uint64_t free = ~occ;

        // 4 3 2
        // 5 0 1
        // 6 7 8
        switch (dir)
        {
        case 1:
            return ShiftRight(FillRightOccluded(seed, free));
        case 5:
            return ShiftLeft(FillLeftOccluded(seed, free));
        case 7:
            return ShiftDown(FillDownOccluded(seed, free));
        case 3:
            return ShiftUp(FillUpOccluded(seed, free));
        case 8:
            return ShiftDownRight(FillDownRightOccluded(seed, free));
        case 4:
            return ShiftUpLeft(FillUpLeftOccluded(seed, free));
        case 2:
            return ShiftUpRight(FillUpRightOccluded(seed, free));
        case 6:
            return ShiftDownLeft(FillDownLeftOccluded(seed, free));
        default:
            return 0;
        }
    }

    constexpr uint64_t Size = 0;

    /*******************************************************************/

    /**
    Get a bitboard with all positions set to 1 which can be attacked
    from a rook or queen on the square.
    */
    static constexpr uint64_t attacks_rook(int square, uint64_t occ)
    {
        uint64_t seed = 1ull << square;
        uint64_t free = ~occ;
        return ShiftRight(FillRightOccluded(seed, free))
            | ShiftLeft(FillLeftOccluded(seed, free))
            | ShiftUp(FillUpOccluded(seed, free))
            | ShiftDown(FillDownOccluded(seed, free));
    }


    /*******************************************************************/

    /**
    Get a bitboard with all positions set to 1 which can be attacked
    from a bishop or queen on the square.
    */
    static constexpr BitBoard attacks_bishop(int square, uint64_t occ)
    {
        uint64_t seed = 1ull << square;
        uint64_t free = ~occ;
        return ShiftUpRight(FillUpRightOccluded(seed, free))
            | ShiftUpLeft(FillUpLeftOccluded(seed, free))
            | ShiftDownLeft(FillDownLeftOccluded(seed, free))
            | ShiftDownRight(FillDownRightOccluded(seed, free));
    }

    static constexpr uint64_t Queen(int square, uint64_t occ) {
        return attacks_bishop(square, occ) | attacks_rook(square, occ);
    }
}