using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Movegen
{
    public class Interop
    {
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong Switch_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong GeneticObstructionDiff_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong GeneticObstructionDiffV2_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong FoldingHash_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong Genetic8Ray_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong Loop_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong Dumb7_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong Kogge_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong Bob_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong BobAdvanced_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong Leorik_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong LeorikNT_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong Hyper_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong Pext_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong PextEmu_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong Plain_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong HVar_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong Fancy_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong Explode_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong SBAMG_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong SBAMGNT_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong BinaryNetwork_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong Hyperbola_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong HyperbolaNT_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong Rotate_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong Arithm_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong ArithmNT_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong Kindergarten_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong Obstruct_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong ObstructNT_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong QBB_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong GeneticQBB_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong Sissy_t_Queen(int sq, ulong occupy);
        [DllImport("Runtime\\Movegen_Compare.exe")]
        public static extern ulong Bitrotate_t_Queen(int sq, ulong occupy);
    }
}
