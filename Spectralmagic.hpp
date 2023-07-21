#pragma once
#include <stdint.h>
#include <bit>

namespace Chess_Lookup::SpectralMagic
{


    [[noreturn]] inline void unreachable()
    {
#if defined(__GNUC__)
        __builtin_unreachable();
#elif defined(_MSC_VER)
        __assume(false);
#endif
    }

    static constexpr uint64_t rook_masks[64] = {
         18446461494909402753ull, 18446178916109254019ull, 18445613758508956549ull, 18444483443308361609ull, 18442222812907171729ull, 18437701552104791969ull, 18428659030500032449ull, 18410573987290513281ull,
         18446461494909370879ull, 18446178916109222911ull, 18445613758508926463ull, 18444483443308333567ull, 18442222812907147775ull, 18437701552104776191ull, 18428659030500033023ull, 18410573987290513919ull,
         18446461494901210879ull, 18446178916101258751ull, 18445613758501223423ull, 18444483443301152767ull, 18442222812901011455ull, 18437701552100728831ull, 18428659030500163583ull, 18410573987290644479ull,
         18446461492812250879ull, 18446178914062433791ull, 18445613756529245183ull, 18444483441462867967ull, 18442222811330113535ull, 18437701551064604671ull, 18428659030533586943ull, 18410573987324067839ull,
         18446460958038490879ull, 18446178392123244031ull, 18445613251702815743ull, 18444482970861959167ull, 18442222409180246015ull, 18437701285816819711ull, 18428659039089967103ull, 18410573995880447999ull,
         18446324055955930879ull, 18446044775690665471ull, 18445484016136879103ull, 18444362497029306367ull, 18442119458814160895ull, 18437633382383869951ull, 18428661229523288063ull, 18410576186313768959ull,
         18411277122820570879ull, 18411838968950554111ull, 18412399711257099263ull, 18413521195870189567ull, 18415764165096370175ull, 18420250103548731391ull, 18429221980453453823ull, 18411136937243934719ull,
         9367204646130482943ull, 9511037255406190079ull, 9654587285881748479ull, 9941687346832865279ull, 10515887468735098879ull, 11664287712539566079ull, 13961088200148500479ull, 9331317138511593471ull,
    };

    static constexpr uint64_t bish_masks[64] = {
         18428694421974023679ull, 18446673567257459711ull, 18446743798293722623ull, 18446744072633576447ull, 18446744073671530495ull, 18446744065051963391ull, 18446741857371152383ull, 18446176691079331839ull,
         18437719247841787903ull, 18428694421974024191ull, 18446673567257329663ull, 18446743798259908607ull, 18446744063976144895ull, 18446741857366966271ull, 18446176691079348223ull, 18445609308449144831ull,
         18442231660775734783ull, 18437719247841917951ull, 18428694421940729343ull, 18446673558600936447ull, 18446741581957421055ull, 18446176690007683071ull, 18445609308453330943ull, 18444474543197110271ull,
         18444487867259288575ull, 18442231660809025535ull, 18437719239318433791ull, 18428692205904059903ull, 18446106185164110847ull, 18445609034107058175ull, 18444474544268767231ull, 18442205014827982847ull,
         18445615974745634815ull, 18444487875781718015ull, 18442229478797074431ull, 18437151933931044863ull, 18427559794152570367ull, 18444404311622941695ull, 18442205289172170751ull, 18437666504634789887ull,
         18446181115098558463ull, 18445618156487565311ull, 18443929280722223103ull, 18441114487701372927ull, 18435484901701451775ull, 18424225731840835071ull, 18437736736746896383ull, 18428729399784241151ull,
         18446741857371152383ull, 18446739641032753151ull, 18446733009332731903ull, 18446721936374366207ull, 18446699801153110015ull, 18446656078352351231ull, 18446708820483505663ull, 18446673567257459711ull,
         18446176691079331839ull, 18445609308449144831ull, 18443911593243705343ull, 18441076915902087167ull, 18435410299260502015ull, 18424217262266253311ull, 18437719247841787903ull, 18428694421974023679ull,
    };


    static constexpr uint64_t Size = (274645 + 2 * 64) * sizeof(uint64_t);

