#pragma once
// Datum  : 2022-01-25
// Author : Tsoj
// Content: [Old C++ implementation](https://gitlab.com/tsoj/Googleplex_Starthinker/-/blob/master/src/bitboard.hpp)
//          of a sliding piece algorithm that today is used by
//          [Nalwald](https://gitlab.com/tsoj/Nalwald/-/blob/master/bitboard.nim).
#include <stdint.h>
#include <bit>
#include <array>
#include <stddef.h>

namespace Chess_Lookup::Kindergarten
{
    constexpr uint64_t main_diagonal = 0b1000000001000000001000000001000000001000000001000000001000000001; // A1 to H8
    constexpr uint64_t first_file = 0b0000000100000001000000010000000100000001000000010000000100000001;

    uint64_t occ_for_square(const uint8_t hash_key, const int square, const std::array<int, 2> dirs, std::function<uint8_t(int, uint64_t)> hash_key_fn)
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

    template<typename F>
    auto for_64(F f)
    {
        std::array<decltype(f(0)), 64> result;
        for (int square = 0; square < 64; square++)
        {
            result[square] = f(square);
        }
        return result;
    }

    const std::array<uint64_t, 64> diagonals_64 = for_64([](int i){
        return occ_for_square(0, i, {9, -9}, [](auto s, auto occ){ return 0; });
    });

    const std::array<uint64_t, 64> anti_diagonals_64 = for_64([](int i){
        return occ_for_square(0, i, {7, -7}, [](auto s, auto occ){ return 0; });
    });

    constexpr inline uint8_t hashkey_rank(const int square, const uint64_t occupancy)
    {
        return ((occupancy >> ((square / 8) * 8)) >> 1) & 0b111111U;
    }
    constexpr inline uint8_t hashkey_file(const int square, const uint64_t occupancy)
    {
        return (((((occupancy >> (square % 8)) & first_file) * main_diagonal) >> 56) >> 1) & 0b111111U;
    }
    constexpr inline uint8_t hashkey_diagonal(const int square, const uint64_t occupancy)
    {
        return ((((occupancy & diagonals_64[square]) * first_file) >> 56) >> 1) & 0b111111U;
    }
    constexpr inline uint8_t hashkey_anti_diagonal(const int square, const uint64_t occupancy)
    {
        return ((((occupancy & anti_diagonals_64[square]) * first_file) >> 56) >> 1) & 0b111111U;
    }

    std::array<std::array<uint64_t, 64>, 64> attack_table(const std::array<int, 2> dirs, std::function<uint8_t(int, uint64_t)> hash_key_fn)
    {
        return for_64([&](int square){
            return for_64([&](int hash_key){
                return occ_for_square(hash_key, square, dirs, hash_key_fn);
            });
        });
    }

    const std::array<std::array<uint64_t, 64>, 64> rank_attack_table = attack_table({-1, 1}, hashkey_rank);
    const std::array<std::array<uint64_t, 64>, 64> file_attack_table = attack_table({-8, 8}, hashkey_file);
    const std::array<std::array<uint64_t, 64>, 64> diagonal_attack_table = attack_table({-9, 9}, hashkey_diagonal);
    const std::array<std::array<uint64_t, 64>, 64> anti_diagonal_attack_table = attack_table({-7, 7}, hashkey_anti_diagonal);

    static constexpr auto Size =
        sizeof(anti_diagonal_attack_table) +
        sizeof(diagonal_attack_table) +
        sizeof(file_attack_table) +
        sizeof(rank_attack_table) +
        sizeof(anti_diagonals_64) +
        sizeof(diagonals_64);

    // return the uint64 with the rook targets
    static uint64_t Rook(int square, uint64_t occupation)
    {
        return rank_attack_table[square][hashkey_rank(square, occupation)] |
               file_attack_table[square][hashkey_file(square, occupation)];
    }

    // return the uint64 with the bishops targets
    static uint64_t Bishop(int square, uint64_t occupation)
    {
        return anti_diagonal_attack_table[square][hashkey_anti_diagonal(square, occupation)] |
               diagonal_attack_table[square][hashkey_diagonal(square, occupation)];
    }

    static uint64_t Queen(int square, uint64_t occupation)
    {
        return Rook(square, occupation) | Bishop(square, occupation);
    }
}