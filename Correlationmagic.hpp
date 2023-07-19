/**
 * Correlationmagic.hpp
 *
 * Copyright © 2023 Daniel Inführ
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited.
 * For Questions and allowance to use this code contact daniel.infuehr(@)live.de
 *
 * Maintained by Daniel Inführ, 2023
 *
 * @file Correlationmagic.hpp
 * @author Daniel Inführ
 * @copyright 2023
 * @section License
 */

#pragma once
#include <stdint.h>
#include <bit>

namespace Chess_Lookup::Correlationmagic {
	static constexpr uint64_t bishop_magics[8] = {
		 281754153844992ull,
		 1100594872576ull,
		 281483600331392ull,
		 2286985260581120ull,
		 1143509276953600ull,
		 563501328237568ull,
		 141289400076288ull,
		 565157600174592ull
	};
	static constexpr uint64_t rook_magics[32] = {
		 36028866279506054ull,
		 4503672709455874ull,
		 4521471020107776ull,
		 72057871080099328ull,
		 8848039510016ull,
		 13228769804300ull,
		 13194760423424ull,
		 14293923824128ull,
		 17600826707968ull,
		 4400195052352ull,
		 1099545446512ull,
		 274886345092ull,
		 616327823360ull,
		 291252477952ull,
		 141197247488ull,
		 69524849984ull,
		 1108320714880ull,
		 139643060232ull,
		 74367107584ull,
		 8827961600ull,
		 549890527232ull,
		 69285842944ull,
		 69264822274ull,
		 17252753410ull,
		 549760012160ull,
		 68721689104ull,
		 17180451856ull,
		 4295366944ull,
		 17730707194370ull,
		 2199158530242ull,
		 567070957698ull,
		 139066476548ull
	};

	static constexpr uint8_t bishop_spectralmagic[64][6] = {
	{ 8, 16, 22, 32, 38, 48 },
	{ 8, 16, 20, 23, 30, 40 },
	{ 7, 9, 17, 25, 33, 48 },
	{ 8, 14, 20, 30, 45, 51 },
	{ 10, 11, 22, 34, 44, 50 },
	{ 10, 23, 29, 30, 39, 49 },
	{ 11, 15, 23, 31, 39, 47 },
	{ 9, 13, 25, 33, 41, 49 } };


	static constexpr uint8_t rook_spectralmagic[64][7] = {
	{ 1, 2, 7, 22, 29, 36, 55 },
	{ 1, 13, 19, 26, 32, 36, 52 },
	{ 11, 18, 25, 32, 38, 44, 52 },
	{ 9, 10, 11, 24, 31, 38, 56 },
	{ 15, 22, 27, 28, 34, 35, 43 },
	{ 2, 3, 21, 28, 35, 42, 43 },
	{ 11, 17, 24, 26, 29, 42, 43 },
	{ 9, 15, 22, 28, 40, 42, 43 },
	{ 12, 17, 18, 24, 25, 33, 44 },
	{ 6, 8, 9, 13, 20, 31, 42 },
	{ 4, 5, 6, 11, 18, 25, 40 },
	{ 2, 7, 8, 14, 15, 23, 38 },
	{ 14, 31, 32, 33, 34, 35, 39 },
	{ 13, 28, 30, 31, 32, 33, 38 },
	{ 10, 16, 17, 29, 30, 31, 37 },
	{ 6, 8, 10, 16, 28, 29, 36 },
	{ 7, 20, 24, 26, 27, 33, 40 },
	{ 3, 21, 22, 24, 25, 31, 37 },
	{ 9, 21, 23, 28, 30, 32, 36 },
	{ 8, 20, 21, 25, 26, 27, 33 },
	{ 12, 15, 16, 17, 18, 27, 39 },
	{ 12, 17, 22, 23, 24, 29, 36 },
	{ 1, 12, 14, 16, 23, 29, 36 },
	{ 1, 13, 19, 20, 22, 26, 34 },
	{ 7, 8, 9, 10, 11, 22, 39 },
	{ 4, 9, 14, 15, 16, 21, 36 },
	{ 4, 10, 13, 14, 15, 19, 34 },
	{ 5, 8, 11, 12, 17, 18, 32 },
	{ 1, 9, 16, 23, 30, 37, 44 },
	{ 1, 6, 7, 13, 20, 27, 41 },
	{ 1, 7, 13, 20, 27, 34, 39 },
	{ 2, 11, 17, 24, 29, 30, 37 } };

