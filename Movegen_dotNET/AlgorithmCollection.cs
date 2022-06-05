using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reflection;
using System.Runtime.Intrinsics.X86;
using System.Text;
using System.Threading.Tasks;

namespace Movegen
{
    public class Algorithm
    {
        public bool Imported { get; set; }
        public string Name { get; set; }
        public string Description { get; set; }
        public Func<int, ulong, ulong> Queen { get; set; }
    }


    public class AlgorithmCollection
    {
        const int perf_poscount = 5000000;
        List<Algorithm> algorithms = new List<Algorithm>();

        //Algos that need special setup or are incremental
        static HashSet<string> forbiddenImports = new HashSet<string>()
        {
            "QBB","GeneticQBB", "Sissy", "Hyper", "Rotate"
        };

        public AlgorithmCollection()
        {
            //Convert PINVOKE and Native code to delegates
            var importedClasses = typeof(Interop).GetMethods(BindingFlags.Public | BindingFlags.Static).ToArray();
            var importedAlgos = importedClasses.Select(m => m.Name.Substring(0, m.Name.Length - 8)).ToArray();
            var importedFunctions = importedClasses.Select(x => (Func<int, ulong, ulong>)Delegate.CreateDelegate(typeof(Func<int, ulong, ulong>), x)).ToArray();

            var compiledClasses = AppDomain.CurrentDomain.GetAssemblies().SelectMany(t => t.GetTypes())
                                   .Where(t => t.IsClass && t.Namespace == "Movegen.Implementation").ToArray();
            var compiledAlgos = compiledClasses.Select(x => x.Name).ToArray();
            var compiledFunctions = compiledClasses.Select(x => x.GetMethod("Queen")).Select(x => (Func<int, ulong, ulong>)Delegate.CreateDelegate(typeof(Func<int, ulong, ulong>), x)).ToArray();

            for (int i = 0; i < compiledClasses.Length; i++)
            {
                algorithms.Add(new Algorithm()
                {
                    Name = compiledAlgos[i],
                    Description = "na",
                    Queen = compiledFunctions[i],
                    Imported = false
                });
            }

            //Enable this for imported code
            //for (int i = 0; i < importedClasses.Length; i++)
            //{
            //    if (forbiddenImports.Contains(importedAlgos[i])) continue;
            //    algorithms.Add(new Algorithm()
            //    {
            //        Name = "Imported: " + importedAlgos[i],
            //        Description = "na",
            //        Queen = importedFunctions[i],
            //        Imported = true
            //    });
            //}

        }

        void TestSqOcc(int sq, ulong occ)
        {
            ulong reference = Movegen.Implementation.Switch.Queen(sq, occ);
            foreach (var algo in algorithms)
            {
                ulong result = algo.Queen(sq, occ);
                if (result != reference) throw new InvalidOperationException(algo.Name);
            }
        }

        internal void Verify()
        {
            Console.Write("Verify Engines...");
            Random r = new Random();
            for (int i = 0; i < 64; i++) TestSqOcc(i, 0);
            for (int i = 0; i < 64; i++) TestSqOcc(i, 510);
            for (int i = 0; i < 64; i++) TestSqOcc(i, ulong.MaxValue);
            for (int i = 0; i < 10000; i++)
            {
                int sq = r.Next() & 63;
                ulong occ = (ulong)r.NextInt64();
                TestSqOcc(sq, occ);
            }
            Console.WriteLine("OK");
        }

