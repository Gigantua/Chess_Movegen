using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Runtime
{
    public class Environment
    {
        public static string GetProcessorName()
        {
            var key = Registry.LocalMachine.OpenSubKey(@"HARDWARE\DESCRIPTION\System\CentralProcessor\0\");
            return key?.GetValue("ProcessorNameString").ToString() ?? "Not Found";
        }

    }
}