	static constexpr uint64_t bishop_masks[64] = {
		 18428694421974023679ull, 18446673567257459711ull, 18446743798293722623ull, 18446744072633576447ull, 18446744073671530495ull, 18446744065051963391ull, 18446741857371152383ull, 18446176691079331839ull,
		 18437719247841787903ull, 18428694421974024191ull, 18446673567257329663ull, 18446743798259908607ull, 18446744063976144895ull, 18446741857366966271ull, 18446176691079348223ull, 18445609308449144831ull,
		 18442231660775734783ull, 18437719247841917951ull, 18428694421940729343ull, 18446673558600936447ull, 18446741581957421055ull, 18446176690007683071ull, 18445609308453330943ull, 18444474543197110271ull,
		 18444487867259288575ull, 18442231660809025535ull, 18437719239318433791ull, 18428692205904059903ull, 18446106185164110847ull, 18445609034107058175ull, 18444474544268767231ull, 18442205014827982847ull,
		 18445615974745634815ull, 18444487875781718015ull, 18442229478797074431ull, 18437151933931044863ull, 18427559794152570367ull, 18444404311622941695ull, 18442205289172170751ull, 18437666504634789887ull,
		 18446181115098558463ull, 18445618156487565311ull, 18443929280722223103ull, 18441114487701372927ull, 18435484901701451775ull, 18424225731840835071ull, 18437736736746896383ull, 18428729399784241151ull,
		 18446741857371152383ull, 18446739641032753151ull, 18446733009332731903ull, 18446721936374366207ull, 18446699801153110015ull, 18446656078352351231ull, 18446708820483505663ull, 18446673567257459711ull,
		 18446176691079331839ull, 18445609308449144831ull, 18443911593243705343ull, 18441076915902087167ull, 18435410299260502015ull, 18424217262266253311ull, 18437719247841787903ull, 18428694421974023679ull,
	};

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

	static inline uint64_t* attack_table_bishop;
	static inline uint64_t* attack_table_rook;

	static constexpr uint64_t Size = (64 * (1ull << 9) + 64 * (1ull << 12) + 64) * sizeof(uint64_t);

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
		attack_table_bishop = new uint64_t[64 * (1ull << 9)];
		attack_table_rook = new uint64_t[64 * (1ull << 12)];

		for (int sq = 0; sq < 64; sq++) {
			int relevant_bits = 1ull << std::popcount(~bishop_masks[sq]);
			for (uint64_t blocker = 0; blocker < relevant_bits; blocker++) {
				uint64_t occ = bit_deposit(blocker, ~bishop_masks[sq]);
				uint64_t* attacks = attack_table_bishop + (sq << 9);
				uint64_t magic = bishop_magics[sq >> 3] >> (sq & 7);
				uint64_t index = ((occ | bishop_masks[sq]) * magic) >> 55;
				attacks[index] = bish(sq, occ);
			}
		}
		for (int sq = 0; sq < 64; sq++) {
			int relevant_bits = 1ull << std::popcount(~rook_masks[sq]);
			for (uint64_t blocker = 0; blocker < relevant_bits; blocker++) {
				uint64_t occ = bit_deposit(blocker, ~rook_masks[sq]);
				uint64_t* attacks = attack_table_rook + (sq << 12);
				uint64_t magic = rook_magics[sq >> 1] >> (sq & 1);
				uint64_t index = ((occ | rook_masks[sq]) * magic) >> 52;
				attacks[index] = rook(sq, occ);
			}
		}

	}

	static inline uint64_t bishop(int sq, uint64_t occ) {
		uint64_t masked_occ = occ | bishop_masks[sq];
		uint64_t magic = bishop_magics[sq >> 3] >> (sq & 7);
		uint64_t index = (masked_occ * magic) >> 55;
		return  *(attack_table_bishop + (sq << 9) + index);
	};

	static inline uint64_t rook(int sq, uint64_t occ) {
		uint64_t masked_occ = occ | rook_masks[sq];
		uint64_t magic = rook_magics[sq >> 1] >> (sq & 1);
		uint64_t index = (masked_occ * magic) >> 52;
		return *(attack_table_rook + (sq << 12) + index);
	};

	uint64_t inline spectral_bishop(int sq, uint64_t occ) {
		uint64_t masked_occ = occ | bishop_masks[sq];
		uint64_t* attacks = attack_table_bishop + (sq << 9);
		const uint8_t* s = bishop_spectralmagic[sq >> 3];
		uint64_t index = (
			(masked_occ << (s[0] - (sq & 7))) +
			(masked_occ << (s[1] - (sq & 7))) +
			(masked_occ << (s[2] - (sq & 7))) +
			(masked_occ << (s[3] - (sq & 7))) +
			(masked_occ << (s[4] - (sq & 7))) +
			(masked_occ << (s[5] - (sq & 7)))) >> 55;
		return attacks[index];
	};

	uint64_t inline spectral_rook(int sq, uint64_t occ) {
		uint64_t masked_occ = occ | rook_masks[sq];
		uint64_t* attacks = attack_table_rook + (sq << 12);
		const uint8_t* s = rook_spectralmagic[sq >> 1];
		uint64_t index = (
			(masked_occ << (s[0] - (sq & 1))) +
			(masked_occ << (s[1] - (sq & 1))) +
			(masked_occ << (s[2] - (sq & 1))) +
			(masked_occ << (s[3] - (sq & 1))) +
			(masked_occ << (s[4] - (sq & 1))) +
			(masked_occ << (s[5] - (sq & 1))) +
			(masked_occ << (s[6] - (sq & 1)))) >> 52;
		return attacks[index];
	};


	static inline uint64_t SpectralQueen(int sq, uint64_t occ) {
		return spectral_bishop(sq, occ) | spectral_rook(sq, occ);
	}


	static inline uint64_t Queen(int sq, uint64_t occ) {
		return bishop(sq, occ) | rook(sq, occ);
	}

}