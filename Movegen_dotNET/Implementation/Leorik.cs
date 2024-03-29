﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Movegen.Implementation
{
    public static class Leorik
    {
        public static readonly ulong[] DiagonalMask = 
        {
            0x8040201008040200UL, 0x0080402010080500UL, 0x0000804020110A00UL, 0x0000008041221400UL,
            0x0000000182442800UL, 0x0000010204885000UL, 0x000102040810A000UL, 0x0102040810204000UL,
            0x4020100804020002UL, 0x8040201008050005UL, 0x00804020110A000AUL, 0x0000804122140014UL,
            0x0000018244280028UL, 0x0001020488500050UL, 0x0102040810A000A0UL, 0x0204081020400040UL,
            0x2010080402000204UL, 0x4020100805000508UL, 0x804020110A000A11UL, 0x0080412214001422UL,
            0x0001824428002844UL, 0x0102048850005088UL, 0x02040810A000A010UL, 0x0408102040004020UL,
            0x1008040200020408UL, 0x2010080500050810UL, 0x4020110A000A1120UL, 0x8041221400142241UL,
            0x0182442800284482UL, 0x0204885000508804UL, 0x040810A000A01008UL, 0x0810204000402010UL,
            0x0804020002040810UL, 0x1008050005081020UL, 0x20110A000A112040UL, 0x4122140014224180UL,
            0x8244280028448201UL, 0x0488500050880402UL, 0x0810A000A0100804UL, 0x1020400040201008UL,
            0x0402000204081020UL, 0x0805000508102040UL, 0x110A000A11204080UL, 0x2214001422418000UL,
            0x4428002844820100UL, 0x8850005088040201UL, 0x10A000A010080402UL, 0x2040004020100804UL,
            0x0200020408102040UL, 0x0500050810204080UL, 0x0A000A1120408000UL, 0x1400142241800000UL,
            0x2800284482010000UL, 0x5000508804020100UL, 0xA000A01008040201UL, 0x4000402010080402UL,
            0x0002040810204080UL, 0x0005081020408000UL, 0x000A112040800000UL, 0x0014224180000000UL,
            0x0028448201000000UL, 0x0050880402010000UL, 0x00A0100804020100UL, 0x0040201008040201UL
        };

        public static readonly ulong[] OrthogonalMask = 
        {
            0x01010101010101FEUL, 0x02020202020202FDUL, 0x04040404040404FBUL, 0x08080808080808F7UL,
            0x10101010101010EFUL, 0x20202020202020DFUL, 0x40404040404040BFUL, 0x808080808080807FUL,
            0x010101010101FE01UL, 0x020202020202FD02UL, 0x040404040404FB04UL, 0x080808080808F708UL,
            0x101010101010EF10UL, 0x202020202020DF20UL, 0x404040404040BF40UL, 0x8080808080807F80UL,
            0x0101010101FE0101UL, 0x0202020202FD0202UL, 0x0404040404FB0404UL, 0x0808080808F70808UL,
            0x1010101010EF1010UL, 0x2020202020DF2020UL, 0x4040404040BF4040UL, 0x80808080807F8080UL,
            0x01010101FE010101UL, 0x02020202FD020202UL, 0x04040404FB040404UL, 0x08080808F7080808UL,
            0x10101010EF101010UL, 0x20202020DF202020UL, 0x40404040BF404040UL, 0x808080807F808080UL,
            0x010101FE01010101UL, 0x020202FD02020202UL, 0x040404FB04040404UL, 0x080808F708080808UL,
            0x101010EF10101010UL, 0x202020DF20202020UL, 0x404040BF40404040UL, 0x8080807F80808080UL,
            0x0101FE0101010101UL, 0x0202FD0202020202UL, 0x0404FB0404040404UL, 0x0808F70808080808UL,
            0x1010EF1010101010UL, 0x2020DF2020202020UL, 0x4040BF4040404040UL, 0x80807F8080808080UL,
            0x01FE010101010101UL, 0x02FD020202020202UL, 0x04FB040404040404UL, 0x08F7080808080808UL,
            0x10EF101010101010UL, 0x20DF202020202020UL, 0x40BF404040404040UL, 0x807F808080808080UL,
            0xFE01010101010101UL, 0xFD02020202020202UL, 0xFB04040404040404UL, 0xF708080808080808UL,
            0xEF10101010101010UL, 0xDF20202020202020UL, 0xBF40404040404040UL, 0x7F80808080808080UL
        };

        public static readonly ulong[] Diagonals = 
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
            0x1008040201000000UL, 0x2010080402010000UL, 0x4020100804020100UL, 0x8040201008040201UL
        };

        public static readonly ulong[] AntiDiagonals =
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

        //returns the index of the least significant bit of the bitboard, bb can't be 0
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static int LSB(ulong bb) => BitOperations.TrailingZeroCount(bb);

        //resets the least significant bit of the bitboard
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static ulong ClearLSB(ulong bb) => bb & (bb - 1);
        //public static ulong ClearLSB(ulong bb) => Bmi1.X64.ResetLowestSetBit(bb);

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static int PopCount(ulong bb) => BitOperations.PopCount(bb);

        const ulong HORIZONTAL = 0x00000000000000FFUL;
        const ulong VERTICAL = 0x0101010101010101UL;

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static ulong GetBishopTargets(ulong occupation, int square)
        {
            ulong bbPiece = 1UL << square;
            ulong bbBlocker = occupation & ~bbPiece;
            //mask the bits below bbPiece
            ulong bbBelow = bbPiece - 1;
            return GenLines(Diagonals[square], AntiDiagonals[square], bbBlocker, bbBelow);
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static ulong GetRookTargets(ulong occupation, int square)
        {
            ulong bbPiece = 1UL << square;
            ulong bbBlocker = occupation & ~bbPiece;
            //mask the bits below bbPiece
            ulong bbBelow = bbPiece - 1;
            //horizontal line through square
            ulong bbHorizontal = HORIZONTAL << (square & 56);
            //vertical line through square
            ulong bbVertical = VERTICAL << (square & 7);
            return GenLines(bbHorizontal, bbVertical, bbBlocker, bbBelow);
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static ulong Queen(int square, ulong occupation)
        {
            return (GetBishopTargets(occupation, square) |
            GetRookTargets(occupation, square)) ^ (1ul << square);
        }
            

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        private static ulong GenLines(ulong bbLineA, ulong bbLineB, ulong bbBlocker, ulong bbBelow) =>
            GenLine(bbLineA, bbBlocker & bbLineA, bbBelow) |
            GenLine(bbLineB, bbBlocker & bbLineB, bbBelow);

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        private static ulong GenLine(ulong bbLine, ulong bbBlocker, ulong bbBelow)
        {
            //MaskLow sets all low bits up to and including the lowest blocker above orgin, the rest are zeroed out.
            //MaskHigh sets all low bits up to and including the highest blocker below origin, the rest are zerored out.
            //The bits of the line that are different between the two masks are the valid targets (including the first blockers on each side)
            return (MaskLow(bbBlocker & ~bbBelow) ^ MaskHigh(bbBlocker & bbBelow)) & bbLine;
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        //identify the highest set bit and shift a mask so the bits below are set and the rest are zeroed
        private static ulong MaskHigh(ulong bb) => 0x7FFFFFFFFFFFFFFFUL >> BitOperations.LeadingZeroCount(bb | 1);

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        //identify the lowest set bit and set all bits below while zeroing the rest
        private static ulong MaskLow(ulong bb) => bb ^ (bb - 1);
    }
}
