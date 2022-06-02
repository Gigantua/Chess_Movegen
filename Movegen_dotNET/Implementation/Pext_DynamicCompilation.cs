using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.CSharp;
using System.CodeDom.Compiler;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.Emit;
using System.Reflection;

namespace Movegen_cs.Runtime
{
    public class Pext_DynamicCompilation
    {
        Assembly compiledASM;
        public Func<int, ulong, ulong> Compile()
        {
            SyntaxTree syntaxTree = CSharpSyntaxTree.ParseText(Pext_DynamicCompilation_Source.SourceCode);

            // define other necessary objects for compilation
            string assemblyName = Path.GetRandomFileName();
            MetadataReference[] references = new MetadataReference[]
            {
                MetadataReference.CreateFromFile(typeof(object).Assembly.Location),
                MetadataReference.CreateFromFile(typeof(Enumerable).Assembly.Location)
            };

            // analyse and generate IL code from syntax tree
            CSharpCompilation compilation = CSharpCompilation.Create(
                assemblyName,
                syntaxTrees: new[] { syntaxTree },
                references: references,
                options: new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary));

            using (var ms = new MemoryStream())
            {
                // write IL code into memory
                EmitResult result = compilation.Emit(ms);

                if (!result.Success)
                {
                    // handle exceptions
                    IEnumerable<Diagnostic> failures = result.Diagnostics.Where(diagnostic =>
                        diagnostic.IsWarningAsError ||
                        diagnostic.Severity == DiagnosticSeverity.Error);

                    foreach (Diagnostic diagnostic in failures)
                    {
                        Console.Error.WriteLine("{0}: {1}", diagnostic.Id, diagnostic.GetMessage());
                    }
                    return null;
                }
                else
                {
                    // load this 'virtual' DLL so that we can use
                    ms.Seek(0, SeekOrigin.Begin);
                    compiledASM = Assembly.Load(ms.ToArray());
                    // create instance of the desired class and call the desired function
                    Type type = compiledASM.GetType("Movegen.Implementation.Pext");
                    return (Func<int, ulong, ulong>)Delegate.CreateDelegate(typeof(Func<int, ulong, ulong>), type.GetMethod("Queen_Compiled"));
                }
            }
        }

        public void Unload()
        {
            //Todo: Unload Assembly
        }
    }
}
