using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Runtime.InteropServices;

namespace Movegen.Implementation
{
    public static class ObstructionDiff
    {
        static int FileOf(int S) => S & 7;
        static ulong GetLower(int S) => ((1ul << S) - 1);
        static ulong GetUpper(int S) => (0xFFFFFFFFFFFFFFFF << (S));
        static ulong init_rank(int s) => 0xFFul << (s & 56);

        static ulong init_file(int s) => 0x0101010101010101ul << FileOf(s);

        static ulong init_diag(int sq)
        {
            int d = 8 * FileOf(sq) - (sq & 56);
            int n = -d & (d >> 31);
            int s = d & (-d >> 31);
            return (0x8040201008040201ul >> s) << n;
        }

        static ulong init_anti(int sq)
        {
            int d = 56 - 8 * FileOf(sq) - (sq & 56);
            int n = -d & (d >> 31);
            int s = d & (-d >> 31);
            return (0x0102040810204080ul >> s) << n;
        }

        struct lineEx
        {
            public ulong lower;
            public ulong upper;
            public ulong uni;

            static ulong init_low(int sq, ulong line)
            {
                ulong lineEx = line ^ (1ul << sq);
                return GetLower(sq) & lineEx;
            }

            static ulong init_up(int sq, ulong line)
            {
                ulong lineEx = line ^ (1ul << sq);
                return GetUpper(sq) & lineEx;
            }

            public lineEx(int sq, ulong line)
            {
                lower = init_low(sq, line);
                upper = init_up(sq, line);
                uni = upper | lower;
            }
        };
        static lineEx[] lines = new lineEx[256];

        static ObstructionDiff()
        {
            for (int i = 0; i < 64; i++)
            {
                lines[i * 4 + 0] = new lineEx(i, init_rank(i));
                lines[i * 4 + 1] = new lineEx(i, init_file(i));
                lines[i * 4 + 2] = new lineEx(i, init_diag(i));
                lines[i * 4 + 3] = new lineEx(i, init_anti(i));
            }
        }


        static ulong line_attack(int sq, ulong occ, int dir)
        {
            lineEx line = lines[4 * sq + dir];
            ulong lower = (line.lower & occ) | 1;
            ulong upper = line.upper & occ;
            ulong msb = (1ul << 63) >> BitOperations.LeadingZeroCount(lower);  //Extract Highest Set Isolated Bit
            ulong lsb = upper & ((ulong)-(long)upper);           //Extract Lowest Set Isolated Bit
            ulong oDif = lsb * 2 - msb;
            return line.uni & oDif;
        }

        public static ulong Bishop(int sq, ulong occ)
        {
            return line_attack(sq, occ, 2) | line_attack(sq, occ, 3);
        }

        public static ulong Rook(int sq, ulong occ)
        {
            return line_attack(sq, occ, 0) | line_attack(sq, occ, 1);
        }

        public static ulong Queen(int sq, ulong occ)
        {
            return Bishop(sq, occ) | Rook(sq, occ);
        }
    }
}
