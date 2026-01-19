#pragma once
#include <array>
#include <bit>
#include <immintrin.h>
/*
    Origional algorithm 
*/

namespace Chess_Lookup::Titboard
{
    using U8 = std::uint8_t;
    using BitBoard = std::uint64_t;
    using U16 = std::uint16_t;
    using Move = U16;
    using Sq = std::uint8_t;

    constexpr Sq FFFileOf(U8 index)       noexcept { return index & 7; }
    constexpr Sq FindLS1B(BitBoard bb)  noexcept { return std::countr_zero(bb); }
    constexpr U8 BBFileOf(Sq square)    noexcept { return 1 << FFFileOf(square); }
    constexpr Sq RankOf(Sq index)       noexcept { return index >> 3; }
    constexpr U8 BBRankOf(Sq square)    noexcept { return 1 << RankOf(square); }
    constexpr BitBoard SqToBB(Sq index) noexcept { return 1ull << index; }
    constexpr bool ValidSq(int index) noexcept { return index >= 0 && index < 64; }


    constexpr BitBoard FILE_ABB = 0x01'01'01'01'01'01'01'01;
    constexpr BitBoard FILE_BBB = FILE_ABB << 1;
    constexpr BitBoard FILE_CBB = FILE_ABB << 2;
    constexpr BitBoard FILE_DBB = FILE_ABB << 3;
    constexpr BitBoard FILE_EBB = FILE_ABB << 4;
    constexpr BitBoard FILE_FBB = FILE_ABB << 5;
    constexpr BitBoard FILE_GBB = FILE_ABB << 6;
    constexpr BitBoard FILE_HBB = FILE_ABB << 7;

    constexpr BitBoard RANK_1BB = 0x00'00'00'00'00'00'00'FF;
    constexpr BitBoard RANK_2BB = RANK_1BB << 8;
    constexpr BitBoard RANK_3BB = RANK_1BB << 16;
    constexpr BitBoard RANK_4BB = RANK_1BB << 24;
    constexpr BitBoard RANK_5BB = RANK_1BB << 32;
    constexpr BitBoard RANK_6BB = RANK_1BB << 40;
    constexpr BitBoard RANK_7BB = RANK_1BB << 48;
    constexpr BitBoard RANK_8BB = RANK_1BB << 56;

    constexpr BitBoard CROSS_DIAG = 0x8040201008040201;         // A1 - H8
    constexpr BitBoard ANTI_CROSS_DIAG = 0x0102040810204080;    // A8 - H1

    constexpr U8 CollapsedRanksIndex(BitBoard b) noexcept
    {
        //collapses the bb into a file
        //then performs collapsed files
        b |= b >> 4;
        b |= b >> 2;
        b |= b >> 1;
        return ((b & FILE_ABB) * ANTI_CROSS_DIAG) >> 56;
    }
    constexpr U8 CollapsedRanksIndex(BitBoard b, U8 file) noexcept
    {
        // return (((b >> file) & FILE_ABB) * ANTI_CROSS_DIAG) >> 56;
        return ((b >> file) * ANTI_CROSS_DIAG) >> 56;
    }

