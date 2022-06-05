using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Movegen.Runtime
{
    public static class Xorshift
    {
        private static uint x, y, z, w ;

        static Xorshift()
        {
            Reset();
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static uint Next()
        {
            uint t = x ^ (x << 11);
            x = y; y = z; z = w;
            return w = w ^ (w >> 19) ^ t ^ (t >> 8);
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static ulong NextULong()
        {
            return ((ulong)Next()) | (((ulong)Next()) << 32);
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static void Reset()
        {
            x = 548787455;
            y = 842502087;
            z = 3579807591; 
            w = 273326509;
        }

    }
}