    static inline uint64_t* attack_table;
    static void Init() {
        uint64_t BB_AF = 0x0101010101010101;
        uint64_t BB_HF = 0x8080808080808080;
        uint64_t BB_R1 = 0x00000000000000FF;
        uint64_t BB_R8 = 0xFF00000000000000;

        auto bish = [&](int s, uint64_t o)
        {
            uint64_t tmp, att = 0;
            o &= ~(1ull << s);
            tmp = 1ull << s; while ((tmp & (o | BB_HF | BB_R8)) == 0) { att |= tmp <<= 9; }
            tmp = 1ull << s; while ((tmp & (o | BB_AF | BB_R8)) == 0) { att |= tmp <<= 7; }
            tmp = 1ull << s; while ((tmp & (o | BB_AF | BB_R1)) == 0) { att |= tmp >>= 9; }
            tmp = 1ull << s; while ((tmp & (o | BB_HF | BB_R1)) == 0) { att |= tmp >>= 7; }
            return att;
        };

        auto rook = [&](int s, uint64_t o)
        {
            uint64_t tmp, att = 0;
            o &= ~(1ull << s);
            tmp = 1ull << s; while ((tmp & (o | BB_HF)) == 0) { att |= tmp <<= 1; }
            tmp = 1ull << s; while ((tmp & (o | BB_AF)) == 0) { att |= tmp >>= 1; }
            tmp = 1ull << s; while ((tmp & (o | BB_R8)) == 0) { att |= tmp <<= 8; }
            tmp = 1ull << s; while ((tmp & (o | BB_R1)) == 0) { att |= tmp >>= 8; }
            return att;
        };
        auto bit_deposit = [](uint64_t val, uint64_t mask) {
            uint64_t res = 0;
            for (uint64_t bb = 1; mask; bb += bb)
            {
                res |= (val & bb) ? mask & -mask : 0;
                mask &= mask - 1;
            }
            return res;
        };
        uint64_t rook_magics[64] = { 36029346774794240ull, 18014467228966912ull, 36028934457921536ull, 36028865738442752ull, 36028831378703360ull, 36028814198833664ull, 72057602627862784ull, 36028801313931392ull, 70369817927680ull, 140739635847168ull, 140737756798976ull, 70368878396416ull, 70368811287040ull, 70368777732352ull, 562949986975745ull, 70369817919616ull, 36029346774794240ull, 4503874505285632ull, 1099513724944ull, 2199027449864ull, 549756863488ull, 2199024304132ull, 4398047559681ull, 2199023288321ull, 70369817927680ull, 4503600164243456ull, 9007201402228736ull, 4503601774856192ull, 140739635840000ull, 4400193995264ull, 140739635839232ull, 9007201402224896ull, 70368752566400ull, 70368752566304ull, 17592194433056ull, 17592194433032ull, 137472507908ull, 17592219598856ull, 2199040032772ull, 2151678016ull, 9007474132680704ull, 2305843146652663808ull, 68720009216ull, 34628174848ull, 274878169090ull, 68719607812ull, 4295098376ull, 2147614721ull, 70369281048640ull, 4503600164241472ull, 2251800082120768ull, 1125900041060416ull, 2251799880794176ull, 1125899940397184ull, 72057602627862784ull, 9007203549708416ull, 549755830273ull, 274877915137ull, 137438957569ull, 68719478785ull, 34359739393ull, 17179869697ull, 281475010265089ull, 8589967361ull };
        uint64_t bish_magics[64] = { 4398054899720ull, 2199023583232ull, 281475077373952ull, 290482176502267904ull, 37154714105675776ull, 144678138163494912ull, 9223376434901811200ull, 144115196665792512ull, 17592219598880ull, 17592194433040ull, 72057595111800832ull, 2305847407293759488ull, 9295429631161139200ull, 1152921642046849024ull, 4611686027017338880ull, 288230393331582976ull, 9007199791612160ull, 68720001280ull, 562949955518976ull, 281475245146624ull, 9223442405600002048ull, 562950087640064ull, 288230384741648384ull, 72057602627863040ull, 1152956688978939904ull, 140737756792832ull, 17592202821760ull, 2199027449858ull, 17592219598912ull, 549756862592ull, 4611686087146868736ull, 72057731476881920ull, 144115462953762848ull, 36028814198837248ull, 274878431234ull, 275146342416ull, 35184640524292ull, 9007200328484864ull, 70377334114304ull, 140746078290432ull, 576460786663170048ull, 72057611217801216ull, 17592253153344ull, 72057594054705280ull, 671089664ull, 2199157473536ull, 4503599694479616ull, 73014444288ull, 144119586123415552ull, 144117387099635712ull, 72057602628124672ull, 1224979098644905984ull, 288230651029684224ull, 72057731476883456ull, 17600775983104ull, 140771848101888ull, 9223372045444712448ull, 144115196665792512ull, 9007199321850880ull, 1297036692682703360ull, 1152921505680589056ull, 1152921505143718016ull, 301990912ull, 35184380477456ull };
        int rook_offsets[64] = { 84, 87, 78, 60, 66, 72, 0, 21, 111, 390, 102, 75, 57, 30, 0, 9, 96, 168, 1056, 516, 213, 126, 216, 108, 24, 15, 0, 12, 114, 186, 576, 39, 417, 993, 381, 114, 102, 96, 51, 90, 6, 27, 324, 2805, 633, 5166, 1068, 174, 3, 0, 0, 0, 3, 3, 12, 12, 0, 45, 33, 12, 6, 27, 45, 54 };
        int bish_offsets[64] = { 501, 240, 138, 3, 3, 0, 111, 45, 237, 222, 126, 78, 3, 48, 96, 15, 48, 72, 417, 126, 126, 21, 33, 27, 6, 78, 120, 162, 5616, 159, 99, 33, 108, 102, 363, 12501, 6885, 21, 87, 87, 12, 6, 48, 102, 66, 78, 33, 60, 123, 117, 48, 6, 78, 36, 282, 246, 57, 36, 42, 6, 75, 3, 180, 435 };
        attack_table = new uint64_t[274645];
        for (int sq = 0; sq < 64; sq++) {
            int relevant_bits = 1ull << std::popcount(~bish_masks[sq]);
            for (uint64_t blocker = 0; blocker < relevant_bits; blocker++) {
                uint64_t occ = bit_deposit(blocker, ~bish_masks[sq]);
                uint64_t* attacks = attack_table + bish_offsets[sq];
                uint64_t index = ((occ | bish_masks[sq]) * bish_magics[sq]) >> 46;
                attacks[index] = bish(sq, occ);
            }
        }
        for (int sq = 0; sq < 64; sq++) {
            int relevant_bits = 1ull << std::popcount(~rook_masks[sq]);
            for (uint64_t blocker = 0; blocker < relevant_bits; blocker++) {
                uint64_t occ = bit_deposit(blocker, ~rook_masks[sq]);
                uint64_t* attacks = attack_table + rook_offsets[sq];
                uint64_t index = ((occ | rook_masks[sq]) * rook_magics[sq]) >> 46;
                attacks[index] = rook(sq, occ);
            }
        }
    }