    enum AttackDirection : U8
    {
        File,
        Rank,
        Diagonal,
        AntiDiagonal
    };
    consteval std::array<std::array<BitBoard, 4>, 64> PrecomputeMask() noexcept
    {
        std::array<std::array<BitBoard, 4>, 64> r_val{};
        for (U8 i = 0; i < 64; ++i)
        {
            U8 rank = RankOf(i);
            U8 file = FFFileOf(i);
            BitBoard cross_attacks{ 0ull };
            BitBoard anti_cross_attacks{ 0ull };

            for (int8_t r = rank + 1, f = file + 1; r < 8 && f < 8; ++r, ++f)    cross_attacks |= SqToBB(U8(r * 8 + f));
            for (int8_t r = rank - 1, f = file - 1; r >= 0 && f >= 0; --r, --f)  cross_attacks |= SqToBB(U8(r * 8 + f));
            for (int8_t r = rank + 1, f = file - 1; r < 8 && f >= 0; ++r, --f)   anti_cross_attacks |= SqToBB(U8(r * 8 + f));
            for (int8_t r = rank - 1, f = file + 1; r >= 0 && f < 8; --r, ++f)   anti_cross_attacks |= SqToBB(U8(r * 8 + f));

            r_val[i][File] = (FILE_ABB << file) & ~SqToBB(i); //pt_Rook file attacks
            r_val[i][Rank] = (RANK_1BB << (8 * rank)) & ~SqToBB(i); // pt_Rook Rank attacks
            r_val[i][Diagonal] = cross_attacks & ~SqToBB(i); //Bishop cross attacks
            r_val[i][AntiDiagonal] = anti_cross_attacks & ~SqToBB(i); //Bishop anti cross attacks
        }
        return r_val;
    }
    consteval std::array<BitBoard, 64> PrecomputeQueenMask() noexcept
    {
        std::array<BitBoard, 64> r_val{};
        for (U8 i = 0; i < 64; ++i)
        {
            U8 rank = RankOf(i);
            U8 file = FFFileOf(i);
            BitBoard cross_attacks{ 0ull };
            BitBoard anti_cross_attacks{ 0ull };

            for (int8_t r = rank + 1, f = file + 1; r < 8 && f < 8; ++r, ++f)    cross_attacks |= SqToBB(U8(r * 8 + f));
            for (int8_t r = rank - 1, f = file - 1; r >= 0 && f >= 0; --r, --f)  cross_attacks |= SqToBB(U8(r * 8 + f));
            for (int8_t r = rank + 1, f = file - 1; r < 8 && f >= 0; ++r, --f)   anti_cross_attacks |= SqToBB(U8(r * 8 + f));
            for (int8_t r = rank - 1, f = file + 1; r >= 0 && f < 8; --r, ++f)   anti_cross_attacks |= SqToBB(U8(r * 8 + f));

            r_val[i] |= (FILE_ABB << file) & ~SqToBB(i); //pt_Rook file attacks
            r_val[i] |= (RANK_1BB << (8 * rank)) & ~SqToBB(i); // pt_Rook Rank attacks
            r_val[i] |= cross_attacks & ~SqToBB(i); //Bishop cross attacks
            r_val[i] |= anti_cross_attacks & ~SqToBB(i); //Bishop anti cross attacks
        }
        return r_val;
    }
    template <typename T>
    constexpr T ipow(T num, unsigned int pow)
    {
        return (pow >= sizeof(unsigned int) * 8) ? 0 :
            pow == 0 ? 1 : num * ipow(num, pow - 1);
    }
    template<bool gen_us>
    consteval std::array<std::array<U16, 256>, 8> compute_base_2_to_3() noexcept
    {
        std::array<std::array<U16, 256>, 8> result{};
        for (U8 missed_file = 0; missed_file < 8; ++missed_file)
        {
            for (U16 i = 0; i < 256; ++i)
            {
                for (int j = 0; j < 8; ++j)
                {
                    if (j == missed_file) continue;

                    if constexpr (gen_us)
                    {
                        result.at(missed_file).at(i) += ((i >> j) & 1) * ((j < missed_file) ? ipow(3, j) : ipow(3, j - 1));
                    }
                    else
                    {
                        result.at(missed_file).at(i) += ((i >> j) & 1) * ((j < missed_file) ? (2 * ipow(3, j)) : (2 * ipow(3, j - 1)));
                    }
                }
            }
        }
        return result;
    }
    inline constexpr std::array<std::array<BitBoard, 4>, 64> SLIDING_ATTACKS_MASK = PrecomputeMask();
    inline constexpr std::array<BitBoard, 64> QUEEN_ATTACK_MASK = PrecomputeQueenMask();
    inline constexpr std::array<std::array<U16, 256>, 8> base_2_to_3_us = compute_base_2_to_3<true>();
    inline constexpr std::array<std::array<U16, 256>, 8> base_2_to_3_them = compute_base_2_to_3<false>();

    consteval std::array<std::array<std::array<U16, 256>, 256>, 8> compute_base_3_lookup() noexcept
    {
        std::array<std::array<std::array<U16, 256>, 256>, 8> result{};

        std::array<std::array<U16, 256>, 8> base_2_to_3_us_ = compute_base_2_to_3<true>();
        std::array<std::array<U16, 256>, 8> base_2_to_3_them_ = compute_base_2_to_3<false>();

        for (U8 missed_file = 0; missed_file < 8; ++missed_file)
        {
            for (U16 us = 0; us < 256; ++us)
            {
                for (U16 them = 0; them < 256; ++them)
                {
                    result[missed_file][us][them] = U16(
                        base_2_to_3_us_[missed_file][us] + base_2_to_3_them_[missed_file][them]
                    );
                }
            }
        }

        return result;
    }

