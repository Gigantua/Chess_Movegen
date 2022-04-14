/**
 * Genetic8Ray.hpp
 *
 * Copyright © 2022 Daniel Inführ
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited.
 * For Questions and allowance to use this code contact under daniel.infuehr(@)live.de
 *
 * Maintained by Daniel Inführ, 2022
 *
 * @file Genetic8Ray.hpp
 * @author Daniel Inführ
 * @copyright 2022 
 * @section License
 */

//This was created by writing a custom C++ Code generator that 
//tries every abstract syntax tree that is legal with a list of 16 c++ code tokens. 


//LIST OF 16 TOKENS:
/**
1ull
2ull
56ull
sq
occ
mask
std::popcount(arg0)
std::countl_zero(arg0)
std::countr_zero(arg0)
bit_reverse(arg0)
(arg0 | arg1)
(arg0 & ~arg1)
(arg0 ^ arg1)
(arg0 - arg1)
(arg0 << arg1)
(arg0 >> arg1)
**/

#pragma once
#include <stdint.h>

#define dir_HO(X) (0xFFull << (X & 56))
#define dir_VE(X) (0x0101010101010101ull << (X & 7))
#define dir_D1(X) (mask_shift<0x8040201008040201ull>((X & 7) - (X >> 3)))
#define dir_D2(X) (mask_shift<0x0102040810204080ull>(7 - (X & 7) - (X >> 3)))
#define GetLower(X) ((1ull << X) - 1)
#define GetUpper(X) (0xFFFFFFFFFFFFFFFF << (X))

namespace Chess_Lookup::Genetic8Ray
{
	constexpr uint64_t Size = 0;

	template<uint64_t bb>
	static constexpr uint64_t mask_shift(int ranks) {
		return ranks > 0 ? bb >> (ranks << 3) : bb << -(ranks << 3);
	}

	template <typename T, T m, int k>
	static constexpr T swapbits(T p) {
		T q = ((p >> k) ^ p) & m;
		return p ^ q ^ (q << k);
	}

	static constexpr uint64_t bit_reverse(uint64_t n)
	{
		constexpr uint64_t  m1 = ((uint64_t(1) << 63) - 1) / (1 + (1 << 1) + (1 << 2));
		constexpr uint64_t  m2 = ((uint64_t(1) << 63) - 1) / (1 + (1 << 3) + (1 << 6));
		constexpr uint64_t  m3 = ((uint64_t(1) << 9) - 1) + (((uint64_t(1) << 9) - 1) << 36);
		constexpr uint64_t  m4 = (uint64_t(1) << 27) - 1;
		n = swapbits<uint64_t, m1, 2>(n);
		n = swapbits<uint64_t, m2, 6>(n);
		n = swapbits<uint64_t, m3, 18>(n);
		n = swapbits<uint64_t, m4, 36>(n);
		n = (n >> 63) | (n << 1);
		return n;
	}

	static constexpr uint64_t SolveLineUpper_HO(uint64_t occ, uint64_t mask)
	{
		occ &= mask;
		return (occ ^ (occ - 1ull)) & mask;
	}

	static constexpr uint64_t SolveLineLower_HO(uint64_t occ, uint64_t mask)
	{
		occ &= mask;
		return (occ ^ bit_reverse((bit_reverse(occ) - 1ull))) & mask;
	}

	static constexpr uint64_t SolveLineUpper(uint64_t occ, uint64_t mask)
	{
		occ &= mask;
		return ((occ - 1ull) << 1ull) & mask;
	}

	static constexpr uint64_t SolveLineLower(uint64_t occ, uint64_t mask)
	{
		occ &= mask;
		return (bit_reverse((bit_reverse(occ) - 1ull)) >> 1ull) & mask;
	}

	static constexpr uint64_t Rook(int sq, uint64_t occ)
	{
		const uint64_t lower =  GetLower(sq);
		const uint64_t upper =  GetUpper(sq) ^ (1ull << sq);
		const uint64_t ho =	dir_HO(sq);
		const uint64_t ve = dir_VE(sq);

		return SolveLineUpper_HO(occ, upper & ho) | SolveLineLower_HO(occ, lower & ho) |
			   SolveLineUpper(occ, upper & ve) | SolveLineLower(occ, lower & ve);
	}

	static constexpr uint64_t Bishop(int sq, uint64_t occ)
	{
		const uint64_t lower = GetLower(sq);
		const uint64_t upper = GetUpper(sq) ^ (1ull << sq);
		const uint64_t d1 = dir_D1(sq);
		const uint64_t d2 = dir_D2(sq);

		return SolveLineUpper(occ, upper & d1) | SolveLineLower(occ, lower & d1) | 
			   SolveLineUpper(occ, upper & d2) | SolveLineLower(occ, lower & d2);
	}

	static constexpr uint64_t Queen(int sq, uint64_t occ)
	{
		return Bishop(sq, occ) | Rook(sq, occ);
	}

}

#undef dir_HO
#undef dir_VE
#undef dir_D1
#undef dir_D2
#undef GetLower
#undef GetUpper