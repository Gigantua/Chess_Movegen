#pragma once

// Robert Hyatt's and Michael Sherwin's classical bitboard approach
// generate moves for the sliding pieces.

#include <cstdint>
#include <bit>
#include <array>

namespace Chess_Lookup::BobLU {

	struct Rays {
		uint64_t rayNW;
		uint64_t rayNN;
		uint64_t rayNE;
		uint64_t rayEE;
		uint64_t raySE;
		uint64_t raySS;
		uint64_t raySW;
		uint64_t rayWW;
		uint64_t rwsNW;
		uint64_t rwsNN;
		uint64_t rwsNE;
		uint64_t rwsEE;
		uint64_t rwsSE;
		uint64_t rwsSS;
		uint64_t rwsSW;
		uint64_t rwsWW;
	};

	consteval std::array<Rays,64> Initialize() {
		enum { FILE1, FILE2, FILE3, FILE4, FILE5, FILE6, FILE7, FILE8 };
		enum { RANK1, RANK2, RANK3, RANK4, RANK5, RANK6, RANK7, RANK8 };

		int sq, ts, file, rank, c;
		std::array<Rays, 64> ray{};
		for (sq = 0; sq <= 63; sq++) {
			file = sq & 7;
			rank = sq >> 3;

			// Northwest
			ray[sq].rayNW = 0;
			for (c = 1, ts = sq + 7; file - c >= FILE1 && rank + c <= RANK8; c++, ts += 7) ray[sq].rayNW |= 1ull << ts;
			ray[sq].rwsNW = ray[sq].rayNW | 0x8000000000000000;

			// Northeast
			ray[sq].rayNE = 0;
			for (c = 1, ts = sq + 9; file + c <= FILE8 && rank + c <= RANK8; c++, ts += 9) ray[sq].rayNE |= 1ull << ts;
			ray[sq].rwsNE = ray[sq].rayNE | 0x8000000000000000;

			// Southeast
			ray[sq].raySE = 0;
			for (c = 1, ts = sq - 7; file + c <= FILE8 && rank - c >= RANK1; c++, ts -= 7) ray[sq].raySE |= 1ull << ts;
			ray[sq].rwsSE = ray[sq].raySE | 0x0000000000000001;

			// Southwest
			ray[sq].raySW = 0;
			for (c = 1, ts = sq - 9; file - c >= FILE1 && rank - c >= RANK1; c++, ts -= 9) ray[sq].raySW |= 1ull << ts;
			ray[sq].rwsSW = ray[sq].raySW | 0x0000000000000001;

			// North
			ray[sq].rayNN = 0;
			for (c = 1, ts = sq + 8; rank + c <= RANK8; c++, ts += 8) ray[sq].rayNN |= 1ull << ts;
			ray[sq].rwsNN = ray[sq].rayNN | 0x8000000000000000;

			// East
			ray[sq].rayEE = 0;
			for (c = 1, ts = sq + 1; file + c <= FILE8; c++, ts += 1) ray[sq].rayEE |= 1ull << ts;
			ray[sq].rwsEE = ray[sq].rayEE | 0x8000000000000000;

			// South
			ray[sq].raySS = 0;
			for (c = 1, ts = sq - 8; rank - c >= RANK1; c++, ts -= 8) ray[sq].raySS |= 1ull << ts;
			ray[sq].rwsSS = ray[sq].raySS | 0x0000000000000001;

			// West
			ray[sq].rayWW = 0;
			for (c = 1, ts = sq - 1; file - c >= FILE1; c++, ts -= 1) ray[sq].rayWW |= 1ull << ts;
			ray[sq].rwsWW = ray[sq].rayWW | 0x0000000000000001;
		}
		return ray;
	}
	constexpr std::array<Rays, 64> ray = Initialize();

	constexpr auto Size = sizeof(ray);


	static constexpr uint64_t Bishop(int sq, uint64_t occ) {
		uint64_t r2 = 0;
		occ |= 0x8000000000000001;

		r2 |= ray[sq].rayNW ^ ray[std::countr_zero(ray[sq].rwsNW & occ)].rayNW;
		r2 |= ray[sq].rayNE ^ ray[std::countr_zero(ray[sq].rwsNE & occ)].rayNE;

		r2 |= ray[sq].raySE ^ ray[63 - std::countl_zero(ray[sq].rwsSE & occ)].raySE;
		r2 |= ray[sq].raySW ^ ray[63 - std::countl_zero(ray[sq].rwsSW & occ)].raySW;

		return r2;
	}

	static constexpr uint64_t Rook(int sq, uint64_t occ) {
		uint64_t r1 = 0;
		occ |= 0x8000000000000001;

		r1 |= ray[sq].rayNN ^ ray[std::countr_zero(ray[sq].rwsNN & occ)].rayNN;
		r1 |= ray[sq].rayEE ^ ray[std::countr_zero(ray[sq].rwsEE & occ)].rayEE;

		r1 |= ray[sq].raySS ^ ray[63 - std::countl_zero(ray[sq].rwsSS & occ)].raySS;
		r1 |= ray[sq].rayWW ^ ray[63 - std::countl_zero(ray[sq].rwsWW & occ)].rayWW;

		return r1;
	}

	template<int sq>
	static constexpr uint64_t Bishop(uint64_t occ) {
		uint64_t r2 = 0;
		occ |= 0x8000000000000001;

		r2 |= ray[sq].rayNW ^ ray[std::countr_zero(ray[sq].rwsNW & occ)].rayNW;
		r2 |= ray[sq].rayNE ^ ray[std::countr_zero(ray[sq].rwsNE & occ)].rayNE;

		r2 |= ray[sq].raySE ^ ray[63 - std::countl_zero(ray[sq].rwsSE & occ)].raySE;
		r2 |= ray[sq].raySW ^ ray[63 - std::countl_zero(ray[sq].rwsSW & occ)].raySW;

		return r2;
	}

	template<int sq>
	static constexpr uint64_t Rook(uint64_t occ) {
		uint64_t r1 = 0;
		occ |= 0x8000000000000001;

		r1 |= ray[sq].rayNN ^ ray[std::countr_zero(ray[sq].rwsNN & occ)].rayNN;
		r1 |= ray[sq].rayEE ^ ray[std::countr_zero(ray[sq].rwsEE & occ)].rayEE;

		r1 |= ray[sq].raySS ^ ray[63 - std::countl_zero(ray[sq].rwsSS & occ)].raySS;
		r1 |= ray[sq].rayWW ^ ray[63 - std::countl_zero(ray[sq].rwsWW & occ)].rayWW;

		return r1;
	}

	static constexpr uint64_t Queen(int sq, uint64_t occ) {
		return Rook(sq, occ) | Bishop(sq, occ);
	}

	template<int sq>
	static constexpr uint64_t Queen(uint64_t occ) {
		return Rook<sq>(occ) | Bishop<sq>(occ);
	}
	
}