    inline constexpr std::array<std::array<std::array<U16, 256>, 256>, 8> base_3_lookup = compute_base_3_lookup();

    inline constexpr U16 GetBaseThreeUsThem(U8 us, U8 them, Sq piece_square) noexcept
    {
        return base_3_lookup[piece_square][us][them];
    }

    struct move_info
    {
        constexpr move_info() = default;
        BitBoard attacks_;
    };
    std::array<std::array<std::array<move_info, 2187>, 4>, 64> PrecomputeTitboards()
    {
        std::array<std::array<std::array<move_info, 2187>, 4>, 64> result{};
        for (U8 sq = 0; sq < 64; ++sq)
        {
            for (U16 us = 0; us < 256; ++us)
            {
                for (U16 them = 0; them < 256; ++them)
                {
                    //skipping useless blocker configurations
                    if (us & them || (((~us) & BBFileOf(sq) || them & BBFileOf(sq)) & ((~us) & BBRankOf(sq) || them & BBRankOf(sq)))) continue;

                    move_info file_attack_moves{};
                    move_info rank_attack_moves{};
                    move_info diagonal_attack_moves{};
                    move_info anti_diagonal_attack_moves{};

                    const U8 rank_combined = (us | them) & ~BBFileOf(sq);
                    U8 other_combined = (us | them) & ~BBRankOf(sq);

                    const U8 rankofsq = RankOf(sq);
                    const U8 fileofsq = FFFileOf(sq);

                    BitBoard diag_attacks = 0ull;
                    BitBoard diag_quiets{}, diag_captures{};
                    BitBoard anti_diag_attacks = 0ull;
                    BitBoard adiag_quiets{}, adiag_captures{};

                    if (us & BBFileOf(sq))
                    {
                        for (int8_t current_file = fileofsq + 1; current_file < 8; ++current_file)
                        {
                            if ((us >> current_file) & 1) break; //our piece
                            if (!((rank_combined >> current_file) & 1)) //empty
                            {
                                rank_attack_moves.attacks_ |= SqToBB(sq + (current_file - fileofsq));
                                continue;
                            }
                            if ((them >> current_file) & 1) //their piece
                            {
                                rank_attack_moves.attacks_ |= SqToBB(sq + (current_file - fileofsq));
                                break;
                            }
                        }
                        for (int8_t current_file = fileofsq - 1; current_file > -1; --current_file)
                        {
                            if ((us >> current_file) & 1) break;
                            if (!((rank_combined >> current_file) & 1))
                            {
                                rank_attack_moves.attacks_ |= SqToBB(sq - (fileofsq - current_file));
                                continue;
                            }
                            if ((them >> current_file) & 1)
                            {
                                rank_attack_moves.attacks_ |= SqToBB(sq - (fileofsq - current_file));
                                break;
                            }
                        }
                        const U16 p1 = base_2_to_3_us[fileofsq][us & ~BBFileOf(sq)];
                        const U16 p2 = 2 * base_2_to_3_us[fileofsq][them];
                        result.at(sq).at(Rank).at(p1 + p2) = rank_attack_moves;
                    }

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    if (us & BBRankOf(sq))
                    {
                        for (int8_t current_file = rankofsq + 1; current_file < 8; ++current_file)
                        {
                            if ((us >> current_file) & 1) break; //our piece
                            if (!((other_combined >> current_file) & 1)) //empty
                            {
                                file_attack_moves.attacks_ |= SqToBB(sq + 8 * (current_file - rankofsq));

                                if (ValidSq(sq + 9 * (current_file - rankofsq)))
                                {
                                    auto const atk = SqToBB(sq + 9 * (current_file - rankofsq));
                                    diag_attacks |= atk;
                                    diag_quiets |= atk;
                                }
                                if (ValidSq(sq + 7 * (current_file - rankofsq)))
                                {
                                    auto const atk = SqToBB(sq + 7 * (current_file - rankofsq));
                                    anti_diag_attacks |= atk;
                                    adiag_quiets |= atk;
                                }
                                continue;
                            }
                            if ((them >> current_file) & 1) //their piece
                            {
                                file_attack_moves.attacks_ |= SqToBB(sq + 8 * (current_file - rankofsq));

                                if (ValidSq(sq + 9 * (current_file - rankofsq)))
                                {
                                    auto const atk = SqToBB(sq + 9 * (current_file - rankofsq));
                                    diag_attacks |= atk;
                                    diag_captures |= atk;
                                }

                                if (ValidSq(sq + 7 * (current_file - rankofsq)))
                                {
                                    auto const atk = SqToBB(sq + 7 * (current_file - rankofsq));
                                    anti_diag_attacks |= atk;
                                    adiag_captures |= atk;
                                }
                                break;
                            }

                        }
                        for (int8_t current_file = rankofsq - 1; current_file > -1; --current_file)
                        {
                            if ((us >> current_file) & 1) break;
                            if (!((other_combined >> current_file) & 1))
                            {
                                file_attack_moves.attacks_ |= SqToBB(sq - 8 * (rankofsq - current_file));

                                if (ValidSq(sq - 9 * (rankofsq - current_file)))
                                {
                                    auto const atk = SqToBB(sq - 9 * (rankofsq - current_file));
                                    diag_attacks |= atk;
                                    diag_quiets |= atk;
                                }

                                if (ValidSq(sq - 7 * (rankofsq - current_file)))
                                {
                                    auto const atk = SqToBB(sq - 7 * (rankofsq - current_file));
                                    anti_diag_attacks |= atk;
                                    adiag_quiets |= atk;
                                }

                                continue;
                            }
                            if ((them >> current_file) & 1)
                            {
                                file_attack_moves.attacks_ |= SqToBB(sq - 8 * (rankofsq - current_file));

                                if (ValidSq(sq - 9 * (rankofsq - current_file)))
                                {
                                    auto const atk = SqToBB(sq - 9 * (rankofsq - current_file));
                                    diag_attacks |= atk;
                                    diag_captures |= atk;
                                }

                                if (ValidSq(sq - 7 * (rankofsq - current_file)))
                                {
                                    auto const atk = SqToBB(sq - 7 * (rankofsq - current_file));
                                    anti_diag_attacks |= atk;
                                    adiag_captures |= atk;
                                }
                                break;
                            }
                        }

                        diag_attacks &= SLIDING_ATTACKS_MASK[sq][(int)Diagonal];
                        diag_captures &= SLIDING_ATTACKS_MASK[sq][(int)Diagonal];
                        diag_quiets &= SLIDING_ATTACKS_MASK[sq][(int)Diagonal];

                        anti_diag_attacks &= SLIDING_ATTACKS_MASK[sq][(int)AntiDiagonal];
                        adiag_captures &= SLIDING_ATTACKS_MASK[sq][(int)AntiDiagonal];
                        adiag_quiets &= SLIDING_ATTACKS_MASK[sq][(int)AntiDiagonal];


                        diagonal_attack_moves.attacks_ = diag_attacks;
                        anti_diagonal_attack_moves.attacks_ = anti_diag_attacks;

                        const U16 p1 = base_2_to_3_us[rankofsq][us & ~BBRankOf(sq)];
                        const U16 p2 = 2 * base_2_to_3_us[rankofsq][them];
                        result.at(sq).at((U8)File).at(p1 + p2) = file_attack_moves;
                        result.at(sq).at((U8)Diagonal).at(p1 + p2) = diagonal_attack_moves;
                        result.at(sq).at((U8)AntiDiagonal).at(p1 + p2) = anti_diagonal_attack_moves;
                    }
                }
            }
        }
        return result;
    }
    inline std::array<std::array<std::array<move_info, 2187>, 4>, 64> SLIDING_ATTACK_CONFIG = PrecomputeTitboards();


