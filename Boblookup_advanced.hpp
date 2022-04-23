#pragma once

// Robert Hyatt's and Michael Sherwin's classical bitboard approach
// generate moves for the sliding pieces.

//Improvements by Daniel Infuehr 21.04.2022

#include <stdint.h>
#include <bit>
#include <array>

#	define dir_HO(X) (0xFFull << (X & 56))
#	define dir_VE(X) (0x0101010101010101ull << (X & 7))
#	define dir_D1(X) (mask_shift(0x8040201008040201ull, (X & 7) - (X >> 3)))
#	define dir_D2(X) (mask_shift(0x0102040810204080ull, 7 - (X & 7) - (X >> 3)))
#	define GetLower(X) ((1ull << X) - 1)
#	define GetUpper(X) (0xFFFFFFFFFFFFFFFE << (X))

namespace Chess_Lookup::BobAdvanced {

	struct Ray8 
	{
		uint64_t rayNW; uint64_t rayNN; uint64_t rayNE; uint64_t rayEE;
		uint64_t raySE; uint64_t raySS; uint64_t raySW; uint64_t rayWW;
	};

	static constexpr uint64_t mask_shift(uint64_t bb, int ranks)
	{
		if (ranks > 0) return bb >> (ranks << 3);
		else return bb << -(ranks << 3);
	}

	constexpr std::array<Ray8, 65> ray = []() {
		std::array<Ray8, 65> ray;
		for (int sq = 0; sq < 64; sq++)
		{
			ray[sq].rayNW = dir_D2(sq) & GetUpper(sq); // Northwest
			ray[sq].rayNN = dir_VE(sq) & GetUpper(sq); // North
			ray[sq].rayNE = dir_D1(sq) & GetUpper(sq); // Northeast
			ray[sq].rayEE = dir_HO(sq) & GetUpper(sq); // East
			ray[sq].raySE = dir_D1(sq) & GetLower(sq); // Southeast
			ray[sq].raySW = dir_D2(sq) & GetLower(sq); // Southwest
			ray[sq].raySS = dir_VE(sq) & GetLower(sq); // South
			ray[sq].rayWW = dir_HO(sq) & GetLower(sq); // West
		}
		ray[64] = ray[63];
		return ray;
	}();

	constexpr std::array<Ray8, 65> rev = []() {
		std::array<Ray8, 65> rev;
		for (int sq = 0; sq < 64; sq++)
		{
			rev[sq] = ray[63 - sq];
		}
		rev[64] = ray[0];
		return rev;
	}();

	constexpr std::array<uint64_t, 64> queens = []()
	{
		std::array<uint64_t, 64> q = {};
		for (int sq = 0; sq < 64; sq++)
		{
			q[sq] = (dir_HO(sq) | dir_VE(sq) | dir_D1(sq) | dir_D2(sq)) ^ (1ull << sq);
		}
		return q;
	}();

	constexpr auto Size = sizeof(ray);

	static constexpr uint64_t Queen(int sq, uint64_t occ) 
	{
		uint64_t bb = (
			  ray[std::countr_zero(ray[sq].rayNW & occ)].rayNW
			| ray[std::countr_zero(ray[sq].rayNN & occ)].rayNN
			| ray[std::countr_zero(ray[sq].rayNE & occ)].rayNE
			| ray[std::countr_zero(ray[sq].rayEE & occ)].rayEE
			| rev[std::countl_zero(ray[sq].raySE & occ)].raySE
			| rev[std::countl_zero(ray[sq].raySS & occ)].raySS
			| rev[std::countl_zero(ray[sq].raySW & occ)].raySW
			| rev[std::countl_zero(ray[sq].rayWW & occ)].rayWW)
			^ queens[sq];

		return bb; // Rook(sq, occ) | Bishop(sq, occ);
	}
#undef dir_HO
#undef dir_VE
#undef dir_D1
#undef dir_D2
#undef GetLower
#undef GetUpper
}