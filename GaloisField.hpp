/**
 * GaloisField.hpp
 *
 * Copyright © 2023 Daniel Inführ
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited.
 * For Questions and allowance to use this code contact under daniel.infuehr(@)live.de
 *
 * Maintained by Daniel Inführ, 2023
 *
 * @file GaloisField.hpp
 * @author Daniel Inführ
 * @copyright 2023
 * @section License
 */

 //The main idea of the _mm512_gf2p8affine_epi64_epi8 is that is a general 8x8 binary matrix multiply of each 64bit qword inside a 512bit lane.
 //This can be used to rotate bits like bitrotate which is 
 //https://builders.intel.com/docs/networkbuilders/galois-field-new-instructions-gfni-technology-guide.pdf

#pragma once
#include <cstdint>
#include <array>

//AVX512F_GFNI
namespace Chess_Lookup::GaloisField
{
	constexpr auto Size = 0;
	constexpr auto Limit = 4; //emulate AVX512 as 256 bit for perf reasons - and a single queen lookup. Set to 8 for full compatibility

	union qword
	{
		uint64_t value;
		uint8_t byte[8];
	};

	union __m512i {
		struct {
			qword qword[8];
		};

		uint64_t& operator[] (const int index) {
			return qword[index].value;
		}

		const uint64_t& operator[] (const int index) const {
			return qword[index].value;
		}
	};

	static constexpr int parity(uint8_t x) {
		int t = 0;
		for (int i = 0; i < 8; i++)
		{
			int bit = (x & (1 << i)) != 0;
			t = t ^ bit;
		}
		return t;
	}

	constexpr std::array<int, 256> parity_lu = []()
	{
		std::array<int, 256> val = {};
		for (unsigned int i = 0; i < 256; i++) {
			val[i] = parity(i);
		}
		return val;
	}();

	static uint8_t affine_byte(uint8_t qword[8], uint8_t byte) {
		uint8_t res = 0;
		res |= parity_lu[(qword[7 - 0] & byte)] << 0;
		res |= parity_lu[(qword[7 - 1] & byte)] << 1;
		res |= parity_lu[(qword[7 - 2] & byte)] << 2;
		res |= parity_lu[(qword[7 - 3] & byte)] << 3;
		res |= parity_lu[(qword[7 - 4] & byte)] << 4;
		res |= parity_lu[(qword[7 - 5] & byte)] << 5;
		res |= parity_lu[(qword[7 - 6] & byte)] << 6;
		res |= parity_lu[(qword[7 - 7] & byte)] << 7;
		return res;
	}

	static __m512i _mm512_set1_epi64(uint64_t broadcast) {
		__m512i res;
		for (int i = 0; i < 8; i++) {
			res.qword[i] = { broadcast };
		}
		return res;
	}

	//This is the main part of the algorithm: 8x8 matrix mulitplication via avx512. In this case reversing bits - but a real algeabraic solution might be possible.
	//A solution would be a matrix array that can solve all possible input configurations for a slider just by multiplication.
	static __m512i _mm512_gf2p8affine_epi64_epi8(__m512i x, __m512i A, uint8_t imm8) {
		__m512i res;
		for (int j = 0; j < Limit; j++) {
			res.qword[j].byte[0] = affine_byte(A.qword[j].byte, x.qword[j].byte[0]) ^ imm8;
			res.qword[j].byte[1] = affine_byte(A.qword[j].byte, x.qword[j].byte[1]) ^ imm8;
			res.qword[j].byte[2] = affine_byte(A.qword[j].byte, x.qword[j].byte[2]) ^ imm8;
			res.qword[j].byte[3] = affine_byte(A.qword[j].byte, x.qword[j].byte[3]) ^ imm8;
			res.qword[j].byte[4] = affine_byte(A.qword[j].byte, x.qword[j].byte[4]) ^ imm8;
			res.qword[j].byte[5] = affine_byte(A.qword[j].byte, x.qword[j].byte[5]) ^ imm8;
			res.qword[j].byte[6] = affine_byte(A.qword[j].byte, x.qword[j].byte[6]) ^ imm8;
			res.qword[j].byte[7] = affine_byte(A.qword[j].byte, x.qword[j].byte[7]) ^ imm8;
		}
		return res;
	}

	static __m512i reverse_1x8(__m512i input) {
		const __m512i select = _mm512_set1_epi64(0x8040201008040201);
		return _mm512_gf2p8affine_epi64_epi8(input, select, 0x00);
	}

	static uint64_t byteswap(uint64_t value)
	{
#ifdef __linux__ 
		#include <byteswap.h>
		return bswap_64(value);
#else
		return std::byteswap(value);
#endif
	}