    template<AttackDirection direction, bool UsePext>
    inline BitBoard GetMovesForSliding(Sq piece_sq, BitBoard us, BitBoard them) noexcept
    {
        if constexpr (direction == Rank)
        {
            const U8 file_of_attacker = FFFileOf(piece_sq);
            const U8 file_bit = U8(1u << file_of_attacker);
            U8 us_collapsed{};
            U8 them_collapsed{};
            if constexpr (UsePext)
            {
                const BitBoard rank_mask = RANK_1BB << (piece_sq & 56);
                us_collapsed = U8(_pext_u64(us, rank_mask));
                them_collapsed = U8(_pext_u64(them, rank_mask));
            }
            else
            {
                const U8 rank_shift = piece_sq & 56;
                us_collapsed = U8((us >> rank_shift) & 0xFFu);
                them_collapsed = U8((them >> rank_shift) & 0xFFu);
            }
            us_collapsed &= U8(~file_bit);
            them_collapsed &= U8(~file_bit);
            const U16 lookup_index = GetBaseThreeUsThem(us_collapsed, them_collapsed, file_of_attacker);


            return SLIDING_ATTACK_CONFIG[piece_sq][direction][lookup_index].attacks_;
        }
        else if constexpr (direction == File)
        {
            const U8 rank_of_attacker = RankOf(piece_sq);
            const U8 file_of_attacker = FFFileOf(piece_sq);
            U8 us_collapsed{};
            U8 them_collapsed{};
            if constexpr (UsePext)
            {
                const BitBoard file_mask = FILE_ABB << file_of_attacker;
                us_collapsed = U8(_pext_u64(us, file_mask));
                them_collapsed = U8(_pext_u64(them, file_mask));
                const U8 rank_bit = U8(1u << rank_of_attacker);
                us_collapsed &= U8(~rank_bit);
                them_collapsed &= U8(~rank_bit);
            }
            else
            {
                const BitBoard attack_mask = SLIDING_ATTACKS_MASK[piece_sq][direction];
                us_collapsed = CollapsedRanksIndex(us & attack_mask, file_of_attacker);
                them_collapsed = CollapsedRanksIndex(them & attack_mask, file_of_attacker);
            }
            const U16 lookup_index = GetBaseThreeUsThem(us_collapsed, them_collapsed, rank_of_attacker);
            return SLIDING_ATTACK_CONFIG[piece_sq][direction][lookup_index].attacks_;
        }
        else //direction == Diag || direction == Anti Diag
        {
            const U8 rank_of_attacker = RankOf(piece_sq);
            const U8 file_of_attacker = FFFileOf(piece_sq);
            U8 us_collapsed{};
            U8 them_collapsed{};
            if constexpr (UsePext)
            {
                const BitBoard attack_mask = SLIDING_ATTACKS_MASK[piece_sq][direction];
                const BitBoard full_mask = attack_mask | SqToBB(piece_sq);
                const U8 start_rank = (direction == Diagonal)
                    ? (rank_of_attacker > file_of_attacker ? U8(rank_of_attacker - file_of_attacker) : 0)
                    : ((rank_of_attacker + file_of_attacker > 7)
                        ? U8(rank_of_attacker + file_of_attacker - 7)
                        : 0);
                us_collapsed = U8(_pext_u64(us, full_mask) << start_rank);
                them_collapsed = U8(_pext_u64(them, full_mask) << start_rank);
                const U8 rank_bit = U8(1u << rank_of_attacker);
                us_collapsed &= U8(~rank_bit);
                them_collapsed &= U8(~rank_bit);
            }
            else
            {
                const BitBoard attack_mask = SLIDING_ATTACKS_MASK[piece_sq][direction];
                us_collapsed = CollapsedRanksIndex(us & attack_mask);
                them_collapsed = CollapsedRanksIndex(them & attack_mask);
            }
            const U16 lookup_index = GetBaseThreeUsThem(us_collapsed, them_collapsed, rank_of_attacker);

            return SLIDING_ATTACK_CONFIG[piece_sq][direction][lookup_index].attacks_;
        }
    }
    
