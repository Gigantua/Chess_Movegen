//(c) Michael J Sherwin 2020
//SISSY BOARDS - https://www.chessprogramming.org/SISSY_Bitboards

#include <stdint.h>

namespace Chess_Lookup::SISSY
{
    typedef char s08;
    typedef unsigned char u08;
    typedef short s16;
    typedef int s32;
    typedef unsigned long u32;
    typedef long long s64;
    typedef unsigned long long u64;

    constexpr auto one = 1ull;

    union SplitBB {
        struct {
            u08 r1;
            u08 r2;
            u08 r3;
            u08 r4;
            u08 r5;
            u08 r6;
            u08 r7;
            u08 r8;
        };
        struct {
            u32 l32;
            u32 h32;
        };
        u64 bb;
    };

    u64 qss[64][256][8];
    u64 bss[64][128][6];
    u64 bob[64];
    u64 b7e[64];
    u64 rob[64];

    constexpr auto Size = sizeof(qss) + sizeof(bss) + 3 * sizeof(bob);

    void InitializeBSS() {
        u08 sq, sqr, k, l;
        s08 x, dx, y, dy;
        u64 b, bb, i, j, ii, jj;

        for (sq = 0; sq < 64; sq++) {
            y = sq >> 3;
            x = sq & 7;
            for (i = 0; i < 128; i++) {
                for (k = 8, l = 0; k <= 48; k += 8, l++) {
                    bb = 0;
                    b = ((u64)i << k) & bob[sq];
                    for (dx = +1, dy = +1; x + dx < +8 && y + dy < +8; dx++, dy++) {
                        sqr = (((y + dy) << 3) + x + dx);
                        bb |= one << sqr;
                        if ((one << sqr) & b) break;
                    }
                    for (dx = -1, dy = +1; x + dx > -1 && y + dy < +8; dx--, dy++) {
                        sqr = (((y + dy) << 3) + x + dx);
                        bb |= one << sqr;
                        if ((one << sqr) & b) break;
                    }
                    for (dx = +1, dy = -1; x + dx < +8 && y + dy > -1; dx++, dy--) {
                        sqr = (((y + dy) << 3) + x + dx);
                        bb |= one << sqr;
                        if ((one << sqr) & b) break;
                    }
                    for (dx = -1, dy = -1; x + dx > -1 && y + dy > -1; dx--, dy--) {
                        sqr = (((y + dy) << 3) + x + dx);
                        bb |= one << sqr;
                        if ((one << sqr) & b) break;
                    }
                    bss[sq][i][l] = bb;
                }
            }
        }

        for (sq = 0; sq <= 63; sq++) {
            for (ii = 0; ii <= 127; ii++) {
                for (jj = 0; jj <= 127; jj++) {
                    i = ((ii << 8) & bob[sq]) >> 8;
                    j = ((jj << 32) & bob[sq]) >> 32;
                    bss[sq][i | j][0] = bss[sq][i][0] & bss[sq][j][3];
                    i = ((ii << 16) & bob[sq]) >> 16;
                    j = ((jj << 40) & bob[sq]) >> 40;
                    bss[sq][i | j][1] = bss[sq][i][1] & bss[sq][j][4];
                    i = ((ii << 24) & bob[sq]) >> 24;
                    j = ((jj << 48) & bob[sq]) >> 48;
                    bss[sq][i | j][2] = bss[sq][i][2] & bss[sq][j][5];
                }
            }
        }
    }

    void InitializeQSS() {
        u08 sq, sqr, k, l;
        s08 x, y, dx, dy;
        s32 i;
        u64 b, bb;

        for (sq = 0; sq < 64; sq++) {
            y = sq >> 3;
            x = sq & 7;
            bob[sq] = 0;
            rob[sq] = 0;
            for (i = 0; i < 256; i++) {
                for (k = 0, l = 0; k <= 56; k += 8, l++) {
                    bb = 0;
                    b = (u64)i << k;
                    for (dx = +1, dy = +1; x + dx < +8 && y + dy < +8; dx++, dy++) {
                        sqr = (((y + dy) << 3) + x + dx);
                        bb |= one << sqr;
                        bob[sq] |= one << sqr;
                        if ((one << sqr) & b) break;
                    }
                    for (dx = -1, dy = +1; x + dx > -1 && y + dy < +8; dx--, dy++) {
                        sqr = (((y + dy) << 3) + x + dx);
                        bb |= one << sqr;
                        bob[sq] |= one << sqr;
                        if ((one << sqr) & b) break;
                    }
                    for (dx = +1, dy = -1; x + dx < +8 && y + dy > -1; dx++, dy--) {
                        sqr = (((y + dy) << 3) + x + dx);
                        bb |= one << sqr;
                        bob[sq] |= one << sqr;
                        if ((one << sqr) & b) break;
                    }
                    for (dx = -1, dy = -1; x + dx > -1 && y + dy > -1; dx--, dy--) {
                        sqr = (((y + dy) << 3) + x + dx);
                        bb |= one << sqr;
                        bob[sq] |= one << sqr;
                        if ((one << sqr) & b) break;
                    }
                    for (dx = -1; x + dx > -1; dx--) {
                        sqr = (y << 3) + x + dx;
                        bb |= one << sqr;
                        rob[sq] |= one << sqr;
                        if ((one << sqr) & b) break;
                    }
                    for (dx = +1; x + dx < +8; dx++) {
                        sqr = (y << 3) + x + dx;
                        bb |= one << sqr;
                        rob[sq] |= one << sqr;
                        if ((one << sqr) & b) break;
                    }
                    for (dy = +1; y + dy < +8; dy++) {
                        sqr = ((y + dy) << 3) + x;
                        bb |= one << sqr;
                        rob[sq] |= one << sqr;
                        if ((one << sqr) & b) break;
                    }
                    for (dy = -1; y + dy > -1; dy--) {
                        sqr = ((y + dy) << 3) + x;
                        bb |= one << sqr;
                        rob[sq] |= one << sqr;
                        if ((one << sqr) & b) break;
                    }
                    qss[sq][i][l] = bb;
                }
            }
            b7e[sq] = bob[sq] & 0x007e7e7e7e7e7e00;
        }
    }

    void Init() {
        InitializeQSS();
        InitializeBSS();
    }

    uint64_t Queen(int sq, uint64_t occ) {
        return qss[sq][occ & 255][0]
            & qss[sq][(occ >> 8) & 255][1]
            & qss[sq][(occ >> 16) & 255][2]
            & qss[sq][(occ >> 24) & 255][3]
            & qss[sq][(occ >> 32) & 255][4]
            & qss[sq][(occ >> 40) & 255][5]
            & qss[sq][(occ >> 48) & 255][6]
            & qss[sq][(occ >> 56) & 255][7];
    }
}