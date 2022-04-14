#pragma once
#include <stdint.h>

//(c) Gerd Isenberg, Aleks Peshkov 2007
//Subtracting a Rook from a Blocking Piece - https://www.chessprogramming.org/Subtracting_a_Rook_from_a_Blocking_Piece

//Improvement by Daniel Inführ 2022 - Using a non yet existing bitreverse intrinsics - but it exists on cuda. 
//Update 2022: This is the fastest algorithm known on CUDA by far! http://www.talkchess.com/forum3/viewtopic.php?f=7&t=79078&start=20

namespace Chess_Lookup::Bitrotation
{
    template <typename T, T m, int k>
    static inline T swapbits(T p) {
        T q = ((p >> k) ^ p) & m;
        return p ^ q ^ (q << k);
    }

    uint64_t bit_reverse(uint64_t n)
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

    template<uint64_t bb>
    uint64_t mask_shift(int ranks) {
        return ranks > 0 ? bb >> (ranks << 3) : bb << -(ranks << 3);
    }

#	define dir_HO(X) (0xFFull << (X & 56))
#	define dir_VE(X) (0x0101010101010101ull << (X & 7))
#	define dir_D1(X) (mask_shift<0x8040201008040201ull>((X & 7) - (X >> 3)))
#	define dir_D2(X) (mask_shift<0x0102040810204080ull>(7 - (X & 7) - (X >> 3)))
		
	/* Generate attack using the hyperbola quintessence approach */
	uint64_t attack(uint64_t pieces, uint32_t x, uint64_t mask) {
		uint64_t o = pieces & mask;
		return ((o - (1ull << x)) ^ bit_reverse(bit_reverse(o) - (1ull << (x ^ 63)))) & mask;
	}

    static uint64_t Queen(int sq, uint64_t occ) {

        return	  attack(occ, sq, dir_HO(sq) ^ (1ull << sq))
				| attack(occ, sq, dir_VE(sq) ^ (1ull << sq))
				| attack(occ, sq, dir_D1(sq) ^ (1ull << sq))
				| attack(occ, sq, dir_D2(sq) ^ (1ull << sq));
    }

#undef dir_HO
#undef dir_VE
#undef dir_D1
#undef dir_D2
}
