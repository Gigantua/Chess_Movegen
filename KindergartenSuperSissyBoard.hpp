#pragma once
// Datum  : 21.01.2023
// Author : Michael J Sherwin 2023
// Content: The name is Kindergarten Super SISSY Bitboards - https://www.talkchess.com/forum3/viewtopic.php?f=7&t=81234&start=30
//          The code can be further "minimized" according to the author
//			C++20 constexpr port by Daniel Infuehr

#include <stdint.h>

namespace Chess_Lookup::KGSSB
{
	uint64_t vMask[64];
	uint64_t hMask[64];
	uint64_t dMask[64];
	uint64_t aMask[64];

	uint64_t vSubset[64][64];
	uint64_t hSubset[64][64];
	uint64_t dSubset[64][64];
	uint64_t aSubset[64][64];

	static constexpr uint64_t Size = (64 * 64 * 4 + 64 * 4) * sizeof(uint64_t);

	enum { FILEa, FILEb, FILEc, FILEd, FILEe, FILEf, FILEg, FILEh };

	enum { RANK1, RANK2, RANK3, RANK4, RANK5, RANK6, RANK7, RANK8 };


	static void InitSquare(int sq)
	{
		int ts, dx, dy;
		uint64_t occ, index;
		int x = sq % 8;
		int y = sq / 8;

		// Initialize Kindergarten Super SISSY Bitboards
		// diagonals
		for (ts = sq + 9, dx = x + 1, dy = y + 1; dx < FILEh && dy < RANK8; dMask[sq] |= 1ull << ts, ts += 9, dx++, dy++);
		for (ts = sq - 9, dx = x - 1, dy = y - 1; dx > FILEa && dy > RANK1; dMask[sq] |= 1ull << ts, ts -= 9, dx--, dy--);

		// anti diagonals
		for (ts = sq + 7, dx = x - 1, dy = y + 1; dx > FILEa && dy < RANK8; aMask[sq] |= 1ull << ts, ts += 7, dx--, dy++);
		for (ts = sq - 7, dx = x + 1, dy = y - 1; dx < FILEh && dy > RANK1; aMask[sq] |= 1ull << ts, ts -= 7, dx++, dy--);

		// diagonal indexes
		for (index = 0; index < 64; index++) {
			dSubset[sq][index] = 0;
			occ = index << 1;
			if ((sq & 7) != FILEh && (sq >> 3) != RANK8) {
				for (ts = sq + 9; ; ts += 9) {
					dSubset[sq][index] |= (1ull << ts);
					if (occ & (1ull << (ts & 7))) break;
					if ((ts & 7) == FILEh || (ts >> 3) == RANK8) break;
				}
			}
			if ((sq & 7) != FILEa && (sq >> 3) != RANK1) {
				for (ts = sq - 9; ; ts -= 9) {
					dSubset[sq][index] |= (1ull << ts);
					if (occ & (1ull << (ts & 7))) break;
					if ((ts & 7) == FILEa || (ts >> 3) == RANK1) break;
				}
			}
		}

		// anti diagonal indexes
		for (index = 0; index < 64; index++) {
			aSubset[sq][index] = 0;
			occ = index << 1;
			if ((sq & 7) != FILEa && (sq >> 3) != RANK8) {
				for (ts = sq + 7; ; ts += 7) {
					aSubset[sq][index] |= (1ull << ts);
					if (occ & (1ull << (ts & 7))) break;
					if ((ts & 7) == FILEa || (ts >> 3) == RANK8) break;
				}
			}
			if ((sq & 7) != FILEh && (sq >> 3) != RANK1) {
				for (ts = sq - 7; ; ts -= 7) {
					aSubset[sq][index] |= (1ull << ts);
					if (occ & (1ull << (ts & 7))) break;
					if ((ts & 7) == FILEh || (ts >> 3) == RANK1) break;
				}
			}
		}

		// horizontal lines
		for (ts = sq + 1, dx = x + 1; dx < FILEh; hMask[sq] |= 1ull << ts, ts += 1, dx++);
		for (ts = sq - 1, dx = x - 1; dx > FILEa; hMask[sq] |= 1ull << ts, ts -= 1, dx--);

		// vertical indexes
		for (index = 0; index < 64; index++) {
			vSubset[sq][index] = 0;
			uint64_t blockers = 0;
			for (int i = 0; i <= 5; i++) {
				if (index & (1ull << i)) {
					blockers |= (1ull << (((5 - i) << 3) + 8));
				}
			}
			if ((sq >> 3) != RANK8) {
				for (ts = sq + 8; ; ts += 8) {
					vSubset[sq][index] |= (1ull << ts);
					if (blockers & (1ull << (ts - (ts & 7)))) break;
					if ((ts >> 3) == RANK8) break;
				}
			}
			if ((sq >> 3) != RANK1) {
				for (ts = sq - 8; ; ts -= 8) {
					vSubset[sq][index] |= (1ull << ts);
					if (blockers & (1ull << (ts - (ts & 7)))) break;
					if ((ts >> 3) == RANK1) break;
				}
			}
		}

		// horizontal indexes
		for (index = 0; index < 64; index++) {
			hSubset[sq][index] = 0;
			occ = index << 1;
			if ((sq & 7) != FILEh) {
				for (ts = sq + 1; ; ts += 1) {
					hSubset[sq][index] |= (1ull << ts);
					if (occ & (1ull << (ts & 7))) break;
					if ((ts & 7) == FILEh) break;
				}
			}
			if ((sq & 7) != FILEa) {
				for (ts = sq - 1; ; ts -= 1) {
					hSubset[sq][index] |= (1ull << ts);
					if (occ & (1ull << (ts & 7))) break;
					if ((ts & 7) == FILEa) break;
				}
			}
		}
	}

	static void Init()
	{
		for (int i = 0; i < 64; i++) {
			InitSquare(i);
		}
	}

	static uint64_t Bishop(int sq, uint64_t occ)
	{
		uint64_t dBlockers = occ & dMask[sq];
		uint64_t aBlockers = occ & aMask[sq];
		uint64_t dIndex = ((dBlockers * 0x0202020202020202ull) >> 58);
		uint64_t aIndex = ((aBlockers * 0x0202020202020202ull) >> 58);
		return (dSubset[sq][dIndex] | aSubset[sq][aIndex]) & ~(1ull << sq);
	}

	static uint64_t Rook(int sq, uint64_t occ)
	{
		uint64_t vBlockers = (occ >> (sq & 7)) & 0x0101010101010101ull;
		uint64_t hBlockers = occ & hMask[sq];
		uint64_t vIndex = ((vBlockers * 0x0080402010080400ull) >> 58);
		uint64_t hIndex = (hBlockers >> (((sq >> 3) << 3)) + 1);
		return (vSubset[sq][vIndex] | hSubset[sq][hIndex]) & ~(1ull << sq);
	}


	static uint64_t Queen(int sq, uint64_t occ)
	{
		return Rook(sq, occ) | Bishop(sq, occ);
	}
	
}