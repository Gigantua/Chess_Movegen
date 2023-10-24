#pragma once
// Datum  : 2023-10-24
// Author : Tsoj
// Content: Pre-school bitboards, like kindergarten bitboards but unified rank+file and diag+anti-diag tables respectively.
#include <stdint.h>
#include <bit>
#include <array>
#include <stddef.h>

namespace Chess_Lookup::PreSchool
{
    constexpr uint64_t main_diagonal = 0b1000000001000000001000000001000000001000000001000000001000000001; // A1 to H8
    constexpr uint64_t first_file = 0b0000000100000001000000010000000100000001000000010000000100000001;

    template<size_t N>
    uint64_t occ_for_square(const uint16_t hash_key, const int square, const std::array<int, N> dirs, std::function<uint16_t(int, uint64_t)> hash_key_fn)
    {
        uint64_t result = 0;
        for (const int dir : dirs)
        {
            int cur = square;
            while (true)
            {
                cur += dir;
                if (cur >= 64 || cur < 0 || abs((cur % 8) - ((cur - dir) % 8)) >= 2)
                {
                    break;
                }
                const uint64_t bit = 1ULL << cur;
                result |= bit;

                if (hash_key_fn(square, bit) & hash_key)
                {
                    break;
                }
            }
        }
        return result;
    }

    template<size_t N>
    auto collect_n(auto f)
    {
        std::array<decltype(f(0)), N> result;
        for (int i = 0; i < N; i++)
        {
            result[i] = f(i);
        }
        return result;
    }

    const std::array<uint64_t, 64> diagonals_64 = collect_n<64>([](int i){
        return occ_for_square(0, i, std::array{9, -9}, [](auto s, auto occ){ return 0; });
    });

    const std::array<uint64_t, 64> anti_diagonals_64 = collect_n<64>([](int i){
        return occ_for_square(0, i, std::array{7, -7}, [](auto s, auto occ){ return 0; });
    });

    constexpr inline uint16_t hashkey_fr(const int square, const uint64_t occupancy)
    {
        return 
        ((((((occupancy >> (square % 8)) & first_file) * main_diagonal) >> 50) >> 1) & 0b111111000000U) |
        (((occupancy >> ((square / 8) * 8)) >> 1) & 0b111111U);
    }
    constexpr inline uint16_t hashkey_d(const int square, const uint64_t occupancy)
    {
        return
        (((((occupancy & anti_diagonals_64[square]) * first_file) >> 50) >> 1) & 0b111111000000U) |
        (((((occupancy & diagonals_64[square]) * first_file) >> 56) >> 1) & 0b111111U);
    }

    std::array<std::array<uint64_t, 4096>, 64> attack_table(const std::array<int, 4> dirs, std::function<uint16_t(int, uint64_t)> hash_key_fn)
    {
        return collect_n<64>([&](int square){
            return collect_n<4096>([&](int hash_key){
                return occ_for_square(hash_key, square, dirs, hash_key_fn);
            });
        });
    }

    const std::array<std::array<uint64_t, 4096>, 64> fr_attack_table = attack_table({-1, 1, 8, -8}, hashkey_fr);
    const std::array<std::array<uint64_t, 4096>, 64> d_attack_table = attack_table({-7, 7, 9, -9}, hashkey_d);

    static constexpr auto Size =
        sizeof(fr_attack_table) +
        sizeof(d_attack_table) +
        sizeof(anti_diagonals_64) +
        sizeof(diagonals_64);

    // return the uint64 with the rook targets
    static uint64_t Rook(int square, uint64_t occupation)
    {
        return fr_attack_table[square][hashkey_fr(square, occupation)];
    }

    // return the uint64 with the bishops targets
    static uint64_t Bishop(int square, uint64_t occupation)
    {
        return d_attack_table[square][hashkey_d(square, occupation)];
    }

    static uint64_t Queen(int square, uint64_t occupation)
    {
        return Rook(square, occupation) | Bishop(square, occupation);
    }
}