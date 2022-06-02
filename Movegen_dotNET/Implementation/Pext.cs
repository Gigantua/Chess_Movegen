using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Runtime.InteropServices;
using System.Runtime.Intrinsics.X86;
using System.Runtime.CompilerServices;

namespace Movegen.Implementation
{
    public static class Pext
    {
        static ulong RelevantBishopSee(int x, int y)
        {
            // result attacks bitboard
            ulong attacks = 0ul;

            // init ranks & files
            int r, f;

            // mask relevant bishop occupancy bits
            for (r = y + 1, f = x + 1; r <= 6 && f <= 6; r++, f++) attacks |= (1ul << (r * 8 + f));
            for (r = y - 1, f = x + 1; r >= 1 && f <= 6; r--, f++) attacks |= (1ul << (r * 8 + f));
            for (r = y + 1, f = x - 1; r <= 6 && f >= 1; r++, f--) attacks |= (1ul << (r * 8 + f));
            for (r = y - 1, f = x - 1; r >= 1 && f >= 1; r--, f--) attacks |= (1ul << (r * 8 + f));

            // return attack map
            return attacks;
        }

        static ulong RelevantRookSee(int x, int y)
        {
            // result attacks bitboard
            ulong attacks = 0ul;

            // init ranks & files
            int r, f;

            // mask relevant rook occupancy bits
            for (r = y + 1; r <= 6; r++) attacks |= (1ul << (r * 8 + x));
            for (r = y - 1; r >= 1; r--) attacks |= (1ul << (r * 8 + x));
            for (f = x + 1; f <= 6; f++) attacks |= (1ul << (y * 8 + f));
            for (f = x - 1; f >= 1; f--) attacks |= (1ul << (y * 8 + f));

            // return attack map
            return attacks;
        }

        public struct PextEntry
        {
            public uint offset_rook;
            public uint offset_bish;
            public ulong mask_rook;
            public ulong mask_bish;

            public PextEntry(uint offset_rook, uint offset_bish, ulong mask_rook, ulong mask_bish)
            {
                this.offset_rook = offset_rook;
                this.offset_bish = offset_bish;
                this.mask_rook = mask_rook;
                this.mask_bish = mask_bish;
            }
        }


        public static ulong[] Attacks;
        public static PextEntry[] Entries = new PextEntry[64];


        static PextEntry make_entry(int sq, ulong mask_rook, ulong mask_bish, List<ulong> target)
        {
            uint offset_rook = (uint)target.Count;
            int cnt = BitOperations.PopCount((ulong)mask_rook);
            for (ulong i = 0; i < (ulong)(1 << cnt); i++)
            {
                ulong occ = Bmi2.X64.ParallelBitDeposit(i, mask_rook);
                target.Add(Switch.Rook(sq, occ));
            }

            uint offset_bish = (uint)target.Count;
            cnt = BitOperations.PopCount((ulong)mask_bish);
            for (ulong i = 0; i < (ulong)(1 << cnt); i++)
            {
                ulong occ = Bmi2.X64.ParallelBitDeposit(i, mask_bish);
                target.Add(Switch.Bishop(sq, occ));
            }

            return new PextEntry(offset_rook, offset_bish, mask_rook, mask_bish);
        }

        static Pext()
        {
            List<ulong> attacks = new List<ulong>();
            for (int x = 0; x < 8; x++)
            {
                for (int y = 0; y < 8; y++)
                {
                    int sq = y * 8 + x;
                    Entries[sq] = make_entry(sq, RelevantRookSee(x, y), RelevantBishopSee(x, y), attacks);
                }
            }
            Attacks = attacks.ToArray();
        }


        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static ulong Rook(int sq, ulong occupy)
        {
            return Attacks[Entries[sq].offset_rook + Bmi2.X64.ParallelBitExtract(occupy, Entries[sq].mask_rook)];
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static ulong Bishop(int sq, ulong occupy)
        {
            return Attacks[Entries[sq].offset_bish + Bmi2.X64.ParallelBitExtract(occupy, Entries[sq].mask_bish)];
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static ulong Queen(int sq, ulong occupy)
        {
            return Rook(sq, occupy) | Bishop(sq, occupy);
        }

        [MethodImpl(MethodImplOptions.NoInlining)]
        public static ulong Queen_NoInline(int sq, ulong occupy)
        {
            return Rook(sq, occupy) | Bishop(sq, occupy);
        }

    }
}
