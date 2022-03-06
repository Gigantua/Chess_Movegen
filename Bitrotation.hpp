#pragma once

#include <stdint.h>

namespace Chess_Lookup::Bitrotation
{
    template <typename T, T m, int k>
    static inline T swapbits(T p) {
        T q = ((p >> k) ^ p) & m;
        return p ^ q ^ (q << k);
    }

    uint64_t bitreverse(uint64_t n)
    {
        static const uint64_t  m1 = ((uint64_t(1) << 63) - 1) / (1 + (1 << 1) + (1 << 2));
        static const uint64_t  m2 = ((uint64_t(1) << 63) - 1) / (1 + (1 << 3) + (1 << 6));
        static const uint64_t  m3 = ((uint64_t(1) << 9) - 1) + (((uint64_t(1) << 9) - 1) << 36);
        static const uint64_t  m4 = (uint64_t(1) << 27) - 1;
        n = swapbits<uint64_t, m1, 2>(n);
        n = swapbits<uint64_t, m2, 6>(n);
        n = swapbits<uint64_t, m3, 18>(n);
        n = swapbits<uint64_t, m4, 36>(n);
        n = (n >> 63) | (n << 1);
        return n;
    }
    constexpr auto Size = 0; //0 kb version


    static uint64_t Queen(int square, uint64_t occupation) {
        uint64_t reversed = bitreverse(2); //1ull << 62

        //Help here
        return 42;
    }
}
