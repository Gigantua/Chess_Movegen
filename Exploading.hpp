/*******************************************************************/
/*
The exploding bitboard attacks
as part of the board structure.

(c) 2006 Harald Lüßen
*/
/*******************************************************************/

#include <stdint.h>
#include <array>

namespace Chess_Lookup::ExplodingBoard
{
    typedef uint64_t Bitboard;
    typedef std::array<std::array<int, 128>, 8> rankmask;

    static constexpr uint64_t initB[64] = { 0x200ull, 0x500ull, 0xa00ull, 0x1400ull, 0x2800ull, 0x5000ull, 0xa000ull, 0x4000ull, 0x20002ull, 0x50005ull, 0xa000aull, 0x140014ull, 0x280028ull, 0x500050ull, 0xa000a0ull, 0x400040ull, 0x2000200ull, 0x5000500ull, 0xa000a00ull, 0x14001400ull, 0x28002800ull, 0x50005000ull, 0xa000a000ull, 0x40004000ull, 0x200020000ull, 0x500050000ull, 0xa000a0000ull, 0x1400140000ull, 0x2800280000ull, 0x5000500000ull, 0xa000a00000ull, 0x4000400000ull, 0x20002000000ull, 0x50005000000ull, 0xa000a000000ull, 0x140014000000ull, 0x280028000000ull, 0x500050000000ull, 0xa000a0000000ull, 0x400040000000ull, 0x2000200000000ull, 0x5000500000000ull, 0xa000a00000000ull, 0x14001400000000ull, 0x28002800000000ull, 0x50005000000000ull, 0xa000a000000000ull, 0x40004000000000ull, 0x200020000000000ull, 0x500050000000000ull, 0xa000a0000000000ull, 0x1400140000000000ull, 0x2800280000000000ull, 0x5000500000000000ull, 0xa000a00000000000ull, 0x4000400000000000ull, 0x2000000000000ull, 0x5000000000000ull, 0xa000000000000ull, 0x14000000000000ull, 0x28000000000000ull, 0x50000000000000ull, 0xa0000000000000ull, 0x40000000000000ull };
    static constexpr uint64_t maskB[64] = { 0x8040201008040200ull, 0x80402010080500ull, 0x804020110a00ull, 0x8041221400ull, 0x182442800ull, 0x10204885000ull, 0x102040810a000ull, 0x102040810204000ull, 0x4020100804020002ull, 0x8040201008050005ull, 0x804020110a000aull, 0x804122140014ull, 0x18244280028ull, 0x1020488500050ull, 0x102040810a000a0ull, 0x204081020400040ull, 0x2010080402000204ull, 0x4020100805000508ull, 0x804020110a000a11ull, 0x80412214001422ull, 0x1824428002844ull, 0x102048850005088ull, 0x2040810a000a010ull, 0x408102040004020ull, 0x1008040200020408ull, 0x2010080500050810ull, 0x4020110a000a1120ull, 0x8041221400142241ull, 0x182442800284482ull, 0x204885000508804ull, 0x40810a000a01008ull, 0x810204000402010ull, 0x804020002040810ull, 0x1008050005081020ull, 0x20110a000a112040ull, 0x4122140014224180ull, 0x8244280028448201ull, 0x488500050880402ull, 0x810a000a0100804ull, 0x1020400040201008ull, 0x402000204081020ull, 0x805000508102040ull, 0x110a000a11204080ull, 0x2214001422418000ull, 0x4428002844820100ull, 0x8850005088040201ull, 0x10a000a010080402ull, 0x2040004020100804ull, 0x200020408102040ull, 0x500050810204080ull, 0xa000a1120408000ull, 0x1400142241800000ull, 0x2800284482010000ull, 0x5000508804020100ull, 0xa000a01008040201ull, 0x4000402010080402ull, 0x2040810204080ull, 0x5081020408000ull, 0xa112040800000ull, 0x14224180000000ull, 0x28448201000000ull, 0x50880402010000ull, 0xa0100804020100ull, 0x40201008040201ull };
    static constexpr uint64_t initR[64] = { 0x102ull, 0x205ull, 0x40aull, 0x814ull, 0x1028ull, 0x2050ull, 0x40a0ull, 0x8040ull, 0x10201ull, 0x20502ull, 0x40a04ull, 0x81408ull, 0x102810ull, 0x205020ull, 0x40a040ull, 0x804080ull, 0x1020100ull, 0x2050200ull, 0x40a0400ull, 0x8140800ull, 0x10281000ull, 0x20502000ull, 0x40a04000ull, 0x80408000ull, 0x102010000ull, 0x205020000ull, 0x40a040000ull, 0x814080000ull, 0x1028100000ull, 0x2050200000ull, 0x40a0400000ull, 0x8040800000ull, 0x10201000000ull, 0x20502000000ull, 0x40a04000000ull, 0x81408000000ull, 0x102810000000ull, 0x205020000000ull, 0x40a040000000ull, 0x804080000000ull, 0x1020100000000ull, 0x2050200000000ull, 0x40a0400000000ull, 0x8140800000000ull, 0x10281000000000ull, 0x20502000000000ull, 0x40a04000000000ull, 0x80408000000000ull, 0x102010000000000ull, 0x205020000000000ull, 0x40a040000000000ull, 0x814080000000000ull, 0x1028100000000000ull, 0x2050200000000000ull, 0x40a0400000000000ull, 0x8040800000000000ull, 0x201000000000000ull, 0x502000000000000ull, 0xa04000000000000ull, 0x1408000000000000ull, 0x2810000000000000ull, 0x5020000000000000ull, 0xa040000000000000ull, 0x4080000000000000ull };
    static constexpr uint64_t maskR[64] = { 0x1010101010101feull, 0x2020202020202fdull, 0x4040404040404fbull, 0x8080808080808f7ull, 0x10101010101010efull, 0x20202020202020dfull, 0x40404040404040bfull, 0x808080808080807full, 0x10101010101fe01ull, 0x20202020202fd02ull, 0x40404040404fb04ull, 0x80808080808f708ull, 0x101010101010ef10ull, 0x202020202020df20ull, 0x404040404040bf40ull, 0x8080808080807f80ull, 0x101010101fe0101ull, 0x202020202fd0202ull, 0x404040404fb0404ull, 0x808080808f70808ull, 0x1010101010ef1010ull, 0x2020202020df2020ull, 0x4040404040bf4040ull, 0x80808080807f8080ull, 0x1010101fe010101ull, 0x2020202fd020202ull, 0x4040404fb040404ull, 0x8080808f7080808ull, 0x10101010ef101010ull, 0x20202020df202020ull, 0x40404040bf404040ull, 0x808080807f808080ull, 0x10101fe01010101ull, 0x20202fd02020202ull, 0x40404fb04040404ull, 0x80808f708080808ull, 0x101010ef10101010ull, 0x202020df20202020ull, 0x404040bf40404040ull, 0x8080807f80808080ull, 0x101fe0101010101ull, 0x202fd0202020202ull, 0x404fb0404040404ull, 0x808f70808080808ull, 0x1010ef1010101010ull, 0x2020df2020202020ull, 0x4040bf4040404040ull, 0x80807f8080808080ull, 0x1fe010101010101ull, 0x2fd020202020202ull, 0x4fb040404040404ull, 0x8f7080808080808ull, 0x10ef101010101010ull, 0x20df202020202020ull, 0x40bf404040404040ull, 0x807f808080808080ull, 0xfe01010101010101ull, 0xfd02020202020202ull, 0xfb04040404040404ull, 0xf708080808080808ull, 0xef10101010101010ull, 0xdf20202020202020ull, 0xbf40404040404040ull, 0x7f80808080808080ull };