    static inline uint64_t rook(int sq, uint64_t occ) {
        uint64_t m = occ | rook_masks[sq];
        switch (sq) {
        case 0: return (attack_table + 84)[((m << 14) + (m << 39) + (m << 55)) >> 46];
        case 1: return (attack_table + 87)[((m << 13) + (m << 36) + (m << 54)) >> 46];
        case 2: return (attack_table + 78)[((m << 12) + (m << 37) + (m << 55)) >> 46];
        case 3: return (attack_table + 60)[((m << 11) + (m << 36) + (m << 55)) >> 46];
        case 4: return (attack_table + 66)[((m << 10) + (m << 35) + (m << 55)) >> 46];
        case 5: return (attack_table + 72)[((m << 9) + (m << 34) + (m << 55)) >> 46];
        case 6: return (attack_table + 0)[((m << 8) + (m << 33) + (m << 56)) >> 46];
        case 7: return (attack_table + 21)[((m << 7) + (m << 32) + (m << 55)) >> 46];
        case 8: return (attack_table + 111)[((m << 13) + (m << 30) + (m << 46)) >> 46];
        case 9: return (attack_table + 390)[((m << 13) + (m << 31) + (m << 47)) >> 46];
        case 10: return (attack_table + 102)[((m << 13) + (m << 28) + (m << 47)) >> 46];
        case 11: return (attack_table + 75)[((m << 10) + (m << 27) + (m << 46)) >> 46];
        case 12: return (attack_table + 57)[((m << 9) + (m << 26) + (m << 46)) >> 46];
        case 13: return (attack_table + 30)[((m << 8) + (m << 25) + (m << 46)) >> 46];
        case 14: return (attack_table + 0)[((m << 0) + (m << 25) + (m << 49)) >> 46];
        case 15: return (attack_table + 9)[((m << 7) + (m << 30) + (m << 46)) >> 46];
        case 16: return (attack_table + 96)[((m << 14) + (m << 39) + (m << 55)) >> 46];
        case 17: return (attack_table + 168)[((m << 13) + (m << 38) + (m << 52)) >> 46];
        case 18: return (attack_table + 1056)[((m << 4) + (m << 21) + (m << 40)) >> 46];
        case 19: return (attack_table + 516)[((m << 3) + (m << 22) + (m << 41)) >> 46];
        case 20: return (attack_table + 213)[((m << 10) + (m << 20) + (m << 39)) >> 46];
        case 21: return (attack_table + 126)[((m << 2) + (m << 20) + (m << 41)) >> 46];
        case 22: return (attack_table + 216)[((m << 0) + (m << 20) + (m << 42)) >> 46];
        case 23: return (attack_table + 108)[((m << 0) + (m << 15) + (m << 41)) >> 46];
        case 24: return (attack_table + 24)[((m << 13) + (m << 30) + (m << 46)) >> 46];
        case 25: return (attack_table + 15)[((m << 11) + (m << 29) + (m << 52)) >> 46];
        case 26: return (attack_table + 0)[((m << 12) + (m << 31) + (m << 53)) >> 46];
        case 27: return (attack_table + 12)[((m << 11) + (m << 31) + (m << 52)) >> 46];
        case 28: return (attack_table + 114)[((m << 10) + (m << 31) + (m << 47)) >> 46];
        case 29: return (attack_table + 186)[((m << 9) + (m << 31) + (m << 42)) >> 46];
        case 30: return (attack_table + 576)[((m << 8) + (m << 31) + (m << 47)) >> 46];
        case 31: return (attack_table + 39)[((m << 8) + (m << 31) + (m << 53)) >> 46];
        case 32: return (attack_table + 417)[((m << 7) + (m << 23) + (m << 46)) >> 46];
        case 33: return (attack_table + 993)[((m << 5) + (m << 23) + (m << 46)) >> 46];
        case 34: return (attack_table + 381)[((m << 5) + (m << 23) + (m << 44)) >> 46];
        case 35: return (attack_table + 114)[((m << 3) + (m << 23) + (m << 44)) >> 46];
        case 36: return (attack_table + 102)[((m << 2) + (m << 25) + (m << 37)) >> 46];
        case 37: return (attack_table + 96)[((m << 3) + (m << 25) + (m << 44)) >> 46];
        case 38: return (attack_table + 51)[((m << 2) + (m << 24) + (m << 41)) >> 46];
        case 39: return (attack_table + 90)[((m << 6) + (m << 22) + (m << 31)) >> 46];
        case 40: return (attack_table + 6)[((m << 15) + (m << 38) + (m << 53)) >> 46];
        case 41: return (attack_table + 27)[((m << 14) + (m << 37) + (m << 61)) >> 46];
        case 42: return (attack_table + 324)[((m << 13) + (m << 19) + (m << 36)) >> 46];
        case 43: return (attack_table + 2805)[((m << 10) + (m << 28) + (m << 35)) >> 46];
        case 44: return (attack_table + 633)[((m << 1) + (m << 18) + (m << 38)) >> 46];
        case 45: return (attack_table + 5166)[((m << 2) + (m << 17) + (m << 36)) >> 46];
        case 46: return (attack_table + 1068)[((m << 3) + (m << 17) + (m << 32)) >> 46];
        case 47: return (attack_table + 174)[((m << 0) + (m << 17) + (m << 31)) >> 46];
        case 48: return (attack_table + 3)[((m << 6) + (m << 29) + (m << 46)) >> 46];
        case 49: return (attack_table + 0)[((m << 6) + (m << 29) + (m << 52)) >> 46];
        case 50: return (attack_table + 0)[((m << 6) + (m << 28) + (m << 51)) >> 46];
        case 51: return (attack_table + 0)[((m << 6) + (m << 27) + (m << 50)) >> 46];
        case 52: return (attack_table + 3)[((m << 6) + (m << 26) + (m << 51)) >> 46];
        case 53: return (attack_table + 3)[((m << 7) + (m << 25) + (m << 50)) >> 46];
        case 54: return (attack_table + 12)[((m << 8) + (m << 33) + (m << 56)) >> 46];
        case 55: return (attack_table + 12)[((m << 7) + (m << 32) + (m << 53)) >> 46];
        case 56: return (attack_table + 0)[((m << 0) + (m << 14) + (m << 39)) >> 46];
        case 57: return (attack_table + 45)[((m << 0) + (m << 13) + (m << 38)) >> 46];
        case 58: return (attack_table + 33)[((m << 0) + (m << 12) + (m << 37)) >> 46];
        case 59: return (attack_table + 12)[((m << 0) + (m << 11) + (m << 36)) >> 46];
        case 60: return (attack_table + 6)[((m << 0) + (m << 10) + (m << 35)) >> 46];
        case 61: return (attack_table + 27)[((m << 0) + (m << 9) + (m << 34)) >> 46];
        case 62: return (attack_table + 45)[((m << 0) + (m << 25) + (m << 48)) >> 46];
        case 63: return (attack_table + 54)[((m << 0) + (m << 15) + (m << 33)) >> 46];
        default: unreachable();
        }
    }

