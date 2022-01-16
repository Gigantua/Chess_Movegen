#include <array>
#include <bit>
#include <cstdint>
#ifdef __AVX2__
#include <immintrin.h>
#endif

namespace Chess_Lookup::SlideArithmInline
{
	#define FileOf(S) ((S) & 7)
	template<int dir>
	static constexpr uint64_t dirMask(int sq)
	{
		uint64_t C;
		if constexpr (dir == 0) {
			uint64_t C = 0xFFull;
			return (C << (sq & 56)) & ~(1ull << sq);
		}
		else if constexpr (dir == 1) {
			uint64_t C = 0x0101010101010101ull;
			return (C << FileOf(sq)) & ~(1ull << sq);
		}
		else if constexpr (dir == 2) {
			uint64_t C = 0x8040201008040201ull;
			int d = 8 * FileOf(sq) - (sq & 56);
			int n = -d & (d >> 31);
			int s = d & (-d >> 31);
			return ((C >> s) << n) & ~(1ull << sq);
		}
		else if constexpr (dir == 3) {
			uint64_t C = 0x0102040810204080ull;
			int d = 56 - 8 * FileOf(sq) - (sq & 56);
			int n = -d & (d >> 31);
			int s = d & (-d >> 31);
			return ((C >> s) << n) & ~(1ull << sq);
		}
	}
	constexpr auto Size = 0;

	static uint64_t bzhi(uint64_t src, int idx) {
#ifdef __AVX2__
		return _bzhi_u64(src, idx);
#endif
		return src & (1 << idx) - 1;
	}

	static uint64_t blsmsk(uint64_t x) {
#ifdef __AVX2__
		return _blsmsk_u64(x);
#endif
		return x ^ (x - 1);
	}

	/* Start of code */
	static const inline uint64_t slide_arithmetic(uint32_t p, uint64_t block) {
		//BZHI
		//[src & (1 << inx) - 1] ;
		// split the line into upper and lower rays
		uint64_t mask = bzhi(block, p);

		// for the bottom we use CLZ + a shift to fill in from the top
		uint64_t blocked_down = 0x7FFFFFFFFFFFFFFFull >> std::countl_zero(block & mask | 1ull);

		//_blsmsk_u64 = X^X-1
		// the intersection of the two is the move set after masking with the line
		return (blsmsk(block & ~mask) ^ blocked_down);
	}

	static const inline uint64_t Queen(uint32_t s, uint64_t occ)
	{
		const uint64_t h = dirMask<0>(s);
		const uint64_t v = dirMask<1>(s);
		const uint64_t d1 = dirMask<2>(s);
		const uint64_t d2 = dirMask<3>(s);
		return slide_arithmetic(s, h & occ) & h
			 ^ slide_arithmetic(s, v & occ) & v
			 ^ slide_arithmetic(s, d1 & occ) & d1
			 ^ slide_arithmetic(s, d2 & occ) & d2;
	}
}