    /**
    Number of expanding steps (explosions) for a bishop
    */
    static constexpr int repsB[64] =
    {
        6, 5, 4, 3, 3, 4, 5, 6,
        5, 5, 4, 3, 3, 4, 5, 5,
        4, 4, 4, 3, 3, 4, 4, 4,
        3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3,
        4, 4, 4, 3, 3, 4, 4, 4,
        5, 5, 4, 3, 3, 4, 5, 5,
        6, 5, 4, 3, 3, 4, 5, 6,
    };

    /*
    = init               >>= 9               *= 0x5005          &= mask            at |= bb
     . . . . . . . .     . . . . . . . .     . . . . . . . .    . . . . . . . .    . . . . . . . .
     . . . . . . . .     . . . . . . . .     . . . . . . . .    . . . . . . . .    . . . . . . . .
     . . . . . . . .     . . . . . . . .     . 1 1 . . 1 . .    . 1 . . . 1 . .    . 1 . . . 1 . .
     . . 1 . 1 . . .     . . . . . . . .     . . . . . . . .    . . . . . . . .    . . 1 . 1 . . .
     . . . s . . . .     . . . 1 . 1 . .     1 1 . . 1 . . .    . . . s . . . .    . . . s . . . .
     . . 1 . 1 . . .     . . . . . . . .     . . . . . . . .    . . . . . . . .    . . 1 . 1 . . .
     . . . . . . . .     . . . 1 . 1 . .     . 1 1 . . 1 . .    . 1 . . . 1 . .    . 1 . . . 1 . .
     . . . . . . . .     . . . . . . . .     . . . . . . . .    . . . . . . . .    . . . . . . . .
    */

