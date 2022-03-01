// Datum  : 10.02.2022
// Author : (c) Daniel Infuehr
// Content: AVX2 Branchless Fill Algorithm
// This header must be included without any change if you use parts of this code

#pragma once
#include <stdint.h>
#include <algorithm>

#ifdef __AVX2__
#	include <immintrin.h>
#endif

namespace Chess_Lookup::AVXShift
{
    static constexpr uint64_t BB_AF = 0x0101010101010101;
    static constexpr uint64_t BB_HF = 0x8080808080808080;
    static constexpr uint64_t BB_R1 = 0x00000000000000FF;
    static constexpr uint64_t BB_R8 = 0xFF00000000000000;

    static constexpr auto Size = 0; //Above will get inlined into code

#ifdef __AVX2__
    struct Vec4I {
        __m256i ymm;

        Vec4I()
        { } //Empty Constructor

        Vec4I(__m256i&& value) : ymm(value)
        {

        }

        Vec4I(uint64_t value) : ymm(_mm256_set1_epi64x(value))
        {
            
        }
        Vec4I(uint64_t a, uint64_t b, uint64_t c, uint64_t d) : ymm(_mm256_set_epi64x(a,b,c,d))
        {

        }

        inline Vec4I operator|(const Vec4I& rhs) const {
            return Vec4I(_mm256_or_si256(ymm, rhs.ymm));
        }

        inline Vec4I& operator|=(const Vec4I& rhs) {
            ymm = _mm256_or_si256(ymm, rhs.ymm);
            return *this;
        }

        inline Vec4I& operator&=(const Vec4I& rhs) {
            ymm = _mm256_and_si256(ymm, rhs.ymm);
            return *this;
        }

        inline Vec4I& operator<<=(const Vec4I& rhs) {
            ymm = _mm256_sllv_epi64(ymm, rhs.ymm);
            return *this;
        }

        inline Vec4I& operator>>=(const Vec4I& rhs) {
            ymm = _mm256_srlv_epi64(ymm, rhs.ymm); 
            return *this;
        }

        inline Vec4I& andNot(const Vec4I& rhs) {
            ymm = _mm256_andnot_si256(rhs.ymm, ymm); //andNot in intrisics = ~a & b. But andNot = a & ~b
            return *this;
        }

        inline void Store(void* ptr) {
            _mm256_storeu_epi64(ptr, ymm);
        }

        inline void Set(const Vec4I& rhs)
        {
            ymm = rhs.ymm;
        }

        inline void Set(uint64_t a, uint64_t b, uint64_t c, uint64_t d)
        {
            ymm = _mm256_set_epi64x(a, b, c, d);
        }
        inline void Set(uint64_t a)
        {
            ymm = _mm256_set1_epi64x(a);
        }

        inline void Zero() {
            ymm = _mm256_setzero_si256();
        }

        inline bool IsZero() const {
            return _mm256_testz_si256(ymm, ymm);
        }

        inline uint64_t horizontal_or() const {

            //Replace both _mm256_or_si256 by any operator to support other 64 bit horizontal reductions
            __m256i x1 = _mm256_or_si256(ymm, _mm256_permute2x128_si256(ymm, ymm, 1));
            __m256i x2 = _mm256_shuffle_epi32(x1, 0b01001110);
            __m256i x3 = _mm256_or_si256(x1, x2);
            return _mm256_extract_epi64(x3, 0); //_mm_cvtsi128_si64x(_mm256_castsi256_si128(x3));

           // Same performance - scalar OR
           //const __m128i temp = _mm256_extracti128_si256(ymm, 1);
           //return (uint64_t&)ymm
           //    | (uint64_t)(_mm_extract_epi64(_mm256_castsi256_si128(ymm), 1))
           //    | (uint64_t&)(temp)
           //    | (uint64_t)(_mm_extract_epi64(temp, 1));
        }
    };
#endif

    static constexpr uint64_t Bishop(int s, uint64_t o)
    {
        uint64_t tmp, att = 0;
        o &= ~(1ull << s);
        tmp = 1ull << s; while ((tmp & (o | BB_HF | BB_R8)) == 0) { att |= tmp <<= 9; }
        tmp = 1ull << s; while ((tmp & (o | BB_AF | BB_R8)) == 0) { att |= tmp <<= 7; }
        tmp = 1ull << s; while ((tmp & (o | BB_AF | BB_R1)) == 0) { att |= tmp >>= 9; }
        tmp = 1ull << s; while ((tmp & (o | BB_HF | BB_R1)) == 0) { att |= tmp >>= 7; }
        return att;
    }

    static constexpr uint64_t Rook(int s, uint64_t o)
    {
        uint64_t tmp, att = 0;
        o &= ~(1ull << s);
        tmp = 1ull << s; while ((tmp & (o | BB_HF)) == 0) { att |= tmp <<= 1; }
        tmp = 1ull << s; while ((tmp & (o | BB_AF)) == 0) { att |= tmp >>= 1; }
        tmp = 1ull << s; while ((tmp & (o | BB_R8)) == 0) { att |= tmp <<= 8; }
        tmp = 1ull << s; while ((tmp & (o | BB_R1)) == 0) { att |= tmp >>= 8; }
        return att;
    }

    static inline uint64_t Queen(const int s, uint64_t o)
    {
#ifndef __AVX2__
        return Rook(s, o) | Bishop(s, o);
#else
        //This is branchless improvement of 'NO HEADACHES' algorithm code. (no stop condition. Expand 7 times) 
        //Trying to stop early by !_mm256_testz_si256(tmp.ymm, tmp.ymm) halves performance!

        //That being said - this is generally a bad idea since other AVX algorithms like dumb7fill can calculate 4 sliders in parallel. 
        //This still calculates only one slider. 

        //4x faster avx version:
        const Vec4I shift = Vec4I(9, 7, 1, 8);
        const Vec4I Occ = Vec4I(o).andNot(1ull << s);
        Vec4I A, tmp, att;
        att.Zero();
        
        //Same code repeated 7x per 4 rays: 
        //att.ymm = _mm256_or_si256(att.ymm, tmp.ymm = _mm256_sllv_epi64(_mm256_andnot_si256(A.ymm, tmp.ymm), shift.ymm));

        A = (Occ | Vec4I(BB_HF | BB_R8, BB_AF | BB_R8, BB_HF, BB_R8));
        tmp = (1ull << s);
        tmp.andNot(A); att |= tmp <<= shift;
        tmp.andNot(A); att |= tmp <<= shift;
        tmp.andNot(A); att |= tmp <<= shift;
        tmp.andNot(A); att |= tmp <<= shift;
        tmp.andNot(A); att |= tmp <<= shift;
        tmp.andNot(A); att |= tmp <<= shift;
        tmp.andNot(A); att |= tmp <<= shift;

        A = (Occ | Vec4I(BB_AF | BB_R1, BB_HF | BB_R1, BB_AF, BB_R1));
        tmp = (1ull << s);
        tmp.andNot(A); att |= tmp >>= shift;
        tmp.andNot(A); att |= tmp >>= shift;
        tmp.andNot(A); att |= tmp >>= shift;
        tmp.andNot(A); att |= tmp >>= shift;
        tmp.andNot(A); att |= tmp >>= shift;
        tmp.andNot(A); att |= tmp >>= shift;
        tmp.andNot(A); att |= tmp >>= shift;

        return att.horizontal_or();
#endif
    }
}
