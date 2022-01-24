#pragma once

#include <cstdint>

namespace Chess_Lookup::Dumb7Fill {

    using U64 = uint64_t;
    constexpr auto Size = 0;

    static constexpr uint64_t north(uint64_t index, uint64_t empty) {
        empty ^= 18446744073709551615U;
        uint64_t flood = index;
        index = (index << 8) & empty;
        flood |= index;
        index = (index << 8) & empty;
        flood |= index;
        index = (index << 8) & empty;
        flood |= index;
        index = (index << 8) & empty;
        flood |= index;
        index = (index << 8) & empty;
        flood |= index;
        index = (index << 8) & empty;
        flood |= index;
        index = (index << 8) & empty;
        flood |= index;
        return (flood << 8) & 18446744073709551615U;
    }



    static constexpr uint64_t south(uint64_t index, uint64_t empty) {
        empty ^= 18446744073709551615U;
        uint64_t flood = index;
        index = (index >> 8) & empty;
        flood |= index;
        index = (index >> 8) & empty;
        flood |= index;
        index = (index >> 8) & empty;
        flood |= index;
        index = (index >> 8) & empty;
        flood |= index;
        index = (index >> 8) & empty;
        flood |= index;
        index = (index >> 8) & empty;
        flood |= index;
        index = (index >> 8) & empty;
        flood |= index;

        return (flood >> 8) & 18446744073709551615U;
    }



    static constexpr uint64_t east(uint64_t index, uint64_t empty) {
        empty ^= 18446744073709551615U;
        empty &= 0xfefefefefefefefe;
        uint64_t flood = index;
        index = (index << 1) & empty;
        flood |= index;
        index = (index << 1) & empty;
        flood |= index;
        index = (index << 1) & empty;
        flood |= index;
        index = (index << 1) & empty;
        flood |= index;
        index = (index << 1) & empty;
        flood |= index;
        index = (index << 1) & empty;
        flood |= index;
        index = (index << 1) & empty;
        flood |= index;

        return (flood << 1) & 0xfefefefefefefefe;
    }



    static constexpr uint64_t west(uint64_t index, uint64_t empty) {
        empty ^= 18446744073709551615U;
        empty &= 0x7f7f7f7f7f7f7f7f;
        uint64_t flood = index;
        index = (index >> 1) & empty;
        flood |= index;
        index = (index >> 1) & empty;
        flood |= index;
        index = (index >> 1) & empty;
        flood |= index;
        index = (index >> 1) & empty;
        flood |= index;
        index = (index >> 1) & empty;
        flood |= index;
        index = (index >> 1) & empty;
        flood |= index;
        index = (index >> 1) & empty;
        flood |= index;

        return (flood >> 1) & 0x7f7f7f7f7f7f7f7f;
    }



    static constexpr uint64_t noEa(uint64_t index, uint64_t empty) {
        empty ^= 18446744073709551615U;
        empty &= 0xfefefefefefefefe;
        uint64_t flood = index;
        index = (index << 9) & empty;
        flood |= index;
        index = (index << 9) & empty;
        flood |= index;
        index = (index << 9) & empty;
        flood |= index;
        index = (index << 9) & empty;
        flood |= index;
        index = (index << 9) & empty;
        flood |= index;
        index = (index << 9) & empty;
        flood |= index;
        index = (index << 9) & empty;
        flood |= index;

        return (flood << 9) & 0xfefefefefefefefe;
    }



    static constexpr uint64_t soEa(uint64_t index, uint64_t empty) {
        empty ^= 18446744073709551615U;
        empty &= 0xfefefefefefefefe;
        uint64_t flood = index;
        index = (index >> 7) & empty;
        flood |= index;
        index = (index >> 7) & empty;
        flood |= index;
        index = (index >> 7) & empty;
        flood |= index;
        index = (index >> 7) & empty;
        flood |= index;
        index = (index >> 7) & empty;
        flood |= index;
        index = (index >> 7) & empty;
        flood |= index;
        index = (index >> 7) & empty;
        flood |= index;

        return (flood >> 7) & 0xfefefefefefefefe;
    }



    static constexpr uint64_t noWe(uint64_t index, uint64_t empty) {
        empty ^= 18446744073709551615U;
        empty &= 0x7f7f7f7f7f7f7f7f;
        uint64_t flood = index;
        index = (index << 7) & empty;
        flood |= index;
        index = (index << 7) & empty;
        flood |= index;
        index = (index << 7) & empty;
        flood |= index;
        index = (index << 7) & empty;
        flood |= index;
        index = (index << 7) & empty;
        flood |= index;
        index = (index << 7) & empty;
        flood |= index;
        index = (index << 7) & empty;
        flood |= index;

        return (flood << 7) & 0x7f7f7f7f7f7f7f7f;
    }



    static constexpr uint64_t soWe(uint64_t index, uint64_t empty) {
        empty ^= 18446744073709551615U;
        empty &= 0x7f7f7f7f7f7f7f7f;
        uint64_t flood = index;
        index = (index >> 9) & empty;
        flood |= index;
        index = (index >> 9) & empty;
        flood |= index;
        index = (index >> 9) & empty;
        flood |= index;
        index = (index >> 9) & empty;
        flood |= index;
        index = (index >> 9) & empty;
        flood |= index;
        index = (index >> 9) & empty;
        flood |= index;
        index = (index >> 9) & empty;
        flood |= index;

        return (flood >> 9) & 0x7f7f7f7f7f7f7f7f;
    }

    static constexpr uint64_t Bishop(int sq, uint64_t occ)
    {
        uint64_t bishop = 1ull << sq;
        return noEa(bishop, occ) |
            soEa(bishop, occ) |
            soWe(bishop, occ) |
            noWe(bishop, occ);
    }

    static constexpr uint64_t Rook(int sq, uint64_t occ)
    {
        uint64_t rook = 1ull << sq;
        return  south(rook, occ) |
            north(rook, occ) |
            east(rook, occ) |
            west(rook, occ);
    }

    static constexpr uint64_t Queen(int sq, uint64_t occ)
    {
        return Bishop(sq, occ) | Rook(sq, occ);
    }
}