    static constexpr uint64_t bishopAttacks(int sq, const uint64_t& free)
    {
        uint64_t msk = maskB[sq];
        uint64_t bb = initB[sq];
        uint64_t at = bb;
        bb &= free;
        switch (repsB[sq])
        {
            case 6:
                bb >>= 9; bb *= 0x00050005; bb &= msk; at |= bb; bb &= free; 
            case 5:
                bb >>= 9; bb *= 0x00050005; bb &= msk; at |= bb; bb &= free;
            case 4:
                bb >>= 9; bb *= 0x00050005; bb &= msk; at |= bb; bb &= free;
            case 3:
                bb >>= 9; bb *= 0x00050005; bb &= msk; at |= bb; bb &= free;
                bb >>= 9; bb *= 0x00050005; bb &= msk; at |= bb; bb &= free;
                bb >>= 9; bb *= 0x00050005; bb &= msk; at |= bb;
        }
        return at;
    }


    /**
    Number of expanding steps (explosions) for a rook
    */
    static constexpr int repsR[64] =
    {
        7, 6, 6, 6, 6, 6, 6, 8,
        7, 5, 5, 5, 5, 5, 5, 8,
        7, 5, 4, 4, 4, 4, 5, 8,
        7, 5, 4, 3, 3, 4, 5, 8,
        7, 5, 4, 3, 3, 4, 5, 8,
        7, 5, 4, 4, 4, 4, 5, 8,
        7, 5, 5, 5, 5, 5, 5, 8,
        7, 6, 6, 6, 6, 6, 6, 8,
    };

    static constexpr rankmask initRankR()
    {
        rankmask rankR{};
        for (int sq = 0; sq < 8; ++sq)
        {
            for (int i = 0; i < 128; i += 2)
            {
                int rr = 0;
                for (int j = sq - 1; j >= 0; --j)
                {
                    rr |= (1 << j);
                    if (!(i & (1 << j)))  // the 1 bits are the free squares
                        break;
                }
                for (int j = sq + 1; j < 8; ++j)
                {
                    rr |= (1 << j);
                    if (!(i & (1 << j)))  // the 1 bits are the free squares
                        break;
                }
                rankR[sq][i] = rr;
                rankR[sq][i + 1] = rr;
            }
        }
        return rankR;
    }
    static constexpr rankmask rankR = initRankR();  // or byte or Bitboard?



    static constexpr auto Size = sizeof(rankR) + sizeof(maskR) + sizeof(initR) + sizeof(initB) + sizeof(maskB);

    /*
    = init               >>= 8               *= 10281           &= mask            at |= bb
     . . . . . . . .     . . . . . . . .     . . . . . . . .    . . . . . . . .    . . . . . . . .
     . . . . . . . .     . . . . . . . .     . . . . . . . .    . . . . . . . .    . . . . . . . .
     . . . . . . . .     . . . . . . . .     . . . 1 . . . .    . . . 1 . . . .    . . . 1 . . . .
     . . . 1 . . . .     . . . . . . . .     . . 1 . 1 . . .    . . . . . . . .    . . . 1 . . . .
     . . 1 s 1 . . .     . . . 1 . . . .     . 1 . 1 . 1 . .    . 1 . s . 1 . .    . 1 1 s 1 1 . .
     . . . 1 . . . .     . . 1 . 1 . . .     . . 1 . 1 . . .    . . . . . . . .    . . . 1 . . . .
     . . . . . . . .     . . . 1 . . . .     . . . 1 . . . .    . . . 1 . . . .    . . . 1 . . . .
     . . . . . . . .     . . . . . . . .     . . . . . . . .    . . . . . . . .    . . . . . . . .
                                           and nasty overflows
    */


    static constexpr void rook_five_to_do(uint64_t& bb, uint64_t& cl, uint64_t& at, uint64_t msk, uint64_t free)
    {
        cl = at;
        bb >>= 8; bb *= 0x00010281; bb &= msk; at |= bb; bb &= free;
        bb &= ~cl;
    }

    static constexpr void rook_four_to_do(uint64_t& bb, uint64_t& cl, uint64_t& at, uint64_t msk, uint64_t free)
    {
        cl = at;
        bb >>= 8; bb *= 0x00010281; bb &= msk; at |= bb; bb &= free;
        bb &= ~cl;
    }