        void Native_Code(ulong[] occs, int[] squares)
        {
            Console.WriteLine("\nCSharp Native Code");
            {
                Stopwatch stopwatch = Stopwatch.StartNew();
                ulong bulk = 0;
                for (int i = 0; i < perf_poscount; i++)
                {
                    ulong occ = occs[i]; int offset = 12 * i;
                    for (int r = 0; r < 12; r++)
                    {
                        bulk ^= Movegen.Implementation.Switch.Queen(squares[offset + r], occ);
                    }
                }
                double result = perf_poscount * 12000.0 / (stopwatch.Elapsed.TotalSeconds * 1000000000.0);
                Console.WriteLine($"{"Switch",-40} {result.ToString("0.00"),-10}");
            }
            {
                Stopwatch stopwatch = Stopwatch.StartNew();
                ulong bulk = 0;
                for (int i = 0; i < perf_poscount; i++)
                {
                    ulong occ = occs[i]; int offset = 12 * i;
                    for (int r = 0; r < 12; r++)
                    {
                        bulk ^= Movegen.Implementation.ObstructionDiff.Queen(squares[offset + r], occ);
                    }
                }
                double result = perf_poscount * 12000.0 / (stopwatch.Elapsed.TotalSeconds * 1000000000.0);
                Console.WriteLine($"{"ObstructionDiff",-40} {result.ToString("0.00"),-10}");
            }
            {
                Stopwatch stopwatch = Stopwatch.StartNew();
                ulong bulk = 0;
                for (int i = 0; i < perf_poscount; i++)
                {
                    ulong occ = occs[i]; int offset = 12 * i;
                    for (int r = 0; r < 12; r++)
                    {
                        bulk ^= Movegen.Implementation.Leorik.Queen(squares[offset + r], occ);
                    }
                }
                double result = perf_poscount * 12000.0 / (stopwatch.Elapsed.TotalSeconds * 1000000000.0);
                Console.WriteLine($"{"Leorik",-40} {result.ToString("0.00"),-10}");
            }
            {
                Stopwatch stopwatch = Stopwatch.StartNew();
                ulong bulk = 0;
                for (int i = 0; i < perf_poscount; i++)
                {
                    ulong occ = occs[i]; int offset = 12 * i;
                    for (int r = 0; r < 12; r++)
                    {
                        bulk ^= Movegen.Implementation.HyperbolaQsc.Queen(squares[offset + r], occ);
                    }
                }
                double result = perf_poscount * 12000.0 / (stopwatch.Elapsed.TotalSeconds * 1000000000.0);
                Console.WriteLine($"{"HyperbolaQsc",-40} {result.ToString("0.00"),-10}");
            }
            {
                Stopwatch stopwatch = Stopwatch.StartNew();
                ulong bulk = 0;
                for (int i = 0; i < perf_poscount; i++)
                {
                    ulong occ = occs[i]; int offset = 12 * i;
                    for (int r = 0; r < 12; r++)
                    {
                        bulk ^= Movegen.Implementation.FancyMagic.Queen(squares[offset + r], occ);
                    }
                }
                double result = perf_poscount * 12000.0 / (stopwatch.Elapsed.TotalSeconds * 1000000000.0);
                Console.WriteLine($"{"FancyMagic",-40} {result.ToString("0.00"),-10}");
            }
            {
                Stopwatch stopwatch = Stopwatch.StartNew();
                ulong bulk = 0;
                for (int i = 0; i < perf_poscount; i++)
                {
                    ulong occ = occs[i]; int offset = 12 * i;
                    for (int r = 0; r < 12; r++)
                    {
                        bulk ^= Movegen.Implementation.Pext.Queen(squares[offset + r], occ);
                    }
                }
                double result = perf_poscount * 12000.0 / (stopwatch.Elapsed.TotalSeconds * 1000000000.0);
                Console.WriteLine($"{"Pext Inlined",-40} {result.ToString("0.00"),-10}");
            }

        }

