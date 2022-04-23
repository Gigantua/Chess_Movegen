/*
 This sliding lookup implementation is based on QBBEngine by Fabio Gobbato
*/
#pragma once
#include <stdint.h>
#include <bit>

namespace Chess_Lookup::QBB
{
    static constexpr uint64_t MSB(uint64_t value)
    {
        return 63ull - std::countl_zero(value);
    }

    static constexpr uint64_t LSB(uint64_t value)
    {
        return 63ull - std::countr_zero(value);
    }

    static constexpr uint64_t Size = 0;

    /* return the bitboard with the rook destinations */
    static constexpr uint64_t Rook(uint64_t sq, uint64_t occupation)
    {
        uint64_t piece = 1ULL << sq;
        occupation ^= piece; /* remove the selected piece from the occupation */
        uint64_t piecesup = (0x0101010101010101ULL << sq) & (occupation | 0xFF00000000000000ULL); /* find the pieces up */
        uint64_t piecesdo = (0x8080808080808080ULL >> (63 - sq)) & (occupation | 0x00000000000000FFULL); /* find the pieces down */
        uint64_t piecesri = (0x00000000000000FFULL << sq) & (occupation | 0x8080808080808080ULL); /* find pieces on the right */
        uint64_t piecesle = (0xFF00000000000000ULL >> (63 - sq)) & (occupation | 0x0101010101010101ULL); /* find pieces on the left */
        return (((0x8080808080808080ULL >> LSB(piecesup)) & (0x0101010101010101ULL << MSB(piecesdo))) |
                ((0xFF00000000000000ULL >> LSB(piecesri)) & (0x00000000000000FFULL << MSB(piecesle)))) ^ piece;
        /* From every direction find the first piece and from that piece put a mask in the opposite direction.
           Put togheter all the 4 masks and remove the moving piece */
    }

    /* return the bitboard with the bishops destinations */
    static constexpr uint64_t Bishop(uint64_t sq, uint64_t occupation)
    {  /* it's the same as the rook */
        uint64_t piece = 1ULL << sq;
        occupation ^= piece;
        uint64_t piecesup = (0x8040201008040201ULL << sq) & (occupation | 0xFF80808080808080ULL);
        uint64_t piecesdo = (0x8040201008040201ULL >> (63 - sq)) & (occupation | 0x01010101010101FFULL);
        uint64_t piecesle = (0x8102040810204081ULL << sq) & (occupation | 0xFF01010101010101ULL);
        uint64_t piecesri = (0x8102040810204081ULL >> (63 - sq)) & (occupation | 0x80808080808080FFULL);
        return (((0x8040201008040201ULL >> LSB(piecesup)) & (0x8040201008040201ULL << MSB(piecesdo))) |
                ((0x8102040810204081ULL >> LSB(piecesle)) & (0x8102040810204081ULL << MSB(piecesri)))) ^ piece;
    }

    /* return the bitboard with the rook destinations */
    template<uint64_t sq>
    static constexpr uint64_t Rook(uint64_t occupation)
    {
        constexpr uint64_t piece = 1ULL << sq;
        occupation ^= piece; /* remove the selected piece from the occupation */
        uint64_t piecesup = (0x0101010101010101ULL << sq) & (occupation | 0xFF00000000000000ULL); /* find the pieces up */
        uint64_t piecesdo = (0x8080808080808080ULL >> (63 - sq)) & (occupation | 0x00000000000000FFULL); /* find the pieces down */
        uint64_t piecesri = (0x00000000000000FFULL << sq) & (occupation | 0x8080808080808080ULL); /* find pieces on the right */
        uint64_t piecesle = (0xFF00000000000000ULL >> (63 - sq)) & (occupation | 0x0101010101010101ULL); /* find pieces on the left */
        return (((0x8080808080808080ULL >> LSB(piecesup)) & (0x0101010101010101ULL << MSB(piecesdo))) |
            ((0xFF00000000000000ULL >> LSB(piecesri)) & (0x00000000000000FFULL << MSB(piecesle)))) ^ piece;
        /* From every direction find the first piece and from that piece put a mask in the opposite direction.
           Put togheter all the 4 masks and remove the moving piece */
    }

    /* return the bitboard with the bishops destinations */
    template<uint64_t sq>
    static constexpr uint64_t Bishop(uint64_t occupation)
    {  /* it's the same as the rook */
        constexpr uint64_t piece = 1ULL << sq;
        occupation ^= piece;
        uint64_t piecesup = (0x8040201008040201ULL << sq) & (occupation | 0xFF80808080808080ULL);
        uint64_t piecesdo = (0x8040201008040201ULL >> (63 - sq)) & (occupation | 0x01010101010101FFULL);
        uint64_t piecesle = (0x8102040810204081ULL << sq) & (occupation | 0xFF01010101010101ULL);
        uint64_t piecesri = (0x8102040810204081ULL >> (63 - sq)) & (occupation | 0x80808080808080FFULL);
        return (((0x8040201008040201ULL >> LSB(piecesup)) & (0x8040201008040201ULL << MSB(piecesdo))) |
            ((0x8102040810204081ULL >> LSB(piecesle)) & (0x8102040810204081ULL << MSB(piecesri)))) ^ piece;
    }

    static constexpr uint64_t Queen(uint64_t sq, uint64_t occupation) {
        return Rook(sq, occupation) | Bishop(sq, occupation);
    }

    template<int sq>
    static constexpr uint64_t Queen(uint64_t occupation) {
        return Rook<sq>(occupation) | Bishop<sq>(occupation);
    }
}