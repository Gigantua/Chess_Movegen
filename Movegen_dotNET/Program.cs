// ==++==
// 
//   Daniel Infuehr (c) All rights reserved.
// 
// ==--==
/*============================================================
**
** Class:  Program.cs
** 
** Purpose: Comparison of Sliding Piece Algorithms in dotNet vs c++
**
**
===========================================================*/


//Proof of concept phase

using System.Diagnostics;
using Movegen_dotNET.Sliders;

Console.WriteLine(Runtime.Environment.GetProcessorName());
const int poscnt = 1000000;

void MeasureAlgo()
{
	//Prepare random 
	Random random = new Random(362436069);
	List<ulong> occs = new List<ulong>();
	List<int> squares = new List<int>();
	for (int i = 0; i < poscnt; i++)
	{
		occs.Add((ulong)random.NextInt64());

		for (int r = 0; r < 12; r++)
		{
			squares.Add(random.Next() % 64);
		}
	}
	Stopwatch stopwatch = Stopwatch.StartNew();	
	ulong dontopt = 0;
	for (int i = 0; i < poscnt; i++)
	{
		ulong occ = occs[i];
		for (int r = 0; r < 12; r++)
		{
			dontopt ^= Movegen_dotNET.Sliders.Switch.Queen(squares[12 * i + r], occ);
		}
	}
	double result = poscnt * 12000.0 / (stopwatch.Elapsed.TotalSeconds * 1000000000.0);
	Console.WriteLine($"{"Switch",-20} {result.ToString("0.00"),-10}");
	//auto perf = std::to_string(result);
	//auto table = std::to_string(T::Size() / 8);
	//table.append(7 - table.size(), ' ');
	//table += " [" + std::to_string(T::Size() / 1024) + "kb]";

	//printf("%-35s%-30s%-20s%-25s%-10s%-45s%-50s\n", T::name.data(), perf.c_str(), table.c_str(), T::sp_op.data(), is_tmpl, T::author.data(), T::reference.data());
}

void MeasureAlgo_DLLImport()
{
	//Prepare random 
	Random random = new Random(362436069);
	List<ulong> occs = new List<ulong>();
	List<int> squares = new List<int>();
	for (int i = 0; i < poscnt; i++)
	{
		occs.Add((ulong)random.NextInt64());

		for (int r = 0; r < 12; r++)
		{
			squares.Add(random.Next() % 64);
		}
	}
	Stopwatch stopwatch = Stopwatch.StartNew();
	ulong dontopt = 0;
	for (int i = 0; i < poscnt; i++)
	{
		ulong occ = occs[i];
		for (int r = 0; r < 12; r++)
		{
			dontopt ^= Movegen_dotNET.Sliders.Switch.Switch_t_Queen(squares[12 * i + r], occ);
		}
	}
	double result = poscnt * 12000.0 / (stopwatch.Elapsed.TotalSeconds * 1000000000.0);
	Console.WriteLine($"{"Switch (DllImport)", -20} {result.ToString("0.00"), -10}");
	//auto perf = std::to_string(result);
	//auto table = std::to_string(T::Size() / 8);
	//table.append(7 - table.size(), ' ');
	//table += " [" + std::to_string(T::Size() / 1024) + "kb]";

	//printf("%-35s%-30s%-20s%-25s%-10s%-45s%-50s\n", T::name.data(), perf.c_str(), table.c_str(), T::sp_op.data(), is_tmpl, T::author.data(), T::reference.data());
}


Console.WriteLine("Name\tPerformance [MQueens/s]");
MeasureAlgo();
MeasureAlgo_DLLImport();