        void Implement_Code(ulong[] occs, int[] squares)
        {
            Console.WriteLine("\nImplementation Comparison");
            {
                Stopwatch stopwatch = Stopwatch.StartNew();
                ulong bulk = 0;
                for (int i = 0; i < perf_poscount; i++)
                {
                    ulong occ = occs[i]; int offset = 12 * i;
                    for (int r = 0; r < 12; r++)
                    {
                        bulk ^= Movegen.Implementation.Pext.Queen_NoInline(squares[offset + r], occ);
                    }
                }
                double result = perf_poscount * 12000.0 / (stopwatch.Elapsed.TotalSeconds * 1000000000.0);
                Console.WriteLine($"{"Pext NoInline",-40} {result.ToString("0.00"),-10}");
            }

            {
                var Queen = algorithms.First(x => x.Name == "Pext").Queen;
                Stopwatch stopwatch = Stopwatch.StartNew();
                ulong bulk = 0;
                for (int i = 0; i < perf_poscount; i++)
                {
                    ulong occ = occs[i]; int offset = 12 * i;
                    for (int r = 0; r < 12; r++)
                    {
                        bulk ^= Queen(squares[offset + r], occ);
                    }
                }
                double result = perf_poscount * 12000.0 / (stopwatch.Elapsed.TotalSeconds * 1000000000.0);
                Console.WriteLine($"{"Pext Delegate",-40} {result.ToString("0.00"),-10}");
            }

            {
                Stopwatch stopwatch = Stopwatch.StartNew();
                ulong bulk = 0;
                for (int i = 0; i < perf_poscount; i++)
                {
                    ulong occ = occs[i]; int offset = 12 * i;
                    for (int r = 0; r < 12; r++)
                    {
                        bulk ^= Movegen.Implementation.Pext.Queen(squares[offset + r], occ);
                    }
                }
                double result = perf_poscount * 12000.0 / (stopwatch.Elapsed.TotalSeconds * 1000000000.0);
                Console.WriteLine($"{"Pext Inlined",-40} {result.ToString("0.00"),-10}");
            }

            {
                var Attacks = Movegen.Implementation.Pext.Attacks;
                var Entries = Movegen.Implementation.Pext.Entries;
                Stopwatch stopwatch = Stopwatch.StartNew();
                ulong bulk = 0;
                for (int i = 0; i < perf_poscount; i++)
                {
                    ulong occ = occs[i]; int offset = 12 * i;
                    for (int r = 0; r < 12; r++)
                    {
                        int sq = squares[offset + r];
                        bulk ^= (Attacks[Entries[sq].offset_rook + Bmi2.X64.ParallelBitExtract(occ, Entries[sq].mask_rook)] |
                            Attacks[Entries[sq].offset_bish + Bmi2.X64.ParallelBitExtract(occ, Entries[sq].mask_bish)]);
                    }
                }
                double result = perf_poscount * 12000.0 / (stopwatch.Elapsed.TotalSeconds * 1000000000.0);
                Console.WriteLine($"{"Pext Manual Inlining",-40} {result.ToString("0.00"),-10}");
            }

            {
                Movegen_cs.Runtime.Pext_DynamicCompilation compiler = new Movegen_cs.Runtime.Pext_DynamicCompilation();
                var Queen = compiler.Compile();
                Queen(0, 0); //Static constructor is called, asm fully loaded etc. 

                Stopwatch stopwatch = Stopwatch.StartNew();
                ulong bulk = 0;
                for (int i = 0; i < perf_poscount; i++)
                {
                    ulong occ = occs[i]; int offset = 12 * i;
                    for (int r = 0; r < 12; r++)
                    {
                        bulk ^= Queen(squares[offset + r], occ);
                    }
                }
                double result = perf_poscount * 12000.0 / (stopwatch.Elapsed.TotalSeconds * 1000000000.0);
                Console.WriteLine($"{"Pext Dynamic Compilation",-40} {result.ToString("0.00"),-10}");

                compiler.Unload();
            }

            //{
            //    Stopwatch stopwatch = Stopwatch.StartNew();
            //    ulong bulk = 0;
            //    for (int i = 0; i < perf_poscount; i++)
            //    {
            //        ulong occ = occs[i]; int offset = 12 * i;
            //        for (int r = 0; r < 12; r++)
            //        {
            //            bulk ^= Interop.Pext_t_Queen(squares[offset + r], occ);
            //        }
            //    }
            //    double result = perf_poscount * 12000.0 / (stopwatch.Elapsed.TotalSeconds * 1000000000.0);
            //    Console.WriteLine($"{"Pext Pinvoke C++",-40} {result.ToString("0.00"),-10}");
            //}
        }

        void Imported_Code(ulong[] occs, int[] squares)
        {
            Console.WriteLine("\nImported Algorithmic Comparison");
            foreach (var algo in algorithms.Where(x => x.Imported == true))
            {
                var Queen = algo.Queen;
                Stopwatch stopwatch = Stopwatch.StartNew();
                ulong bulk = 0;
                for (int i = 0; i < perf_poscount; i++)
                {
                    ulong occ = occs[i]; int offset = 12 * i;
                    for (int r = 0; r < 12; r++)
                    {
                        bulk ^= Queen(squares[offset + r], occ);
                    }
                }
                double result = perf_poscount * 12000.0 / (stopwatch.Elapsed.TotalSeconds * 1000000000.0);
                Console.WriteLine($"{algo.Name,-40} {result.ToString("0.00"),-10}");
            }
        }

        public void Run()
        {
            //Prepare random 
            Random random = new Random(362436069);
            List<ulong> occs = new List<ulong>();
            List<int> squares = new List<int>();
            for (int i = 0; i < perf_poscount; i++)
            {
                occs.Add((ulong)random.NextInt64());

                for (int r = 0; r < 12; r++)
                {
                    squares.Add(random.Next() % 64);
                }
            }
            ulong[] O = occs.ToArray();
            int[] sq = squares.ToArray();

            for(int i=0;i<5;i++)
            {
                Native_Code(O, sq);

                //Implement_Code(O, sq);

                // To run this make sure to have movegen_compare.exe besides movegen_cs.exe
                // Imported_Code(O, sq);
            }
        }

        internal void PrintHeader()
        {
            Console.WriteLine($"{"Algorithm",-40} {"Million Queen/s",-10}");
        }
    }
}
