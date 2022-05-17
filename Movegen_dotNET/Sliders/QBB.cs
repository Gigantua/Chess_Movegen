using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace Movegen_dotNET.Sliders
{
    public static class QBB
    {
        static int MSB(ulong value)
        {
            return 63 - BitOperations.LeadingZeroCount(value);
        }

        static int LSB(ulong value)
        {
            return 63 - BitOperations.TrailingZeroCount(value);
        }

        public static ulong Rook(int sq, ulong occupation)
        {
            ulong piece = 1ul << sq;
            occupation ^= piece; /* remove the selected piece from the occupation */
            ulong piecesup = (0x0101010101010101ul << sq) & (occupation | 0xFF00000000000000ul);        /* find the pieces up */
            ulong piecesdo = (0x8080808080808080ul >> (63 - sq)) & (occupation | 0x00000000000000FFul); /* find the pieces down */
            ulong piecesri = (0x00000000000000FFul << sq) & (occupation | 0x8080808080808080ul);        /* find pieces on the right */
            ulong piecesle = (0xFF00000000000000ul >> (63 - sq)) & (occupation | 0x0101010101010101ul); /* find pieces on the left */
            return (((0x8080808080808080ul >> LSB(piecesup)) & (0x0101010101010101ul << MSB(piecesdo))) |
                   ((0xFF00000000000000ul >> LSB(piecesri)) & (0x00000000000000FFul << MSB(piecesle)))) ^ piece;
        }

        public static ulong Bishop(int sq, ulong occupation)
        {  
            ulong piece = 1ul << sq;
            occupation ^= piece;
            ulong piecesup = (0x8040201008040201ul << sq) & (occupation | 0xFF80808080808080ul);
            ulong piecesdo = (0x8040201008040201ul >> (63 - sq)) & (occupation | 0x01010101010101FFul);
            ulong piecesle = (0x8102040810204081ul << sq) & (occupation | 0xFF01010101010101ul);
            ulong piecesri = (0x8102040810204081ul >> (63 - sq)) & (occupation | 0x80808080808080FFul);
            return (((0x8040201008040201ul >> LSB(piecesup)) & (0x8040201008040201ul << MSB(piecesdo))) |
                   ((0x8102040810204081ul >> LSB(piecesle)) & (0x8102040810204081ul << MSB(piecesri)))) ^ piece;
        }

        public static ulong Queen(int sq, ulong occupation)
        {
            return Rook(sq, occupation) | Bishop(sq, occupation);
        }

    }
}
