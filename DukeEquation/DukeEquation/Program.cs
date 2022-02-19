using System;

namespace DukeEquation
{
    class Program
    {
        static void Main(string[] args)
        {
            int myVar;
            Console.WriteLine("Enter variable:_ ");
            string strVar = Console.ReadLine();
            myVar = int.Parse(strVar);

            Console.WriteLine(-1 + 4 * myVar);
            Console.WriteLine((35 + 5) % myVar);
            Console.WriteLine(14 + -4 * 6 / 12);
            Console.WriteLine(2 + 12 / 6 * 1 - myVar % 2);

            if (myVar > 4)
            {
                Console.WriteLine("myVar is greater than four.");
            }
            else
            {
                Console.WriteLine("myVar is less than four.");
            }
        }
    }
}
