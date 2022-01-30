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
    constexpr std::array<uint64_t, 64> ranks_64 = []()
    {
        uint64_t ranks[8] = {};
        for (uint64_t i = 0; i < 8; i++)
        {
            ranks[i] = (uint64_t)(0b11111111) << (i * 8);
        }
        std::array<uint64_t, 64> ranks_64_ret = {};
        for (uint64_t i = 0; i < 64; i++)
        {
            ranks_64_ret[i] = ranks[i / 8];
        }
        return ranks_64_ret;
    }();
    constexpr std::array<uint64_t, 64> files_64 = []()
    {
        uint64_t files[8] = {};
        for (uint64_t i = 0; i < 8; i++)
        {
            files[i] = (uint64_t)(0b0000000100000001000000010000000100000001000000010000000100000001) << i;
        }
        std::array<uint64_t, 64> files_64_ret = {};
        for (uint64_t i = 0; i < 64; i++)
        {
            files_64_ret[i] = files[i % 8];
        }
        return files_64_ret;
    }();
    constexpr uint64_t upper_left_side_zero = 0b1000000011000000111000001111000011111000111111001111111011111111;
    constexpr uint64_t lower_right_side_zero = 0b1111111101111111001111110001111100001111000001110000001100000001;
    constexpr uint64_t lower_left_side_zero = 0b1111111011111100111110001111000011100000110000001000000000000000;
    constexpr uint64_t upper_right_side_zero = 0b0000000000000001000000110000011100001111000111110011111101111111;
    constexpr uint64_t main_diagonal = 0b1000000001000000001000000001000000001000000001000000001000000001; //A1 to H8
    constexpr uint64_t anti_diagonal = 0b0000000100000010000001000000100000010000001000000100000010000000; //H1 to A8
    constexpr std::array<uint64_t, 64> diagonals_64 = []()
    {
        std::array<uint64_t, 64> diagonals_64_ret = {};
        for (uint64_t i = 0; i < 8; i++)
        {
            uint64_t current_diagonal = (main_diagonal << i) & upper_left_side_zero;
            uint64_t tmp = current_diagonal;
            while (tmp != 0)
            {
                uint64_t index = std::countr_zero(tmp);
                diagonals_64_ret[index] = current_diagonal;
                tmp = tmp & (~(1ull << index));
            }
        }
        for (uint64_t i = 1; i < 8; i++)
        {
            uint64_t current_diagonal = (main_diagonal >> i) & lower_right_side_zero;
            uint64_t tmp = current_diagonal;
            while (tmp != 0)
            {
                uint64_t index = std::countr_zero(tmp);
                diagonals_64_ret[index] = current_diagonal;
                tmp = tmp & ~(1ull << index);
            }
        }
        return diagonals_64_ret;
    }();
    constexpr std::array<uint64_t, 64> anti_diagonals_64 = []()
    {
        std::array<uint64_t, 64> anti_diagonals_64_ret = {};
        for (int i = 1; i < 8; i++)
        {
            uint64_t current_anti_diagonal = (anti_diagonal << i) & lower_left_side_zero;
            uint64_t tmp = current_anti_diagonal;
            while (tmp != 0)
            {
                uint64_t index = std::countr_zero(tmp);
                anti_diagonals_64_ret[index] = current_anti_diagonal;
                tmp = tmp & ~(1ull << index);
            }
        }
        {
            uint64_t current_anti_diagonal = anti_diagonal;
            uint64_t tmp = current_anti_diagonal;
            while (tmp != 0)
            {
                uint64_t index = std::countr_zero(tmp);
                anti_diagonals_64_ret[index] = current_anti_diagonal;
                tmp = tmp & ~(1ull << index);
            }
        }
        for (int i = 1; i < 8; i++)
        {
            uint64_t current_anti_diagonal = (anti_diagonal >> i) & upper_right_side_zero;
            uint64_t tmp = current_anti_diagonal;
            while (tmp != 0)
            {
                uint64_t index = std::countr_zero(tmp);
                anti_diagonals_64_ret[index] = current_anti_diagonal;
                tmp = tmp & ~(1ull << index);
            }
        }
        return anti_diagonals_64_ret;
    }();

    constexpr inline uint8_t hashkeyRank(const int& square, const uint64_t& occupancy)
    {
        return ((occupancy >> ((square / 8) * 8)) >> 1) & 0b111111U;
    }
    constexpr inline uint8_t hashkeyFile(const int& square, const uint64_t& occupancy)
    {
        return (((((occupancy >> (square % 8)) & files_64[0]) * main_diagonal) >> 56) >> 1) & 0b111111U;
    }
    constexpr inline uint8_t hashkeyDiagonal(const int& square, const uint64_t& occupancy)
    {
        return ((((occupancy & diagonals_64[square]) * files_64[0]) >> 56) >> 1) & 0b111111U;
    }
    constexpr inline uint8_t hashkeyAntiDiagonal(const int& square, const uint64_t& occupancy)
    {
        return ((((occupancy & anti_diagonals_64[square]) * files_64[0]) >> 56) >> 1) & 0b111111U;
    }

    constexpr uint64_t north = 8;
    constexpr uint64_t south = -8;
    constexpr uint64_t east = 1;
    constexpr uint64_t west = -1;
    constexpr uint64_t north_east = 9;
    constexpr uint64_t north_west = 7;
    constexpr uint64_t south_west = -9;
    constexpr uint64_t south_east = -7;
    constexpr std::array<uint64_t, 64> possible_ranks = []()
    {
        std::array<uint64_t, 64> possible_ranks_ret = {};
        for (uint64_t i = 0; i < 64; i++)
        {
            uint64_t tmp = (uint64_t)(0b10000001) | (((uint64_t)(i)) << 1);
            for (int j = 0; j < 8; j++)
            {
                possible_ranks_ret[i] |= tmp << (j * 8);
            }
        }
        return possible_ranks_ret;
    }();
    constexpr std::array<uint64_t, 64> possible_files = []()
    {
        std::array<uint64_t, 64> possible_files_ret = {};
        for (uint64_t i = 0; i < 64; i++)
        {
            auto rankToFile = [&](uint64_t rank)
            {
                return (((rank & 0b11111111U) * main_diagonal) & files_64[7]) >> 7;
            };
            uint64_t tmp = rankToFile((uint64_t)(0b10000001) | (((uint64_t)(i)) << 1));
            for (int j = 0; j < 8; j++)
            {
                possible_files_ret[i] |= tmp << j;
            }
        }
        return possible_files_ret;
    }();
    constexpr std::array<std::array<uint64_t, 64>, 64> rank_attack_table = []()
    {
        std::array<std::array<uint64_t, 64>, 64> rank_attack_table_ret = {};
        for (int index = 0; index < 64; index++)
        {
            for (uint64_t possible_ranks_index = 0; possible_ranks_index < 64; possible_ranks_index++)
            {
                uint64_t tmp_attack_mask = 0;
                uint64_t occupancy = possible_ranks[possible_ranks_index];
                uint64_t i = index;
                while (true)
                {
                    i += east;
                    if (i >= 64)
                    {
                        break;
                    }
                    if (index % 8 == 7)
                    {
                        break;
                    }
                    if ((occupancy & (1ull << i)) != 0)
                    {
                        tmp_attack_mask |= (1ull << i);
                        break;
                    }
                    else
                    {
                        tmp_attack_mask |= (1ull << i);
                    }
                }
                i = index;
                while (true)
                {
                    i += west;
                    if (i >= 64) //equals i < 0)
                    {
                        break;
                    }
                    if (index % 8 == 0)
                    {
                        break;
                    }
                    if ((occupancy & (1ull << i)) != 0)
                    {
                        tmp_attack_mask |= (1ull << i);
                        break;
                    }
                    else
                    {
                        tmp_attack_mask |= (1ull << i);
                    }
                }
                rank_attack_table_ret[index][hashkeyRank(index, occupancy)] = tmp_attack_mask;
            }
        }
        return rank_attack_table_ret;
    }();
    constexpr std::array<std::array<uint64_t, 64>, 64> file_attack_table = []()
    {
        std::array<std::array<uint64_t, 64>, 64> file_attack_table_ret = {};
        for (int index = 0; index < 64; index++)
        {
            for (uint64_t possible_files_index = 0; possible_files_index < 64; possible_files_index++)
            {
                uint64_t tmp_attack_mask = 0;
                uint64_t occupancy = possible_files[possible_files_index];
                uint64_t i = index;
                while (true)
                {
                    i += north;
                    if (i >= 64)
                    {
                        break;
                    }
                    if ((occupancy & (1ull << i)) != 0)
                    {
                        tmp_attack_mask |= (1ull << i);
                        break;
                    }
                    else
                    {
                        tmp_attack_mask |= (1ull << i);
                    }
                }
                i = index;
                while (true)
                {
                    i += south;
                    if (i >= 64/*equals i < 0*/)
                    {
                        break;
                    }
                    if ((occupancy & (1ull << i)) != 0)
                    {
                        tmp_attack_mask |= (1ull << i);
                        break;
                    }
                    else
                    {
                        tmp_attack_mask |= (1ull << i);
                    }
                }
                file_attack_table_ret[index][hashkeyFile(index, occupancy)] = tmp_attack_mask;
            }
        }
        return file_attack_table_ret;
    }();
    constexpr std::array<std::array<uint64_t, 64>, 64> diagonal_attack_table = []()
    {
        std::array<std::array<uint64_t, 64>, 64> diagonal_attack_table_ret = {};
        for (int index = 0; index < 64; index++)
        {
            for (uint64_t possible_ranks_index = 0; possible_ranks_index < 64; possible_ranks_index++)
            {
                uint64_t tmp_attack_mask = 0;
                uint64_t occupancy = possible_ranks[possible_ranks_index];
                uint64_t i = index;
                while (true)
                {
                    i += north_east;
                    if (i >= 64)
                    {
                        break;
                    }
                    if (index % 8 == 7)
                    {
                        break;
                    }
                    if ((occupancy & (1ull << i)) != 0)
                    {
                        tmp_attack_mask |= (1ull << i);
                        break;
                    }
                    else
                    {
                        tmp_attack_mask |= (1ull << i);
                    }
                }
                i = index;
                while (true)
                {
                    i += south_west;

                    if (i >= 64/*equals i < 0*/)
                    {
                        break;
                    }
                    if (index % 8 == 0)
                    {
                        break;
                    }
                    if ((occupancy & (1ull << i)) != 0)
                    {
                        tmp_attack_mask |= (1ull << i);
                        break;
                    }
                    else
                    {
                        tmp_attack_mask |= (1ull << i);
                    }
                }
                diagonal_attack_table_ret[index][hashkeyDiagonal(index, occupancy)] = tmp_attack_mask;
            }
        }
        return diagonal_attack_table_ret;
    }();
    constexpr std::array<std::array<uint64_t, 64>, 64> anti_diagonal_attack_table = []()
    {
        std::array<std::array<uint64_t, 64>, 64> anti_diagonal_attack_table_ret = {};
        for (int index = 0; index < 64; index++)
        {
            for (uint64_t possible_ranks_index = 0; possible_ranks_index < 64; possible_ranks_index++)
            {
                uint64_t tmp_attack_mask = 0;
                uint64_t occupancy = possible_ranks[possible_ranks_index];
                uint64_t i = index;
                while (true)
                {
                    i += north_west;
                    if (i >= 64)
                    {
                        break;
                    }
                    if (index % 8 == 0)
                    {
                        break;
                    }
                    if ((occupancy & (1ull << i)) != 0)
                    {
                        tmp_attack_mask |= (1ull << i);
                        break;
                    }
                    else
                    {
                        tmp_attack_mask |= (1ull << i);
                    }
                }
                i = index;
                while (true)
                {
                    i += south_east;
                    if (i >= 64/*equals i < 0*/)
                    {
                        break;
                    }
                    if (index % 8 == 7)
                    {
                        break;
                    }
                    if ((occupancy & (1ull << i)) != 0)
                    {
                        tmp_attack_mask |= (1ull << i);
                        break;
                    }
                    else
                    {
                        tmp_attack_mask |= (1ull << i);
                    }
                }
                anti_diagonal_attack_table_ret[index][hashkeyAntiDiagonal(index, occupancy)] = tmp_attack_mask;
            }
        }
        return anti_diagonal_attack_table_ret;
    }();

    static constexpr auto Size =
        sizeof(anti_diagonal_attack_table) +
        sizeof(diagonal_attack_table) +
        sizeof(file_attack_table) +
        sizeof(rank_attack_table) +
        sizeof(anti_diagonals_64) +
        sizeof(diagonals_64) +
        sizeof(files_64) +
        sizeof(ranks_64);

    //return the uint64 with the rook targets
    static constexpr uint64_t Rook(int square, uint64_t occupation)
    {
        return rank_attack_table[square][hashkeyRank(square, occupation)] |
            file_attack_table[square][hashkeyFile(square, occupation)];
    }

    //return the uint64 with the bishops targets
    static constexpr uint64_t Bishop(int square, uint64_t occupation)
    {
        return anti_diagonal_attack_table[square][hashkeyAntiDiagonal(square, occupation)] |
            diagonal_attack_table[square][hashkeyDiagonal(square, occupation)];
    }

    static uint64_t Queen(int square, uint64_t occupation) {
        return anti_diagonal_attack_table[square][hashkeyAntiDiagonal(square, occupation)] |
            diagonal_attack_table[square][hashkeyDiagonal(square, occupation)] |
            rank_attack_table[square][hashkeyRank(square, occupation)] |
            file_attack_table[square][hashkeyFile(square, occupation)];
    }
}