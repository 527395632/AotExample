using System.Runtime.InteropServices;

namespace DynamicLibrary2
{
    public class Entry
    {
        [UnmanagedCallersOnly(EntryPoint = "Init2")]
        public static void Init2()
        {
            Console.WriteLine("=======================");
        }
    }
}
