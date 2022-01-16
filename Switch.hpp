//(c) Daniel Inführ 2019
//for questions email to daniel.infuehr@live.de
//Created with Espresso Logistic Heuristic minimizer
#pragma once
#include <stdint.h>

namespace Chess_Lookup {
	static constexpr uint64_t GetSliderHCond(uint64_t SliderSquare, uint64_t occupy) {
		uint64_t result{};
		switch (SliderSquare) {
		case 0:
			result = 2ull;
			if ((occupy & 2ull) == 0) result |= 4ull;
			if ((occupy & 6ull) == 0) result |= 8ull;
			if ((occupy & 14ull) == 0) result |= 16ull;
			if ((occupy & 30ull) == 0) result |= 32ull;
			if ((occupy & 62ull) == 0) result |= 64ull;
			if ((occupy & 126ull) == 0) result |= 128ull;
			return result;
		case 1:
			result = 5ull;
			if ((occupy & 4ull) == 0) result |= 8ull;
			if ((occupy & 12ull) == 0) result |= 16ull;
			if ((occupy & 28ull) == 0) result |= 32ull;
			if ((occupy & 60ull) == 0) result |= 64ull;
			if ((occupy & 124ull) == 0) result |= 128ull;
			return result;
		case 2:
			result = 10ull;
			if ((occupy & 2ull) == 0) result |= 1ull;
			if ((occupy & 8ull) == 0) result |= 16ull;
			if ((occupy & 24ull) == 0) result |= 32ull;
			if ((occupy & 56ull) == 0) result |= 64ull;
			if ((occupy & 120ull) == 0) result |= 128ull;
			return result;
		case 3:
			result = 20ull;
			if ((occupy & 4ull) == 0) result |= 2ull;
			if ((occupy & 6ull) == 0) result |= 1ull;
			if ((occupy & 16ull) == 0) result |= 32ull;
			if ((occupy & 48ull) == 0) result |= 64ull;
			if ((occupy & 112ull) == 0) result |= 128ull;
			return result;
		case 4:
			result = 40ull;
			if ((occupy & 8ull) == 0) result |= 4ull;
			if ((occupy & 12ull) == 0) result |= 2ull;
			if ((occupy & 14ull) == 0) result |= 1ull;
			if ((occupy & 32ull) == 0) result |= 64ull;
			if ((occupy & 96ull) == 0) result |= 128ull;
			return result;
		case 5:
			result = 80ull;
			if ((occupy & 16ull) == 0) result |= 8ull;
			if ((occupy & 24ull) == 0) result |= 4ull;
			if ((occupy & 28ull) == 0) result |= 2ull;
			if ((occupy & 30ull) == 0) result |= 1ull;
			if ((occupy & 64ull) == 0) result |= 128ull;
			return result;
		case 6:
			result = 160ull;
			if ((occupy & 32ull) == 0) result |= 16ull;
			if ((occupy & 48ull) == 0) result |= 8ull;
			if ((occupy & 56ull) == 0) result |= 4ull;
			if ((occupy & 60ull) == 0) result |= 2ull;
			if ((occupy & 62ull) == 0) result |= 1ull;
			return result;
		case 7:
			result = 64ull;
			if ((occupy & 64ull) == 0) result |= 32ull;
			if ((occupy & 96ull) == 0) result |= 16ull;
			if ((occupy & 112ull) == 0) result |= 8ull;
			if ((occupy & 120ull) == 0) result |= 4ull;
			if ((occupy & 124ull) == 0) result |= 2ull;
			if ((occupy & 126ull) == 0) result |= 1ull;
			return result;
		case 8:
			result = 512ull;
			if ((occupy & 512ull) == 0) result |= 1024ull;
			if ((occupy & 1536ull) == 0) result |= 2048ull;
			if ((occupy & 3584ull) == 0) result |= 4096ull;
			if ((occupy & 7680ull) == 0) result |= 8192ull;
			if ((occupy & 15872ull) == 0) result |= 16384ull;
			if ((occupy & 32256ull) == 0) result |= 32768ull;
			return result;
		case 9:
			result = 1280ull;
			if ((occupy & 1024ull) == 0) result |= 2048ull;
			if ((occupy & 3072ull) == 0) result |= 4096ull;
			if ((occupy & 7168ull) == 0) result |= 8192ull;
			if ((occupy & 15360ull) == 0) result |= 16384ull;
			if ((occupy & 31744ull) == 0) result |= 32768ull;
			return result;
		case 10:
			result = 2560ull;
			if ((occupy & 512ull) == 0) result |= 256ull;
			if ((occupy & 2048ull) == 0) result |= 4096ull;
			if ((occupy & 6144ull) == 0) result |= 8192ull;
			if ((occupy & 14336ull) == 0) result |= 16384ull;
			if ((occupy & 30720ull) == 0) result |= 32768ull;
			return result;
		case 11:
			result = 5120ull;
			if ((occupy & 1024ull) == 0) result |= 512ull;
			if ((occupy & 1536ull) == 0) result |= 256ull;
			if ((occupy & 4096ull) == 0) result |= 8192ull;
			if ((occupy & 12288ull) == 0) result |= 16384ull;
			if ((occupy & 28672ull) == 0) result |= 32768ull;
			return result;
		case 12:
			result = 10240ull;
			if ((occupy & 2048ull) == 0) result |= 1024ull;
			if ((occupy & 3072ull) == 0) result |= 512ull;
			if ((occupy & 3584ull) == 0) result |= 256ull;
			if ((occupy & 8192ull) == 0) result |= 16384ull;
			if ((occupy & 24576ull) == 0) result |= 32768ull;
			return result;
		case 13:
			result = 20480ull;
			if ((occupy & 4096ull) == 0) result |= 2048ull;
			if ((occupy & 6144ull) == 0) result |= 1024ull;
			if ((occupy & 7168ull) == 0) result |= 512ull;
			if ((occupy & 7680ull) == 0) result |= 256ull;
			if ((occupy & 16384ull) == 0) result |= 32768ull;
			return result;
		case 14:
			result = 40960ull;
			if ((occupy & 8192ull) == 0) result |= 4096ull;
			if ((occupy & 12288ull) == 0) result |= 2048ull;
			if ((occupy & 14336ull) == 0) result |= 1024ull;
			if ((occupy & 15360ull) == 0) result |= 512ull;
			if ((occupy & 15872ull) == 0) result |= 256ull;
			return result;
		case 15:
			result = 16384ull;
			if ((occupy & 16384ull) == 0) result |= 8192ull;
			if ((occupy & 24576ull) == 0) result |= 4096ull;
			if ((occupy & 28672ull) == 0) result |= 2048ull;
			if ((occupy & 30720ull) == 0) result |= 1024ull;
			if ((occupy & 31744ull) == 0) result |= 512ull;
			if ((occupy & 32256ull) == 0) result |= 256ull;
			return result;
		case 16:
			result = 131072ull;
			if ((occupy & 131072ull) == 0) result |= 262144ull;
			if ((occupy & 393216ull) == 0) result |= 524288ull;
			if ((occupy & 917504ull) == 0) result |= 1048576ull;
			if ((occupy & 1966080ull) == 0) result |= 2097152ull;
			if ((occupy & 4063232ull) == 0) result |= 4194304ull;
			if ((occupy & 8257536ull) == 0) result |= 8388608ull;
			return result;
		case 17:
			result = 327680ull;
			if ((occupy & 262144ull) == 0) result |= 524288ull;
			if ((occupy & 786432ull) == 0) result |= 1048576ull;
			if ((occupy & 1835008ull) == 0) result |= 2097152ull;
			if ((occupy & 3932160ull) == 0) result |= 4194304ull;
			if ((occupy & 8126464ull) == 0) result |= 8388608ull;
			return result;
		case 18:
			result = 655360ull;
			if ((occupy & 131072ull) == 0) result |= 65536ull;
			if ((occupy & 524288ull) == 0) result |= 1048576ull;
			if ((occupy & 1572864ull) == 0) result |= 2097152ull;
			if ((occupy & 3670016ull) == 0) result |= 4194304ull;
			if ((occupy & 7864320ull) == 0) result |= 8388608ull;
			return result;
		case 19:
			result = 1310720ull;
			if ((occupy & 262144ull) == 0) result |= 131072ull;
			if ((occupy & 393216ull) == 0) result |= 65536ull;
			if ((occupy & 1048576ull) == 0) result |= 2097152ull;
			if ((occupy & 3145728ull) == 0) result |= 4194304ull;
			if ((occupy & 7340032ull) == 0) result |= 8388608ull;
			return result;
		case 20:
			result = 2621440ull;
			if ((occupy & 524288ull) == 0) result |= 262144ull;
			if ((occupy & 786432ull) == 0) result |= 131072ull;
			if ((occupy & 917504ull) == 0) result |= 65536ull;
			if ((occupy & 2097152ull) == 0) result |= 4194304ull;
			if ((occupy & 6291456ull) == 0) result |= 8388608ull;
			return result;
		case 21:
			result = 5242880ull;
			if ((occupy & 1048576ull) == 0) result |= 524288ull;
			if ((occupy & 1572864ull) == 0) result |= 262144ull;
			if ((occupy & 1835008ull) == 0) result |= 131072ull;
			if ((occupy & 1966080ull) == 0) result |= 65536ull;
			if ((occupy & 4194304ull) == 0) result |= 8388608ull;
			return result;
		case 22:
			result = 10485760ull;
			if ((occupy & 2097152ull) == 0) result |= 1048576ull;
			if ((occupy & 3145728ull) == 0) result |= 524288ull;
			if ((occupy & 3670016ull) == 0) result |= 262144ull;
			if ((occupy & 3932160ull) == 0) result |= 131072ull;
			if ((occupy & 4063232ull) == 0) result |= 65536ull;
			return result;
		case 23:
			result = 4194304ull;
			if ((occupy & 4194304ull) == 0) result |= 2097152ull;
			if ((occupy & 6291456ull) == 0) result |= 1048576ull;
			if ((occupy & 7340032ull) == 0) result |= 524288ull;
			if ((occupy & 7864320ull) == 0) result |= 262144ull;
			if ((occupy & 8126464ull) == 0) result |= 131072ull;
			if ((occupy & 8257536ull) == 0) result |= 65536ull;
			return result;
		case 24:
			result = 33554432ull;
			if ((occupy & 33554432ull) == 0) result |= 67108864ull;
			if ((occupy & 100663296ull) == 0) result |= 134217728ull;
			if ((occupy & 234881024ull) == 0) result |= 268435456ull;
			if ((occupy & 503316480ull) == 0) result |= 536870912ull;
			if ((occupy & 1040187392ull) == 0) result |= 1073741824ull;
			if ((occupy & 2113929216ull) == 0) result |= 2147483648ull;
			return result;
		case 25:
			result = 83886080ull;
			if ((occupy & 67108864ull) == 0) result |= 134217728ull;
			if ((occupy & 201326592ull) == 0) result |= 268435456ull;
			if ((occupy & 469762048ull) == 0) result |= 536870912ull;
			if ((occupy & 1006632960ull) == 0) result |= 1073741824ull;
			if ((occupy & 2080374784ull) == 0) result |= 2147483648ull;
			return result;
		case 26:
			result = 167772160ull;
			if ((occupy & 33554432ull) == 0) result |= 16777216ull;
			if ((occupy & 134217728ull) == 0) result |= 268435456ull;
			if ((occupy & 402653184ull) == 0) result |= 536870912ull;
			if ((occupy & 939524096ull) == 0) result |= 1073741824ull;
			if ((occupy & 2013265920ull) == 0) result |= 2147483648ull;
			return result;
		case 27:
			result = 335544320ull;
			if ((occupy & 67108864ull) == 0) result |= 33554432ull;
			if ((occupy & 100663296ull) == 0) result |= 16777216ull;
			if ((occupy & 268435456ull) == 0) result |= 536870912ull;
			if ((occupy & 805306368ull) == 0) result |= 1073741824ull;
			if ((occupy & 1879048192ull) == 0) result |= 2147483648ull;
			return result;
		case 28:
			result = 671088640ull;
			if ((occupy & 134217728ull) == 0) result |= 67108864ull;
			if ((occupy & 201326592ull) == 0) result |= 33554432ull;
			if ((occupy & 234881024ull) == 0) result |= 16777216ull;
			if ((occupy & 536870912ull) == 0) result |= 1073741824ull;
			if ((occupy & 1610612736ull) == 0) result |= 2147483648ull;
			return result;
		case 29:
			result = 1342177280ull;
			if ((occupy & 268435456ull) == 0) result |= 134217728ull;
			if ((occupy & 402653184ull) == 0) result |= 67108864ull;
			if ((occupy & 469762048ull) == 0) result |= 33554432ull;
			if ((occupy & 503316480ull) == 0) result |= 16777216ull;
			if ((occupy & 1073741824ull) == 0) result |= 2147483648ull;
			return result;
		case 30:
			result = 2684354560ull;
			if ((occupy & 536870912ull) == 0) result |= 268435456ull;
			if ((occupy & 805306368ull) == 0) result |= 134217728ull;
			if ((occupy & 939524096ull) == 0) result |= 67108864ull;
			if ((occupy & 1006632960ull) == 0) result |= 33554432ull;
			if ((occupy & 1040187392ull) == 0) result |= 16777216ull;
			return result;
		case 31:
			result = 1073741824ull;
			if ((occupy & 1073741824ull) == 0) result |= 536870912ull;
			if ((occupy & 1610612736ull) == 0) result |= 268435456ull;
			if ((occupy & 1879048192ull) == 0) result |= 134217728ull;
			if ((occupy & 2013265920ull) == 0) result |= 67108864ull;
			if ((occupy & 2080374784ull) == 0) result |= 33554432ull;
			if ((occupy & 2113929216ull) == 0) result |= 16777216ull;
			return result;
		case 32:
			result = 8589934592ull;
			if ((occupy & 8589934592ull) == 0) result |= 17179869184ull;
			if ((occupy & 25769803776ull) == 0) result |= 34359738368ull;
			if ((occupy & 60129542144ull) == 0) result |= 68719476736ull;
			if ((occupy & 128849018880ull) == 0) result |= 137438953472ull;
			if ((occupy & 266287972352ull) == 0) result |= 274877906944ull;
			if ((occupy & 541165879296ull) == 0) result |= 549755813888ull;
			return result;
		case 33:
			result = 21474836480ull;
			if ((occupy & 17179869184ull) == 0) result |= 34359738368ull;
			if ((occupy & 51539607552ull) == 0) result |= 68719476736ull;
			if ((occupy & 120259084288ull) == 0) result |= 137438953472ull;
			if ((occupy & 257698037760ull) == 0) result |= 274877906944ull;
			if ((occupy & 532575944704ull) == 0) result |= 549755813888ull;
			return result;
		case 34:
			result = 42949672960ull;
			if ((occupy & 8589934592ull) == 0) result |= 4294967296ull;
			if ((occupy & 34359738368ull) == 0) result |= 68719476736ull;
			if ((occupy & 103079215104ull) == 0) result |= 137438953472ull;
			if ((occupy & 240518168576ull) == 0) result |= 274877906944ull;
			if ((occupy & 515396075520ull) == 0) result |= 549755813888ull;
			return result;
		case 35:
			result = 85899345920ull;
			if ((occupy & 17179869184ull) == 0) result |= 8589934592ull;
			if ((occupy & 25769803776ull) == 0) result |= 4294967296ull;
			if ((occupy & 68719476736ull) == 0) result |= 137438953472ull;
			if ((occupy & 206158430208ull) == 0) result |= 274877906944ull;
			if ((occupy & 481036337152ull) == 0) result |= 549755813888ull;
			return result;
		case 36:
			result = 171798691840ull;
			if ((occupy & 34359738368ull) == 0) result |= 17179869184ull;
			if ((occupy & 51539607552ull) == 0) result |= 8589934592ull;
			if ((occupy & 60129542144ull) == 0) result |= 4294967296ull;
			if ((occupy & 137438953472ull) == 0) result |= 274877906944ull;
			if ((occupy & 412316860416ull) == 0) result |= 549755813888ull;
			return result;
		case 37:
			result = 343597383680ull;
			if ((occupy & 68719476736ull) == 0) result |= 34359738368ull;
			if ((occupy & 103079215104ull) == 0) result |= 17179869184ull;
			if ((occupy & 120259084288ull) == 0) result |= 8589934592ull;
			if ((occupy & 128849018880ull) == 0) result |= 4294967296ull;
			if ((occupy & 274877906944ull) == 0) result |= 549755813888ull;
			return result;
		case 38:
			result = 687194767360ull;
			if ((occupy & 137438953472ull) == 0) result |= 68719476736ull;
			if ((occupy & 206158430208ull) == 0) result |= 34359738368ull;
			if ((occupy & 240518168576ull) == 0) result |= 17179869184ull;
			if ((occupy & 257698037760ull) == 0) result |= 8589934592ull;
			if ((occupy & 266287972352ull) == 0) result |= 4294967296ull;
			return result;
		case 39:
			result = 274877906944ull;
			if ((occupy & 274877906944ull) == 0) result |= 137438953472ull;
			if ((occupy & 412316860416ull) == 0) result |= 68719476736ull;
			if ((occupy & 481036337152ull) == 0) result |= 34359738368ull;
			if ((occupy & 515396075520ull) == 0) result |= 17179869184ull;
			if ((occupy & 532575944704ull) == 0) result |= 8589934592ull;
			if ((occupy & 541165879296ull) == 0) result |= 4294967296ull;
			return result;
		case 40:
			result = 2199023255552ull;
			if ((occupy & 2199023255552ull) == 0) result |= 4398046511104ull;
			if ((occupy & 6597069766656ull) == 0) result |= 8796093022208ull;
			if ((occupy & 15393162788864ull) == 0) result |= 17592186044416ull;
			if ((occupy & 32985348833280ull) == 0) result |= 35184372088832ull;
			if ((occupy & 68169720922112ull) == 0) result |= 70368744177664ull;
			if ((occupy & 138538465099776ull) == 0) result |= 140737488355328ull;
			return result;
		case 41:
			result = 5497558138880ull;
			if ((occupy & 4398046511104ull) == 0) result |= 8796093022208ull;
			if ((occupy & 13194139533312ull) == 0) result |= 17592186044416ull;
			if ((occupy & 30786325577728ull) == 0) result |= 35184372088832ull;
			if ((occupy & 65970697666560ull) == 0) result |= 70368744177664ull;
			if ((occupy & 136339441844224ull) == 0) result |= 140737488355328ull;
			return result;
		case 42:
			result = 10995116277760ull;
			if ((occupy & 2199023255552ull) == 0) result |= 1099511627776ull;
			if ((occupy & 8796093022208ull) == 0) result |= 17592186044416ull;
			if ((occupy & 26388279066624ull) == 0) result |= 35184372088832ull;
			if ((occupy & 61572651155456ull) == 0) result |= 70368744177664ull;
			if ((occupy & 131941395333120ull) == 0) result |= 140737488355328ull;
			return result;
		case 43:
			result = 21990232555520ull;
			if ((occupy & 4398046511104ull) == 0) result |= 2199023255552ull;
			if ((occupy & 6597069766656ull) == 0) result |= 1099511627776ull;
			if ((occupy & 17592186044416ull) == 0) result |= 35184372088832ull;
			if ((occupy & 52776558133248ull) == 0) result |= 70368744177664ull;
			if ((occupy & 123145302310912ull) == 0) result |= 140737488355328ull;
			return result;
		case 44:
			result = 43980465111040ull;
			if ((occupy & 8796093022208ull) == 0) result |= 4398046511104ull;
			if ((occupy & 13194139533312ull) == 0) result |= 2199023255552ull;
			if ((occupy & 15393162788864ull) == 0) result |= 1099511627776ull;
			if ((occupy & 35184372088832ull) == 0) result |= 70368744177664ull;
			if ((occupy & 105553116266496ull) == 0) result |= 140737488355328ull;
			return result;
		case 45:
			result = 87960930222080ull;
			if ((occupy & 17592186044416ull) == 0) result |= 8796093022208ull;
			if ((occupy & 26388279066624ull) == 0) result |= 4398046511104ull;
			if ((occupy & 30786325577728ull) == 0) result |= 2199023255552ull;
			if ((occupy & 32985348833280ull) == 0) result |= 1099511627776ull;
			if ((occupy & 70368744177664ull) == 0) result |= 140737488355328ull;
			return result;
		case 46:
			result = 175921860444160ull;
			if ((occupy & 35184372088832ull) == 0) result |= 17592186044416ull;
			if ((occupy & 52776558133248ull) == 0) result |= 8796093022208ull;
			if ((occupy & 61572651155456ull) == 0) result |= 4398046511104ull;
			if ((occupy & 65970697666560ull) == 0) result |= 2199023255552ull;
			if ((occupy & 68169720922112ull) == 0) result |= 1099511627776ull;
			return result;
		case 47:
			result = 70368744177664ull;
			if ((occupy & 70368744177664ull) == 0) result |= 35184372088832ull;
			if ((occupy & 105553116266496ull) == 0) result |= 17592186044416ull;
			if ((occupy & 123145302310912ull) == 0) result |= 8796093022208ull;
			if ((occupy & 131941395333120ull) == 0) result |= 4398046511104ull;
			if ((occupy & 136339441844224ull) == 0) result |= 2199023255552ull;
			if ((occupy & 138538465099776ull) == 0) result |= 1099511627776ull;
			return result;
		case 48:
			result = 562949953421312ull;
			if ((occupy & 562949953421312ull) == 0) result |= 1125899906842624ull;
			if ((occupy & 1688849860263936ull) == 0) result |= 2251799813685248ull;
			if ((occupy & 3940649673949184ull) == 0) result |= 4503599627370496ull;
			if ((occupy & 8444249301319680ull) == 0) result |= 9007199254740992ull;
			if ((occupy & 17451448556060672ull) == 0) result |= 18014398509481984ull;
			if ((occupy & 35465847065542656ull) == 0) result |= 36028797018963968ull;
			return result;
		case 49:
			result = 1407374883553280ull;
			if ((occupy & 1125899906842624ull) == 0) result |= 2251799813685248ull;
			if ((occupy & 3377699720527872ull) == 0) result |= 4503599627370496ull;
			if ((occupy & 7881299347898368ull) == 0) result |= 9007199254740992ull;
			if ((occupy & 16888498602639360ull) == 0) result |= 18014398509481984ull;
			if ((occupy & 34902897112121344ull) == 0) result |= 36028797018963968ull;
			return result;
		case 50:
			result = 2814749767106560ull;
			if ((occupy & 562949953421312ull) == 0) result |= 281474976710656ull;
			if ((occupy & 2251799813685248ull) == 0) result |= 4503599627370496ull;
			if ((occupy & 6755399441055744ull) == 0) result |= 9007199254740992ull;
			if ((occupy & 15762598695796736ull) == 0) result |= 18014398509481984ull;
			if ((occupy & 33776997205278720ull) == 0) result |= 36028797018963968ull;
			return result;
		case 51:
			result = 5629499534213120ull;
			if ((occupy & 1125899906842624ull) == 0) result |= 562949953421312ull;
			if ((occupy & 1688849860263936ull) == 0) result |= 281474976710656ull;
			if ((occupy & 4503599627370496ull) == 0) result |= 9007199254740992ull;
			if ((occupy & 13510798882111488ull) == 0) result |= 18014398509481984ull;
			if ((occupy & 31525197391593472ull) == 0) result |= 36028797018963968ull;
			return result;
		case 52:
			result = 11258999068426240ull;
			if ((occupy & 2251799813685248ull) == 0) result |= 1125899906842624ull;
			if ((occupy & 3377699720527872ull) == 0) result |= 562949953421312ull;
			if ((occupy & 3940649673949184ull) == 0) result |= 281474976710656ull;
			if ((occupy & 9007199254740992ull) == 0) result |= 18014398509481984ull;
			if ((occupy & 27021597764222976ull) == 0) result |= 36028797018963968ull;
			return result;
		case 53:
			result = 22517998136852480ull;
			if ((occupy & 4503599627370496ull) == 0) result |= 2251799813685248ull;
			if ((occupy & 6755399441055744ull) == 0) result |= 1125899906842624ull;
			if ((occupy & 7881299347898368ull) == 0) result |= 562949953421312ull;
			if ((occupy & 8444249301319680ull) == 0) result |= 281474976710656ull;
			if ((occupy & 18014398509481984ull) == 0) result |= 36028797018963968ull;
			return result;
		case 54:
			result = 45035996273704960ull;
			if ((occupy & 9007199254740992ull) == 0) result |= 4503599627370496ull;
			if ((occupy & 13510798882111488ull) == 0) result |= 2251799813685248ull;
			if ((occupy & 15762598695796736ull) == 0) result |= 1125899906842624ull;
			if ((occupy & 16888498602639360ull) == 0) result |= 562949953421312ull;
			if ((occupy & 17451448556060672ull) == 0) result |= 281474976710656ull;
			return result;
		case 55:
			result = 18014398509481984ull;
			if ((occupy & 18014398509481984ull) == 0) result |= 9007199254740992ull;
			if ((occupy & 27021597764222976ull) == 0) result |= 4503599627370496ull;
			if ((occupy & 31525197391593472ull) == 0) result |= 2251799813685248ull;
			if ((occupy & 33776997205278720ull) == 0) result |= 1125899906842624ull;
			if ((occupy & 34902897112121344ull) == 0) result |= 562949953421312ull;
			if ((occupy & 35465847065542656ull) == 0) result |= 281474976710656ull;
			return result;
		case 56:
			result = 144115188075855872ull;
			if ((occupy & 144115188075855872ull) == 0) result |= 288230376151711744ull;
			if ((occupy & 432345564227567616ull) == 0) result |= 576460752303423488ull;
			if ((occupy & 1008806316530991104ull) == 0) result |= 1152921504606846976ull;
			if ((occupy & 2161727821137838080ull) == 0) result |= 2305843009213693952ull;
			if ((occupy & 4467570830351532032ull) == 0) result |= 4611686018427387904ull;
			if ((occupy & 9079256848778919936ull) == 0) result |= 9223372036854775808ull;
			return result;
		case 57:
			result = 360287970189639680ull;
			if ((occupy & 288230376151711744ull) == 0) result |= 576460752303423488ull;
			if ((occupy & 864691128455135232ull) == 0) result |= 1152921504606846976ull;
			if ((occupy & 2017612633061982208ull) == 0) result |= 2305843009213693952ull;
			if ((occupy & 4323455642275676160ull) == 0) result |= 4611686018427387904ull;
			if ((occupy & 8935141660703064064ull) == 0) result |= 9223372036854775808ull;
			return result;
		case 58:
			result = 720575940379279360ull;
			if ((occupy & 144115188075855872ull) == 0) result |= 72057594037927936ull;
			if ((occupy & 576460752303423488ull) == 0) result |= 1152921504606846976ull;
			if ((occupy & 1729382256910270464ull) == 0) result |= 2305843009213693952ull;
			if ((occupy & 4035225266123964416ull) == 0) result |= 4611686018427387904ull;
			if ((occupy & 8646911284551352320ull) == 0) result |= 9223372036854775808ull;
			return result;
		case 59:
			result = 1441151880758558720ull;
			if ((occupy & 288230376151711744ull) == 0) result |= 144115188075855872ull;
			if ((occupy & 432345564227567616ull) == 0) result |= 72057594037927936ull;
			if ((occupy & 1152921504606846976ull) == 0) result |= 2305843009213693952ull;
			if ((occupy & 3458764513820540928ull) == 0) result |= 4611686018427387904ull;
			if ((occupy & 8070450532247928832ull) == 0) result |= 9223372036854775808ull;
			return result;
		case 60:
			result = 2882303761517117440ull;
			if ((occupy & 576460752303423488ull) == 0) result |= 288230376151711744ull;
			if ((occupy & 864691128455135232ull) == 0) result |= 144115188075855872ull;
			if ((occupy & 1008806316530991104ull) == 0) result |= 72057594037927936ull;
			if ((occupy & 2305843009213693952ull) == 0) result |= 4611686018427387904ull;
			if ((occupy & 6917529027641081856ull) == 0) result |= 9223372036854775808ull;
			return result;
		case 61:
			result = 5764607523034234880ull;
			if ((occupy & 1152921504606846976ull) == 0) result |= 576460752303423488ull;
			if ((occupy & 1729382256910270464ull) == 0) result |= 288230376151711744ull;
			if ((occupy & 2017612633061982208ull) == 0) result |= 144115188075855872ull;
			if ((occupy & 2161727821137838080ull) == 0) result |= 72057594037927936ull;
			if ((occupy & 4611686018427387904ull) == 0) result |= 9223372036854775808ull;
			return result;
		case 62:
			result = 11529215046068469760ull;
			if ((occupy & 2305843009213693952ull) == 0) result |= 1152921504606846976ull;
			if ((occupy & 3458764513820540928ull) == 0) result |= 576460752303423488ull;
			if ((occupy & 4035225266123964416ull) == 0) result |= 288230376151711744ull;
			if ((occupy & 4323455642275676160ull) == 0) result |= 144115188075855872ull;
			if ((occupy & 4467570830351532032ull) == 0) result |= 72057594037927936ull;
			return result;
		case 63:
			result = 4611686018427387904ull;
			if ((occupy & 4611686018427387904ull) == 0) result |= 2305843009213693952ull;
			if ((occupy & 6917529027641081856ull) == 0) result |= 1152921504606846976ull;
			if ((occupy & 8070450532247928832ull) == 0) result |= 576460752303423488ull;
			if ((occupy & 8646911284551352320ull) == 0) result |= 288230376151711744ull;
			if ((occupy & 8935141660703064064ull) == 0) result |= 144115188075855872ull;
			if ((occupy & 9079256848778919936ull) == 0) result |= 72057594037927936ull;
			return result;
		}
		return 0;
	}
	static constexpr uint64_t GetSliderVCond(uint64_t SliderSquare, uint64_t occupy) {
		uint64_t result{};
		switch (SliderSquare) {
		case 0:
			result = 256ull;
			if ((occupy & 256ull) == 0) result |= 65536ull;
			if ((occupy & 65792ull) == 0) result |= 16777216ull;
			if ((occupy & 16843008ull) == 0) result |= 4294967296ull;
			if ((occupy & 4311810304ull) == 0) result |= 1099511627776ull;
			if ((occupy & 1103823438080ull) == 0) result |= 281474976710656ull;
			if ((occupy & 282578800148736ull) == 0) result |= 72057594037927936ull;
			return result;
		case 1:
			result = 512ull;
			if ((occupy & 512ull) == 0) result |= 131072ull;
			if ((occupy & 131584ull) == 0) result |= 33554432ull;
			if ((occupy & 33686016ull) == 0) result |= 8589934592ull;
			if ((occupy & 8623620608ull) == 0) result |= 2199023255552ull;
			if ((occupy & 2207646876160ull) == 0) result |= 562949953421312ull;
			if ((occupy & 565157600297472ull) == 0) result |= 144115188075855872ull;
			return result;
		case 2:
			result = 1024ull;
			if ((occupy & 1024ull) == 0) result |= 262144ull;
			if ((occupy & 263168ull) == 0) result |= 67108864ull;
			if ((occupy & 67372032ull) == 0) result |= 17179869184ull;
			if ((occupy & 17247241216ull) == 0) result |= 4398046511104ull;
			if ((occupy & 4415293752320ull) == 0) result |= 1125899906842624ull;
			if ((occupy & 1130315200594944ull) == 0) result |= 288230376151711744ull;
			return result;
		case 3:
			result = 2048ull;
			if ((occupy & 2048ull) == 0) result |= 524288ull;
			if ((occupy & 526336ull) == 0) result |= 134217728ull;
			if ((occupy & 134744064ull) == 0) result |= 34359738368ull;
			if ((occupy & 34494482432ull) == 0) result |= 8796093022208ull;
			if ((occupy & 8830587504640ull) == 0) result |= 2251799813685248ull;
			if ((occupy & 2260630401189888ull) == 0) result |= 576460752303423488ull;
			return result;
		case 4:
			result = 4096ull;
			if ((occupy & 4096ull) == 0) result |= 1048576ull;
			if ((occupy & 1052672ull) == 0) result |= 268435456ull;
			if ((occupy & 269488128ull) == 0) result |= 68719476736ull;
			if ((occupy & 68988964864ull) == 0) result |= 17592186044416ull;
			if ((occupy & 17661175009280ull) == 0) result |= 4503599627370496ull;
			if ((occupy & 4521260802379776ull) == 0) result |= 1152921504606846976ull;
			return result;
		case 5:
			result = 8192ull;
			if ((occupy & 8192ull) == 0) result |= 2097152ull;
			if ((occupy & 2105344ull) == 0) result |= 536870912ull;
			if ((occupy & 538976256ull) == 0) result |= 137438953472ull;
			if ((occupy & 137977929728ull) == 0) result |= 35184372088832ull;
			if ((occupy & 35322350018560ull) == 0) result |= 9007199254740992ull;
			if ((occupy & 9042521604759552ull) == 0) result |= 2305843009213693952ull;
			return result;
		case 6:
			result = 16384ull;
			if ((occupy & 16384ull) == 0) result |= 4194304ull;
			if ((occupy & 4210688ull) == 0) result |= 1073741824ull;
			if ((occupy & 1077952512ull) == 0) result |= 274877906944ull;
			if ((occupy & 275955859456ull) == 0) result |= 70368744177664ull;
			if ((occupy & 70644700037120ull) == 0) result |= 18014398509481984ull;
			if ((occupy & 18085043209519104ull) == 0) result |= 4611686018427387904ull;
			return result;
		case 7:
			result = 32768ull;
			if ((occupy & 32768ull) == 0) result |= 8388608ull;
			if ((occupy & 8421376ull) == 0) result |= 2147483648ull;
			if ((occupy & 2155905024ull) == 0) result |= 549755813888ull;
			if ((occupy & 551911718912ull) == 0) result |= 140737488355328ull;
			if ((occupy & 141289400074240ull) == 0) result |= 36028797018963968ull;
			if ((occupy & 36170086419038208ull) == 0) result |= 9223372036854775808ull;
			return result;
		case 8:
			result = 65537ull;
			if ((occupy & 65536ull) == 0) result |= 16777216ull;
			if ((occupy & 16842752ull) == 0) result |= 4294967296ull;
			if ((occupy & 4311810048ull) == 0) result |= 1099511627776ull;
			if ((occupy & 1103823437824ull) == 0) result |= 281474976710656ull;
			if ((occupy & 282578800148480ull) == 0) result |= 72057594037927936ull;
			return result;
		case 9:
			result = 131074ull;
			if ((occupy & 131072ull) == 0) result |= 33554432ull;
			if ((occupy & 33685504ull) == 0) result |= 8589934592ull;
			if ((occupy & 8623620096ull) == 0) result |= 2199023255552ull;
			if ((occupy & 2207646875648ull) == 0) result |= 562949953421312ull;
			if ((occupy & 565157600296960ull) == 0) result |= 144115188075855872ull;
			return result;
		case 10:
			result = 262148ull;
			if ((occupy & 262144ull) == 0) result |= 67108864ull;
			if ((occupy & 67371008ull) == 0) result |= 17179869184ull;
			if ((occupy & 17247240192ull) == 0) result |= 4398046511104ull;
			if ((occupy & 4415293751296ull) == 0) result |= 1125899906842624ull;
			if ((occupy & 1130315200593920ull) == 0) result |= 288230376151711744ull;
			return result;
		case 11:
			result = 524296ull;
			if ((occupy & 524288ull) == 0) result |= 134217728ull;
			if ((occupy & 134742016ull) == 0) result |= 34359738368ull;
			if ((occupy & 34494480384ull) == 0) result |= 8796093022208ull;
			if ((occupy & 8830587502592ull) == 0) result |= 2251799813685248ull;
			if ((occupy & 2260630401187840ull) == 0) result |= 576460752303423488ull;
			return result;
		case 12:
			result = 1048592ull;
			if ((occupy & 1048576ull) == 0) result |= 268435456ull;
			if ((occupy & 269484032ull) == 0) result |= 68719476736ull;
			if ((occupy & 68988960768ull) == 0) result |= 17592186044416ull;
			if ((occupy & 17661175005184ull) == 0) result |= 4503599627370496ull;
			if ((occupy & 4521260802375680ull) == 0) result |= 1152921504606846976ull;
			return result;
		case 13:
			result = 2097184ull;
			if ((occupy & 2097152ull) == 0) result |= 536870912ull;
			if ((occupy & 538968064ull) == 0) result |= 137438953472ull;
			if ((occupy & 137977921536ull) == 0) result |= 35184372088832ull;
			if ((occupy & 35322350010368ull) == 0) result |= 9007199254740992ull;
			if ((occupy & 9042521604751360ull) == 0) result |= 2305843009213693952ull;
			return result;
		case 14:
			result = 4194368ull;
			if ((occupy & 4194304ull) == 0) result |= 1073741824ull;
			if ((occupy & 1077936128ull) == 0) result |= 274877906944ull;
			if ((occupy & 275955843072ull) == 0) result |= 70368744177664ull;
			if ((occupy & 70644700020736ull) == 0) result |= 18014398509481984ull;
			if ((occupy & 18085043209502720ull) == 0) result |= 4611686018427387904ull;
			return result;
		case 15:
			result = 8388736ull;
			if ((occupy & 8388608ull) == 0) result |= 2147483648ull;
			if ((occupy & 2155872256ull) == 0) result |= 549755813888ull;
			if ((occupy & 551911686144ull) == 0) result |= 140737488355328ull;
			if ((occupy & 141289400041472ull) == 0) result |= 36028797018963968ull;
			if ((occupy & 36170086419005440ull) == 0) result |= 9223372036854775808ull;
			return result;
		case 16:
			result = 16777472ull;
			if ((occupy & 256ull) == 0) result |= 1ull;
			if ((occupy & 16777216ull) == 0) result |= 4294967296ull;
			if ((occupy & 4311744512ull) == 0) result |= 1099511627776ull;
			if ((occupy & 1103823372288ull) == 0) result |= 281474976710656ull;
			if ((occupy & 282578800082944ull) == 0) result |= 72057594037927936ull;
			return result;
		case 17:
			result = 33554944ull;
			if ((occupy & 512ull) == 0) result |= 2ull;
			if ((occupy & 33554432ull) == 0) result |= 8589934592ull;
			if ((occupy & 8623489024ull) == 0) result |= 2199023255552ull;
			if ((occupy & 2207646744576ull) == 0) result |= 562949953421312ull;
			if ((occupy & 565157600165888ull) == 0) result |= 144115188075855872ull;
			return result;
		case 18:
			result = 67109888ull;
			if ((occupy & 1024ull) == 0) result |= 4ull;
			if ((occupy & 67108864ull) == 0) result |= 17179869184ull;
			if ((occupy & 17246978048ull) == 0) result |= 4398046511104ull;
			if ((occupy & 4415293489152ull) == 0) result |= 1125899906842624ull;
			if ((occupy & 1130315200331776ull) == 0) result |= 288230376151711744ull;
			return result;
		case 19:
			result = 134219776ull;
			if ((occupy & 2048ull) == 0) result |= 8ull;
			if ((occupy & 134217728ull) == 0) result |= 34359738368ull;
			if ((occupy & 34493956096ull) == 0) result |= 8796093022208ull;
			if ((occupy & 8830586978304ull) == 0) result |= 2251799813685248ull;
			if ((occupy & 2260630400663552ull) == 0) result |= 576460752303423488ull;
			return result;
		case 20:
			result = 268439552ull;
			if ((occupy & 4096ull) == 0) result |= 16ull;
			if ((occupy & 268435456ull) == 0) result |= 68719476736ull;
			if ((occupy & 68987912192ull) == 0) result |= 17592186044416ull;
			if ((occupy & 17661173956608ull) == 0) result |= 4503599627370496ull;
			if ((occupy & 4521260801327104ull) == 0) result |= 1152921504606846976ull;
			return result;
		case 21:
			result = 536879104ull;
			if ((occupy & 8192ull) == 0) result |= 32ull;
			if ((occupy & 536870912ull) == 0) result |= 137438953472ull;
			if ((occupy & 137975824384ull) == 0) result |= 35184372088832ull;
			if ((occupy & 35322347913216ull) == 0) result |= 9007199254740992ull;
			if ((occupy & 9042521602654208ull) == 0) result |= 2305843009213693952ull;
			return result;
		case 22:
			result = 1073758208ull;
			if ((occupy & 16384ull) == 0) result |= 64ull;
			if ((occupy & 1073741824ull) == 0) result |= 274877906944ull;
			if ((occupy & 275951648768ull) == 0) result |= 70368744177664ull;
			if ((occupy & 70644695826432ull) == 0) result |= 18014398509481984ull;
			if ((occupy & 18085043205308416ull) == 0) result |= 4611686018427387904ull;
			return result;
		case 23:
			result = 2147516416ull;
			if ((occupy & 32768ull) == 0) result |= 128ull;
			if ((occupy & 2147483648ull) == 0) result |= 549755813888ull;
			if ((occupy & 551903297536ull) == 0) result |= 140737488355328ull;
			if ((occupy & 141289391652864ull) == 0) result |= 36028797018963968ull;
			if ((occupy & 36170086410616832ull) == 0) result |= 9223372036854775808ull;
			return result;
		case 24:
			result = 4295032832ull;
			if ((occupy & 65536ull) == 0) result |= 256ull;
			if ((occupy & 65792ull) == 0) result |= 1ull;
			if ((occupy & 4294967296ull) == 0) result |= 1099511627776ull;
			if ((occupy & 1103806595072ull) == 0) result |= 281474976710656ull;
			if ((occupy & 282578783305728ull) == 0) result |= 72057594037927936ull;
			return result;
		case 25:
			result = 8590065664ull;
			if ((occupy & 131072ull) == 0) result |= 512ull;
			if ((occupy & 131584ull) == 0) result |= 2ull;
			if ((occupy & 8589934592ull) == 0) result |= 2199023255552ull;
			if ((occupy & 2207613190144ull) == 0) result |= 562949953421312ull;
			if ((occupy & 565157566611456ull) == 0) result |= 144115188075855872ull;
			return result;
		case 26:
			result = 17180131328ull;
			if ((occupy & 262144ull) == 0) result |= 1024ull;
			if ((occupy & 263168ull) == 0) result |= 4ull;
			if ((occupy & 17179869184ull) == 0) result |= 4398046511104ull;
			if ((occupy & 4415226380288ull) == 0) result |= 1125899906842624ull;
			if ((occupy & 1130315133222912ull) == 0) result |= 288230376151711744ull;
			return result;
		case 27:
			result = 34360262656ull;
			if ((occupy & 524288ull) == 0) result |= 2048ull;
			if ((occupy & 526336ull) == 0) result |= 8ull;
			if ((occupy & 34359738368ull) == 0) result |= 8796093022208ull;
			if ((occupy & 8830452760576ull) == 0) result |= 2251799813685248ull;
			if ((occupy & 2260630266445824ull) == 0) result |= 576460752303423488ull;
			return result;
		case 28:
			result = 68720525312ull;
			if ((occupy & 1048576ull) == 0) result |= 4096ull;
			if ((occupy & 1052672ull) == 0) result |= 16ull;
			if ((occupy & 68719476736ull) == 0) result |= 17592186044416ull;
			if ((occupy & 17660905521152ull) == 0) result |= 4503599627370496ull;
			if ((occupy & 4521260532891648ull) == 0) result |= 1152921504606846976ull;
			return result;
		case 29:
			result = 137441050624ull;
			if ((occupy & 2097152ull) == 0) result |= 8192ull;
			if ((occupy & 2105344ull) == 0) result |= 32ull;
			if ((occupy & 137438953472ull) == 0) result |= 35184372088832ull;
			if ((occupy & 35321811042304ull) == 0) result |= 9007199254740992ull;
			if ((occupy & 9042521065783296ull) == 0) result |= 2305843009213693952ull;
			return result;
		case 30:
			result = 274882101248ull;
			if ((occupy & 4194304ull) == 0) result |= 16384ull;
			if ((occupy & 4210688ull) == 0) result |= 64ull;
			if ((occupy & 274877906944ull) == 0) result |= 70368744177664ull;
			if ((occupy & 70643622084608ull) == 0) result |= 18014398509481984ull;
			if ((occupy & 18085042131566592ull) == 0) result |= 4611686018427387904ull;
			return result;
		case 31:
			result = 549764202496ull;
			if ((occupy & 8388608ull) == 0) result |= 32768ull;
			if ((occupy & 8421376ull) == 0) result |= 128ull;
			if ((occupy & 549755813888ull) == 0) result |= 140737488355328ull;
			if ((occupy & 141287244169216ull) == 0) result |= 36028797018963968ull;
			if ((occupy & 36170084263133184ull) == 0) result |= 9223372036854775808ull;
			return result;
		case 32:
			result = 1099528404992ull;
			if ((occupy & 16777216ull) == 0) result |= 65536ull;
			if ((occupy & 16842752ull) == 0) result |= 256ull;
			if ((occupy & 16843008ull) == 0) result |= 1ull;
			if ((occupy & 1099511627776ull) == 0) result |= 281474976710656ull;
			if ((occupy & 282574488338432ull) == 0) result |= 72057594037927936ull;
			return result;
		case 33:
			result = 2199056809984ull;
			if ((occupy & 33554432ull) == 0) result |= 131072ull;
			if ((occupy & 33685504ull) == 0) result |= 512ull;
			if ((occupy & 33686016ull) == 0) result |= 2ull;
			if ((occupy & 2199023255552ull) == 0) result |= 562949953421312ull;
			if ((occupy & 565148976676864ull) == 0) result |= 144115188075855872ull;
			return result;
		case 34:
			result = 4398113619968ull;
			if ((occupy & 67108864ull) == 0) result |= 262144ull;
			if ((occupy & 67371008ull) == 0) result |= 1024ull;
			if ((occupy & 67372032ull) == 0) result |= 4ull;
			if ((occupy & 4398046511104ull) == 0) result |= 1125899906842624ull;
			if ((occupy & 1130297953353728ull) == 0) result |= 288230376151711744ull;
			return result;
		case 35:
			result = 8796227239936ull;
			if ((occupy & 134217728ull) == 0) result |= 524288ull;
			if ((occupy & 134742016ull) == 0) result |= 2048ull;
			if ((occupy & 134744064ull) == 0) result |= 8ull;
			if ((occupy & 8796093022208ull) == 0) result |= 2251799813685248ull;
			if ((occupy & 2260595906707456ull) == 0) result |= 576460752303423488ull;
			return result;
		case 36:
			result = 17592454479872ull;
			if ((occupy & 268435456ull) == 0) result |= 1048576ull;
			if ((occupy & 269484032ull) == 0) result |= 4096ull;
			if ((occupy & 269488128ull) == 0) result |= 16ull;
			if ((occupy & 17592186044416ull) == 0) result |= 4503599627370496ull;
			if ((occupy & 4521191813414912ull) == 0) result |= 1152921504606846976ull;
			return result;
		case 37:
			result = 35184908959744ull;
			if ((occupy & 536870912ull) == 0) result |= 2097152ull;
			if ((occupy & 538968064ull) == 0) result |= 8192ull;
			if ((occupy & 538976256ull) == 0) result |= 32ull;
			if ((occupy & 35184372088832ull) == 0) result |= 9007199254740992ull;
			if ((occupy & 9042383626829824ull) == 0) result |= 2305843009213693952ull;
			return result;
		case 38:
			result = 70369817919488ull;
			if ((occupy & 1073741824ull) == 0) result |= 4194304ull;
			if ((occupy & 1077936128ull) == 0) result |= 16384ull;
			if ((occupy & 1077952512ull) == 0) result |= 64ull;
			if ((occupy & 70368744177664ull) == 0) result |= 18014398509481984ull;
			if ((occupy & 18084767253659648ull) == 0) result |= 4611686018427387904ull;
			return result;
		case 39:
			result = 140739635838976ull;
			if ((occupy & 2147483648ull) == 0) result |= 8388608ull;
			if ((occupy & 2155872256ull) == 0) result |= 32768ull;
			if ((occupy & 2155905024ull) == 0) result |= 128ull;
			if ((occupy & 140737488355328ull) == 0) result |= 36028797018963968ull;
			if ((occupy & 36169534507319296ull) == 0) result |= 9223372036854775808ull;
			return result;
		case 40:
			result = 281479271677952ull;
			if ((occupy & 4294967296ull) == 0) result |= 16777216ull;
			if ((occupy & 4311744512ull) == 0) result |= 65536ull;
			if ((occupy & 4311810048ull) == 0) result |= 256ull;
			if ((occupy & 4311810304ull) == 0) result |= 1ull;
			if ((occupy & 281474976710656ull) == 0) result |= 72057594037927936ull;
			return result;
		case 41:
			result = 562958543355904ull;
			if ((occupy & 8589934592ull) == 0) result |= 33554432ull;
			if ((occupy & 8623489024ull) == 0) result |= 131072ull;
			if ((occupy & 8623620096ull) == 0) result |= 512ull;
			if ((occupy & 8623620608ull) == 0) result |= 2ull;
			if ((occupy & 562949953421312ull) == 0) result |= 144115188075855872ull;
			return result;
		case 42:
			result = 1125917086711808ull;
			if ((occupy & 17179869184ull) == 0) result |= 67108864ull;
			if ((occupy & 17246978048ull) == 0) result |= 262144ull;
			if ((occupy & 17247240192ull) == 0) result |= 1024ull;
			if ((occupy & 17247241216ull) == 0) result |= 4ull;
			if ((occupy & 1125899906842624ull) == 0) result |= 288230376151711744ull;
			return result;
		case 43:
			result = 2251834173423616ull;
			if ((occupy & 34359738368ull) == 0) result |= 134217728ull;
			if ((occupy & 34493956096ull) == 0) result |= 524288ull;
			if ((occupy & 34494480384ull) == 0) result |= 2048ull;
			if ((occupy & 34494482432ull) == 0) result |= 8ull;
			if ((occupy & 2251799813685248ull) == 0) result |= 576460752303423488ull;
			return result;
		case 44:
			result = 4503668346847232ull;
			if ((occupy & 68719476736ull) == 0) result |= 268435456ull;
			if ((occupy & 68987912192ull) == 0) result |= 1048576ull;
			if ((occupy & 68988960768ull) == 0) result |= 4096ull;
			if ((occupy & 68988964864ull) == 0) result |= 16ull;
			if ((occupy & 4503599627370496ull) == 0) result |= 1152921504606846976ull;
			return result;
		case 45:
			result = 9007336693694464ull;
			if ((occupy & 137438953472ull) == 0) result |= 536870912ull;
			if ((occupy & 137975824384ull) == 0) result |= 2097152ull;
			if ((occupy & 137977921536ull) == 0) result |= 8192ull;
			if ((occupy & 137977929728ull) == 0) result |= 32ull;
			if ((occupy & 9007199254740992ull) == 0) result |= 2305843009213693952ull;
			return result;
		case 46:
			result = 18014673387388928ull;
			if ((occupy & 274877906944ull) == 0) result |= 1073741824ull;
			if ((occupy & 275951648768ull) == 0) result |= 4194304ull;
			if ((occupy & 275955843072ull) == 0) result |= 16384ull;
			if ((occupy & 275955859456ull) == 0) result |= 64ull;
			if ((occupy & 18014398509481984ull) == 0) result |= 4611686018427387904ull;
			return result;
		case 47:
			result = 36029346774777856ull;
			if ((occupy & 549755813888ull) == 0) result |= 2147483648ull;
			if ((occupy & 551903297536ull) == 0) result |= 8388608ull;
			if ((occupy & 551911686144ull) == 0) result |= 32768ull;
			if ((occupy & 551911718912ull) == 0) result |= 128ull;
			if ((occupy & 36028797018963968ull) == 0) result |= 9223372036854775808ull;
			return result;
		case 48:
			result = 72058693549555712ull;
			if ((occupy & 1099511627776ull) == 0) result |= 4294967296ull;
			if ((occupy & 1103806595072ull) == 0) result |= 16777216ull;
			if ((occupy & 1103823372288ull) == 0) result |= 65536ull;
			if ((occupy & 1103823437824ull) == 0) result |= 256ull;
			if ((occupy & 1103823438080ull) == 0) result |= 1ull;
			return result;
		case 49:
			result = 144117387099111424ull;
			if ((occupy & 2199023255552ull) == 0) result |= 8589934592ull;
			if ((occupy & 2207613190144ull) == 0) result |= 33554432ull;
			if ((occupy & 2207646744576ull) == 0) result |= 131072ull;
			if ((occupy & 2207646875648ull) == 0) result |= 512ull;
			if ((occupy & 2207646876160ull) == 0) result |= 2ull;
			return result;
		case 50:
			result = 288234774198222848ull;
			if ((occupy & 4398046511104ull) == 0) result |= 17179869184ull;
			if ((occupy & 4415226380288ull) == 0) result |= 67108864ull;
			if ((occupy & 4415293489152ull) == 0) result |= 262144ull;
			if ((occupy & 4415293751296ull) == 0) result |= 1024ull;
			if ((occupy & 4415293752320ull) == 0) result |= 4ull;
			return result;
		case 51:
			result = 576469548396445696ull;
			if ((occupy & 8796093022208ull) == 0) result |= 34359738368ull;
			if ((occupy & 8830452760576ull) == 0) result |= 134217728ull;
			if ((occupy & 8830586978304ull) == 0) result |= 524288ull;
			if ((occupy & 8830587502592ull) == 0) result |= 2048ull;
			if ((occupy & 8830587504640ull) == 0) result |= 8ull;
			return result;
		case 52:
			result = 1152939096792891392ull;
			if ((occupy & 17592186044416ull) == 0) result |= 68719476736ull;
			if ((occupy & 17660905521152ull) == 0) result |= 268435456ull;
			if ((occupy & 17661173956608ull) == 0) result |= 1048576ull;
			if ((occupy & 17661175005184ull) == 0) result |= 4096ull;
			if ((occupy & 17661175009280ull) == 0) result |= 16ull;
			return result;
		case 53:
			result = 2305878193585782784ull;
			if ((occupy & 35184372088832ull) == 0) result |= 137438953472ull;
			if ((occupy & 35321811042304ull) == 0) result |= 536870912ull;
			if ((occupy & 35322347913216ull) == 0) result |= 2097152ull;
			if ((occupy & 35322350010368ull) == 0) result |= 8192ull;
			if ((occupy & 35322350018560ull) == 0) result |= 32ull;
			return result;
		case 54:
			result = 4611756387171565568ull;
			if ((occupy & 70368744177664ull) == 0) result |= 274877906944ull;
			if ((occupy & 70643622084608ull) == 0) result |= 1073741824ull;
			if ((occupy & 70644695826432ull) == 0) result |= 4194304ull;
			if ((occupy & 70644700020736ull) == 0) result |= 16384ull;
			if ((occupy & 70644700037120ull) == 0) result |= 64ull;
			return result;
		case 55:
			result = 9223512774343131136ull;
			if ((occupy & 140737488355328ull) == 0) result |= 549755813888ull;
			if ((occupy & 141287244169216ull) == 0) result |= 2147483648ull;
			if ((occupy & 141289391652864ull) == 0) result |= 8388608ull;
			if ((occupy & 141289400041472ull) == 0) result |= 32768ull;
			if ((occupy & 141289400074240ull) == 0) result |= 128ull;
			return result;
		case 56:
			result = 281474976710656ull;
			if ((occupy & 281474976710656ull) == 0) result |= 1099511627776ull;
			if ((occupy & 282574488338432ull) == 0) result |= 4294967296ull;
			if ((occupy & 282578783305728ull) == 0) result |= 16777216ull;
			if ((occupy & 282578800082944ull) == 0) result |= 65536ull;
			if ((occupy & 282578800148480ull) == 0) result |= 256ull;
			if ((occupy & 282578800148736ull) == 0) result |= 1ull;
			return result;
		case 57:
			result = 562949953421312ull;
			if ((occupy & 562949953421312ull) == 0) result |= 2199023255552ull;
			if ((occupy & 565148976676864ull) == 0) result |= 8589934592ull;
			if ((occupy & 565157566611456ull) == 0) result |= 33554432ull;
			if ((occupy & 565157600165888ull) == 0) result |= 131072ull;
			if ((occupy & 565157600296960ull) == 0) result |= 512ull;
			if ((occupy & 565157600297472ull) == 0) result |= 2ull;
			return result;
		case 58:
			result = 1125899906842624ull;
			if ((occupy & 1125899906842624ull) == 0) result |= 4398046511104ull;
			if ((occupy & 1130297953353728ull) == 0) result |= 17179869184ull;
			if ((occupy & 1130315133222912ull) == 0) result |= 67108864ull;
			if ((occupy & 1130315200331776ull) == 0) result |= 262144ull;
			if ((occupy & 1130315200593920ull) == 0) result |= 1024ull;
			if ((occupy & 1130315200594944ull) == 0) result |= 4ull;
			return result;
		case 59:
			result = 2251799813685248ull;
			if ((occupy & 2251799813685248ull) == 0) result |= 8796093022208ull;
			if ((occupy & 2260595906707456ull) == 0) result |= 34359738368ull;
			if ((occupy & 2260630266445824ull) == 0) result |= 134217728ull;
			if ((occupy & 2260630400663552ull) == 0) result |= 524288ull;
			if ((occupy & 2260630401187840ull) == 0) result |= 2048ull;
			if ((occupy & 2260630401189888ull) == 0) result |= 8ull;
			return result;
		case 60:
			result = 4503599627370496ull;
			if ((occupy & 4503599627370496ull) == 0) result |= 17592186044416ull;
			if ((occupy & 4521191813414912ull) == 0) result |= 68719476736ull;
			if ((occupy & 4521260532891648ull) == 0) result |= 268435456ull;
			if ((occupy & 4521260801327104ull) == 0) result |= 1048576ull;
			if ((occupy & 4521260802375680ull) == 0) result |= 4096ull;
			if ((occupy & 4521260802379776ull) == 0) result |= 16ull;
			return result;
		case 61:
			result = 9007199254740992ull;
			if ((occupy & 9007199254740992ull) == 0) result |= 35184372088832ull;
			if ((occupy & 9042383626829824ull) == 0) result |= 137438953472ull;
			if ((occupy & 9042521065783296ull) == 0) result |= 536870912ull;
			if ((occupy & 9042521602654208ull) == 0) result |= 2097152ull;
			if ((occupy & 9042521604751360ull) == 0) result |= 8192ull;
			if ((occupy & 9042521604759552ull) == 0) result |= 32ull;
			return result;
		case 62:
			result = 18014398509481984ull;
			if ((occupy & 18014398509481984ull) == 0) result |= 70368744177664ull;
			if ((occupy & 18084767253659648ull) == 0) result |= 274877906944ull;
			if ((occupy & 18085042131566592ull) == 0) result |= 1073741824ull;
			if ((occupy & 18085043205308416ull) == 0) result |= 4194304ull;
			if ((occupy & 18085043209502720ull) == 0) result |= 16384ull;
			if ((occupy & 18085043209519104ull) == 0) result |= 64ull;
			return result;
		case 63:
			result = 36028797018963968ull;
			if ((occupy & 36028797018963968ull) == 0) result |= 140737488355328ull;
			if ((occupy & 36169534507319296ull) == 0) result |= 549755813888ull;
			if ((occupy & 36170084263133184ull) == 0) result |= 2147483648ull;
			if ((occupy & 36170086410616832ull) == 0) result |= 8388608ull;
			if ((occupy & 36170086419005440ull) == 0) result |= 32768ull;
			if ((occupy & 36170086419038208ull) == 0) result |= 128ull;
			return result;
		}
		return 0;
	}
	static constexpr uint64_t GetSliderD2Cond(uint64_t SliderSquare, uint64_t occupy) {
		uint64_t result{};
		switch (SliderSquare) {
		case 0:
			result = 0ull;
			return result;
		case 1:
			result = 256ull;
			return result;
		case 2:
			result = 512ull;
			if ((occupy & 512ull) == 0) result |= 65536ull;
			return result;
		case 3:
			result = 1024ull;
			if ((occupy & 1024ull) == 0) result |= 131072ull;
			if ((occupy & 132096ull) == 0) result |= 16777216ull;
			return result;
		case 4:
			result = 2048ull;
			if ((occupy & 2048ull) == 0) result |= 262144ull;
			if ((occupy & 264192ull) == 0) result |= 33554432ull;
			if ((occupy & 33818624ull) == 0) result |= 4294967296ull;
			return result;
		case 5:
			result = 4096ull;
			if ((occupy & 4096ull) == 0) result |= 524288ull;
			if ((occupy & 528384ull) == 0) result |= 67108864ull;
			if ((occupy & 67637248ull) == 0) result |= 8589934592ull;
			if ((occupy & 8657571840ull) == 0) result |= 1099511627776ull;
			return result;
		case 6:
			result = 8192ull;
			if ((occupy & 8192ull) == 0) result |= 1048576ull;
			if ((occupy & 1056768ull) == 0) result |= 134217728ull;
			if ((occupy & 135274496ull) == 0) result |= 17179869184ull;
			if ((occupy & 17315143680ull) == 0) result |= 2199023255552ull;
			if ((occupy & 2216338399232ull) == 0) result |= 281474976710656ull;
			return result;
		case 7:
			result = 16384ull;
			if ((occupy & 16384ull) == 0) result |= 2097152ull;
			if ((occupy & 2113536ull) == 0) result |= 268435456ull;
			if ((occupy & 270548992ull) == 0) result |= 34359738368ull;
			if ((occupy & 34630287360ull) == 0) result |= 4398046511104ull;
			if ((occupy & 4432676798464ull) == 0) result |= 562949953421312ull;
			if ((occupy & 567382630219776ull) == 0) result |= 72057594037927936ull;
			return result;
		case 8:
			result = 2ull;
			return result;
		case 9:
			result = 65540ull;
			return result;
		case 10:
			result = 131080ull;
			if ((occupy & 131072ull) == 0) result |= 16777216ull;
			return result;
		case 11:
			result = 262160ull;
			if ((occupy & 262144ull) == 0) result |= 33554432ull;
			if ((occupy & 33816576ull) == 0) result |= 4294967296ull;
			return result;
		case 12:
			result = 524320ull;
			if ((occupy & 524288ull) == 0) result |= 67108864ull;
			if ((occupy & 67633152ull) == 0) result |= 8589934592ull;
			if ((occupy & 8657567744ull) == 0) result |= 1099511627776ull;
			return result;
		case 13:
			result = 1048640ull;
			if ((occupy & 1048576ull) == 0) result |= 134217728ull;
			if ((occupy & 135266304ull) == 0) result |= 17179869184ull;
			if ((occupy & 17315135488ull) == 0) result |= 2199023255552ull;
			if ((occupy & 2216338391040ull) == 0) result |= 281474976710656ull;
			return result;
		case 14:
			result = 2097280ull;
			if ((occupy & 2097152ull) == 0) result |= 268435456ull;
			if ((occupy & 270532608ull) == 0) result |= 34359738368ull;
			if ((occupy & 34630270976ull) == 0) result |= 4398046511104ull;
			if ((occupy & 4432676782080ull) == 0) result |= 562949953421312ull;
			if ((occupy & 567382630203392ull) == 0) result |= 72057594037927936ull;
			return result;
		case 15:
			result = 4194304ull;
			if ((occupy & 4194304ull) == 0) result |= 536870912ull;
			if ((occupy & 541065216ull) == 0) result |= 68719476736ull;
			if ((occupy & 69260541952ull) == 0) result |= 8796093022208ull;
			if ((occupy & 8865353564160ull) == 0) result |= 1125899906842624ull;
			if ((occupy & 1134765260406784ull) == 0) result |= 144115188075855872ull;
			return result;
		case 16:
			result = 512ull;
			if ((occupy & 512ull) == 0) result |= 4ull;
			return result;
		case 17:
			result = 16778240ull;
			if ((occupy & 1024ull) == 0) result |= 8ull;
			return result;
		case 18:
			result = 33556480ull;
			if ((occupy & 2048ull) == 0) result |= 16ull;
			if ((occupy & 33554432ull) == 0) result |= 4294967296ull;
			return result;
		case 19:
			result = 67112960ull;
			if ((occupy & 4096ull) == 0) result |= 32ull;
			if ((occupy & 67108864ull) == 0) result |= 8589934592ull;
			if ((occupy & 8657043456ull) == 0) result |= 1099511627776ull;
			return result;
		case 20:
			result = 134225920ull;
			if ((occupy & 8192ull) == 0) result |= 64ull;
			if ((occupy & 134217728ull) == 0) result |= 17179869184ull;
			if ((occupy & 17314086912ull) == 0) result |= 2199023255552ull;
			if ((occupy & 2216337342464ull) == 0) result |= 281474976710656ull;
			return result;
		case 21:
			result = 268451840ull;
			if ((occupy & 16384ull) == 0) result |= 128ull;
			if ((occupy & 268435456ull) == 0) result |= 34359738368ull;
			if ((occupy & 34628173824ull) == 0) result |= 4398046511104ull;
			if ((occupy & 4432674684928ull) == 0) result |= 562949953421312ull;
			if ((occupy & 567382628106240ull) == 0) result |= 72057594037927936ull;
			return result;
		case 22:
			result = 536903680ull;
			if ((occupy & 536870912ull) == 0) result |= 68719476736ull;
			if ((occupy & 69256347648ull) == 0) result |= 8796093022208ull;
			if ((occupy & 8865349369856ull) == 0) result |= 1125899906842624ull;
			if ((occupy & 1134765256212480ull) == 0) result |= 144115188075855872ull;
			return result;
		case 23:
			result = 1073741824ull;
			if ((occupy & 1073741824ull) == 0) result |= 137438953472ull;
			if ((occupy & 138512695296ull) == 0) result |= 17592186044416ull;
			if ((occupy & 17730698739712ull) == 0) result |= 2251799813685248ull;
			if ((occupy & 2269530512424960ull) == 0) result |= 288230376151711744ull;
			return result;
		case 24:
			result = 131072ull;
			if ((occupy & 131072ull) == 0) result |= 1024ull;
			if ((occupy & 132096ull) == 0) result |= 8ull;
			return result;
		case 25:
			result = 4295229440ull;
			if ((occupy & 262144ull) == 0) result |= 2048ull;
			if ((occupy & 264192ull) == 0) result |= 16ull;
			return result;
		case 26:
			result = 8590458880ull;
			if ((occupy & 524288ull) == 0) result |= 4096ull;
			if ((occupy & 528384ull) == 0) result |= 32ull;
			if ((occupy & 8589934592ull) == 0) result |= 1099511627776ull;
			return result;
		case 27:
			result = 17180917760ull;
			if ((occupy & 1048576ull) == 0) result |= 8192ull;
			if ((occupy & 1056768ull) == 0) result |= 64ull;
			if ((occupy & 17179869184ull) == 0) result |= 2199023255552ull;
			if ((occupy & 2216203124736ull) == 0) result |= 281474976710656ull;
			return result;
		case 28:
			result = 34361835520ull;
			if ((occupy & 2097152ull) == 0) result |= 16384ull;
			if ((occupy & 2113536ull) == 0) result |= 128ull;
			if ((occupy & 34359738368ull) == 0) result |= 4398046511104ull;
			if ((occupy & 4432406249472ull) == 0) result |= 562949953421312ull;
			if ((occupy & 567382359670784ull) == 0) result |= 72057594037927936ull;
			return result;
		case 29:
			result = 68723671040ull;
			if ((occupy & 4194304ull) == 0) result |= 32768ull;
			if ((occupy & 68719476736ull) == 0) result |= 8796093022208ull;
			if ((occupy & 8864812498944ull) == 0) result |= 1125899906842624ull;
			if ((occupy & 1134764719341568ull) == 0) result |= 144115188075855872ull;
			return result;
		case 30:
			result = 137447342080ull;
			if ((occupy & 137438953472ull) == 0) result |= 17592186044416ull;
			if ((occupy & 17729624997888ull) == 0) result |= 2251799813685248ull;
			if ((occupy & 2269529438683136ull) == 0) result |= 288230376151711744ull;
			return result;
		case 31:
			result = 274877906944ull;
			if ((occupy & 274877906944ull) == 0) result |= 35184372088832ull;
			if ((occupy & 35459249995776ull) == 0) result |= 4503599627370496ull;
			if ((occupy & 4539058877366272ull) == 0) result |= 576460752303423488ull;
			return result;
		case 32:
			result = 33554432ull;
			if ((occupy & 33554432ull) == 0) result |= 262144ull;
			if ((occupy & 33816576ull) == 0) result |= 2048ull;
			if ((occupy & 33818624ull) == 0) result |= 16ull;
			return result;
		case 33:
			result = 1099578736640ull;
			if ((occupy & 67108864ull) == 0) result |= 524288ull;
			if ((occupy & 67633152ull) == 0) result |= 4096ull;
			if ((occupy & 67637248ull) == 0) result |= 32ull;
			return result;
		case 34:
			result = 2199157473280ull;
			if ((occupy & 134217728ull) == 0) result |= 1048576ull;
			if ((occupy & 135266304ull) == 0) result |= 8192ull;
			if ((occupy & 135274496ull) == 0) result |= 64ull;
			if ((occupy & 2199023255552ull) == 0) result |= 281474976710656ull;
			return result;
		case 35:
			result = 4398314946560ull;
			if ((occupy & 268435456ull) == 0) result |= 2097152ull;
			if ((occupy & 270532608ull) == 0) result |= 16384ull;
			if ((occupy & 270548992ull) == 0) result |= 128ull;
			if ((occupy & 4398046511104ull) == 0) result |= 562949953421312ull;
			if ((occupy & 567347999932416ull) == 0) result |= 72057594037927936ull;
			return result;
		case 36:
			result = 8796629893120ull;
			if ((occupy & 536870912ull) == 0) result |= 4194304ull;
			if ((occupy & 541065216ull) == 0) result |= 32768ull;
			if ((occupy & 8796093022208ull) == 0) result |= 1125899906842624ull;
			if ((occupy & 1134695999864832ull) == 0) result |= 144115188075855872ull;
			return result;
		case 37:
			result = 17593259786240ull;
			if ((occupy & 1073741824ull) == 0) result |= 8388608ull;
			if ((occupy & 17592186044416ull) == 0) result |= 2251799813685248ull;
			if ((occupy & 2269391999729664ull) == 0) result |= 288230376151711744ull;
			return result;
		case 38:
			result = 35186519572480ull;
			if ((occupy & 35184372088832ull) == 0) result |= 4503599627370496ull;
			if ((occupy & 4538783999459328ull) == 0) result |= 576460752303423488ull;
			return result;
		case 39:
			result = 70368744177664ull;
			if ((occupy & 70368744177664ull) == 0) result |= 9007199254740992ull;
			if ((occupy & 9077567998918656ull) == 0) result |= 1152921504606846976ull;
			return result;
		case 40:
			result = 8589934592ull;
			if ((occupy & 8589934592ull) == 0) result |= 67108864ull;
			if ((occupy & 8657043456ull) == 0) result |= 524288ull;
			if ((occupy & 8657567744ull) == 0) result |= 4096ull;
			if ((occupy & 8657571840ull) == 0) result |= 32ull;
			return result;
		case 41:
			result = 281492156579840ull;
			if ((occupy & 17179869184ull) == 0) result |= 134217728ull;
			if ((occupy & 17314086912ull) == 0) result |= 1048576ull;
			if ((occupy & 17315135488ull) == 0) result |= 8192ull;
			if ((occupy & 17315143680ull) == 0) result |= 64ull;
			return result;
		case 42:
			result = 562984313159680ull;
			if ((occupy & 34359738368ull) == 0) result |= 268435456ull;
			if ((occupy & 34628173824ull) == 0) result |= 2097152ull;
			if ((occupy & 34630270976ull) == 0) result |= 16384ull;
			if ((occupy & 34630287360ull) == 0) result |= 128ull;
			if ((occupy & 562949953421312ull) == 0) result |= 72057594037927936ull;
			return result;
		case 43:
			result = 1125968626319360ull;
			if ((occupy & 68719476736ull) == 0) result |= 536870912ull;
			if ((occupy & 69256347648ull) == 0) result |= 4194304ull;
			if ((occupy & 69260541952ull) == 0) result |= 32768ull;
			if ((occupy & 1125899906842624ull) == 0) result |= 144115188075855872ull;
			return result;
		case 44:
			result = 2251937252638720ull;
			if ((occupy & 137438953472ull) == 0) result |= 1073741824ull;
			if ((occupy & 138512695296ull) == 0) result |= 8388608ull;
			if ((occupy & 2251799813685248ull) == 0) result |= 288230376151711744ull;
			return result;
		case 45:
			result = 4503874505277440ull;
			if ((occupy & 274877906944ull) == 0) result |= 2147483648ull;
			if ((occupy & 4503599627370496ull) == 0) result |= 576460752303423488ull;
			return result;
		case 46:
			result = 9007749010554880ull;
			if ((occupy & 9007199254740992ull) == 0) result |= 1152921504606846976ull;
			return result;
		case 47:
			result = 18014398509481984ull;
			if ((occupy & 18014398509481984ull) == 0) result |= 2305843009213693952ull;
			return result;
		case 48:
			result = 2199023255552ull;
			if ((occupy & 2199023255552ull) == 0) result |= 17179869184ull;
			if ((occupy & 2216203124736ull) == 0) result |= 134217728ull;
			if ((occupy & 2216337342464ull) == 0) result |= 1048576ull;
			if ((occupy & 2216338391040ull) == 0) result |= 8192ull;
			if ((occupy & 2216338399232ull) == 0) result |= 64ull;
			return result;
		case 49:
			result = 72061992084439040ull;
			if ((occupy & 4398046511104ull) == 0) result |= 34359738368ull;
			if ((occupy & 4432406249472ull) == 0) result |= 268435456ull;
			if ((occupy & 4432674684928ull) == 0) result |= 2097152ull;
			if ((occupy & 4432676782080ull) == 0) result |= 16384ull;
			if ((occupy & 4432676798464ull) == 0) result |= 128ull;
			return result;
		case 50:
			result = 144123984168878080ull;
			if ((occupy & 8796093022208ull) == 0) result |= 68719476736ull;
			if ((occupy & 8864812498944ull) == 0) result |= 536870912ull;
			if ((occupy & 8865349369856ull) == 0) result |= 4194304ull;
			if ((occupy & 8865353564160ull) == 0) result |= 32768ull;
			return result;
		case 51:
			result = 288247968337756160ull;
			if ((occupy & 17592186044416ull) == 0) result |= 137438953472ull;
			if ((occupy & 17729624997888ull) == 0) result |= 1073741824ull;
			if ((occupy & 17730698739712ull) == 0) result |= 8388608ull;
			return result;
		case 52:
			result = 576495936675512320ull;
			if ((occupy & 35184372088832ull) == 0) result |= 274877906944ull;
			if ((occupy & 35459249995776ull) == 0) result |= 2147483648ull;
			return result;
		case 53:
			result = 1152991873351024640ull;
			if ((occupy & 70368744177664ull) == 0) result |= 549755813888ull;
			return result;
		case 54:
			result = 2305983746702049280ull;
			return result;
		case 55:
			result = 4611686018427387904ull;
			return result;
		case 56:
			result = 562949953421312ull;
			if ((occupy & 562949953421312ull) == 0) result |= 4398046511104ull;
			if ((occupy & 567347999932416ull) == 0) result |= 34359738368ull;
			if ((occupy & 567382359670784ull) == 0) result |= 268435456ull;
			if ((occupy & 567382628106240ull) == 0) result |= 2097152ull;
			if ((occupy & 567382630203392ull) == 0) result |= 16384ull;
			if ((occupy & 567382630219776ull) == 0) result |= 128ull;
			return result;
		case 57:
			result = 1125899906842624ull;
			if ((occupy & 1125899906842624ull) == 0) result |= 8796093022208ull;
			if ((occupy & 1134695999864832ull) == 0) result |= 68719476736ull;
			if ((occupy & 1134764719341568ull) == 0) result |= 536870912ull;
			if ((occupy & 1134765256212480ull) == 0) result |= 4194304ull;
			if ((occupy & 1134765260406784ull) == 0) result |= 32768ull;
			return result;
		case 58:
			result = 2251799813685248ull;
			if ((occupy & 2251799813685248ull) == 0) result |= 17592186044416ull;
			if ((occupy & 2269391999729664ull) == 0) result |= 137438953472ull;
			if ((occupy & 2269529438683136ull) == 0) result |= 1073741824ull;
			if ((occupy & 2269530512424960ull) == 0) result |= 8388608ull;
			return result;
		case 59:
			result = 4503599627370496ull;
			if ((occupy & 4503599627370496ull) == 0) result |= 35184372088832ull;
			if ((occupy & 4538783999459328ull) == 0) result |= 274877906944ull;
			if ((occupy & 4539058877366272ull) == 0) result |= 2147483648ull;
			return result;
		case 60:
			result = 9007199254740992ull;
			if ((occupy & 9007199254740992ull) == 0) result |= 70368744177664ull;
			if ((occupy & 9077567998918656ull) == 0) result |= 549755813888ull;
			return result;
		case 61:
			result = 18014398509481984ull;
			if ((occupy & 18014398509481984ull) == 0) result |= 140737488355328ull;
			return result;
		case 62:
			result = 36028797018963968ull;
			return result;
		case 63:
			result = 0ull;
			return result;
		}
		return 0;
	}
	static constexpr uint64_t GetSliderD1Cond(uint64_t SliderSquare, uint64_t occupy) {
		uint64_t result{};
		switch (SliderSquare) {
		case 0:
			result = 512ull;
			if ((occupy & 512ull) == 0) result |= 262144ull;
			if ((occupy & 262656ull) == 0) result |= 134217728ull;
			if ((occupy & 134480384ull) == 0) result |= 68719476736ull;
			if ((occupy & 68853957120ull) == 0) result |= 35184372088832ull;
			if ((occupy & 35253226045952ull) == 0) result |= 18014398509481984ull;
			if ((occupy & 18049651735527936ull) == 0) result |= 9223372036854775808ull;
			return result;
		case 1:
			result = 1024ull;
			if ((occupy & 1024ull) == 0) result |= 524288ull;
			if ((occupy & 525312ull) == 0) result |= 268435456ull;
			if ((occupy & 268960768ull) == 0) result |= 137438953472ull;
			if ((occupy & 137707914240ull) == 0) result |= 70368744177664ull;
			if ((occupy & 70506452091904ull) == 0) result |= 36028797018963968ull;
			return result;
		case 2:
			result = 2048ull;
			if ((occupy & 2048ull) == 0) result |= 1048576ull;
			if ((occupy & 1050624ull) == 0) result |= 536870912ull;
			if ((occupy & 537921536ull) == 0) result |= 274877906944ull;
			if ((occupy & 275415828480ull) == 0) result |= 140737488355328ull;
			return result;
		case 3:
			result = 4096ull;
			if ((occupy & 4096ull) == 0) result |= 2097152ull;
			if ((occupy & 2101248ull) == 0) result |= 1073741824ull;
			if ((occupy & 1075843072ull) == 0) result |= 549755813888ull;
			return result;
		case 4:
			result = 8192ull;
			if ((occupy & 8192ull) == 0) result |= 4194304ull;
			if ((occupy & 4202496ull) == 0) result |= 2147483648ull;
			return result;
		case 5:
			result = 16384ull;
			if ((occupy & 16384ull) == 0) result |= 8388608ull;
			return result;
		case 6:
			result = 32768ull;
			return result;
		case 7:
			result = 0ull;
			return result;
		case 8:
			result = 131072ull;
			if ((occupy & 131072ull) == 0) result |= 67108864ull;
			if ((occupy & 67239936ull) == 0) result |= 34359738368ull;
			if ((occupy & 34426978304ull) == 0) result |= 17592186044416ull;
			if ((occupy & 17626613022720ull) == 0) result |= 9007199254740992ull;
			if ((occupy & 9024825867763712ull) == 0) result |= 4611686018427387904ull;
			return result;
		case 9:
			result = 262145ull;
			if ((occupy & 262144ull) == 0) result |= 134217728ull;
			if ((occupy & 134479872ull) == 0) result |= 68719476736ull;
			if ((occupy & 68853956608ull) == 0) result |= 35184372088832ull;
			if ((occupy & 35253226045440ull) == 0) result |= 18014398509481984ull;
			if ((occupy & 18049651735527424ull) == 0) result |= 9223372036854775808ull;
			return result;
		case 10:
			result = 524290ull;
			if ((occupy & 524288ull) == 0) result |= 268435456ull;
			if ((occupy & 268959744ull) == 0) result |= 137438953472ull;
			if ((occupy & 137707913216ull) == 0) result |= 70368744177664ull;
			if ((occupy & 70506452090880ull) == 0) result |= 36028797018963968ull;
			return result;
		case 11:
			result = 1048580ull;
			if ((occupy & 1048576ull) == 0) result |= 536870912ull;
			if ((occupy & 537919488ull) == 0) result |= 274877906944ull;
			if ((occupy & 275415826432ull) == 0) result |= 140737488355328ull;
			return result;
		case 12:
			result = 2097160ull;
			if ((occupy & 2097152ull) == 0) result |= 1073741824ull;
			if ((occupy & 1075838976ull) == 0) result |= 549755813888ull;
			return result;
		case 13:
			result = 4194320ull;
			if ((occupy & 4194304ull) == 0) result |= 2147483648ull;
			return result;
		case 14:
			result = 8388640ull;
			return result;
		case 15:
			result = 64ull;
			return result;
		case 16:
			result = 33554432ull;
			if ((occupy & 33554432ull) == 0) result |= 17179869184ull;
			if ((occupy & 17213423616ull) == 0) result |= 8796093022208ull;
			if ((occupy & 8813306445824ull) == 0) result |= 4503599627370496ull;
			if ((occupy & 4512412933816320ull) == 0) result |= 2305843009213693952ull;
			return result;
		case 17:
			result = 67109120ull;
			if ((occupy & 67108864ull) == 0) result |= 34359738368ull;
			if ((occupy & 34426847232ull) == 0) result |= 17592186044416ull;
			if ((occupy & 17626612891648ull) == 0) result |= 9007199254740992ull;
			if ((occupy & 9024825867632640ull) == 0) result |= 4611686018427387904ull;
			return result;
		case 18:
			result = 134218240ull;
			if ((occupy & 512ull) == 0) result |= 1ull;
			if ((occupy & 134217728ull) == 0) result |= 68719476736ull;
			if ((occupy & 68853694464ull) == 0) result |= 35184372088832ull;
			if ((occupy & 35253225783296ull) == 0) result |= 18014398509481984ull;
			if ((occupy & 18049651735265280ull) == 0) result |= 9223372036854775808ull;
			return result;
		case 19:
			result = 268436480ull;
			if ((occupy & 1024ull) == 0) result |= 2ull;
			if ((occupy & 268435456ull) == 0) result |= 137438953472ull;
			if ((occupy & 137707388928ull) == 0) result |= 70368744177664ull;
			if ((occupy & 70506451566592ull) == 0) result |= 36028797018963968ull;
			return result;
		case 20:
			result = 536872960ull;
			if ((occupy & 2048ull) == 0) result |= 4ull;
			if ((occupy & 536870912ull) == 0) result |= 274877906944ull;
			if ((occupy & 275414777856ull) == 0) result |= 140737488355328ull;
			return result;
		case 21:
			result = 1073745920ull;
			if ((occupy & 4096ull) == 0) result |= 8ull;
			if ((occupy & 1073741824ull) == 0) result |= 549755813888ull;
			return result;
		case 22:
			result = 2147491840ull;
			if ((occupy & 8192ull) == 0) result |= 16ull;
			return result;
		case 23:
			result = 16384ull;
			if ((occupy & 16384ull) == 0) result |= 32ull;
			return result;
		case 24:
			result = 8589934592ull;
			if ((occupy & 8589934592ull) == 0) result |= 4398046511104ull;
			if ((occupy & 4406636445696ull) == 0) result |= 2251799813685248ull;
			if ((occupy & 2256206450130944ull) == 0) result |= 1152921504606846976ull;
			return result;
		case 25:
			result = 17179934720ull;
			if ((occupy & 17179869184ull) == 0) result |= 8796093022208ull;
			if ((occupy & 8813272891392ull) == 0) result |= 4503599627370496ull;
			if ((occupy & 4512412900261888ull) == 0) result |= 2305843009213693952ull;
			return result;
		case 26:
			result = 34359869440ull;
			if ((occupy & 131072ull) == 0) result |= 256ull;
			if ((occupy & 34359738368ull) == 0) result |= 17592186044416ull;
			if ((occupy & 17626545782784ull) == 0) result |= 9007199254740992ull;
			if ((occupy & 9024825800523776ull) == 0) result |= 4611686018427387904ull;
			return result;
		case 27:
			result = 68719738880ull;
			if ((occupy & 262144ull) == 0) result |= 512ull;
			if ((occupy & 262656ull) == 0) result |= 1ull;
			if ((occupy & 68719476736ull) == 0) result |= 35184372088832ull;
			if ((occupy & 35253091565568ull) == 0) result |= 18014398509481984ull;
			if ((occupy & 18049651601047552ull) == 0) result |= 9223372036854775808ull;
			return result;
		case 28:
			result = 137439477760ull;
			if ((occupy & 524288ull) == 0) result |= 1024ull;
			if ((occupy & 525312ull) == 0) result |= 2ull;
			if ((occupy & 137438953472ull) == 0) result |= 70368744177664ull;
			if ((occupy & 70506183131136ull) == 0) result |= 36028797018963968ull;
			return result;
		case 29:
			result = 274878955520ull;
			if ((occupy & 1048576ull) == 0) result |= 2048ull;
			if ((occupy & 1050624ull) == 0) result |= 4ull;
			if ((occupy & 274877906944ull) == 0) result |= 140737488355328ull;
			return result;
		case 30:
			result = 549757911040ull;
			if ((occupy & 2097152ull) == 0) result |= 4096ull;
			if ((occupy & 2101248ull) == 0) result |= 8ull;
			return result;
		case 31:
			result = 4194304ull;
			if ((occupy & 4194304ull) == 0) result |= 8192ull;
			if ((occupy & 4202496ull) == 0) result |= 16ull;
			return result;
		case 32:
			result = 2199023255552ull;
			if ((occupy & 2199023255552ull) == 0) result |= 1125899906842624ull;
			if ((occupy & 1128098930098176ull) == 0) result |= 576460752303423488ull;
			return result;
		case 33:
			result = 4398063288320ull;
			if ((occupy & 4398046511104ull) == 0) result |= 2251799813685248ull;
			if ((occupy & 2256197860196352ull) == 0) result |= 1152921504606846976ull;
			return result;
		case 34:
			result = 8796126576640ull;
			if ((occupy & 33554432ull) == 0) result |= 65536ull;
			if ((occupy & 8796093022208ull) == 0) result |= 4503599627370496ull;
			if ((occupy & 4512395720392704ull) == 0) result |= 2305843009213693952ull;
			return result;
		case 35:
			result = 17592253153280ull;
			if ((occupy & 67108864ull) == 0) result |= 131072ull;
			if ((occupy & 67239936ull) == 0) result |= 256ull;
			if ((occupy & 17592186044416ull) == 0) result |= 9007199254740992ull;
			if ((occupy & 9024791440785408ull) == 0) result |= 4611686018427387904ull;
			return result;
		case 36:
			result = 35184506306560ull;
			if ((occupy & 134217728ull) == 0) result |= 262144ull;
			if ((occupy & 134479872ull) == 0) result |= 512ull;
			if ((occupy & 134480384ull) == 0) result |= 1ull;
			if ((occupy & 35184372088832ull) == 0) result |= 18014398509481984ull;
			if ((occupy & 18049582881570816ull) == 0) result |= 9223372036854775808ull;
			return result;
		case 37:
			result = 70369012613120ull;
			if ((occupy & 268435456ull) == 0) result |= 524288ull;
			if ((occupy & 268959744ull) == 0) result |= 1024ull;
			if ((occupy & 268960768ull) == 0) result |= 2ull;
			if ((occupy & 70368744177664ull) == 0) result |= 36028797018963968ull;
			return result;
		case 38:
			result = 140738025226240ull;
			if ((occupy & 536870912ull) == 0) result |= 1048576ull;
			if ((occupy & 537919488ull) == 0) result |= 2048ull;
			if ((occupy & 537921536ull) == 0) result |= 4ull;
			return result;
		case 39:
			result = 1073741824ull;
			if ((occupy & 1073741824ull) == 0) result |= 2097152ull;
			if ((occupy & 1075838976ull) == 0) result |= 4096ull;
			if ((occupy & 1075843072ull) == 0) result |= 8ull;
			return result;
		case 40:
			result = 562949953421312ull;
			if ((occupy & 562949953421312ull) == 0) result |= 288230376151711744ull;
			return result;
		case 41:
			result = 1125904201809920ull;
			if ((occupy & 1125899906842624ull) == 0) result |= 576460752303423488ull;
			return result;
		case 42:
			result = 2251808403619840ull;
			if ((occupy & 8589934592ull) == 0) result |= 16777216ull;
			if ((occupy & 2251799813685248ull) == 0) result |= 1152921504606846976ull;
			return result;
		case 43:
			result = 4503616807239680ull;
			if ((occupy & 17179869184ull) == 0) result |= 33554432ull;
			if ((occupy & 17213423616ull) == 0) result |= 65536ull;
			if ((occupy & 4503599627370496ull) == 0) result |= 2305843009213693952ull;
			return result;
		case 44:
			result = 9007233614479360ull;
			if ((occupy & 34359738368ull) == 0) result |= 67108864ull;
			if ((occupy & 34426847232ull) == 0) result |= 131072ull;
			if ((occupy & 34426978304ull) == 0) result |= 256ull;
			if ((occupy & 9007199254740992ull) == 0) result |= 4611686018427387904ull;
			return result;
		case 45:
			result = 18014467228958720ull;
			if ((occupy & 68719476736ull) == 0) result |= 134217728ull;
			if ((occupy & 68853694464ull) == 0) result |= 262144ull;
			if ((occupy & 68853956608ull) == 0) result |= 512ull;
			if ((occupy & 68853957120ull) == 0) result |= 1ull;
			if ((occupy & 18014398509481984ull) == 0) result |= 9223372036854775808ull;
			return result;
		case 46:
			result = 36028934457917440ull;
			if ((occupy & 137438953472ull) == 0) result |= 268435456ull;
			if ((occupy & 137707388928ull) == 0) result |= 524288ull;
			if ((occupy & 137707913216ull) == 0) result |= 1024ull;
			if ((occupy & 137707914240ull) == 0) result |= 2ull;
			return result;
		case 47:
			result = 274877906944ull;
			if ((occupy & 274877906944ull) == 0) result |= 536870912ull;
			if ((occupy & 275414777856ull) == 0) result |= 1048576ull;
			if ((occupy & 275415826432ull) == 0) result |= 2048ull;
			if ((occupy & 275415828480ull) == 0) result |= 4ull;
			return result;
		case 48:
			result = 144115188075855872ull;
			return result;
		case 49:
			result = 288231475663339520ull;
			return result;
		case 50:
			result = 576462951326679040ull;
			if ((occupy & 2199023255552ull) == 0) result |= 4294967296ull;
			return result;
		case 51:
			result = 1152925902653358080ull;
			if ((occupy & 4398046511104ull) == 0) result |= 8589934592ull;
			if ((occupy & 4406636445696ull) == 0) result |= 16777216ull;
			return result;
		case 52:
			result = 2305851805306716160ull;
			if ((occupy & 8796093022208ull) == 0) result |= 17179869184ull;
			if ((occupy & 8813272891392ull) == 0) result |= 33554432ull;
			if ((occupy & 8813306445824ull) == 0) result |= 65536ull;
			return result;
		case 53:
			result = 4611703610613432320ull;
			if ((occupy & 17592186044416ull) == 0) result |= 34359738368ull;
			if ((occupy & 17626545782784ull) == 0) result |= 67108864ull;
			if ((occupy & 17626612891648ull) == 0) result |= 131072ull;
			if ((occupy & 17626613022720ull) == 0) result |= 256ull;
			return result;
		case 54:
			result = 9223407221226864640ull;
			if ((occupy & 35184372088832ull) == 0) result |= 68719476736ull;
			if ((occupy & 35253091565568ull) == 0) result |= 134217728ull;
			if ((occupy & 35253225783296ull) == 0) result |= 262144ull;
			if ((occupy & 35253226045440ull) == 0) result |= 512ull;
			if ((occupy & 35253226045952ull) == 0) result |= 1ull;
			return result;
		case 55:
			result = 70368744177664ull;
			if ((occupy & 70368744177664ull) == 0) result |= 137438953472ull;
			if ((occupy & 70506183131136ull) == 0) result |= 268435456ull;
			if ((occupy & 70506451566592ull) == 0) result |= 524288ull;
			if ((occupy & 70506452090880ull) == 0) result |= 1024ull;
			if ((occupy & 70506452091904ull) == 0) result |= 2ull;
			return result;
		case 56:
			result = 0ull;
			return result;
		case 57:
			result = 281474976710656ull;
			return result;
		case 58:
			result = 562949953421312ull;
			if ((occupy & 562949953421312ull) == 0) result |= 1099511627776ull;
			return result;
		case 59:
			result = 1125899906842624ull;
			if ((occupy & 1125899906842624ull) == 0) result |= 2199023255552ull;
			if ((occupy & 1128098930098176ull) == 0) result |= 4294967296ull;
			return result;
		case 60:
			result = 2251799813685248ull;
			if ((occupy & 2251799813685248ull) == 0) result |= 4398046511104ull;
			if ((occupy & 2256197860196352ull) == 0) result |= 8589934592ull;
			if ((occupy & 2256206450130944ull) == 0) result |= 16777216ull;
			return result;
		case 61:
			result = 4503599627370496ull;
			if ((occupy & 4503599627370496ull) == 0) result |= 8796093022208ull;
			if ((occupy & 4512395720392704ull) == 0) result |= 17179869184ull;
			if ((occupy & 4512412900261888ull) == 0) result |= 33554432ull;
			if ((occupy & 4512412933816320ull) == 0) result |= 65536ull;
			return result;
		case 62:
			result = 9007199254740992ull;
			if ((occupy & 9007199254740992ull) == 0) result |= 17592186044416ull;
			if ((occupy & 9024791440785408ull) == 0) result |= 34359738368ull;
			if ((occupy & 9024825800523776ull) == 0) result |= 67108864ull;
			if ((occupy & 9024825867632640ull) == 0) result |= 131072ull;
			if ((occupy & 9024825867763712ull) == 0) result |= 256ull;
			return result;
		case 63:
			result = 18014398509481984ull;
			if ((occupy & 18014398509481984ull) == 0) result |= 35184372088832ull;
			if ((occupy & 18049582881570816ull) == 0) result |= 68719476736ull;
			if ((occupy & 18049651601047552ull) == 0) result |= 134217728ull;
			if ((occupy & 18049651735265280ull) == 0) result |= 262144ull;
			if ((occupy & 18049651735527424ull) == 0) result |= 512ull;
			if ((occupy & 18049651735527936ull) == 0) result |= 1ull;
			return result;
		}
		return 0;
	}