    template<AttackDirection direction, bool UsePext, Sq piece_sq>
    inline BitBoard GetMovesForSliding(BitBoard us, BitBoard them) noexcept
    {
        if constexpr (direction == Rank)
        {
            const U8 file_of_attacker = FFFileOf(piece_sq);
            const U8 file_bit = U8(1u << file_of_attacker);
            U8 us_collapsed{};
            U8 them_collapsed{};
            if constexpr (UsePext)
            {
                const BitBoard rank_mask = RANK_1BB << (piece_sq & 56);
                us_collapsed = U8(_pext_u64(us, rank_mask));
                them_collapsed = U8(_pext_u64(them, rank_mask));
            }
            else
            {
                const U8 rank_shift = piece_sq & 56;
                us_collapsed = U8((us >> rank_shift) & 0xFFu);
                them_collapsed = U8((them >> rank_shift) & 0xFFu);
            }
            us_collapsed &= U8(~file_bit);
            them_collapsed &= U8(~file_bit);
            const U16 lookup_index = GetBaseThreeUsThem(us_collapsed, them_collapsed, file_of_attacker);


            return SLIDING_ATTACK_CONFIG[piece_sq][direction][lookup_index].attacks_;
        }
        else if constexpr (direction == File)
        {
            const U8 rank_of_attacker = RankOf(piece_sq);
            const U8 file_of_attacker = FFFileOf(piece_sq);
            U8 us_collapsed{};
            U8 them_collapsed{};
            if constexpr (UsePext)
            {
                const BitBoard file_mask = FILE_ABB << file_of_attacker;
                us_collapsed = U8(_pext_u64(us, file_mask));
                them_collapsed = U8(_pext_u64(them, file_mask));
                const U8 rank_bit = U8(1u << rank_of_attacker);
                us_collapsed &= U8(~rank_bit);
                them_collapsed &= U8(~rank_bit);
            }
            else
            {
                const BitBoard attack_mask = SLIDING_ATTACKS_MASK[piece_sq][direction];
                us_collapsed = CollapsedRanksIndex(us & attack_mask, file_of_attacker);
                them_collapsed = CollapsedRanksIndex(them & attack_mask, file_of_attacker);
            }
            const U16 lookup_index = GetBaseThreeUsThem(us_collapsed, them_collapsed, rank_of_attacker);
            return SLIDING_ATTACK_CONFIG[piece_sq][direction][lookup_index].attacks_;
        }
        else //direction == Diag || direction == Anti Diag
        {
            const U8 rank_of_attacker = RankOf(piece_sq);
            const U8 file_of_attacker = FFFileOf(piece_sq);
            U8 us_collapsed{};
            U8 them_collapsed{};
            if constexpr (UsePext)
            {
                const BitBoard attack_mask = SLIDING_ATTACKS_MASK[piece_sq][direction];
                const BitBoard full_mask = attack_mask | SqToBB(piece_sq);
                const U8 start_rank = (direction == Diagonal)
                    ? (rank_of_attacker > file_of_attacker ? U8(rank_of_attacker - file_of_attacker) : 0)
                    : ((rank_of_attacker + file_of_attacker > 7)
                        ? U8(rank_of_attacker + file_of_attacker - 7)
                        : 0);
                us_collapsed = U8(_pext_u64(us, full_mask) << start_rank);
                them_collapsed = U8(_pext_u64(them, full_mask) << start_rank);
                const U8 rank_bit = U8(1u << rank_of_attacker);
                us_collapsed &= U8(~rank_bit);
                them_collapsed &= U8(~rank_bit);
            }
            else
            {
                const BitBoard attack_mask = SLIDING_ATTACKS_MASK[piece_sq][direction];
                us_collapsed = CollapsedRanksIndex(us & attack_mask);
                them_collapsed = CollapsedRanksIndex(them & attack_mask);
            }
            const U16 lookup_index = GetBaseThreeUsThem(us_collapsed, them_collapsed, rank_of_attacker);

            return SLIDING_ATTACK_CONFIG[piece_sq][direction][lookup_index].attacks_;
        }
    }

