//(c) Gerd Isenberg, Aleks Peshkov 2007
//Subtracting a Rook from a Blocking Piece - https://www.chessprogramming.org/Subtracting_a_Rook_from_a_Blocking_Piece

#include <stdint.h>
#include <array>
#include <type_traits>

namespace Chess_Lookup::HyperbolaQscInline {
	template<uint64_t bb>
	static constexpr uint64_t mask_shift(int ranks) {
		return ranks > 0 ? bb >> (ranks << 3) : bb << -(ranks << 3);
	}
	template<int dir>
	static constexpr uint64_t dirMask(int square) {
		int rank = square >> 3;
		int file = square & 7;

		if constexpr (dir == 0)
			return 0xFFull << (square & 56); //HORIZONTAL
		else if constexpr (dir == 1)
			return 0x0101010101010101ull << (square & 7); //VERTICAL
		else if constexpr (dir == 2)
			return mask_shift<0x8040201008040201ull>(file - rank); //Diagonal
		else {
			return mask_shift<0x0102040810204080ull>(7 - file - rank); //Antidiagonal
		}
	}
	template<int dir, int square>
	static consteval uint64_t dirMask() {
		int rank = square >> 3;
		int file = square & 7;

		if constexpr (dir == 0)
			return 0xFFull << (square & 56); //HORIZONTAL
		else if constexpr (dir == 1)
			return 0x0101010101010101ull << (square & 7); //VERTICAL
		else if constexpr (dir == 2)
			return mask_shift<0x8040201008040201ull>(file - rank); //Diagonal
		else {
			return mask_shift<0x0102040810204080ull>(7 - file - rank); //Antidiagonal
		}
	}

	static constexpr auto Size = 0;

	static constexpr uint64_t bit_bswap_constexpr(uint64_t b) {
		b = ((b >> 8) & 0x00FF00FF00FF00FFULL) | ((b << 8) & 0xFF00FF00FF00FF00ULL);
		b = ((b >> 16) & 0x0000FFFF0000FFFFULL) | ((b << 16) & 0xFFFF0000FFFF0000ULL);
		b = ((b >> 32) & 0x00000000FFFFFFFFULL) | ((b << 32) & 0xFFFFFFFF00000000ULL);
		return b;
	}

	static constexpr uint64_t bit_bswap(uint64_t b) {
		if (std::is_constant_evaluated()) { return bit_bswap_constexpr(b); }
#if defined(_MSC_VER)
		return _byteswap_uint64(b);
#elif defined(__GNUC__)
		return __builtin_bswap64(b);
#else
		return bit_bswap_constexpr(b);
#endif
	}

	/* Generate attack using the hyperbola quintessence approach */
	static constexpr uint64_t attack(uint64_t pieces, uint32_t x, uint64_t mask) {
		uint64_t o = pieces & mask;

		return ((o - (1ull << x)) ^ bit_bswap(bit_bswap(o) - (1ull << (x ^ 56)))) & mask;
	}

	static constexpr uint64_t ShiftLeft(uint64_t b) { return (b << 1) & 0xfefefefefefefefeull; }
	static constexpr uint64_t ShiftRight(uint64_t b) { return (b >> 1) & 0x7f7f7f7f7f7f7f7full; }

	
	template<int sq>
	static constexpr uint64_t horizontal_atkL(uint64_t notOcc) {
		uint64_t sqMsk = 1ull << sq;
		notOcc &= 0xfefefefefefefefeull;
		sqMsk |= notOcc & (sqMsk << 1);
		notOcc &= (notOcc << 1);
		sqMsk |= notOcc & (sqMsk << 2);
		notOcc &= (notOcc << 2);
		return ShiftLeft(sqMsk | notOcc & (sqMsk << 4));
	}

	template<int sq>
	static constexpr uint64_t horizontal_atkR(uint64_t notOcc) {
		uint64_t sqMsk = 1ull << sq;
		notOcc &= 0x7f7f7f7f7f7f7f7full;
		sqMsk |= notOcc & (sqMsk >> 1);
		notOcc &= (notOcc >> 1);
		sqMsk |= notOcc & (sqMsk >> 2);
		notOcc &= (notOcc >> 2);
		return ShiftRight(sqMsk | notOcc & (sqMsk >> 4));
	}

	static constexpr uint64_t horizontal_atkL(uint64_t notOcc, uint64_t sqMsk) {
		notOcc &= 0xfefefefefefefefeull;
		sqMsk |= notOcc & (sqMsk << 1);
		notOcc &= (notOcc << 1);
		sqMsk |= notOcc & (sqMsk << 2);
		notOcc &= (notOcc << 2);
		return ShiftLeft(sqMsk | notOcc & (sqMsk << 4));
	}

	static constexpr uint64_t horizontal_atkR(uint64_t notOcc, uint64_t sqMsk) {
		notOcc &= 0x7f7f7f7f7f7f7f7full;
		sqMsk |= notOcc & (sqMsk >> 1);
		notOcc &= (notOcc >> 1);
		sqMsk |= notOcc & (sqMsk >> 2);
		notOcc &= (notOcc >> 2);
		return ShiftRight(sqMsk | notOcc & (sqMsk >> 4));
	}

	static constexpr uint64_t vertical_attack(uint64_t occ, uint32_t sq) {
		return attack(occ, sq, dirMask<1>(sq) ^ (1ull << sq));
	}

	static constexpr uint64_t diagonal_attack(uint64_t occ, uint32_t sq) {
		return attack(occ, sq, dirMask<2>(sq) ^ (1ull << sq));
	}

	static constexpr uint64_t antidiagonal_attack(uint64_t occ, uint32_t sq) {
		return attack(occ, sq, dirMask<3>(sq) ^ (1ull << sq));
	}

	static constexpr uint64_t bishop_attack(int sq, uint64_t occ) {
		return diagonal_attack(occ, sq) | antidiagonal_attack(occ, sq);
	}

	static constexpr uint64_t rook_attack(int sq, uint64_t occ) {
		return vertical_attack(occ, sq) | horizontal_atkL(~occ, 1ull << sq) | horizontal_atkR(~occ, 1ull << sq);
	}

	static constexpr uint64_t Queen(int sq, uint64_t occ) {
		return bishop_attack(sq, occ) | rook_attack(sq, occ);
	}


	template<uint32_t sq>
	static constexpr uint64_t vertical_attack(uint64_t occ) {
		return attack(occ, sq, dirMask<1, sq>() ^ (1ull << sq));
	}

	template<uint32_t sq>
	static constexpr uint64_t diagonal_attack(uint64_t occ) {
		return attack(occ, sq, dirMask<2, sq>() ^ (1ull << sq));
	}

	template<uint32_t sq>
	static constexpr uint64_t antidiagonal_attack(uint64_t occ) {
		return attack(occ, sq, dirMask<3, sq>() ^ (1ull << sq));
	}

	template<uint32_t sq>
	static constexpr uint64_t bishop_attack(uint64_t occ) {
		return diagonal_attack<sq>(occ) | antidiagonal_attack<sq>(occ);
	}

	template<uint32_t sq>
	static constexpr uint64_t rook_attack(uint64_t occ) {
		return vertical_attack<sq>(occ) | horizontal_atkL<sq>(~occ) | horizontal_atkR<sq>(~occ);
	}

	template<uint32_t sq>
	static constexpr uint64_t Queen(uint64_t occ) {
		return bishop_attack<sq>(occ) | rook_attack<sq>(occ);
	}
}