	namespace Lookup_Switch {

		static constexpr uint64_t KingAttacks[] = {
		0x0000000000000302, 0x0000000000000705, 0x0000000000000E0A, 0x0000000000001C14, 0x0000000000003828, 0x0000000000007050, 0x000000000000E0A0, 0x000000000000C040,
		0x0000000000030203, 0x0000000000070507, 0x00000000000E0A0E, 0x00000000001C141C, 0x0000000000382838, 0x0000000000705070, 0x0000000000E0A0E0, 0x0000000000C040C0,
		0x0000000003020300, 0x0000000007050700, 0x000000000E0A0E00, 0x000000001C141C00, 0x0000000038283800, 0x0000000070507000, 0x00000000E0A0E000, 0x00000000C040C000,
		0x0000000302030000, 0x0000000705070000, 0x0000000E0A0E0000, 0x0000001C141C0000, 0x0000003828380000, 0x0000007050700000, 0x000000E0A0E00000, 0x000000C040C00000,
		0x0000030203000000, 0x0000070507000000, 0x00000E0A0E000000, 0x00001C141C000000, 0x0000382838000000, 0x0000705070000000, 0x0000E0A0E0000000, 0x0000C040C0000000,
		0x0003020300000000, 0x0007050700000000, 0x000E0A0E00000000, 0x001C141C00000000, 0x0038283800000000, 0x0070507000000000, 0x00E0A0E000000000, 0x00C040C000000000,
		0x0302030000000000, 0x0705070000000000, 0x0E0A0E0000000000, 0x1C141C0000000000, 0x3828380000000000, 0x7050700000000000, 0xE0A0E00000000000, 0xC040C00000000000,
		0x0203000000000000, 0x0507000000000000, 0x0A0E000000000000, 0x141C000000000000, 0x2838000000000000, 0x5070000000000000, 0xA0E0000000000000, 0x40C0000000000000,
		};
		static constexpr uint64_t KnightAttacks[] = {
		0x0000000000020400, 0x0000000000050800, 0x00000000000A1100, 0x0000000000142200, 0x0000000000284400, 0x0000000000508800, 0x0000000000A01000, 0x0000000000402000,
		0x0000000002040004, 0x0000000005080008, 0x000000000A110011, 0x0000000014220022, 0x0000000028440044, 0x0000000050880088, 0x00000000A0100010, 0x0000000040200020,
		0x0000000204000402, 0x0000000508000805, 0x0000000A1100110A, 0x0000001422002214, 0x0000002844004428, 0x0000005088008850, 0x000000A0100010A0, 0x0000004020002040,
		0x0000020400040200, 0x0000050800080500, 0x00000A1100110A00, 0x0000142200221400, 0x0000284400442800, 0x0000508800885000, 0x0000A0100010A000, 0x0000402000204000,
		0x0002040004020000, 0x0005080008050000, 0x000A1100110A0000, 0x0014220022140000, 0x0028440044280000, 0x0050880088500000, 0x00A0100010A00000, 0x0040200020400000,
		0x0204000402000000, 0x0508000805000000, 0x0A1100110A000000, 0x1422002214000000, 0x2844004428000000, 0x5088008850000000, 0xA0100010A0000000, 0x4020002040000000,
		0x0400040200000000, 0x0800080500000000, 0x1100110A00000000, 0x2200221400000000, 0x4400442800000000, 0x8800885000000000, 0x100010A000000000, 0x2000204000000000,
		0x0004020000000000, 0x0008050000000000, 0x00110A0000000000, 0x0022140000000000, 0x0044280000000000, 0x0088500000000000, 0x0010A00000000000, 0x0020400000000000,
		};

		constexpr auto Size = 0;
		static constexpr uint64_t Rook(uint64_t square, uint64_t occupy) {
			return GetSliderHCond(square, occupy) | GetSliderVCond(square, occupy);
		}

		static constexpr uint64_t Rook_Xray(uint64_t square, uint64_t occupy) {
			uint64_t attacks = Rook(square, occupy);
			return attacks ^ Rook(square, occupy ^ (attacks & occupy));
		}

		static constexpr uint64_t Bishop(uint64_t square, uint64_t occupy) {
			return GetSliderD1Cond(square, occupy) | GetSliderD2Cond(square, occupy);
		}

		static constexpr uint64_t Bishop_Xray(uint64_t square, uint64_t occupy) {
			uint64_t attacks = Bishop(square, occupy);
			return attacks ^ Bishop(square, occupy ^ (attacks & occupy));
		}

		static constexpr uint64_t Queen(uint64_t square, uint64_t occupy) {
			return Rook(square, occupy) | Bishop(square, occupy);
		}

		static constexpr uint64_t Queen_Xray(uint64_t square, uint64_t occupy) {
			return Rook_Xray(square, occupy) | Bishop_Xray(square, occupy);
		}
	};
}