    static constexpr auto Size =
        sizeof(SLIDING_ATTACK_CONFIG) +
        sizeof(QUEEN_ATTACK_MASK) + 
        sizeof(SLIDING_ATTACKS_MASK) +
        sizeof(base_2_to_3_us) +
        sizeof(base_3_lookup) + 
        sizeof(base_2_to_3_us);


    template<int square, bool UsePext>
    static uint64_t Queen(uint64_t occupation)
    {
        return  GetMovesForSliding<File,            UsePext, Sq(square)>(BitBoard(0), BitBoard(occupation)) |
                GetMovesForSliding<Rank,            UsePext, Sq(square)>(BitBoard(0), BitBoard(occupation)) |
                GetMovesForSliding<Diagonal,        UsePext, Sq(square)>(BitBoard(0), BitBoard(occupation)) |
                GetMovesForSliding<AntiDiagonal,    UsePext, Sq(square)>(BitBoard(0), BitBoard(occupation));
    }
    template<bool UsePext>
    static uint64_t Queen(int square, uint64_t occupation)
    {
        return  GetMovesForSliding<File, UsePext>(Sq(square), BitBoard(0), BitBoard(occupation))        |
                GetMovesForSliding<Rank, UsePext>(Sq(square), BitBoard(0), BitBoard(occupation))        | 
                GetMovesForSliding<Diagonal, UsePext>(Sq(square), BitBoard(0), BitBoard(occupation))    |
                GetMovesForSliding<AntiDiagonal, UsePext>(Sq(square), BitBoard(0), BitBoard(occupation));
    }
}