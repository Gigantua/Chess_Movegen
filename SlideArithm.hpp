#include <array>
#include <bit>
#include <cstdint>

namespace Chess_Lookup::SlideArithm
{
	consteval bool safe_coord(int f, int r)
	{
		return (0 <= f && f < 8) && (0 <= r && r < 8);
	}

	consteval uint64_t init_mask(int s, int df, int dr)
	{
		uint64_t b{}; int f{}, r{};
		f = s & 7; r = s >> 3;
		while (safe_coord(f += df, r += dr))
			b |= 1ull << (f + r * 8);

		return b;
	}

	consteval std::array<uint64_t, 256> init_array()
	{
		std::array<uint64_t, 256> a{}; int n{};
		for (int s = 0; s < 64; s++)
		{
			a[n++] = init_mask(s, 1, 0) | init_mask(s, -1, 0);
			a[n++] = init_mask(s, 0, 1) | init_mask(s, 0, -1);
			a[n++] = init_mask(s, 1, 1) | init_mask(s, -1, -1);
			a[n++] = init_mask(s, -1, 1) | init_mask(s, 1, -1);
		}
		return a;
	}
	static constexpr std::array<uint64_t, 256> rank_mask = init_array();
	constexpr auto Size = sizeof(rank_mask);

	/* Start of code */
	static const inline uint64_t slide_arithmetic(uint32_t p, uint64_t block) {
		//BZHI
		//[src & (1 << inx) - 1] ;
		// split the line into upper and lower rays
		uint64_t mask = _bzhi_u64(block, p);

		// for the bottom we use CLZ + a shift to fill in from the top
		uint64_t blocked_down = 0x7FFFFFFFFFFFFFFFull >> std::countl_zero(block & mask | 1ull);

		//_blsmsk_u64 = X^X-1
		// the intersection of the two is the move set after masking with the line
		return (_blsmsk_u64(block & ~mask) ^ blocked_down);
	}

	static const inline uint64_t Queen(uint32_t s, uint64_t occ)
	{
		const uint64_t* r = rank_mask.data() + 4 * s;
		return slide_arithmetic(s, r[0] & occ) & r[0]
			 ^ slide_arithmetic(s, r[1] & occ) & r[1]
			 ^ slide_arithmetic(s, r[2] & occ) & r[2]
			 ^ slide_arithmetic(s, r[3] & occ) & r[3];
	}
}