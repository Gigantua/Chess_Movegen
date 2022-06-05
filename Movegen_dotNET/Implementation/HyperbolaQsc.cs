using System;
using System.Buffers.Binary;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Movegen.Implementation
{
    public static class HyperbolaQsc
    {
        struct Mask
        {
            public ulong diagonal;
            public ulong antidiagonal;
            public ulong vertical;
        };

        static Mask[] mask = new Mask[64];
        static byte[] rank_attack = new byte[512];

        static void InitMask()
        {
            int r, f, i, j, y;
            int[] d = new int[64];

            for (int x = 0; x < 64; ++x)
            {
                for (y = 0; y < 64; ++y) d[y] = 0;
                // directions
                for (i = -1; i <= 1; ++i)
                    for (j = -1; j <= 1; ++j)
                    {
                        if (i == 0 && j == 0) continue;
                        f = x & 07;
                        r = x >> 3;
                        for (r += i, f += j; 0 <= r && r < 8 && 0 <= f && f < 8; r += i, f += j)
                        {
                            y = 8 * r + f;
                            d[y] = 8 * i + j;
                        }
                    }

                // ulong mask
                for (y = x - 9; y >= 0 && d[y] == -9; y -= 9) mask[x].diagonal |= (1ul << y);
                for (y = x + 9; y < 64 && d[y] == 9; y += 9) mask[x].diagonal |= (1ul << y);

                for (y = x - 7; y >= 0 && d[y] == -7; y -= 7) mask[x].antidiagonal |= (1ul << y);
                for (y = x + 7; y < 64 && d[y] == 7; y += 7) mask[x].antidiagonal |= (1ul << y);

                for (y = x - 8; y >= 0; y -= 8) mask[x].vertical |= (1ul << y);
                for (y = x + 8; y < 64; y += 8) mask[x].vertical |= (1ul << y);
            }
        }
        static void InitRank()
        {
            for (int x = 0; x < 64; ++x)
            {
                for (int f = 0; f < 8; ++f)
                {
                    int o = 2 * x;
                    int x2 = 0;
                    int y2 = 0;
                    int b = 0;

                    y2 = 0;
                    for (x2 = f - 1; x2 >= 0; --x2)
                    {
                        b = 1 << x2;
                        y2 |= b;
                        if ((o & b) == b) break;
                    }
                    for (x2 = f + 1; x2 < 8; ++x2)
                    {
                        b = 1 << x2;
                        y2 |= b;
                        if ((o & b) == b) break;
                    }
                    rank_attack[x * 8 + f] = (byte)y2;
                }
            }
        }
        static HyperbolaQsc()
        {
            InitMask();
            InitRank();
        }


        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        static ulong bit_bswap(ulong b)
        {
            return BinaryPrimitives.ReverseEndianness(b);
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        static ulong attack(ulong pieces, int x, ulong mask)
        {
            ulong o = pieces & mask;
            return ((o - (1ul << x)) ^ bit_bswap(bit_bswap(o) - (0x8000000000000000ul >> x))) & mask; //Daniel 28.04.2022 - Faster shift. Replaces (1ul << (s ^ 56))
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        static ulong horizontal_attack(ulong pieces, int x)
        {
            int file_mask = x & 7;
            int rank_mask = x & 56;
            int o = (int)((pieces >> rank_mask) & 126);

            return ((ulong)rank_attack[o * 4 + file_mask]) << rank_mask;
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        static ulong vertical_attack(ulong occ, int sq)
        {
            return attack(occ, sq, mask[sq].vertical);
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        static ulong diagonal_attack(ulong occ, int sq)
        {
            return attack(occ, sq, mask[sq].diagonal);
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static ulong antidiagonal_attack(ulong occ, int sq)
        {
            return attack(occ, sq, mask[sq].antidiagonal);
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static ulong bishop_attack(int sq, ulong occ)
        {
            return diagonal_attack(occ, sq) | antidiagonal_attack(occ, sq);
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static ulong rook_attack(int sq, ulong occ)
        {
            return vertical_attack(occ, sq) | horizontal_attack(occ, sq);
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static ulong Queen(int sq, ulong occ)
        {
            return bishop_attack(sq, occ) | rook_attack(sq, occ);
        }
    }
}