    static inline uint64_t bishop(int sq, uint64_t occ) {
        uint64_t m = occ | bish_masks[sq];
        switch (sq) {
        case 0: return (attack_table + 501)[((m << 3) + (m << 23) + (m << 42)) >> 46];
        case 1: return (attack_table + 240)[((m << 16) + (m << 18) + (m << 41)) >> 46];
        case 2: return (attack_table + 138)[((m << 25) + (m << 26) + (m << 48)) >> 46];
        case 3: return (attack_table + 3)[((m << 29) + (m << 51) + (m << 58)) >> 46];
        case 4: return (attack_table + 3)[((m << 34) + (m << 50) + (m << 55)) >> 46];
        case 5: return (attack_table + 0)[((m << 27) + (m << 49) + (m << 57)) >> 46];
        case 6: return (attack_table + 111)[((m << 19) + (m << 42) + (m << 63)) >> 46];
        case 7: return (attack_table + 45)[((m << 11) + (m << 33) + (m << 57)) >> 46];
        case 8: return (attack_table + 237)[((m << 5) + (m << 25) + (m << 44)) >> 46];
        case 9: return (attack_table + 222)[((m << 4) + (m << 23) + (m << 44)) >> 46];
        case 10: return (attack_table + 126)[((m << 17) + (m << 30) + (m << 56)) >> 46];
        case 11: return (attack_table + 78)[((m << 25) + (m << 42) + (m << 61)) >> 46];
        case 12: return (attack_table + 3)[((m << 28) + (m << 56) + (m << 63)) >> 46];
        case 13: return (attack_table + 48)[((m << 20) + (m << 37) + (m << 60)) >> 46];
        case 14: return (attack_table + 96)[((m << 14) + (m << 33) + (m << 62)) >> 46];
        case 15: return (attack_table + 15)[((m << 11) + (m << 34) + (m << 58)) >> 46];
        case 16: return (attack_table + 48)[((m << 8) + (m << 29) + (m << 53)) >> 46];
        case 17: return (attack_table + 72)[((m << 8) + (m << 19) + (m << 36)) >> 46];
        case 18: return (attack_table + 417)[((m << 9) + (m << 21) + (m << 49)) >> 46];
        case 19: return (attack_table + 126)[((m << 9) + (m << 28) + (m << 48)) >> 46];
        case 20: return (attack_table + 126)[((m << 20) + (m << 46) + (m << 63)) >> 46];
        case 21: return (attack_table + 21)[((m << 10) + (m << 27) + (m << 49)) >> 46];
        case 22: return (attack_table + 33)[((m << 11) + (m << 33) + (m << 58)) >> 46];
        case 23: return (attack_table + 27)[((m << 9) + (m << 33) + (m << 56)) >> 46];
        case 24: return (attack_table + 6)[((m << 12) + (m << 45) + (m << 60)) >> 46];
        case 25: return (attack_table + 78)[((m << 11) + (m << 28) + (m << 47)) >> 46];
        case 26: return (attack_table + 120)[((m << 7) + (m << 24) + (m << 44)) >> 46];
        case 27: return (attack_table + 162)[((m << 1) + (m << 22) + (m << 41)) >> 46];
        case 28: return (attack_table + 5616)[((m << 6) + (m << 25) + (m << 44)) >> 46];
        case 29: return (attack_table + 159)[((m << 7) + (m << 20) + (m << 39)) >> 46];
        case 30: return (attack_table + 99)[((m << 12) + (m << 36) + (m << 62)) >> 46];
        case 31: return (attack_table + 33)[((m << 9) + (m << 37) + (m << 56)) >> 46];
        case 32: return (attack_table + 108)[((m << 5) + (m << 38) + (m << 57)) >> 46];
        case 33: return (attack_table + 102)[((m << 12) + (m << 34) + (m << 55)) >> 46];
        case 34: return (attack_table + 363)[((m << 1) + (m << 19) + (m << 38)) >> 46];
        case 35: return (attack_table + 12501)[((m << 4) + (m << 28) + (m << 38)) >> 46];
        case 36: return (attack_table + 6885)[((m << 2) + (m << 28) + (m << 45)) >> 46];
        case 37: return (attack_table + 21)[((m << 11) + (m << 30) + (m << 53)) >> 46];
        case 38: return (attack_table + 87)[((m << 11) + (m << 33) + (m << 46)) >> 46];
        case 39: return (attack_table + 87)[((m << 9) + (m << 33) + (m << 47)) >> 46];
        case 40: return (attack_table + 12)[((m << 13) + (m << 35) + (m << 59)) >> 46];
        case 41: return (attack_table + 6)[((m << 12) + (m << 34) + (m << 56)) >> 46];
        case 42: return (attack_table + 48)[((m << 6) + (m << 26) + (m << 44)) >> 46];
        case 43: return (attack_table + 102)[((m << 7) + (m << 24) + (m << 56)) >> 46];
        case 44: return (attack_table + 66)[((m << 10) + (m << 27) + (m << 29)) >> 46];
        case 45: return (attack_table + 78)[((m << 8) + (m << 27) + (m << 41)) >> 46];
        case 46: return (attack_table + 33)[((m << 8) + (m << 26) + (m << 52)) >> 46];
        case 47: return (attack_table + 60)[((m << 8) + (m << 32) + (m << 36)) >> 46];
        case 48: return (attack_table + 123)[((m << 20) + (m << 42) + (m << 57)) >> 46];
        case 49: return (attack_table + 117)[((m << 19) + (m << 41) + (m << 57)) >> 46];
        case 50: return (attack_table + 48)[((m << 18) + (m << 33) + (m << 56)) >> 46];
        case 51: return (attack_table + 6)[((m << 17) + (m << 56) + (m << 60)) >> 46];
        case 52: return (attack_table + 78)[((m << 16) + (m << 38) + (m << 58)) >> 46];
        case 53: return (attack_table + 36)[((m << 11) + (m << 37) + (m << 56)) >> 46];
        case 54: return (attack_table + 282)[((m << 12) + (m << 33) + (m << 44)) >> 46];
        case 55: return (attack_table + 246)[((m << 13) + (m << 35) + (m << 47)) >> 46];
        case 56: return (attack_table + 57)[((m << 11) + (m << 33) + (m << 63)) >> 46];
        case 57: return (attack_table + 36)[((m << 11) + (m << 33) + (m << 57)) >> 46];
        case 58: return (attack_table + 42)[((m << 10) + (m << 26) + (m << 53)) >> 46];
        case 59: return (attack_table + 6)[((m << 9) + (m << 57) + (m << 60)) >> 46];
        case 60: return (attack_table + 75)[((m << 8) + (m << 30) + (m << 60)) >> 46];
        case 61: return (attack_table + 3)[((m << 7) + (m << 29) + (m << 60)) >> 46];
        case 62: return (attack_table + 180)[((m << 10) + (m << 25) + (m << 28)) >> 46];
        case 63: return (attack_table + 435)[((m << 4) + (m << 23) + (m << 45)) >> 46];
        default: unreachable();
        }
    }

    static inline uint64_t Queen(int sq, uint64_t occ) {
        return rook(sq, occ) | bishop(sq, occ);
    }

}