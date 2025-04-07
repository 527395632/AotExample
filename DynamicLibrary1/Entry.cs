using System.Runtime.InteropServices;

namespace DynamicLibrary1
{
    public class Entry
    {
        [UnmanagedCallersOnly(EntryPoint = "Init1")]
        public static void Init1()
        {
            Console.WriteLine("-----------------------");
        }
    }
}