    static constexpr void rook_three_to_do(uint64_t& bb, uint64_t& cl, uint64_t& at, uint64_t msk, uint64_t free)
    {
        cl = at;
        bb >>= 8; bb *= 0x00010281; bb &= msk; at |= bb; bb &= free;
        bb &= ~cl;
    }

    static constexpr void rook_two_to_do(uint64_t& bb, uint64_t& cl, uint64_t& at, uint64_t msk, uint64_t free)
    {
        cl = at;
        bb >>= 8; bb *= 0x00010281; bb &= msk; at |= bb; bb &= free;
        bb &= ~cl;
        bb >>= 8; bb *= 0x00010281; bb &= msk; at |= bb;
    }

    static constexpr uint64_t rookAttacks(int sq, uint64_t free)
    {
        uint64_t msk = maskR[sq];   // The mask kills scattered bits
        uint64_t bb = initR[sq];   // This drives the expansion/explosion. Here is the start.
        uint64_t at = bb | (sq < 8 ? rankR[sq][free & 0x7e] : 0); // Collecting the resulting attacks
        uint64_t cl = at;          // Clears some intermediate overflows
        uint64_t ov;                // A nasty overflow bit when 4 directions in first step are possible.
                                    // Not nessessary on left side of board for repsR[sq] = 4 or 5.
                                    // Invent new numbers? 
        // Perhaps it would be easier and faster to use rankR[][] on all ranks.
        // But I like the 'explosive' algorithm. And I want to show that it works.
        bb &= free;
        switch (repsR[sq])
        {
            case 8:
                bb >>= 8; bb *= 0x00010081; bb &= msk; at |= bb; bb &= free;
                bb &= ~cl;
                rook_five_to_do(bb, cl, at, msk, free);
                rook_four_to_do(bb, cl, at, msk, free);
                rook_three_to_do(bb, cl, at, msk, free);
                rook_two_to_do(bb, cl, at, msk, free);
                break;
            case 7:
                bb >>= 8; bb *= 0x00010201; bb &= msk; at |= bb; bb &= free;
                bb &= ~cl;
                rook_five_to_do(bb, cl, at, msk, free);
                rook_four_to_do(bb, cl, at, msk, free);
                rook_three_to_do(bb, cl, at, msk, free);
                rook_two_to_do(bb, cl, at, msk, free);
                break;
            case 6:
                bb >>= 8; bb *= 0x00010281;
                bb &= ~(1ull << (sq - 6));      // Clears for b-squares a nasty overflow from south-west-first-step to h file
                bb &= msk; at |= bb; bb &= free;
                bb &= ~cl;
                rook_five_to_do(bb, cl, at, msk, free);
                rook_four_to_do(bb, cl, at, msk, free);
                rook_three_to_do(bb, cl, at, msk, free);
                rook_two_to_do(bb, cl, at, msk, free);
                break;
            case 5:
                cl = at;
                bb >>= 8; bb *= 0x00010281;
                ov = (1ull << (sq + 3));
                bb |= (bb & ov) >> 1;
                bb &= ~ov;
                bb &= ~(1ull << (sq - 6));      // Clears for b-squares a nasty overflow from south-west-first-step to h file
                bb &= msk; at |= bb; bb &= free;
                bb &= ~cl;
                rook_four_to_do(bb, cl, at, msk, free);
                rook_three_to_do(bb, cl, at, msk, free);
                rook_two_to_do(bb, cl, at, msk, free);
                break;
            case 4:
                cl = at;
                bb >>= 8; bb *= 0x00010281;
                ov = (1ull << (sq + 3));
                bb |= (bb & ov) >> 1;
                bb &= ~ov;
                bb &= msk; at |= bb; bb &= free;
                bb &= ~cl;
                rook_three_to_do(bb, cl, at, msk, free);
                rook_two_to_do(bb, cl, at, msk, free);
                break;
            case 3:
                cl = at;
                bb >>= 8; bb *= 0x00010281;
                ov = (1ull << (sq + 3));
                bb |= (bb & ov) >> 1;
                bb &= ~ov;
                bb &= msk; at |= bb; bb &= free;
                bb &= ~cl;
                rook_two_to_do(bb, cl, at, msk, free);
                break;
        }
        return at;
    }

    static constexpr uint64_t Queen(int sq, uint64_t occ) {
        return rookAttacks(sq, ~occ) | bishopAttacks(sq, ~occ);
    }
}