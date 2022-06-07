using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Movegen.Implementation
{
    public static class Switch
    {
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static ulong GetSliderHCond(int SliderSquare, ulong occupy)
        {
            ulong result = 0;
            switch (SliderSquare)
            {
                case 0:
                    result = 2ul;
                    if ((occupy & 2ul) == 0) result |= 4ul;
                    if ((occupy & 6ul) == 0) result |= 8ul;
                    if ((occupy & 14ul) == 0) result |= 16ul;
                    if ((occupy & 30ul) == 0) result |= 32ul;
                    if ((occupy & 62ul) == 0) result |= 64ul;
                    if ((occupy & 126ul) == 0) result |= 128ul;
                    return result;
                case 1:
                    result = 5ul;
                    if ((occupy & 4ul) == 0) result |= 8ul;
                    if ((occupy & 12ul) == 0) result |= 16ul;
                    if ((occupy & 28ul) == 0) result |= 32ul;
                    if ((occupy & 60ul) == 0) result |= 64ul;
                    if ((occupy & 124ul) == 0) result |= 128ul;
                    return result;
                case 2:
                    result = 10ul;
                    if ((occupy & 2ul) == 0) result |= 1ul;
                    if ((occupy & 8ul) == 0) result |= 16ul;
                    if ((occupy & 24ul) == 0) result |= 32ul;
                    if ((occupy & 56ul) == 0) result |= 64ul;
                    if ((occupy & 120ul) == 0) result |= 128ul;
                    return result;
                case 3:
                    result = 20ul;
                    if ((occupy & 4ul) == 0) result |= 2ul;
                    if ((occupy & 6ul) == 0) result |= 1ul;
                    if ((occupy & 16ul) == 0) result |= 32ul;
                    if ((occupy & 48ul) == 0) result |= 64ul;
                    if ((occupy & 112ul) == 0) result |= 128ul;
                    return result;
                case 4:
                    result = 40ul;
                    if ((occupy & 8ul) == 0) result |= 4ul;
                    if ((occupy & 12ul) == 0) result |= 2ul;
                    if ((occupy & 14ul) == 0) result |= 1ul;
                    if ((occupy & 32ul) == 0) result |= 64ul;
                    if ((occupy & 96ul) == 0) result |= 128ul;
                    return result;
                case 5:
                    result = 80ul;
                    if ((occupy & 16ul) == 0) result |= 8ul;
                    if ((occupy & 24ul) == 0) result |= 4ul;
                    if ((occupy & 28ul) == 0) result |= 2ul;
                    if ((occupy & 30ul) == 0) result |= 1ul;
                    if ((occupy & 64ul) == 0) result |= 128ul;
                    return result;
                case 6:
                    result = 160ul;
                    if ((occupy & 32ul) == 0) result |= 16ul;
                    if ((occupy & 48ul) == 0) result |= 8ul;
                    if ((occupy & 56ul) == 0) result |= 4ul;
                    if ((occupy & 60ul) == 0) result |= 2ul;
                    if ((occupy & 62ul) == 0) result |= 1ul;
                    return result;
                case 7:
                    result = 64ul;
                    if ((occupy & 64ul) == 0) result |= 32ul;
                    if ((occupy & 96ul) == 0) result |= 16ul;
                    if ((occupy & 112ul) == 0) result |= 8ul;
                    if ((occupy & 120ul) == 0) result |= 4ul;
                    if ((occupy & 124ul) == 0) result |= 2ul;
                    if ((occupy & 126ul) == 0) result |= 1ul;
                    return result;
                case 8:
                    result = 512ul;
                    if ((occupy & 512ul) == 0) result |= 1024ul;
                    if ((occupy & 1536ul) == 0) result |= 2048ul;
                    if ((occupy & 3584ul) == 0) result |= 4096ul;
                    if ((occupy & 7680ul) == 0) result |= 8192ul;
                    if ((occupy & 15872ul) == 0) result |= 16384ul;
                    if ((occupy & 32256ul) == 0) result |= 32768ul;
                    return result;
                case 9:
                    result = 1280ul;
                    if ((occupy & 1024ul) == 0) result |= 2048ul;
                    if ((occupy & 3072ul) == 0) result |= 4096ul;
                    if ((occupy & 7168ul) == 0) result |= 8192ul;
                    if ((occupy & 15360ul) == 0) result |= 16384ul;
                    if ((occupy & 31744ul) == 0) result |= 32768ul;
                    return result;
                case 10:
                    result = 2560ul;
                    if ((occupy & 512ul) == 0) result |= 256ul;
                    if ((occupy & 2048ul) == 0) result |= 4096ul;
                    if ((occupy & 6144ul) == 0) result |= 8192ul;
                    if ((occupy & 14336ul) == 0) result |= 16384ul;
                    if ((occupy & 30720ul) == 0) result |= 32768ul;
                    return result;
                case 11:
                    result = 5120ul;
                    if ((occupy & 1024ul) == 0) result |= 512ul;
                    if ((occupy & 1536ul) == 0) result |= 256ul;
                    if ((occupy & 4096ul) == 0) result |= 8192ul;
                    if ((occupy & 12288ul) == 0) result |= 16384ul;
                    if ((occupy & 28672ul) == 0) result |= 32768ul;
                    return result;
                case 12:
                    result = 10240ul;
                    if ((occupy & 2048ul) == 0) result |= 1024ul;
                    if ((occupy & 3072ul) == 0) result |= 512ul;
                    if ((occupy & 3584ul) == 0) result |= 256ul;
                    if ((occupy & 8192ul) == 0) result |= 16384ul;
                    if ((occupy & 24576ul) == 0) result |= 32768ul;
                    return result;
                case 13:
                    result = 20480ul;
                    if ((occupy & 4096ul) == 0) result |= 2048ul;
                    if ((occupy & 6144ul) == 0) result |= 1024ul;
                    if ((occupy & 7168ul) == 0) result |= 512ul;
                    if ((occupy & 7680ul) == 0) result |= 256ul;
                    if ((occupy & 16384ul) == 0) result |= 32768ul;
                    return result;
                case 14:
                    result = 40960ul;
                    if ((occupy & 8192ul) == 0) result |= 4096ul;
                    if ((occupy & 12288ul) == 0) result |= 2048ul;
                    if ((occupy & 14336ul) == 0) result |= 1024ul;
                    if ((occupy & 15360ul) == 0) result |= 512ul;
                    if ((occupy & 15872ul) == 0) result |= 256ul;
                    return result;
                case 15:
                    result = 16384ul;
                    if ((occupy & 16384ul) == 0) result |= 8192ul;
                    if ((occupy & 24576ul) == 0) result |= 4096ul;
                    if ((occupy & 28672ul) == 0) result |= 2048ul;
                    if ((occupy & 30720ul) == 0) result |= 1024ul;
                    if ((occupy & 31744ul) == 0) result |= 512ul;
                    if ((occupy & 32256ul) == 0) result |= 256ul;
                    return result;
                case 16:
                    result = 131072ul;
                    if ((occupy & 131072ul) == 0) result |= 262144ul;
                    if ((occupy & 393216ul) == 0) result |= 524288ul;
                    if ((occupy & 917504ul) == 0) result |= 1048576ul;
                    if ((occupy & 1966080ul) == 0) result |= 2097152ul;
                    if ((occupy & 4063232ul) == 0) result |= 4194304ul;
                    if ((occupy & 8257536ul) == 0) result |= 8388608ul;
                    return result;
                case 17:
                    result = 327680ul;
                    if ((occupy & 262144ul) == 0) result |= 524288ul;
                    if ((occupy & 786432ul) == 0) result |= 1048576ul;
                    if ((occupy & 1835008ul) == 0) result |= 2097152ul;
                    if ((occupy & 3932160ul) == 0) result |= 4194304ul;
                    if ((occupy & 8126464ul) == 0) result |= 8388608ul;
                    return result;
                case 18:
                    result = 655360ul;
                    if ((occupy & 131072ul) == 0) result |= 65536ul;
                    if ((occupy & 524288ul) == 0) result |= 1048576ul;
                    if ((occupy & 1572864ul) == 0) result |= 2097152ul;
                    if ((occupy & 3670016ul) == 0) result |= 4194304ul;
                    if ((occupy & 7864320ul) == 0) result |= 8388608ul;
                    return result;
                case 19:
                    result = 1310720ul;
                    if ((occupy & 262144ul) == 0) result |= 131072ul;
                    if ((occupy & 393216ul) == 0) result |= 65536ul;
                    if ((occupy & 1048576ul) == 0) result |= 2097152ul;
                    if ((occupy & 3145728ul) == 0) result |= 4194304ul;
                    if ((occupy & 7340032ul) == 0) result |= 8388608ul;
                    return result;
                case 20:
                    result = 2621440ul;
                    if ((occupy & 524288ul) == 0) result |= 262144ul;
                    if ((occupy & 786432ul) == 0) result |= 131072ul;
                    if ((occupy & 917504ul) == 0) result |= 65536ul;
                    if ((occupy & 2097152ul) == 0) result |= 4194304ul;
                    if ((occupy & 6291456ul) == 0) result |= 8388608ul;
                    return result;
                case 21:
                    result = 5242880ul;
                    if ((occupy & 1048576ul) == 0) result |= 524288ul;
                    if ((occupy & 1572864ul) == 0) result |= 262144ul;
                    if ((occupy & 1835008ul) == 0) result |= 131072ul;
                    if ((occupy & 1966080ul) == 0) result |= 65536ul;
                    if ((occupy & 4194304ul) == 0) result |= 8388608ul;
                    return result;
                case 22:
                    result = 10485760ul;
                    if ((occupy & 2097152ul) == 0) result |= 1048576ul;
                    if ((occupy & 3145728ul) == 0) result |= 524288ul;
                    if ((occupy & 3670016ul) == 0) result |= 262144ul;
                    if ((occupy & 3932160ul) == 0) result |= 131072ul;
                    if ((occupy & 4063232ul) == 0) result |= 65536ul;
                    return result;
                case 23:
                    result = 4194304ul;
                    if ((occupy & 4194304ul) == 0) result |= 2097152ul;
                    if ((occupy & 6291456ul) == 0) result |= 1048576ul;
                    if ((occupy & 7340032ul) == 0) result |= 524288ul;
                    if ((occupy & 7864320ul) == 0) result |= 262144ul;
                    if ((occupy & 8126464ul) == 0) result |= 131072ul;
                    if ((occupy & 8257536ul) == 0) result |= 65536ul;
                    return result;
                case 24:
                    result = 33554432ul;
                    if ((occupy & 33554432ul) == 0) result |= 67108864ul;
                    if ((occupy & 100663296ul) == 0) result |= 134217728ul;
                    if ((occupy & 234881024ul) == 0) result |= 268435456ul;
                    if ((occupy & 503316480ul) == 0) result |= 536870912ul;
                    if ((occupy & 1040187392ul) == 0) result |= 1073741824ul;
                    if ((occupy & 2113929216ul) == 0) result |= 2147483648ul;
                    return result;
                case 25:
                    result = 83886080ul;
                    if ((occupy & 67108864ul) == 0) result |= 134217728ul;
                    if ((occupy & 201326592ul) == 0) result |= 268435456ul;
                    if ((occupy & 469762048ul) == 0) result |= 536870912ul;
                    if ((occupy & 1006632960ul) == 0) result |= 1073741824ul;
                    if ((occupy & 2080374784ul) == 0) result |= 2147483648ul;
                    return result;
                case 26:
                    result = 167772160ul;
                    if ((occupy & 33554432ul) == 0) result |= 16777216ul;
                    if ((occupy & 134217728ul) == 0) result |= 268435456ul;
                    if ((occupy & 402653184ul) == 0) result |= 536870912ul;
                    if ((occupy & 939524096ul) == 0) result |= 1073741824ul;
                    if ((occupy & 2013265920ul) == 0) result |= 2147483648ul;
                    return result;
                case 27:
                    result = 335544320ul;
                    if ((occupy & 67108864ul) == 0) result |= 33554432ul;
                    if ((occupy & 100663296ul) == 0) result |= 16777216ul;
                    if ((occupy & 268435456ul) == 0) result |= 536870912ul;
                    if ((occupy & 805306368ul) == 0) result |= 1073741824ul;
                    if ((occupy & 1879048192ul) == 0) result |= 2147483648ul;
                    return result;
                case 28:
                    result = 671088640ul;
                    if ((occupy & 134217728ul) == 0) result |= 67108864ul;
                    if ((occupy & 201326592ul) == 0) result |= 33554432ul;
                    if ((occupy & 234881024ul) == 0) result |= 16777216ul;
                    if ((occupy & 536870912ul) == 0) result |= 1073741824ul;
                    if ((occupy & 1610612736ul) == 0) result |= 2147483648ul;
                    return result;
                case 29:
                    result = 1342177280ul;
                    if ((occupy & 268435456ul) == 0) result |= 134217728ul;
                    if ((occupy & 402653184ul) == 0) result |= 67108864ul;
                    if ((occupy & 469762048ul) == 0) result |= 33554432ul;
                    if ((occupy & 503316480ul) == 0) result |= 16777216ul;
                    if ((occupy & 1073741824ul) == 0) result |= 2147483648ul;
                    return result;
                case 30:
                    result = 2684354560ul;
                    if ((occupy & 536870912ul) == 0) result |= 268435456ul;
                    if ((occupy & 805306368ul) == 0) result |= 134217728ul;
                    if ((occupy & 939524096ul) == 0) result |= 67108864ul;
                    if ((occupy & 1006632960ul) == 0) result |= 33554432ul;
                    if ((occupy & 1040187392ul) == 0) result |= 16777216ul;
                    return result;
                case 31:
                    result = 1073741824ul;
                    if ((occupy & 1073741824ul) == 0) result |= 536870912ul;
                    if ((occupy & 1610612736ul) == 0) result |= 268435456ul;
                    if ((occupy & 1879048192ul) == 0) result |= 134217728ul;
                    if ((occupy & 2013265920ul) == 0) result |= 67108864ul;
                    if ((occupy & 2080374784ul) == 0) result |= 33554432ul;
                    if ((occupy & 2113929216ul) == 0) result |= 16777216ul;
                    return result;
                case 32:
                    result = 8589934592ul;
                    if ((occupy & 8589934592ul) == 0) result |= 17179869184ul;
                    if ((occupy & 25769803776ul) == 0) result |= 34359738368ul;
                    if ((occupy & 60129542144ul) == 0) result |= 68719476736ul;
                    if ((occupy & 128849018880ul) == 0) result |= 137438953472ul;
                    if ((occupy & 266287972352ul) == 0) result |= 274877906944ul;
                    if ((occupy & 541165879296ul) == 0) result |= 549755813888ul;
                    return result;
                case 33:
                    result = 21474836480ul;
                    if ((occupy & 17179869184ul) == 0) result |= 34359738368ul;
                    if ((occupy & 51539607552ul) == 0) result |= 68719476736ul;
                    if ((occupy & 120259084288ul) == 0) result |= 137438953472ul;
                    if ((occupy & 257698037760ul) == 0) result |= 274877906944ul;
                    if ((occupy & 532575944704ul) == 0) result |= 549755813888ul;
                    return result;
                case 34:
                    result = 42949672960ul;
                    if ((occupy & 8589934592ul) == 0) result |= 4294967296ul;
                    if ((occupy & 34359738368ul) == 0) result |= 68719476736ul;
                    if ((occupy & 103079215104ul) == 0) result |= 137438953472ul;
                    if ((occupy & 240518168576ul) == 0) result |= 274877906944ul;
                    if ((occupy & 515396075520ul) == 0) result |= 549755813888ul;
                    return result;
                case 35:
                    result = 85899345920ul;
                    if ((occupy & 17179869184ul) == 0) result |= 8589934592ul;
                    if ((occupy & 25769803776ul) == 0) result |= 4294967296ul;
                    if ((occupy & 68719476736ul) == 0) result |= 137438953472ul;
                    if ((occupy & 206158430208ul) == 0) result |= 274877906944ul;
                    if ((occupy & 481036337152ul) == 0) result |= 549755813888ul;
                    return result;
                case 36:
                    result = 171798691840ul;
                    if ((occupy & 34359738368ul) == 0) result |= 17179869184ul;
                    if ((occupy & 51539607552ul) == 0) result |= 8589934592ul;
                    if ((occupy & 60129542144ul) == 0) result |= 4294967296ul;
                    if ((occupy & 137438953472ul) == 0) result |= 274877906944ul;
                    if ((occupy & 412316860416ul) == 0) result |= 549755813888ul;
                    return result;
                case 37:
                    result = 343597383680ul;
                    if ((occupy & 68719476736ul) == 0) result |= 34359738368ul;
                    if ((occupy & 103079215104ul) == 0) result |= 17179869184ul;
                    if ((occupy & 120259084288ul) == 0) result |= 8589934592ul;
                    if ((occupy & 128849018880ul) == 0) result |= 4294967296ul;
                    if ((occupy & 274877906944ul) == 0) result |= 549755813888ul;
                    return result;
                case 38:
                    result = 687194767360ul;
                    if ((occupy & 137438953472ul) == 0) result |= 68719476736ul;
                    if ((occupy & 206158430208ul) == 0) result |= 34359738368ul;
                    if ((occupy & 240518168576ul) == 0) result |= 17179869184ul;
                    if ((occupy & 257698037760ul) == 0) result |= 8589934592ul;
                    if ((occupy & 266287972352ul) == 0) result |= 4294967296ul;
                    return result;
                case 39:
                    result = 274877906944ul;
                    if ((occupy & 274877906944ul) == 0) result |= 137438953472ul;
                    if ((occupy & 412316860416ul) == 0) result |= 68719476736ul;
                    if ((occupy & 481036337152ul) == 0) result |= 34359738368ul;
                    if ((occupy & 515396075520ul) == 0) result |= 17179869184ul;
                    if ((occupy & 532575944704ul) == 0) result |= 8589934592ul;
                    if ((occupy & 541165879296ul) == 0) result |= 4294967296ul;
                    return result;
                case 40:
                    result = 2199023255552ul;
                    if ((occupy & 2199023255552ul) == 0) result |= 4398046511104ul;
                    if ((occupy & 6597069766656ul) == 0) result |= 8796093022208ul;
                    if ((occupy & 15393162788864ul) == 0) result |= 17592186044416ul;
                    if ((occupy & 32985348833280ul) == 0) result |= 35184372088832ul;
                    if ((occupy & 68169720922112ul) == 0) result |= 70368744177664ul;
                    if ((occupy & 138538465099776ul) == 0) result |= 140737488355328ul;
                    return result;
                case 41:
                    result = 5497558138880ul;
                    if ((occupy & 4398046511104ul) == 0) result |= 8796093022208ul;
                    if ((occupy & 13194139533312ul) == 0) result |= 17592186044416ul;
                    if ((occupy & 30786325577728ul) == 0) result |= 35184372088832ul;
                    if ((occupy & 65970697666560ul) == 0) result |= 70368744177664ul;
                    if ((occupy & 136339441844224ul) == 0) result |= 140737488355328ul;
                    return result;
                case 42:
                    result = 10995116277760ul;
                    if ((occupy & 2199023255552ul) == 0) result |= 1099511627776ul;
                    if ((occupy & 8796093022208ul) == 0) result |= 17592186044416ul;
                    if ((occupy & 26388279066624ul) == 0) result |= 35184372088832ul;
                    if ((occupy & 61572651155456ul) == 0) result |= 70368744177664ul;
                    if ((occupy & 131941395333120ul) == 0) result |= 140737488355328ul;
                    return result;
                case 43:
                    result = 21990232555520ul;
                    if ((occupy & 4398046511104ul) == 0) result |= 2199023255552ul;
                    if ((occupy & 6597069766656ul) == 0) result |= 1099511627776ul;
                    if ((occupy & 17592186044416ul) == 0) result |= 35184372088832ul;
                    if ((occupy & 52776558133248ul) == 0) result |= 70368744177664ul;
                    if ((occupy & 123145302310912ul) == 0) result |= 140737488355328ul;
                    return result;
                case 44:
                    result = 43980465111040ul;
                    if ((occupy & 8796093022208ul) == 0) result |= 4398046511104ul;
                    if ((occupy & 13194139533312ul) == 0) result |= 2199023255552ul;
                    if ((occupy & 15393162788864ul) == 0) result |= 1099511627776ul;
                    if ((occupy & 35184372088832ul) == 0) result |= 70368744177664ul;
                    if ((occupy & 105553116266496ul) == 0) result |= 140737488355328ul;
                    return result;
                case 45:
                    result = 87960930222080ul;
                    if ((occupy & 17592186044416ul) == 0) result |= 8796093022208ul;
                    if ((occupy & 26388279066624ul) == 0) result |= 4398046511104ul;
                    if ((occupy & 30786325577728ul) == 0) result |= 2199023255552ul;
                    if ((occupy & 32985348833280ul) == 0) result |= 1099511627776ul;
                    if ((occupy & 70368744177664ul) == 0) result |= 140737488355328ul;
                    return result;
                case 46:
                    result = 175921860444160ul;
                    if ((occupy & 35184372088832ul) == 0) result |= 17592186044416ul;
                    if ((occupy & 52776558133248ul) == 0) result |= 8796093022208ul;
                    if ((occupy & 61572651155456ul) == 0) result |= 4398046511104ul;
                    if ((occupy & 65970697666560ul) == 0) result |= 2199023255552ul;
                    if ((occupy & 68169720922112ul) == 0) result |= 1099511627776ul;
                    return result;
                case 47:
                    result = 70368744177664ul;
                    if ((occupy & 70368744177664ul) == 0) result |= 35184372088832ul;
                    if ((occupy & 105553116266496ul) == 0) result |= 17592186044416ul;
                    if ((occupy & 123145302310912ul) == 0) result |= 8796093022208ul;
                    if ((occupy & 131941395333120ul) == 0) result |= 4398046511104ul;
                    if ((occupy & 136339441844224ul) == 0) result |= 2199023255552ul;
                    if ((occupy & 138538465099776ul) == 0) result |= 1099511627776ul;
                    return result;
                case 48:
                    result = 562949953421312ul;
                    if ((occupy & 562949953421312ul) == 0) result |= 1125899906842624ul;
                    if ((occupy & 1688849860263936ul) == 0) result |= 2251799813685248ul;
                    if ((occupy & 3940649673949184ul) == 0) result |= 4503599627370496ul;
                    if ((occupy & 8444249301319680ul) == 0) result |= 9007199254740992ul;
                    if ((occupy & 17451448556060672ul) == 0) result |= 18014398509481984ul;
                    if ((occupy & 35465847065542656ul) == 0) result |= 36028797018963968ul;
                    return result;
                case 49:
                    result = 1407374883553280ul;
                    if ((occupy & 1125899906842624ul) == 0) result |= 2251799813685248ul;
                    if ((occupy & 3377699720527872ul) == 0) result |= 4503599627370496ul;
                    if ((occupy & 7881299347898368ul) == 0) result |= 9007199254740992ul;
                    if ((occupy & 16888498602639360ul) == 0) result |= 18014398509481984ul;
                    if ((occupy & 34902897112121344ul) == 0) result |= 36028797018963968ul;
                    return result;
                case 50:
                    result = 2814749767106560ul;
                    if ((occupy & 562949953421312ul) == 0) result |= 281474976710656ul;
                    if ((occupy & 2251799813685248ul) == 0) result |= 4503599627370496ul;
                    if ((occupy & 6755399441055744ul) == 0) result |= 9007199254740992ul;
                    if ((occupy & 15762598695796736ul) == 0) result |= 18014398509481984ul;
                    if ((occupy & 33776997205278720ul) == 0) result |= 36028797018963968ul;
                    return result;
                case 51:
                    result = 5629499534213120ul;
                    if ((occupy & 1125899906842624ul) == 0) result |= 562949953421312ul;
                    if ((occupy & 1688849860263936ul) == 0) result |= 281474976710656ul;
                    if ((occupy & 4503599627370496ul) == 0) result |= 9007199254740992ul;
                    if ((occupy & 13510798882111488ul) == 0) result |= 18014398509481984ul;
                    if ((occupy & 31525197391593472ul) == 0) result |= 36028797018963968ul;
                    return result;
                case 52:
                    result = 11258999068426240ul;
                    if ((occupy & 2251799813685248ul) == 0) result |= 1125899906842624ul;
                    if ((occupy & 3377699720527872ul) == 0) result |= 562949953421312ul;
                    if ((occupy & 3940649673949184ul) == 0) result |= 281474976710656ul;
                    if ((occupy & 9007199254740992ul) == 0) result |= 18014398509481984ul;
                    if ((occupy & 27021597764222976ul) == 0) result |= 36028797018963968ul;
                    return result;
                case 53:
                    result = 22517998136852480ul;
                    if ((occupy & 4503599627370496ul) == 0) result |= 2251799813685248ul;
                    if ((occupy & 6755399441055744ul) == 0) result |= 1125899906842624ul;
                    if ((occupy & 7881299347898368ul) == 0) result |= 562949953421312ul;
                    if ((occupy & 8444249301319680ul) == 0) result |= 281474976710656ul;
                    if ((occupy & 18014398509481984ul) == 0) result |= 36028797018963968ul;
                    return result;
                case 54:
                    result = 45035996273704960ul;
                    if ((occupy & 9007199254740992ul) == 0) result |= 4503599627370496ul;
                    if ((occupy & 13510798882111488ul) == 0) result |= 2251799813685248ul;
                    if ((occupy & 15762598695796736ul) == 0) result |= 1125899906842624ul;
                    if ((occupy & 16888498602639360ul) == 0) result |= 562949953421312ul;
                    if ((occupy & 17451448556060672ul) == 0) result |= 281474976710656ul;
                    return result;
                case 55:
                    result = 18014398509481984ul;
                    if ((occupy & 18014398509481984ul) == 0) result |= 9007199254740992ul;
                    if ((occupy & 27021597764222976ul) == 0) result |= 4503599627370496ul;
                    if ((occupy & 31525197391593472ul) == 0) result |= 2251799813685248ul;
                    if ((occupy & 33776997205278720ul) == 0) result |= 1125899906842624ul;
                    if ((occupy & 34902897112121344ul) == 0) result |= 562949953421312ul;
                    if ((occupy & 35465847065542656ul) == 0) result |= 281474976710656ul;
                    return result;
                case 56:
                    result = 144115188075855872ul;
                    if ((occupy & 144115188075855872ul) == 0) result |= 288230376151711744ul;
                    if ((occupy & 432345564227567616ul) == 0) result |= 576460752303423488ul;
                    if ((occupy & 1008806316530991104ul) == 0) result |= 1152921504606846976ul;
                    if ((occupy & 2161727821137838080ul) == 0) result |= 2305843009213693952ul;
                    if ((occupy & 4467570830351532032ul) == 0) result |= 4611686018427387904ul;
                    if ((occupy & 9079256848778919936ul) == 0) result |= 9223372036854775808ul;
                    return result;
                case 57:
                    result = 360287970189639680ul;
                    if ((occupy & 288230376151711744ul) == 0) result |= 576460752303423488ul;
                    if ((occupy & 864691128455135232ul) == 0) result |= 1152921504606846976ul;
                    if ((occupy & 2017612633061982208ul) == 0) result |= 2305843009213693952ul;
                    if ((occupy & 4323455642275676160ul) == 0) result |= 4611686018427387904ul;
                    if ((occupy & 8935141660703064064ul) == 0) result |= 9223372036854775808ul;
                    return result;
                case 58:
                    result = 720575940379279360ul;
                    if ((occupy & 144115188075855872ul) == 0) result |= 72057594037927936ul;
                    if ((occupy & 576460752303423488ul) == 0) result |= 1152921504606846976ul;
                    if ((occupy & 1729382256910270464ul) == 0) result |= 2305843009213693952ul;
                    if ((occupy & 4035225266123964416ul) == 0) result |= 4611686018427387904ul;
                    if ((occupy & 8646911284551352320ul) == 0) result |= 9223372036854775808ul;
                    return result;
                case 59:
                    result = 1441151880758558720ul;
                    if ((occupy & 288230376151711744ul) == 0) result |= 144115188075855872ul;
                    if ((occupy & 432345564227567616ul) == 0) result |= 72057594037927936ul;
                    if ((occupy & 1152921504606846976ul) == 0) result |= 2305843009213693952ul;
                    if ((occupy & 3458764513820540928ul) == 0) result |= 4611686018427387904ul;
                    if ((occupy & 8070450532247928832ul) == 0) result |= 9223372036854775808ul;
                    return result;
                case 60:
                    result = 2882303761517117440ul;
                    if ((occupy & 576460752303423488ul) == 0) result |= 288230376151711744ul;
                    if ((occupy & 864691128455135232ul) == 0) result |= 144115188075855872ul;
                    if ((occupy & 1008806316530991104ul) == 0) result |= 72057594037927936ul;
                    if ((occupy & 2305843009213693952ul) == 0) result |= 4611686018427387904ul;
                    if ((occupy & 6917529027641081856ul) == 0) result |= 9223372036854775808ul;
                    return result;
                case 61:
                    result = 5764607523034234880ul;
                    if ((occupy & 1152921504606846976ul) == 0) result |= 576460752303423488ul;
                    if ((occupy & 1729382256910270464ul) == 0) result |= 288230376151711744ul;
                    if ((occupy & 2017612633061982208ul) == 0) result |= 144115188075855872ul;
                    if ((occupy & 2161727821137838080ul) == 0) result |= 72057594037927936ul;
                    if ((occupy & 4611686018427387904ul) == 0) result |= 9223372036854775808ul;
                    return result;
                case 62:
                    result = 11529215046068469760ul;
                    if ((occupy & 2305843009213693952ul) == 0) result |= 1152921504606846976ul;
                    if ((occupy & 3458764513820540928ul) == 0) result |= 576460752303423488ul;
                    if ((occupy & 4035225266123964416ul) == 0) result |= 288230376151711744ul;
                    if ((occupy & 4323455642275676160ul) == 0) result |= 144115188075855872ul;
                    if ((occupy & 4467570830351532032ul) == 0) result |= 72057594037927936ul;
                    return result;
                case 63:
                    result = 4611686018427387904ul;
                    if ((occupy & 4611686018427387904ul) == 0) result |= 2305843009213693952ul;
                    if ((occupy & 6917529027641081856ul) == 0) result |= 1152921504606846976ul;
                    if ((occupy & 8070450532247928832ul) == 0) result |= 576460752303423488ul;
                    if ((occupy & 8646911284551352320ul) == 0) result |= 288230376151711744ul;
                    if ((occupy & 8935141660703064064ul) == 0) result |= 144115188075855872ul;
                    if ((occupy & 9079256848778919936ul) == 0) result |= 72057594037927936ul;
                    return result;
            }
            return 0;
        }
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static ulong GetSliderVCond(int SliderSquare, ulong occupy)
        {
            ulong result = 0;
            switch (SliderSquare)
            {
                case 0:
                    result = 256ul;
                    if ((occupy & 256ul) == 0) result |= 65536ul;
                    if ((occupy & 65792ul) == 0) result |= 16777216ul;
                    if ((occupy & 16843008ul) == 0) result |= 4294967296ul;
                    if ((occupy & 4311810304ul) == 0) result |= 1099511627776ul;
                    if ((occupy & 1103823438080ul) == 0) result |= 281474976710656ul;
                    if ((occupy & 282578800148736ul) == 0) result |= 72057594037927936ul;
                    return result;
                case 1:
                    result = 512ul;
                    if ((occupy & 512ul) == 0) result |= 131072ul;
                    if ((occupy & 131584ul) == 0) result |= 33554432ul;
                    if ((occupy & 33686016ul) == 0) result |= 8589934592ul;
                    if ((occupy & 8623620608ul) == 0) result |= 2199023255552ul;
                    if ((occupy & 2207646876160ul) == 0) result |= 562949953421312ul;
                    if ((occupy & 565157600297472ul) == 0) result |= 144115188075855872ul;
                    return result;
                case 2:
                    result = 1024ul;
                    if ((occupy & 1024ul) == 0) result |= 262144ul;
                    if ((occupy & 263168ul) == 0) result |= 67108864ul;
                    if ((occupy & 67372032ul) == 0) result |= 17179869184ul;
                    if ((occupy & 17247241216ul) == 0) result |= 4398046511104ul;
                    if ((occupy & 4415293752320ul) == 0) result |= 1125899906842624ul;
                    if ((occupy & 1130315200594944ul) == 0) result |= 288230376151711744ul;
                    return result;
                case 3:
                    result = 2048ul;
                    if ((occupy & 2048ul) == 0) result |= 524288ul;
                    if ((occupy & 526336ul) == 0) result |= 134217728ul;
                    if ((occupy & 134744064ul) == 0) result |= 34359738368ul;
                    if ((occupy & 34494482432ul) == 0) result |= 8796093022208ul;
                    if ((occupy & 8830587504640ul) == 0) result |= 2251799813685248ul;
                    if ((occupy & 2260630401189888ul) == 0) result |= 576460752303423488ul;
                    return result;
                case 4:
                    result = 4096ul;
                    if ((occupy & 4096ul) == 0) result |= 1048576ul;
                    if ((occupy & 1052672ul) == 0) result |= 268435456ul;
                    if ((occupy & 269488128ul) == 0) result |= 68719476736ul;
                    if ((occupy & 68988964864ul) == 0) result |= 17592186044416ul;
                    if ((occupy & 17661175009280ul) == 0) result |= 4503599627370496ul;
                    if ((occupy & 4521260802379776ul) == 0) result |= 1152921504606846976ul;
                    return result;
                case 5:
                    result = 8192ul;
                    if ((occupy & 8192ul) == 0) result |= 2097152ul;
                    if ((occupy & 2105344ul) == 0) result |= 536870912ul;
                    if ((occupy & 538976256ul) == 0) result |= 137438953472ul;
                    if ((occupy & 137977929728ul) == 0) result |= 35184372088832ul;
                    if ((occupy & 35322350018560ul) == 0) result |= 9007199254740992ul;
                    if ((occupy & 9042521604759552ul) == 0) result |= 2305843009213693952ul;
                    return result;
                case 6:
                    result = 16384ul;
                    if ((occupy & 16384ul) == 0) result |= 4194304ul;
                    if ((occupy & 4210688ul) == 0) result |= 1073741824ul;
                    if ((occupy & 1077952512ul) == 0) result |= 274877906944ul;
                    if ((occupy & 275955859456ul) == 0) result |= 70368744177664ul;
                    if ((occupy & 70644700037120ul) == 0) result |= 18014398509481984ul;
                    if ((occupy & 18085043209519104ul) == 0) result |= 4611686018427387904ul;
                    return result;
                case 7:
                    result = 32768ul;
                    if ((occupy & 32768ul) == 0) result |= 8388608ul;
                    if ((occupy & 8421376ul) == 0) result |= 2147483648ul;
                    if ((occupy & 2155905024ul) == 0) result |= 549755813888ul;
                    if ((occupy & 551911718912ul) == 0) result |= 140737488355328ul;
                    if ((occupy & 141289400074240ul) == 0) result |= 36028797018963968ul;
                    if ((occupy & 36170086419038208ul) == 0) result |= 9223372036854775808ul;
                    return result;
                case 8:
                    result = 65537ul;
                    if ((occupy & 65536ul) == 0) result |= 16777216ul;
                    if ((occupy & 16842752ul) == 0) result |= 4294967296ul;
                    if ((occupy & 4311810048ul) == 0) result |= 1099511627776ul;
                    if ((occupy & 1103823437824ul) == 0) result |= 281474976710656ul;
                    if ((occupy & 282578800148480ul) == 0) result |= 72057594037927936ul;
                    return result;
                case 9:
                    result = 131074ul;
                    if ((occupy & 131072ul) == 0) result |= 33554432ul;
                    if ((occupy & 33685504ul) == 0) result |= 8589934592ul;
                    if ((occupy & 8623620096ul) == 0) result |= 2199023255552ul;
                    if ((occupy & 2207646875648ul) == 0) result |= 562949953421312ul;
                    if ((occupy & 565157600296960ul) == 0) result |= 144115188075855872ul;
                    return result;
                case 10:
                    result = 262148ul;
                    if ((occupy & 262144ul) == 0) result |= 67108864ul;
                    if ((occupy & 67371008ul) == 0) result |= 17179869184ul;
                    if ((occupy & 17247240192ul) == 0) result |= 4398046511104ul;
                    if ((occupy & 4415293751296ul) == 0) result |= 1125899906842624ul;
                    if ((occupy & 1130315200593920ul) == 0) result |= 288230376151711744ul;
                    return result;
                case 11:
                    result = 524296ul;
                    if ((occupy & 524288ul) == 0) result |= 134217728ul;
                    if ((occupy & 134742016ul) == 0) result |= 34359738368ul;
                    if ((occupy & 34494480384ul) == 0) result |= 8796093022208ul;
                    if ((occupy & 8830587502592ul) == 0) result |= 2251799813685248ul;
                    if ((occupy & 2260630401187840ul) == 0) result |= 576460752303423488ul;
                    return result;
                case 12:
                    result = 1048592ul;
                    if ((occupy & 1048576ul) == 0) result |= 268435456ul;
                    if ((occupy & 269484032ul) == 0) result |= 68719476736ul;
                    if ((occupy & 68988960768ul) == 0) result |= 17592186044416ul;
                    if ((occupy & 17661175005184ul) == 0) result |= 4503599627370496ul;
                    if ((occupy & 4521260802375680ul) == 0) result |= 1152921504606846976ul;
                    return result;
                case 13:
                    result = 2097184ul;
                    if ((occupy & 2097152ul) == 0) result |= 536870912ul;
                    if ((occupy & 538968064ul) == 0) result |= 137438953472ul;
                    if ((occupy & 137977921536ul) == 0) result |= 35184372088832ul;
                    if ((occupy & 35322350010368ul) == 0) result |= 9007199254740992ul;
                    if ((occupy & 9042521604751360ul) == 0) result |= 2305843009213693952ul;
                    return result;
                case 14:
                    result = 4194368ul;
                    if ((occupy & 4194304ul) == 0) result |= 1073741824ul;
                    if ((occupy & 1077936128ul) == 0) result |= 274877906944ul;
                    if ((occupy & 275955843072ul) == 0) result |= 70368744177664ul;
                    if ((occupy & 70644700020736ul) == 0) result |= 18014398509481984ul;
                    if ((occupy & 18085043209502720ul) == 0) result |= 4611686018427387904ul;
                    return result;
                case 15:
                    result = 8388736ul;
                    if ((occupy & 8388608ul) == 0) result |= 2147483648ul;
                    if ((occupy & 2155872256ul) == 0) result |= 549755813888ul;
                    if ((occupy & 551911686144ul) == 0) result |= 140737488355328ul;
                    if ((occupy & 141289400041472ul) == 0) result |= 36028797018963968ul;
                    if ((occupy & 36170086419005440ul) == 0) result |= 9223372036854775808ul;
                    return result;
                case 16:
                    result = 16777472ul;
                    if ((occupy & 256ul) == 0) result |= 1ul;
                    if ((occupy & 16777216ul) == 0) result |= 4294967296ul;
                    if ((occupy & 4311744512ul) == 0) result |= 1099511627776ul;
                    if ((occupy & 1103823372288ul) == 0) result |= 281474976710656ul;
                    if ((occupy & 282578800082944ul) == 0) result |= 72057594037927936ul;
                    return result;
                case 17:
                    result = 33554944ul;
                    if ((occupy & 512ul) == 0) result |= 2ul;
                    if ((occupy & 33554432ul) == 0) result |= 8589934592ul;
                    if ((occupy & 8623489024ul) == 0) result |= 2199023255552ul;
                    if ((occupy & 2207646744576ul) == 0) result |= 562949953421312ul;
                    if ((occupy & 565157600165888ul) == 0) result |= 144115188075855872ul;
                    return result;
                case 18:
                    result = 67109888ul;
                    if ((occupy & 1024ul) == 0) result |= 4ul;
                    if ((occupy & 67108864ul) == 0) result |= 17179869184ul;
                    if ((occupy & 17246978048ul) == 0) result |= 4398046511104ul;
                    if ((occupy & 4415293489152ul) == 0) result |= 1125899906842624ul;
                    if ((occupy & 1130315200331776ul) == 0) result |= 288230376151711744ul;
                    return result;
                case 19:
                    result = 134219776ul;
                    if ((occupy & 2048ul) == 0) result |= 8ul;
                    if ((occupy & 134217728ul) == 0) result |= 34359738368ul;
                    if ((occupy & 34493956096ul) == 0) result |= 8796093022208ul;
                    if ((occupy & 8830586978304ul) == 0) result |= 2251799813685248ul;
                    if ((occupy & 2260630400663552ul) == 0) result |= 576460752303423488ul;
                    return result;
                case 20:
                    result = 268439552ul;
                    if ((occupy & 4096ul) == 0) result |= 16ul;
                    if ((occupy & 268435456ul) == 0) result |= 68719476736ul;
                    if ((occupy & 68987912192ul) == 0) result |= 17592186044416ul;
                    if ((occupy & 17661173956608ul) == 0) result |= 4503599627370496ul;
                    if ((occupy & 4521260801327104ul) == 0) result |= 1152921504606846976ul;
                    return result;
                case 21:
                    result = 536879104ul;
                    if ((occupy & 8192ul) == 0) result |= 32ul;
                    if ((occupy & 536870912ul) == 0) result |= 137438953472ul;
                    if ((occupy & 137975824384ul) == 0) result |= 35184372088832ul;
                    if ((occupy & 35322347913216ul) == 0) result |= 9007199254740992ul;
                    if ((occupy & 9042521602654208ul) == 0) result |= 2305843009213693952ul;
                    return result;
                case 22:
                    result = 1073758208ul;
                    if ((occupy & 16384ul) == 0) result |= 64ul;
                    if ((occupy & 1073741824ul) == 0) result |= 274877906944ul;
                    if ((occupy & 275951648768ul) == 0) result |= 70368744177664ul;
                    if ((occupy & 70644695826432ul) == 0) result |= 18014398509481984ul;
                    if ((occupy & 18085043205308416ul) == 0) result |= 4611686018427387904ul;
                    return result;
                case 23:
                    result = 2147516416ul;
                    if ((occupy & 32768ul) == 0) result |= 128ul;
                    if ((occupy & 2147483648ul) == 0) result |= 549755813888ul;
                    if ((occupy & 551903297536ul) == 0) result |= 140737488355328ul;
                    if ((occupy & 141289391652864ul) == 0) result |= 36028797018963968ul;
                    if ((occupy & 36170086410616832ul) == 0) result |= 9223372036854775808ul;
                    return result;
                case 24:
                    result = 4295032832ul;
                    if ((occupy & 65536ul) == 0) result |= 256ul;
                    if ((occupy & 65792ul) == 0) result |= 1ul;
                    if ((occupy & 4294967296ul) == 0) result |= 1099511627776ul;
                    if ((occupy & 1103806595072ul) == 0) result |= 281474976710656ul;
                    if ((occupy & 282578783305728ul) == 0) result |= 72057594037927936ul;
                    return result;
                case 25:
                    result = 8590065664ul;
                    if ((occupy & 131072ul) == 0) result |= 512ul;
                    if ((occupy & 131584ul) == 0) result |= 2ul;
                    if ((occupy & 8589934592ul) == 0) result |= 2199023255552ul;
                    if ((occupy & 2207613190144ul) == 0) result |= 562949953421312ul;
                    if ((occupy & 565157566611456ul) == 0) result |= 144115188075855872ul;
                    return result;
                case 26:
                    result = 17180131328ul;
                    if ((occupy & 262144ul) == 0) result |= 1024ul;
                    if ((occupy & 263168ul) == 0) result |= 4ul;
                    if ((occupy & 17179869184ul) == 0) result |= 4398046511104ul;
                    if ((occupy & 4415226380288ul) == 0) result |= 1125899906842624ul;
                    if ((occupy & 1130315133222912ul) == 0) result |= 288230376151711744ul;
                    return result;
                case 27:
                    result = 34360262656ul;
                    if ((occupy & 524288ul) == 0) result |= 2048ul;
                    if ((occupy & 526336ul) == 0) result |= 8ul;
                    if ((occupy & 34359738368ul) == 0) result |= 8796093022208ul;
                    if ((occupy & 8830452760576ul) == 0) result |= 2251799813685248ul;
                    if ((occupy & 2260630266445824ul) == 0) result |= 576460752303423488ul;
                    return result;
                case 28:
                    result = 68720525312ul;
                    if ((occupy & 1048576ul) == 0) result |= 4096ul;
                    if ((occupy & 1052672ul) == 0) result |= 16ul;
                    if ((occupy & 68719476736ul) == 0) result |= 17592186044416ul;
                    if ((occupy & 17660905521152ul) == 0) result |= 4503599627370496ul;
                    if ((occupy & 4521260532891648ul) == 0) result |= 1152921504606846976ul;
                    return result;
                case 29:
                    result = 137441050624ul;
                    if ((occupy & 2097152ul) == 0) result |= 8192ul;
                    if ((occupy & 2105344ul) == 0) result |= 32ul;
                    if ((occupy & 137438953472ul) == 0) result |= 35184372088832ul;
                    if ((occupy & 35321811042304ul) == 0) result |= 9007199254740992ul;
                    if ((occupy & 9042521065783296ul) == 0) result |= 2305843009213693952ul;
                    return result;
                case 30:
                    result = 274882101248ul;
                    if ((occupy & 4194304ul) == 0) result |= 16384ul;
                    if ((occupy & 4210688ul) == 0) result |= 64ul;
                    if ((occupy & 274877906944ul) == 0) result |= 70368744177664ul;
                    if ((occupy & 70643622084608ul) == 0) result |= 18014398509481984ul;
                    if ((occupy & 18085042131566592ul) == 0) result |= 4611686018427387904ul;
                    return result;
                case 31:
                    result = 549764202496ul;
                    if ((occupy & 8388608ul) == 0) result |= 32768ul;
                    if ((occupy & 8421376ul) == 0) result |= 128ul;
                    if ((occupy & 549755813888ul) == 0) result |= 140737488355328ul;
                    if ((occupy & 141287244169216ul) == 0) result |= 36028797018963968ul;
                    if ((occupy & 36170084263133184ul) == 0) result |= 9223372036854775808ul;
                    return result;
                case 32:
                    result = 1099528404992ul;
                    if ((occupy & 16777216ul) == 0) result |= 65536ul;
                    if ((occupy & 16842752ul) == 0) result |= 256ul;
                    if ((occupy & 16843008ul) == 0) result |= 1ul;
                    if ((occupy & 1099511627776ul) == 0) result |= 281474976710656ul;
                    if ((occupy & 282574488338432ul) == 0) result |= 72057594037927936ul;
                    return result;
                case 33:
                    result = 2199056809984ul;
                    if ((occupy & 33554432ul) == 0) result |= 131072ul;
                    if ((occupy & 33685504ul) == 0) result |= 512ul;
                    if ((occupy & 33686016ul) == 0) result |= 2ul;
                    if ((occupy & 2199023255552ul) == 0) result |= 562949953421312ul;
                    if ((occupy & 565148976676864ul) == 0) result |= 144115188075855872ul;
                    return result;
                case 34:
                    result = 4398113619968ul;
                    if ((occupy & 67108864ul) == 0) result |= 262144ul;
                    if ((occupy & 67371008ul) == 0) result |= 1024ul;
                    if ((occupy & 67372032ul) == 0) result |= 4ul;
                    if ((occupy & 4398046511104ul) == 0) result |= 1125899906842624ul;
                    if ((occupy & 1130297953353728ul) == 0) result |= 288230376151711744ul;
                    return result;
                case 35:
                    result = 8796227239936ul;
                    if ((occupy & 134217728ul) == 0) result |= 524288ul;
                    if ((occupy & 134742016ul) == 0) result |= 2048ul;
                    if ((occupy & 134744064ul) == 0) result |= 8ul;
                    if ((occupy & 8796093022208ul) == 0) result |= 2251799813685248ul;
                    if ((occupy & 2260595906707456ul) == 0) result |= 576460752303423488ul;
                    return result;
                case 36:
                    result = 17592454479872ul;
                    if ((occupy & 268435456ul) == 0) result |= 1048576ul;
                    if ((occupy & 269484032ul) == 0) result |= 4096ul;
                    if ((occupy & 269488128ul) == 0) result |= 16ul;
                    if ((occupy & 17592186044416ul) == 0) result |= 4503599627370496ul;
                    if ((occupy & 4521191813414912ul) == 0) result |= 1152921504606846976ul;
                    return result;
                case 37:
                    result = 35184908959744ul;
                    if ((occupy & 536870912ul) == 0) result |= 2097152ul;
                    if ((occupy & 538968064ul) == 0) result |= 8192ul;
                    if ((occupy & 538976256ul) == 0) result |= 32ul;
                    if ((occupy & 35184372088832ul) == 0) result |= 9007199254740992ul;
                    if ((occupy & 9042383626829824ul) == 0) result |= 2305843009213693952ul;
                    return result;
                case 38:
                    result = 70369817919488ul;
                    if ((occupy & 1073741824ul) == 0) result |= 4194304ul;
                    if ((occupy & 1077936128ul) == 0) result |= 16384ul;
                    if ((occupy & 1077952512ul) == 0) result |= 64ul;
                    if ((occupy & 70368744177664ul) == 0) result |= 18014398509481984ul;
                    if ((occupy & 18084767253659648ul) == 0) result |= 4611686018427387904ul;
                    return result;
                case 39:
                    result = 140739635838976ul;
                    if ((occupy & 2147483648ul) == 0) result |= 8388608ul;
                    if ((occupy & 2155872256ul) == 0) result |= 32768ul;
                    if ((occupy & 2155905024ul) == 0) result |= 128ul;
                    if ((occupy & 140737488355328ul) == 0) result |= 36028797018963968ul;
                    if ((occupy & 36169534507319296ul) == 0) result |= 9223372036854775808ul;
                    return result;
                case 40:
                    result = 281479271677952ul;
                    if ((occupy & 4294967296ul) == 0) result |= 16777216ul;
                    if ((occupy & 4311744512ul) == 0) result |= 65536ul;
                    if ((occupy & 4311810048ul) == 0) result |= 256ul;
                    if ((occupy & 4311810304ul) == 0) result |= 1ul;
                    if ((occupy & 281474976710656ul) == 0) result |= 72057594037927936ul;
                    return result;
                case 41:
                    result = 562958543355904ul;
                    if ((occupy & 8589934592ul) == 0) result |= 33554432ul;
                    if ((occupy & 8623489024ul) == 0) result |= 131072ul;
                    if ((occupy & 8623620096ul) == 0) result |= 512ul;
                    if ((occupy & 8623620608ul) == 0) result |= 2ul;
                    if ((occupy & 562949953421312ul) == 0) result |= 144115188075855872ul;
                    return result;
                case 42:
                    result = 1125917086711808ul;
                    if ((occupy & 17179869184ul) == 0) result |= 67108864ul;
                    if ((occupy & 17246978048ul) == 0) result |= 262144ul;
                    if ((occupy & 17247240192ul) == 0) result |= 1024ul;
                    if ((occupy & 17247241216ul) == 0) result |= 4ul;
                    if ((occupy & 1125899906842624ul) == 0) result |= 288230376151711744ul;
                    return result;
                case 43:
                    result = 2251834173423616ul;
                    if ((occupy & 34359738368ul) == 0) result |= 134217728ul;
                    if ((occupy & 34493956096ul) == 0) result |= 524288ul;
                    if ((occupy & 34494480384ul) == 0) result |= 2048ul;
                    if ((occupy & 34494482432ul) == 0) result |= 8ul;
                    if ((occupy & 2251799813685248ul) == 0) result |= 576460752303423488ul;
                    return result;
                case 44:
                    result = 4503668346847232ul;
                    if ((occupy & 68719476736ul) == 0) result |= 268435456ul;
                    if ((occupy & 68987912192ul) == 0) result |= 1048576ul;
                    if ((occupy & 68988960768ul) == 0) result |= 4096ul;
                    if ((occupy & 68988964864ul) == 0) result |= 16ul;
                    if ((occupy & 4503599627370496ul) == 0) result |= 1152921504606846976ul;
                    return result;
                case 45:
                    result = 9007336693694464ul;
                    if ((occupy & 137438953472ul) == 0) result |= 536870912ul;
                    if ((occupy & 137975824384ul) == 0) result |= 2097152ul;
                    if ((occupy & 137977921536ul) == 0) result |= 8192ul;
                    if ((occupy & 137977929728ul) == 0) result |= 32ul;
                    if ((occupy & 9007199254740992ul) == 0) result |= 2305843009213693952ul;
                    return result;
                case 46:
                    result = 18014673387388928ul;
                    if ((occupy & 274877906944ul) == 0) result |= 1073741824ul;
                    if ((occupy & 275951648768ul) == 0) result |= 4194304ul;
                    if ((occupy & 275955843072ul) == 0) result |= 16384ul;
                    if ((occupy & 275955859456ul) == 0) result |= 64ul;
                    if ((occupy & 18014398509481984ul) == 0) result |= 4611686018427387904ul;
                    return result;
                case 47:
                    result = 36029346774777856ul;
                    if ((occupy & 549755813888ul) == 0) result |= 2147483648ul;
                    if ((occupy & 551903297536ul) == 0) result |= 8388608ul;
                    if ((occupy & 551911686144ul) == 0) result |= 32768ul;
                    if ((occupy & 551911718912ul) == 0) result |= 128ul;
                    if ((occupy & 36028797018963968ul) == 0) result |= 9223372036854775808ul;
                    return result;
                case 48:
                    result = 72058693549555712ul;
                    if ((occupy & 1099511627776ul) == 0) result |= 4294967296ul;
                    if ((occupy & 1103806595072ul) == 0) result |= 16777216ul;
                    if ((occupy & 1103823372288ul) == 0) result |= 65536ul;
                    if ((occupy & 1103823437824ul) == 0) result |= 256ul;
                    if ((occupy & 1103823438080ul) == 0) result |= 1ul;
                    return result;
                case 49:
                    result = 144117387099111424ul;
                    if ((occupy & 2199023255552ul) == 0) result |= 8589934592ul;
                    if ((occupy & 2207613190144ul) == 0) result |= 33554432ul;
                    if ((occupy & 2207646744576ul) == 0) result |= 131072ul;
                    if ((occupy & 2207646875648ul) == 0) result |= 512ul;
                    if ((occupy & 2207646876160ul) == 0) result |= 2ul;
                    return result;
                case 50:
                    result = 288234774198222848ul;
                    if ((occupy & 4398046511104ul) == 0) result |= 17179869184ul;
                    if ((occupy & 4415226380288ul) == 0) result |= 67108864ul;
                    if ((occupy & 4415293489152ul) == 0) result |= 262144ul;
                    if ((occupy & 4415293751296ul) == 0) result |= 1024ul;
                    if ((occupy & 4415293752320ul) == 0) result |= 4ul;
                    return result;
                case 51:
                    result = 576469548396445696ul;
                    if ((occupy & 8796093022208ul) == 0) result |= 34359738368ul;
                    if ((occupy & 8830452760576ul) == 0) result |= 134217728ul;
                    if ((occupy & 8830586978304ul) == 0) result |= 524288ul;
                    if ((occupy & 8830587502592ul) == 0) result |= 2048ul;
                    if ((occupy & 8830587504640ul) == 0) result |= 8ul;
                    return result;
                case 52:
                    result = 1152939096792891392ul;
                    if ((occupy & 17592186044416ul) == 0) result |= 68719476736ul;
                    if ((occupy & 17660905521152ul) == 0) result |= 268435456ul;
                    if ((occupy & 17661173956608ul) == 0) result |= 1048576ul;
                    if ((occupy & 17661175005184ul) == 0) result |= 4096ul;
                    if ((occupy & 17661175009280ul) == 0) result |= 16ul;
                    return result;
                case 53:
                    result = 2305878193585782784ul;
                    if ((occupy & 35184372088832ul) == 0) result |= 137438953472ul;
                    if ((occupy & 35321811042304ul) == 0) result |= 536870912ul;
                    if ((occupy & 35322347913216ul) == 0) result |= 2097152ul;
                    if ((occupy & 35322350010368ul) == 0) result |= 8192ul;
                    if ((occupy & 35322350018560ul) == 0) result |= 32ul;
                    return result;
                case 54:
                    result = 4611756387171565568ul;
                    if ((occupy & 70368744177664ul) == 0) result |= 274877906944ul;
                    if ((occupy & 70643622084608ul) == 0) result |= 1073741824ul;
                    if ((occupy & 70644695826432ul) == 0) result |= 4194304ul;
                    if ((occupy & 70644700020736ul) == 0) result |= 16384ul;
                    if ((occupy & 70644700037120ul) == 0) result |= 64ul;
                    return result;
                case 55:
                    result = 9223512774343131136ul;
                    if ((occupy & 140737488355328ul) == 0) result |= 549755813888ul;
                    if ((occupy & 141287244169216ul) == 0) result |= 2147483648ul;
                    if ((occupy & 141289391652864ul) == 0) result |= 8388608ul;
                    if ((occupy & 141289400041472ul) == 0) result |= 32768ul;
                    if ((occupy & 141289400074240ul) == 0) result |= 128ul;
                    return result;
                case 56:
                    result = 281474976710656ul;
                    if ((occupy & 281474976710656ul) == 0) result |= 1099511627776ul;
                    if ((occupy & 282574488338432ul) == 0) result |= 4294967296ul;
                    if ((occupy & 282578783305728ul) == 0) result |= 16777216ul;
                    if ((occupy & 282578800082944ul) == 0) result |= 65536ul;
                    if ((occupy & 282578800148480ul) == 0) result |= 256ul;
                    if ((occupy & 282578800148736ul) == 0) result |= 1ul;
                    return result;
                case 57:
                    result = 562949953421312ul;
                    if ((occupy & 562949953421312ul) == 0) result |= 2199023255552ul;
                    if ((occupy & 565148976676864ul) == 0) result |= 8589934592ul;
                    if ((occupy & 565157566611456ul) == 0) result |= 33554432ul;
                    if ((occupy & 565157600165888ul) == 0) result |= 131072ul;
                    if ((occupy & 565157600296960ul) == 0) result |= 512ul;
                    if ((occupy & 565157600297472ul) == 0) result |= 2ul;
                    return result;
                case 58:
                    result = 1125899906842624ul;
                    if ((occupy & 1125899906842624ul) == 0) result |= 4398046511104ul;
                    if ((occupy & 1130297953353728ul) == 0) result |= 17179869184ul;
                    if ((occupy & 1130315133222912ul) == 0) result |= 67108864ul;
                    if ((occupy & 1130315200331776ul) == 0) result |= 262144ul;
                    if ((occupy & 1130315200593920ul) == 0) result |= 1024ul;
                    if ((occupy & 1130315200594944ul) == 0) result |= 4ul;
                    return result;
                case 59:
                    result = 2251799813685248ul;
                    if ((occupy & 2251799813685248ul) == 0) result |= 8796093022208ul;
                    if ((occupy & 2260595906707456ul) == 0) result |= 34359738368ul;
                    if ((occupy & 2260630266445824ul) == 0) result |= 134217728ul;
                    if ((occupy & 2260630400663552ul) == 0) result |= 524288ul;
                    if ((occupy & 2260630401187840ul) == 0) result |= 2048ul;
                    if ((occupy & 2260630401189888ul) == 0) result |= 8ul;
                    return result;
                case 60:
                    result = 4503599627370496ul;
                    if ((occupy & 4503599627370496ul) == 0) result |= 17592186044416ul;
                    if ((occupy & 4521191813414912ul) == 0) result |= 68719476736ul;
                    if ((occupy & 4521260532891648ul) == 0) result |= 268435456ul;
                    if ((occupy & 4521260801327104ul) == 0) result |= 1048576ul;
                    if ((occupy & 4521260802375680ul) == 0) result |= 4096ul;
                    if ((occupy & 4521260802379776ul) == 0) result |= 16ul;
                    return result;
                case 61:
                    result = 9007199254740992ul;
                    if ((occupy & 9007199254740992ul) == 0) result |= 35184372088832ul;
                    if ((occupy & 9042383626829824ul) == 0) result |= 137438953472ul;
                    if ((occupy & 9042521065783296ul) == 0) result |= 536870912ul;
                    if ((occupy & 9042521602654208ul) == 0) result |= 2097152ul;
                    if ((occupy & 9042521604751360ul) == 0) result |= 8192ul;
                    if ((occupy & 9042521604759552ul) == 0) result |= 32ul;
                    return result;
                case 62:
                    result = 18014398509481984ul;
                    if ((occupy & 18014398509481984ul) == 0) result |= 70368744177664ul;
                    if ((occupy & 18084767253659648ul) == 0) result |= 274877906944ul;
                    if ((occupy & 18085042131566592ul) == 0) result |= 1073741824ul;
                    if ((occupy & 18085043205308416ul) == 0) result |= 4194304ul;
                    if ((occupy & 18085043209502720ul) == 0) result |= 16384ul;
                    if ((occupy & 18085043209519104ul) == 0) result |= 64ul;
                    return result;
                case 63:
                    result = 36028797018963968ul;
                    if ((occupy & 36028797018963968ul) == 0) result |= 140737488355328ul;
                    if ((occupy & 36169534507319296ul) == 0) result |= 549755813888ul;
                    if ((occupy & 36170084263133184ul) == 0) result |= 2147483648ul;
                    if ((occupy & 36170086410616832ul) == 0) result |= 8388608ul;
                    if ((occupy & 36170086419005440ul) == 0) result |= 32768ul;
                    if ((occupy & 36170086419038208ul) == 0) result |= 128ul;
                    return result;
            }
            return 0;
        }
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static ulong GetSliderD2Cond(int SliderSquare, ulong occupy)
        {
            ulong result = 0;
            switch (SliderSquare)
            {
                case 0:
                    result = 0ul;
                    return result;
                case 1:
                    result = 256ul;
                    return result;
                case 2:
                    result = 512ul;
                    if ((occupy & 512ul) == 0) result |= 65536ul;
                    return result;
                case 3:
                    result = 1024ul;
                    if ((occupy & 1024ul) == 0) result |= 131072ul;
                    if ((occupy & 132096ul) == 0) result |= 16777216ul;
                    return result;
                case 4:
                    result = 2048ul;
                    if ((occupy & 2048ul) == 0) result |= 262144ul;
                    if ((occupy & 264192ul) == 0) result |= 33554432ul;
                    if ((occupy & 33818624ul) == 0) result |= 4294967296ul;
                    return result;
                case 5:
                    result = 4096ul;
                    if ((occupy & 4096ul) == 0) result |= 524288ul;
                    if ((occupy & 528384ul) == 0) result |= 67108864ul;
                    if ((occupy & 67637248ul) == 0) result |= 8589934592ul;
                    if ((occupy & 8657571840ul) == 0) result |= 1099511627776ul;
                    return result;
                case 6:
                    result = 8192ul;
                    if ((occupy & 8192ul) == 0) result |= 1048576ul;
                    if ((occupy & 1056768ul) == 0) result |= 134217728ul;
                    if ((occupy & 135274496ul) == 0) result |= 17179869184ul;
                    if ((occupy & 17315143680ul) == 0) result |= 2199023255552ul;
                    if ((occupy & 2216338399232ul) == 0) result |= 281474976710656ul;
                    return result;
                case 7:
                    result = 16384ul;
                    if ((occupy & 16384ul) == 0) result |= 2097152ul;
                    if ((occupy & 2113536ul) == 0) result |= 268435456ul;
                    if ((occupy & 270548992ul) == 0) result |= 34359738368ul;
                    if ((occupy & 34630287360ul) == 0) result |= 4398046511104ul;
                    if ((occupy & 4432676798464ul) == 0) result |= 562949953421312ul;
                    if ((occupy & 567382630219776ul) == 0) result |= 72057594037927936ul;
                    return result;
                case 8:
                    result = 2ul;
                    return result;
                case 9:
                    result = 65540ul;
                    return result;
                case 10:
                    result = 131080ul;
                    if ((occupy & 131072ul) == 0) result |= 16777216ul;
                    return result;
                case 11:
                    result = 262160ul;
                    if ((occupy & 262144ul) == 0) result |= 33554432ul;
                    if ((occupy & 33816576ul) == 0) result |= 4294967296ul;
                    return result;
                case 12:
                    result = 524320ul;
                    if ((occupy & 524288ul) == 0) result |= 67108864ul;
                    if ((occupy & 67633152ul) == 0) result |= 8589934592ul;
                    if ((occupy & 8657567744ul) == 0) result |= 1099511627776ul;
                    return result;
                case 13:
                    result = 1048640ul;
                    if ((occupy & 1048576ul) == 0) result |= 134217728ul;
                    if ((occupy & 135266304ul) == 0) result |= 17179869184ul;
                    if ((occupy & 17315135488ul) == 0) result |= 2199023255552ul;
                    if ((occupy & 2216338391040ul) == 0) result |= 281474976710656ul;
                    return result;
                case 14:
                    result = 2097280ul;
                    if ((occupy & 2097152ul) == 0) result |= 268435456ul;
                    if ((occupy & 270532608ul) == 0) result |= 34359738368ul;
                    if ((occupy & 34630270976ul) == 0) result |= 4398046511104ul;
                    if ((occupy & 4432676782080ul) == 0) result |= 562949953421312ul;
                    if ((occupy & 567382630203392ul) == 0) result |= 72057594037927936ul;
                    return result;
                case 15:
                    result = 4194304ul;
                    if ((occupy & 4194304ul) == 0) result |= 536870912ul;
                    if ((occupy & 541065216ul) == 0) result |= 68719476736ul;
                    if ((occupy & 69260541952ul) == 0) result |= 8796093022208ul;
                    if ((occupy & 8865353564160ul) == 0) result |= 1125899906842624ul;
                    if ((occupy & 1134765260406784ul) == 0) result |= 144115188075855872ul;
                    return result;
                case 16:
                    result = 512ul;
                    if ((occupy & 512ul) == 0) result |= 4ul;
                    return result;
                case 17:
                    result = 16778240ul;
                    if ((occupy & 1024ul) == 0) result |= 8ul;
                    return result;
                case 18:
                    result = 33556480ul;
                    if ((occupy & 2048ul) == 0) result |= 16ul;
                    if ((occupy & 33554432ul) == 0) result |= 4294967296ul;
                    return result;
                case 19:
                    result = 67112960ul;
                    if ((occupy & 4096ul) == 0) result |= 32ul;
                    if ((occupy & 67108864ul) == 0) result |= 8589934592ul;
                    if ((occupy & 8657043456ul) == 0) result |= 1099511627776ul;
                    return result;
                case 20:
                    result = 134225920ul;
                    if ((occupy & 8192ul) == 0) result |= 64ul;
                    if ((occupy & 134217728ul) == 0) result |= 17179869184ul;
                    if ((occupy & 17314086912ul) == 0) result |= 2199023255552ul;
                    if ((occupy & 2216337342464ul) == 0) result |= 281474976710656ul;
                    return result;
                case 21:
                    result = 268451840ul;
                    if ((occupy & 16384ul) == 0) result |= 128ul;
                    if ((occupy & 268435456ul) == 0) result |= 34359738368ul;
                    if ((occupy & 34628173824ul) == 0) result |= 4398046511104ul;
                    if ((occupy & 4432674684928ul) == 0) result |= 562949953421312ul;
                    if ((occupy & 567382628106240ul) == 0) result |= 72057594037927936ul;
                    return result;
                case 22:
                    result = 536903680ul;
                    if ((occupy & 536870912ul) == 0) result |= 68719476736ul;
                    if ((occupy & 69256347648ul) == 0) result |= 8796093022208ul;
                    if ((occupy & 8865349369856ul) == 0) result |= 1125899906842624ul;
                    if ((occupy & 1134765256212480ul) == 0) result |= 144115188075855872ul;
                    return result;
                case 23:
                    result = 1073741824ul;
                    if ((occupy & 1073741824ul) == 0) result |= 137438953472ul;
                    if ((occupy & 138512695296ul) == 0) result |= 17592186044416ul;
                    if ((occupy & 17730698739712ul) == 0) result |= 2251799813685248ul;
                    if ((occupy & 2269530512424960ul) == 0) result |= 288230376151711744ul;
                    return result;
                case 24:
                    result = 131072ul;
                    if ((occupy & 131072ul) == 0) result |= 1024ul;
                    if ((occupy & 132096ul) == 0) result |= 8ul;
                    return result;
                case 25:
                    result = 4295229440ul;
                    if ((occupy & 262144ul) == 0) result |= 2048ul;
                    if ((occupy & 264192ul) == 0) result |= 16ul;
                    return result;
                case 26:
                    result = 8590458880ul;
                    if ((occupy & 524288ul) == 0) result |= 4096ul;
                    if ((occupy & 528384ul) == 0) result |= 32ul;
                    if ((occupy & 8589934592ul) == 0) result |= 1099511627776ul;
                    return result;
                case 27:
                    result = 17180917760ul;
                    if ((occupy & 1048576ul) == 0) result |= 8192ul;
                    if ((occupy & 1056768ul) == 0) result |= 64ul;
                    if ((occupy & 17179869184ul) == 0) result |= 2199023255552ul;
                    if ((occupy & 2216203124736ul) == 0) result |= 281474976710656ul;
                    return result;
                case 28:
                    result = 34361835520ul;
                    if ((occupy & 2097152ul) == 0) result |= 16384ul;
                    if ((occupy & 2113536ul) == 0) result |= 128ul;
                    if ((occupy & 34359738368ul) == 0) result |= 4398046511104ul;
                    if ((occupy & 4432406249472ul) == 0) result |= 562949953421312ul;
                    if ((occupy & 567382359670784ul) == 0) result |= 72057594037927936ul;
                    return result;
                case 29:
                    result = 68723671040ul;
                    if ((occupy & 4194304ul) == 0) result |= 32768ul;
                    if ((occupy & 68719476736ul) == 0) result |= 8796093022208ul;
                    if ((occupy & 8864812498944ul) == 0) result |= 1125899906842624ul;
                    if ((occupy & 1134764719341568ul) == 0) result |= 144115188075855872ul;
                    return result;
                case 30:
                    result = 137447342080ul;
                    if ((occupy & 137438953472ul) == 0) result |= 17592186044416ul;
                    if ((occupy & 17729624997888ul) == 0) result |= 2251799813685248ul;
                    if ((occupy & 2269529438683136ul) == 0) result |= 288230376151711744ul;
                    return result;
                case 31:
                    result = 274877906944ul;
                    if ((occupy & 274877906944ul) == 0) result |= 35184372088832ul;
                    if ((occupy & 35459249995776ul) == 0) result |= 4503599627370496ul;
                    if ((occupy & 4539058877366272ul) == 0) result |= 576460752303423488ul;
                    return result;
                case 32:
                    result = 33554432ul;
                    if ((occupy & 33554432ul) == 0) result |= 262144ul;
                    if ((occupy & 33816576ul) == 0) result |= 2048ul;
                    if ((occupy & 33818624ul) == 0) result |= 16ul;
                    return result;
                case 33:
                    result = 1099578736640ul;
                    if ((occupy & 67108864ul) == 0) result |= 524288ul;
                    if ((occupy & 67633152ul) == 0) result |= 4096ul;
                    if ((occupy & 67637248ul) == 0) result |= 32ul;
                    return result;
                case 34:
                    result = 2199157473280ul;
                    if ((occupy & 134217728ul) == 0) result |= 1048576ul;
                    if ((occupy & 135266304ul) == 0) result |= 8192ul;
                    if ((occupy & 135274496ul) == 0) result |= 64ul;
                    if ((occupy & 2199023255552ul) == 0) result |= 281474976710656ul;
                    return result;
                case 35:
                    result = 4398314946560ul;
                    if ((occupy & 268435456ul) == 0) result |= 2097152ul;
                    if ((occupy & 270532608ul) == 0) result |= 16384ul;
                    if ((occupy & 270548992ul) == 0) result |= 128ul;
                    if ((occupy & 4398046511104ul) == 0) result |= 562949953421312ul;
                    if ((occupy & 567347999932416ul) == 0) result |= 72057594037927936ul;
                    return result;
                case 36:
                    result = 8796629893120ul;
                    if ((occupy & 536870912ul) == 0) result |= 4194304ul;
                    if ((occupy & 541065216ul) == 0) result |= 32768ul;
                    if ((occupy & 8796093022208ul) == 0) result |= 1125899906842624ul;
                    if ((occupy & 1134695999864832ul) == 0) result |= 144115188075855872ul;
                    return result;
                case 37:
                    result = 17593259786240ul;
                    if ((occupy & 1073741824ul) == 0) result |= 8388608ul;
                    if ((occupy & 17592186044416ul) == 0) result |= 2251799813685248ul;
                    if ((occupy & 2269391999729664ul) == 0) result |= 288230376151711744ul;
                    return result;
                case 38:
                    result = 35186519572480ul;
                    if ((occupy & 35184372088832ul) == 0) result |= 4503599627370496ul;
                    if ((occupy & 4538783999459328ul) == 0) result |= 576460752303423488ul;
                    return result;
                case 39:
                    result = 70368744177664ul;
                    if ((occupy & 70368744177664ul) == 0) result |= 9007199254740992ul;
                    if ((occupy & 9077567998918656ul) == 0) result |= 1152921504606846976ul;
                    return result;
                case 40:
                    result = 8589934592ul;
                    if ((occupy & 8589934592ul) == 0) result |= 67108864ul;
                    if ((occupy & 8657043456ul) == 0) result |= 524288ul;
                    if ((occupy & 8657567744ul) == 0) result |= 4096ul;
                    if ((occupy & 8657571840ul) == 0) result |= 32ul;
                    return result;
                case 41:
                    result = 281492156579840ul;
                    if ((occupy & 17179869184ul) == 0) result |= 134217728ul;
                    if ((occupy & 17314086912ul) == 0) result |= 1048576ul;
                    if ((occupy & 17315135488ul) == 0) result |= 8192ul;
                    if ((occupy & 17315143680ul) == 0) result |= 64ul;
                    return result;
                case 42:
                    result = 562984313159680ul;
                    if ((occupy & 34359738368ul) == 0) result |= 268435456ul;
                    if ((occupy & 34628173824ul) == 0) result |= 2097152ul;
                    if ((occupy & 34630270976ul) == 0) result |= 16384ul;
                    if ((occupy & 34630287360ul) == 0) result |= 128ul;
                    if ((occupy & 562949953421312ul) == 0) result |= 72057594037927936ul;
                    return result;
                case 43:
                    result = 1125968626319360ul;
                    if ((occupy & 68719476736ul) == 0) result |= 536870912ul;
                    if ((occupy & 69256347648ul) == 0) result |= 4194304ul;
                    if ((occupy & 69260541952ul) == 0) result |= 32768ul;
                    if ((occupy & 1125899906842624ul) == 0) result |= 144115188075855872ul;
                    return result;
                case 44:
                    result = 2251937252638720ul;
                    if ((occupy & 137438953472ul) == 0) result |= 1073741824ul;
                    if ((occupy & 138512695296ul) == 0) result |= 8388608ul;
                    if ((occupy & 2251799813685248ul) == 0) result |= 288230376151711744ul;
                    return result;
                case 45:
                    result = 4503874505277440ul;
                    if ((occupy & 274877906944ul) == 0) result |= 2147483648ul;
                    if ((occupy & 4503599627370496ul) == 0) result |= 576460752303423488ul;
                    return result;
                case 46:
                    result = 9007749010554880ul;
                    if ((occupy & 9007199254740992ul) == 0) result |= 1152921504606846976ul;
                    return result;
                case 47:
                    result = 18014398509481984ul;
                    if ((occupy & 18014398509481984ul) == 0) result |= 2305843009213693952ul;
                    return result;
                case 48:
                    result = 2199023255552ul;
                    if ((occupy & 2199023255552ul) == 0) result |= 17179869184ul;
                    if ((occupy & 2216203124736ul) == 0) result |= 134217728ul;
                    if ((occupy & 2216337342464ul) == 0) result |= 1048576ul;
                    if ((occupy & 2216338391040ul) == 0) result |= 8192ul;
                    if ((occupy & 2216338399232ul) == 0) result |= 64ul;
                    return result;
                case 49:
                    result = 72061992084439040ul;
                    if ((occupy & 4398046511104ul) == 0) result |= 34359738368ul;
                    if ((occupy & 4432406249472ul) == 0) result |= 268435456ul;
                    if ((occupy & 4432674684928ul) == 0) result |= 2097152ul;
                    if ((occupy & 4432676782080ul) == 0) result |= 16384ul;
                    if ((occupy & 4432676798464ul) == 0) result |= 128ul;
                    return result;
                case 50:
                    result = 144123984168878080ul;
                    if ((occupy & 8796093022208ul) == 0) result |= 68719476736ul;
                    if ((occupy & 8864812498944ul) == 0) result |= 536870912ul;
                    if ((occupy & 8865349369856ul) == 0) result |= 4194304ul;
                    if ((occupy & 8865353564160ul) == 0) result |= 32768ul;
                    return result;
                case 51:
                    result = 288247968337756160ul;
                    if ((occupy & 17592186044416ul) == 0) result |= 137438953472ul;
                    if ((occupy & 17729624997888ul) == 0) result |= 1073741824ul;
                    if ((occupy & 17730698739712ul) == 0) result |= 8388608ul;
                    return result;
                case 52:
                    result = 576495936675512320ul;
                    if ((occupy & 35184372088832ul) == 0) result |= 274877906944ul;
                    if ((occupy & 35459249995776ul) == 0) result |= 2147483648ul;
                    return result;
                case 53:
                    result = 1152991873351024640ul;
                    if ((occupy & 70368744177664ul) == 0) result |= 549755813888ul;
                    return result;
                case 54:
                    result = 2305983746702049280ul;
                    return result;
                case 55:
                    result = 4611686018427387904ul;
                    return result;
                case 56:
                    result = 562949953421312ul;
                    if ((occupy & 562949953421312ul) == 0) result |= 4398046511104ul;
                    if ((occupy & 567347999932416ul) == 0) result |= 34359738368ul;
                    if ((occupy & 567382359670784ul) == 0) result |= 268435456ul;
                    if ((occupy & 567382628106240ul) == 0) result |= 2097152ul;
                    if ((occupy & 567382630203392ul) == 0) result |= 16384ul;
                    if ((occupy & 567382630219776ul) == 0) result |= 128ul;
                    return result;
                case 57:
                    result = 1125899906842624ul;
                    if ((occupy & 1125899906842624ul) == 0) result |= 8796093022208ul;
                    if ((occupy & 1134695999864832ul) == 0) result |= 68719476736ul;
                    if ((occupy & 1134764719341568ul) == 0) result |= 536870912ul;
                    if ((occupy & 1134765256212480ul) == 0) result |= 4194304ul;
                    if ((occupy & 1134765260406784ul) == 0) result |= 32768ul;
                    return result;
                case 58:
                    result = 2251799813685248ul;
                    if ((occupy & 2251799813685248ul) == 0) result |= 17592186044416ul;
                    if ((occupy & 2269391999729664ul) == 0) result |= 137438953472ul;
                    if ((occupy & 2269529438683136ul) == 0) result |= 1073741824ul;
                    if ((occupy & 2269530512424960ul) == 0) result |= 8388608ul;
                    return result;
                case 59:
                    result = 4503599627370496ul;
                    if ((occupy & 4503599627370496ul) == 0) result |= 35184372088832ul;
                    if ((occupy & 4538783999459328ul) == 0) result |= 274877906944ul;
                    if ((occupy & 4539058877366272ul) == 0) result |= 2147483648ul;
                    return result;
                case 60:
                    result = 9007199254740992ul;
                    if ((occupy & 9007199254740992ul) == 0) result |= 70368744177664ul;
                    if ((occupy & 9077567998918656ul) == 0) result |= 549755813888ul;
                    return result;
                case 61:
                    result = 18014398509481984ul;
                    if ((occupy & 18014398509481984ul) == 0) result |= 140737488355328ul;
                    return result;
                case 62:
                    result = 36028797018963968ul;
                    return result;
                case 63:
                    result = 0ul;
                    return result;
            }
            return 0;
        }
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static ulong GetSliderD1Cond(int SliderSquare, ulong occupy)
        {
            ulong result = 0;
            switch (SliderSquare)
            {
                case 0:
                    result = 512ul;
                    if ((occupy & 512ul) == 0) result |= 262144ul;
                    if ((occupy & 262656ul) == 0) result |= 134217728ul;
                    if ((occupy & 134480384ul) == 0) result |= 68719476736ul;
                    if ((occupy & 68853957120ul) == 0) result |= 35184372088832ul;
                    if ((occupy & 35253226045952ul) == 0) result |= 18014398509481984ul;
                    if ((occupy & 18049651735527936ul) == 0) result |= 9223372036854775808ul;
                    return result;
                case 1:
                    result = 1024ul;
                    if ((occupy & 1024ul) == 0) result |= 524288ul;
                    if ((occupy & 525312ul) == 0) result |= 268435456ul;
                    if ((occupy & 268960768ul) == 0) result |= 137438953472ul;
                    if ((occupy & 137707914240ul) == 0) result |= 70368744177664ul;
                    if ((occupy & 70506452091904ul) == 0) result |= 36028797018963968ul;
                    return result;
                case 2:
                    result = 2048ul;
                    if ((occupy & 2048ul) == 0) result |= 1048576ul;
                    if ((occupy & 1050624ul) == 0) result |= 536870912ul;
                    if ((occupy & 537921536ul) == 0) result |= 274877906944ul;
                    if ((occupy & 275415828480ul) == 0) result |= 140737488355328ul;
                    return result;
                case 3:
                    result = 4096ul;
                    if ((occupy & 4096ul) == 0) result |= 2097152ul;
                    if ((occupy & 2101248ul) == 0) result |= 1073741824ul;
                    if ((occupy & 1075843072ul) == 0) result |= 549755813888ul;
                    return result;
                case 4:
                    result = 8192ul;
                    if ((occupy & 8192ul) == 0) result |= 4194304ul;
                    if ((occupy & 4202496ul) == 0) result |= 2147483648ul;
                    return result;
                case 5:
                    result = 16384ul;
                    if ((occupy & 16384ul) == 0) result |= 8388608ul;
                    return result;
                case 6:
                    result = 32768ul;
                    return result;
                case 7:
                    result = 0ul;
                    return result;
                case 8:
                    result = 131072ul;
                    if ((occupy & 131072ul) == 0) result |= 67108864ul;
                    if ((occupy & 67239936ul) == 0) result |= 34359738368ul;
                    if ((occupy & 34426978304ul) == 0) result |= 17592186044416ul;
                    if ((occupy & 17626613022720ul) == 0) result |= 9007199254740992ul;
                    if ((occupy & 9024825867763712ul) == 0) result |= 4611686018427387904ul;
                    return result;
                case 9:
                    result = 262145ul;
                    if ((occupy & 262144ul) == 0) result |= 134217728ul;
                    if ((occupy & 134479872ul) == 0) result |= 68719476736ul;
                    if ((occupy & 68853956608ul) == 0) result |= 35184372088832ul;
                    if ((occupy & 35253226045440ul) == 0) result |= 18014398509481984ul;
                    if ((occupy & 18049651735527424ul) == 0) result |= 9223372036854775808ul;
                    return result;
                case 10:
                    result = 524290ul;
                    if ((occupy & 524288ul) == 0) result |= 268435456ul;
                    if ((occupy & 268959744ul) == 0) result |= 137438953472ul;
                    if ((occupy & 137707913216ul) == 0) result |= 70368744177664ul;
                    if ((occupy & 70506452090880ul) == 0) result |= 36028797018963968ul;
                    return result;
                case 11:
                    result = 1048580ul;
                    if ((occupy & 1048576ul) == 0) result |= 536870912ul;
                    if ((occupy & 537919488ul) == 0) result |= 274877906944ul;
                    if ((occupy & 275415826432ul) == 0) result |= 140737488355328ul;
                    return result;
                case 12:
                    result = 2097160ul;
                    if ((occupy & 2097152ul) == 0) result |= 1073741824ul;
                    if ((occupy & 1075838976ul) == 0) result |= 549755813888ul;
                    return result;
                case 13:
                    result = 4194320ul;
                    if ((occupy & 4194304ul) == 0) result |= 2147483648ul;
                    return result;
                case 14:
                    result = 8388640ul;
                    return result;
                case 15:
                    result = 64ul;
                    return result;
                case 16:
                    result = 33554432ul;
                    if ((occupy & 33554432ul) == 0) result |= 17179869184ul;
                    if ((occupy & 17213423616ul) == 0) result |= 8796093022208ul;
                    if ((occupy & 8813306445824ul) == 0) result |= 4503599627370496ul;
                    if ((occupy & 4512412933816320ul) == 0) result |= 2305843009213693952ul;
                    return result;
                case 17:
                    result = 67109120ul;
                    if ((occupy & 67108864ul) == 0) result |= 34359738368ul;
                    if ((occupy & 34426847232ul) == 0) result |= 17592186044416ul;
                    if ((occupy & 17626612891648ul) == 0) result |= 9007199254740992ul;
                    if ((occupy & 9024825867632640ul) == 0) result |= 4611686018427387904ul;
                    return result;
                case 18:
                    result = 134218240ul;
                    if ((occupy & 512ul) == 0) result |= 1ul;
                    if ((occupy & 134217728ul) == 0) result |= 68719476736ul;
                    if ((occupy & 68853694464ul) == 0) result |= 35184372088832ul;
                    if ((occupy & 35253225783296ul) == 0) result |= 18014398509481984ul;
                    if ((occupy & 18049651735265280ul) == 0) result |= 9223372036854775808ul;
                    return result;
                case 19:
                    result = 268436480ul;
                    if ((occupy & 1024ul) == 0) result |= 2ul;
                    if ((occupy & 268435456ul) == 0) result |= 137438953472ul;
                    if ((occupy & 137707388928ul) == 0) result |= 70368744177664ul;
                    if ((occupy & 70506451566592ul) == 0) result |= 36028797018963968ul;
                    return result;
                case 20:
                    result = 536872960ul;
                    if ((occupy & 2048ul) == 0) result |= 4ul;
                    if ((occupy & 536870912ul) == 0) result |= 274877906944ul;
                    if ((occupy & 275414777856ul) == 0) result |= 140737488355328ul;
                    return result;
                case 21:
                    result = 1073745920ul;
                    if ((occupy & 4096ul) == 0) result |= 8ul;
                    if ((occupy & 1073741824ul) == 0) result |= 549755813888ul;
                    return result;
                case 22:
                    result = 2147491840ul;
                    if ((occupy & 8192ul) == 0) result |= 16ul;
                    return result;
                case 23:
                    result = 16384ul;
                    if ((occupy & 16384ul) == 0) result |= 32ul;
                    return result;
                case 24:
                    result = 8589934592ul;
                    if ((occupy & 8589934592ul) == 0) result |= 4398046511104ul;
                    if ((occupy & 4406636445696ul) == 0) result |= 2251799813685248ul;
                    if ((occupy & 2256206450130944ul) == 0) result |= 1152921504606846976ul;
                    return result;
                case 25:
                    result = 17179934720ul;
                    if ((occupy & 17179869184ul) == 0) result |= 8796093022208ul;
                    if ((occupy & 8813272891392ul) == 0) result |= 4503599627370496ul;
                    if ((occupy & 4512412900261888ul) == 0) result |= 2305843009213693952ul;
                    return result;
                case 26:
                    result = 34359869440ul;
                    if ((occupy & 131072ul) == 0) result |= 256ul;
                    if ((occupy & 34359738368ul) == 0) result |= 17592186044416ul;
                    if ((occupy & 17626545782784ul) == 0) result |= 9007199254740992ul;
                    if ((occupy & 9024825800523776ul) == 0) result |= 4611686018427387904ul;
                    return result;
                case 27:
                    result = 68719738880ul;
                    if ((occupy & 262144ul) == 0) result |= 512ul;
                    if ((occupy & 262656ul) == 0) result |= 1ul;
                    if ((occupy & 68719476736ul) == 0) result |= 35184372088832ul;
                    if ((occupy & 35253091565568ul) == 0) result |= 18014398509481984ul;
                    if ((occupy & 18049651601047552ul) == 0) result |= 9223372036854775808ul;
                    return result;
                case 28:
                    result = 137439477760ul;
                    if ((occupy & 524288ul) == 0) result |= 1024ul;
                    if ((occupy & 525312ul) == 0) result |= 2ul;
                    if ((occupy & 137438953472ul) == 0) result |= 70368744177664ul;
                    if ((occupy & 70506183131136ul) == 0) result |= 36028797018963968ul;
                    return result;
                case 29:
                    result = 274878955520ul;
                    if ((occupy & 1048576ul) == 0) result |= 2048ul;
                    if ((occupy & 1050624ul) == 0) result |= 4ul;
                    if ((occupy & 274877906944ul) == 0) result |= 140737488355328ul;
                    return result;
                case 30:
                    result = 549757911040ul;
                    if ((occupy & 2097152ul) == 0) result |= 4096ul;
                    if ((occupy & 2101248ul) == 0) result |= 8ul;
                    return result;
                case 31:
                    result = 4194304ul;
                    if ((occupy & 4194304ul) == 0) result |= 8192ul;
                    if ((occupy & 4202496ul) == 0) result |= 16ul;
                    return result;
                case 32:
                    result = 2199023255552ul;
                    if ((occupy & 2199023255552ul) == 0) result |= 1125899906842624ul;
                    if ((occupy & 1128098930098176ul) == 0) result |= 576460752303423488ul;
                    return result;
                case 33:
                    result = 4398063288320ul;
                    if ((occupy & 4398046511104ul) == 0) result |= 2251799813685248ul;
                    if ((occupy & 2256197860196352ul) == 0) result |= 1152921504606846976ul;
                    return result;
                case 34:
                    result = 8796126576640ul;
                    if ((occupy & 33554432ul) == 0) result |= 65536ul;
                    if ((occupy & 8796093022208ul) == 0) result |= 4503599627370496ul;
                    if ((occupy & 4512395720392704ul) == 0) result |= 2305843009213693952ul;
                    return result;
                case 35:
                    result = 17592253153280ul;
                    if ((occupy & 67108864ul) == 0) result |= 131072ul;
                    if ((occupy & 67239936ul) == 0) result |= 256ul;
                    if ((occupy & 17592186044416ul) == 0) result |= 9007199254740992ul;
                    if ((occupy & 9024791440785408ul) == 0) result |= 4611686018427387904ul;
                    return result;
                case 36:
                    result = 35184506306560ul;
                    if ((occupy & 134217728ul) == 0) result |= 262144ul;
                    if ((occupy & 134479872ul) == 0) result |= 512ul;
                    if ((occupy & 134480384ul) == 0) result |= 1ul;
                    if ((occupy & 35184372088832ul) == 0) result |= 18014398509481984ul;
                    if ((occupy & 18049582881570816ul) == 0) result |= 9223372036854775808ul;
                    return result;
                case 37:
                    result = 70369012613120ul;
                    if ((occupy & 268435456ul) == 0) result |= 524288ul;
                    if ((occupy & 268959744ul) == 0) result |= 1024ul;
                    if ((occupy & 268960768ul) == 0) result |= 2ul;
                    if ((occupy & 70368744177664ul) == 0) result |= 36028797018963968ul;
                    return result;
                case 38:
                    result = 140738025226240ul;
                    if ((occupy & 536870912ul) == 0) result |= 1048576ul;
                    if ((occupy & 537919488ul) == 0) result |= 2048ul;
                    if ((occupy & 537921536ul) == 0) result |= 4ul;
                    return result;
                case 39:
                    result = 1073741824ul;
                    if ((occupy & 1073741824ul) == 0) result |= 2097152ul;
                    if ((occupy & 1075838976ul) == 0) result |= 4096ul;
                    if ((occupy & 1075843072ul) == 0) result |= 8ul;
                    return result;
                case 40:
                    result = 562949953421312ul;
                    if ((occupy & 562949953421312ul) == 0) result |= 288230376151711744ul;
                    return result;
                case 41:
                    result = 1125904201809920ul;
                    if ((occupy & 1125899906842624ul) == 0) result |= 576460752303423488ul;
                    return result;
                case 42:
                    result = 2251808403619840ul;
                    if ((occupy & 8589934592ul) == 0) result |= 16777216ul;
                    if ((occupy & 2251799813685248ul) == 0) result |= 1152921504606846976ul;
                    return result;
                case 43:
                    result = 4503616807239680ul;
                    if ((occupy & 17179869184ul) == 0) result |= 33554432ul;
                    if ((occupy & 17213423616ul) == 0) result |= 65536ul;
                    if ((occupy & 4503599627370496ul) == 0) result |= 2305843009213693952ul;
                    return result;
                case 44:
                    result = 9007233614479360ul;
                    if ((occupy & 34359738368ul) == 0) result |= 67108864ul;
                    if ((occupy & 34426847232ul) == 0) result |= 131072ul;
                    if ((occupy & 34426978304ul) == 0) result |= 256ul;
                    if ((occupy & 9007199254740992ul) == 0) result |= 4611686018427387904ul;
                    return result;
                case 45:
                    result = 18014467228958720ul;
                    if ((occupy & 68719476736ul) == 0) result |= 134217728ul;
                    if ((occupy & 68853694464ul) == 0) result |= 262144ul;
                    if ((occupy & 68853956608ul) == 0) result |= 512ul;
                    if ((occupy & 68853957120ul) == 0) result |= 1ul;
                    if ((occupy & 18014398509481984ul) == 0) result |= 9223372036854775808ul;
                    return result;
                case 46:
                    result = 36028934457917440ul;
                    if ((occupy & 137438953472ul) == 0) result |= 268435456ul;
                    if ((occupy & 137707388928ul) == 0) result |= 524288ul;
                    if ((occupy & 137707913216ul) == 0) result |= 1024ul;
                    if ((occupy & 137707914240ul) == 0) result |= 2ul;
                    return result;
                case 47:
                    result = 274877906944ul;
                    if ((occupy & 274877906944ul) == 0) result |= 536870912ul;
                    if ((occupy & 275414777856ul) == 0) result |= 1048576ul;
                    if ((occupy & 275415826432ul) == 0) result |= 2048ul;
                    if ((occupy & 275415828480ul) == 0) result |= 4ul;
                    return result;
                case 48:
                    result = 144115188075855872ul;
                    return result;
                case 49:
                    result = 288231475663339520ul;
                    return result;
                case 50:
                    result = 576462951326679040ul;
                    if ((occupy & 2199023255552ul) == 0) result |= 4294967296ul;
                    return result;
                case 51:
                    result = 1152925902653358080ul;
                    if ((occupy & 4398046511104ul) == 0) result |= 8589934592ul;
                    if ((occupy & 4406636445696ul) == 0) result |= 16777216ul;
                    return result;
                case 52:
                    result = 2305851805306716160ul;
                    if ((occupy & 8796093022208ul) == 0) result |= 17179869184ul;
                    if ((occupy & 8813272891392ul) == 0) result |= 33554432ul;
                    if ((occupy & 8813306445824ul) == 0) result |= 65536ul;
                    return result;
                case 53:
                    result = 4611703610613432320ul;
                    if ((occupy & 17592186044416ul) == 0) result |= 34359738368ul;
                    if ((occupy & 17626545782784ul) == 0) result |= 67108864ul;
                    if ((occupy & 17626612891648ul) == 0) result |= 131072ul;
                    if ((occupy & 17626613022720ul) == 0) result |= 256ul;
                    return result;
                case 54:
                    result = 9223407221226864640ul;
                    if ((occupy & 35184372088832ul) == 0) result |= 68719476736ul;
                    if ((occupy & 35253091565568ul) == 0) result |= 134217728ul;
                    if ((occupy & 35253225783296ul) == 0) result |= 262144ul;
                    if ((occupy & 35253226045440ul) == 0) result |= 512ul;
                    if ((occupy & 35253226045952ul) == 0) result |= 1ul;
                    return result;
                case 55:
                    result = 70368744177664ul;
                    if ((occupy & 70368744177664ul) == 0) result |= 137438953472ul;
                    if ((occupy & 70506183131136ul) == 0) result |= 268435456ul;
                    if ((occupy & 70506451566592ul) == 0) result |= 524288ul;
                    if ((occupy & 70506452090880ul) == 0) result |= 1024ul;
                    if ((occupy & 70506452091904ul) == 0) result |= 2ul;
                    return result;
                case 56:
                    result = 0ul;
                    return result;
                case 57:
                    result = 281474976710656ul;
                    return result;
                case 58:
                    result = 562949953421312ul;
                    if ((occupy & 562949953421312ul) == 0) result |= 1099511627776ul;
                    return result;
                case 59:
                    result = 1125899906842624ul;
                    if ((occupy & 1125899906842624ul) == 0) result |= 2199023255552ul;
                    if ((occupy & 1128098930098176ul) == 0) result |= 4294967296ul;
                    return result;
                case 60:
                    result = 2251799813685248ul;
                    if ((occupy & 2251799813685248ul) == 0) result |= 4398046511104ul;
                    if ((occupy & 2256197860196352ul) == 0) result |= 8589934592ul;
                    if ((occupy & 2256206450130944ul) == 0) result |= 16777216ul;
                    return result;
                case 61:
                    result = 4503599627370496ul;
                    if ((occupy & 4503599627370496ul) == 0) result |= 8796093022208ul;
                    if ((occupy & 4512395720392704ul) == 0) result |= 17179869184ul;
                    if ((occupy & 4512412900261888ul) == 0) result |= 33554432ul;
                    if ((occupy & 4512412933816320ul) == 0) result |= 65536ul;
                    return result;
                case 62:
                    result = 9007199254740992ul;
                    if ((occupy & 9007199254740992ul) == 0) result |= 17592186044416ul;
                    if ((occupy & 9024791440785408ul) == 0) result |= 34359738368ul;
                    if ((occupy & 9024825800523776ul) == 0) result |= 67108864ul;
                    if ((occupy & 9024825867632640ul) == 0) result |= 131072ul;
                    if ((occupy & 9024825867763712ul) == 0) result |= 256ul;
                    return result;
                case 63:
                    result = 18014398509481984ul;
                    if ((occupy & 18014398509481984ul) == 0) result |= 35184372088832ul;
                    if ((occupy & 18049582881570816ul) == 0) result |= 68719476736ul;
                    if ((occupy & 18049651601047552ul) == 0) result |= 134217728ul;
                    if ((occupy & 18049651735265280ul) == 0) result |= 262144ul;
                    if ((occupy & 18049651735527424ul) == 0) result |= 512ul;
                    if ((occupy & 18049651735527936ul) == 0) result |= 1ul;
                    return result;
            }
            return 0;
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static ulong Rook(int square, ulong occupy)
        {
            return GetSliderHCond(square, occupy) | GetSliderVCond(square, occupy);
        }
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static ulong Bishop(int square, ulong occupy)
        {
            return GetSliderD1Cond(square, occupy) | GetSliderD2Cond(square, occupy);
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static ulong Queen(int square, ulong occupy)
        {
            return Rook(square, occupy) | Bishop(square, occupy);
        }
    }

}