	//TODO: Implement this with _mm512_shuffle_epi8
	//Reverses bits in all 64 bytes at once 
	static __m512i bit_reverse(__m512i input) {
		__m512i b = _mm512_gf2p8affine_epi64_epi8(input, _mm512_set1_epi64(0x8040201008040201), 0x00);

		if constexpr (Limit == 4) {
#ifdef __AVX2__
			__m256i mask = _mm256_set_epi8(8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7);
			_mm256_storeu_si256((__m256i*)b.qword, _mm256_shuffle_epi8(_mm256_loadu_si256((__m256i*)b.qword), mask));
			return b;
#elif
			return { byteswap(b.qword[0].value), byteswap(b.qword[1].value), byteswap(b.qword[2].value), byteswap(b.qword[3].value), 0ull, 0ull, 0ull, 0ull };
#endif 
		}
		return { byteswap(b.qword[0].value), byteswap(b.qword[1].value), byteswap(b.qword[2].value), byteswap(b.qword[3].value),
				 byteswap(b.qword[4].value), byteswap(b.qword[5].value), byteswap(b.qword[6].value), byteswap(b.qword[7].value) };
	}

	static __m512i operator& (const __m512i& a, const __m512i& b) {
		__m512i res;
		for (int i = 0; i < Limit; i++) {
			res[i] = a[i] & b[i];
		}
		return res;
	}

	static __m512i operator^ (const __m512i& a, const __m512i& b) {
		__m512i res;
		for (int i = 0; i < Limit; i++) {
			res[i] = a[i] ^ b[i];
		}
		return res;
	}

	static __m512i operator- (const __m512i& a, const __m512i& b) {
		__m512i res;
		for (int i = 0; i < Limit; i++) {
			res[i] = a[i] - b[i];
		}
		return res;
	}

	//ALL OF THE ABOVE CAN BECOME THIS:
	//https://godbolt.org/z/vYjaefEnP
	//PREPARATION FOR Actual AVX512 implementation. TODO: TEST
	//Use __AVX512BW__ + AVX512F
	// DEPENDENCIES
	//_mm512_gf2p8affine_epi64_epi8 
	/*
	static __m512i bit_reverse(__m512i input) {
		__m512i b = _mm512_gf2p8affine_epi64_epi8(input, _mm512_set1_epi64(0x8040201008040201), 0x00);

		return _mm512_shuffle_epi8(b, _mm512_set_epi8(
			7, 6, 5, 4, 3, 2, 1, 0,
			15, 14, 13, 12, 11, 10, 9, 8,
			7, 6, 5, 4, 3, 2, 1, 0,
			15, 14, 13, 12, 11, 10, 9, 8,
			7, 6, 5, 4, 3, 2, 1, 0,
			15, 14, 13, 12, 11, 10, 9, 8,
			7, 6, 5, 4, 3, 2, 1, 0,
			15, 14, 13, 12, 11, 10, 9, 8
		));
	}

	static __m512i operator& (const __m512i& a, const __m512i& b) {
		return _mm512_and_si512(a, b);
	}

	static __m512i operator^ (const __m512i& a, const __m512i& b) {
		return _mm512_xor_si512(a, b);
	}

	static __m512i operator- (const __m512i& a, const __m512i& b) {
		return _mm512_sub_epi64(a, b);
	}
	*/

	template<uint64_t bb>
	uint64_t mask_shift(int ranks) {
		return ranks > 0 ? bb >> (ranks << 3) : bb << -(ranks << 3);
	}

#	define dir_HO(X) (0xFFull << (X & 56))
#	define dir_VE(X) (0x0101010101010101ull << (X & 7))
#	define dir_D1(X) (mask_shift<0x8040201008040201ull>((X & 7) - (X >> 3)))
#	define dir_D2(X) (mask_shift<0x0102040810204080ull>(7 - (X & 7) - (X >> 3)))

	/* Generate attack using the hyperbola quintessence approach */
	//uint64_t attack(uint64_t pieces, uint32_t x, uint64_t mask) {
	//	uint64_t o = pieces & mask;
	//	return ((o - (1ull << x)) ^ bit_reverse(bit_reverse(o) - (1ull << (x ^ 63)))) & mask;
	//}

	//This can solve 8 rays, so all moves of two queens at once or 4 (rooks, bishops)
	static __m512i attack8(uint64_t occ, uint64_t x, __m512i mask) {
		__m512i o = _mm512_set1_epi64(occ) & mask;
		__m512i sq = _mm512_set1_epi64(1ull << x);
		__m512i sq_rev = _mm512_set1_epi64((1ull << (x ^ 63)));

		return ((o - sq) ^ bit_reverse(bit_reverse(o) - sq_rev)) & mask;
	}

	static uint64_t Queen(int sq, uint64_t occ) {
		//This mask can be improved, removal of source square is not needed when looking up by square.
		//Generally a permutation of queen, rook, bishop could be created at compiletime and used via template
		//OR a permutation could be looked up in a runtime mask array

		__m512i mask = { dir_HO(sq) ^ (1ull << sq) , dir_VE(sq) ^ (1ull << sq), dir_D1(sq) ^ (1ull << sq), dir_D2(sq) ^ (1ull << sq), 0ull, 0ull, 0ull, 0ull };
		mask = attack8(occ, sq, mask);
		return mask[0] | mask[1] | mask[2] | mask[3];
	}

#undef dir_HO
#undef dir_VE
#undef dir_D1
#undef dir_D2
}