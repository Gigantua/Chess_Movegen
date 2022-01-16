#pragma once

#include <cstdint>

namespace Chess_Lookup::Dumb7Fill {

    using U64 = uint64_t;
    constexpr auto Size = 0;

    static constexpr U64 south(U64 rooks, U64 empty) {
        U64 flood = rooks;
        flood |= rooks = (rooks >> 8) & empty;
        flood |= rooks = (rooks >> 8) & empty;
        flood |= rooks = (rooks >> 8) & empty;
        flood |= rooks = (rooks >> 8) & empty;
        flood |= rooks = (rooks >> 8) & empty;
        flood |= (rooks >> 8) & empty;
        return            flood >> 8;
    }

    static constexpr U64 north(U64 rooks, U64 empty) {
        U64 flood = rooks;
        flood |= rooks = (rooks << 8) & empty;
        flood |= rooks = (rooks << 8) & empty;
        flood |= rooks = (rooks << 8) & empty;
        flood |= rooks = (rooks << 8) & empty;
        flood |= rooks = (rooks << 8) & empty;
        flood |= (rooks << 8) & empty;
        return            flood << 8;
    }

    static constexpr U64 east(U64 rooks, U64 empty) {
        const U64 notA = 0xfefefefefefefefe;
        U64 flood = rooks;
        empty &= notA;
        flood |= rooks = (rooks << 1) & empty;
        flood |= rooks = (rooks << 1) & empty;
        flood |= rooks = (rooks << 1) & empty;
        flood |= rooks = (rooks << 1) & empty;
        flood |= rooks = (rooks << 1) & empty;
        flood |= (rooks << 1) & empty;
        return           (flood << 1) & notA;
    }

    static constexpr U64 west(U64 rooks, U64 empty) {
        const U64 notH = 0x7f7f7f7f7f7f7f7full;
        U64 flood = rooks;
        empty &= notH;
        flood |= rooks = (rooks >> 1) & empty;
        flood |= rooks = (rooks >> 1) & empty;
        flood |= rooks = (rooks >> 1) & empty;
        flood |= rooks = (rooks >> 1) & empty;
        flood |= rooks = (rooks >> 1) & empty;
        flood |= (rooks >> 1) & empty;
        return           (flood >> 1) & notH;
    }


    static constexpr U64 noEa(U64 bishops, U64 empty) {
        const U64 notA = 0xfefefefefefefefeull;
        U64 flood = bishops;
        empty &= notA;
        flood |= bishops = (bishops << 9) & empty;
        flood |= bishops = (bishops << 9) & empty;
        flood |= bishops = (bishops << 9) & empty;
        flood |= bishops = (bishops << 9) & empty;
        flood |= bishops = (bishops << 9) & empty;
        flood |= (bishops << 9) & empty;
        return               (flood << 9) & notA;
    }

    static constexpr U64 soEa(U64 bishops, U64 empty) {
        const U64 notA = 0xfefefefefefefefeull;
        U64 flood = bishops;
        empty &= notA;
        flood |= bishops = (bishops >> 7) & empty;
        flood |= bishops = (bishops >> 7) & empty;
        flood |= bishops = (bishops >> 7) & empty;
        flood |= bishops = (bishops >> 7) & empty;
        flood |= bishops = (bishops >> 7) & empty;
        flood |= (bishops >> 7) & empty;
        return               (flood >> 7) & notA;
    }

    static constexpr U64 soWe(U64 bishops, U64 empty) {
        const U64 notH = 0x7f7f7f7f7f7f7f7full;
        U64 flood = bishops;
        empty &= notH;
        flood |= bishops = (bishops >> 9) & empty;
        flood |= bishops = (bishops >> 9) & empty;
        flood |= bishops = (bishops >> 9) & empty;
        flood |= bishops = (bishops >> 9) & empty;
        flood |= bishops = (bishops >> 9) & empty;
        flood |= (bishops >> 9) & empty;
        return               (flood >> 9) & notH;
    }

    static constexpr U64 noWe(U64 bishops, U64 empty) {
        const U64 notH = 0x7f7f7f7f7f7f7f7full;
        U64 flood = bishops;
        empty &= notH;
        flood |= bishops = (bishops << 7) & empty;
        flood |= bishops = (bishops << 7) & empty;
        flood |= bishops = (bishops << 7) & empty;
        flood |= bishops = (bishops << 7) & empty;
        flood |= bishops = (bishops << 7) & empty;
        flood |= (bishops << 7) & empty;
        return               (flood << 7) & notH;
    }

    static constexpr uint64_t Bishop(int sq, uint64_t occ)
    {
        uint64_t empty = ~occ;
        uint64_t bishop = 1ull >> sq;
        return noEa(bishop, empty) |
               soEa(bishop, empty) |
               soWe(bishop, empty) |
               noWe(bishop, empty);
    }

    static constexpr uint64_t Rook(int sq, uint64_t occ)
    {
        uint64_t empty = ~occ;
        uint64_t rook = 1ull >> sq;
        return  south(rook, empty) |
                north(rook, empty) |
                east(rook, empty) |
                west(rook, empty);
    }

    static constexpr uint64_t Queen(uint64_t occ, int sq)
    {
        return Bishop(sq, occ) | Rook(sq, occ);
    }
}
