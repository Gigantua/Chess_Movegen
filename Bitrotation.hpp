#pragma once
#include <stdint.h>

//Gerd Isenberg, Aleks Peshkov 2007
//Subtracting a Rook from a Blocking Piece - https://www.chessprogramming.org/Subtracting_a_Rook_from_a_Blocking_Piece

//Improvement by Daniel Inführ 2022 - Using a bitreverse intrinsics - which exists on CUDA. 
//On x64 this can be done fast with the gellar field extension avx512 (rotate bits in a 64 bit integer)
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

//Update Daniel 19.04.2022. These Defines are SLOWER than the 4 functions below (on MSVC)
#	define dir_HO(X) (0xFFull << (X & 56))
#	define dir_VE(X) (0x0101010101010101ull << (X & 7))
#	define dir_D1(X) (mask_shift<0x8040201008040201ull>((X & 7) - (X >> 3)))
#	define dir_D2(X) (mask_shift<0x0102040810204080ull>(7 - (X & 7) - (X >> 3)))
	
//New reference for getting masks at runtime
    static constexpr uint64_t mask_HO(uint64_t sq)
    {
        return ((0xFF00000000000000ULL >> (std::countl_zero(0x00000000000000FFULL) & std::countl_zero(sq))) - sq);
    }

    static constexpr uint64_t mask_VE(uint64_t sq)
    {
        return ((0x8080808080808080ULL >> (std::countl_zero(0x0101010101010101ULL) & std::countl_zero(sq))) - sq);
    }

    static constexpr uint64_t mask_D1(uint64_t sq)
    {
        uint64_t a = (0x8040201008040201ULL >> (63 - std::countl_zero((0x01010101010101FFULL & (0x8040201008040201ULL >> std::countr_zero(sq))))));
        uint64_t b = (0x8040201008040201ULL << (63 - std::countl_zero((0x01010101010101FFULL & (0x8040201008040201ULL >> std::countl_zero(sq))))));
        return (a & b) ^ sq;
    }

    static constexpr uint64_t mask_D2(uint64_t sq)
    {
        uint64_t a = (0x8102040810204081ULL << (63 - std::countl_zero((0x80808080808080FFULL & (0x8102040810204081ULL >> std::countl_zero(sq))))));
        uint64_t b = (0x8102040810204081ULL >> (63 - std::countl_zero((0x80808080808080FFULL & (0x8102040810204081ULL >> std::countr_zero(sq))))));
        return (a & b) ^ sq;
    }

	/* Generate attack using the hyperbola quintessence approach */
	uint64_t attack(uint64_t occ, uint64_t mask, uint64_t bit, uint64_t bit_rev)
    {
        uint64_t o = occ & mask;
		return ((o - bit) ^ bit_reverse(bit_reverse(o) - bit_rev)) & mask;
	}

    //This is now a bitnative algorithm. (Supports passing SQ as a bitmask)
    static uint64_t Queen(int sq, uint64_t occ) {
        uint64_t bit = 1ull << sq; 
        uint64_t bit_rev = (1ull << (sq ^ 63));
        return	  attack(occ, mask_HO(bit), bit, bit_rev)
				^ attack(occ, mask_VE(bit), bit, bit_rev)
				^ attack(occ, mask_D1(bit), bit, bit_rev)
				^ attack(occ, mask_D2(bit), bit, bit_rev);
    }

#undef dir_HO
#undef dir_VE
#undef dir_D1
#undef dir_D2
}
