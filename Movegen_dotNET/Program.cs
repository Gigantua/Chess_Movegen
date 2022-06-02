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


using System.Diagnostics;
using System.Reflection;
using Movegen;


AlgorithmCollection collection = new AlgorithmCollection();
Console.WriteLine(Runtime.Environment.GetProcessorName());

collection.Verify();
collection.PrintHeader();
collection.Run();
