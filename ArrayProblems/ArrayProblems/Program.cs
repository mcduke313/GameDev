using System;
using System.Collections.Generic;

namespace ArrayProblems
{
    class Program
    {
        static void Main(string[] args)
        {
            problemOne();
            problemTwo();
        }
        static void problemOne()
        {
            List<string> names = new List<string>();
            Console.WriteLine("Enter as many names as you like or press enter without entering a name to abort.\n");
            string str;
            bool contLoop = true;

            do
            {
                str = Console.ReadLine();
                if(str != "" && str != " ")
                {
                    names.Add(str);
                }
                else
                {
                    contLoop = false;
                }
            } while (contLoop == true);

            if(names.Count == 1)
            {
                Console.WriteLine(names[0] + " liked Your post.");
            }
            else if (names.Count == 2)
            {
                Console.WriteLine(names[0] + " and " + names[1] + " liked Your post.");
            }
            else if (names.Count > 2)
            {
                int i = names.Count - 2;
                Console.WriteLine(names[0] + ", " + names[1] + " and " + i + " other liked Your post.");
            }
        }
        static void problemTwo()
        {
            Dictionary<char, int> charCount = new Dictionary<char, int>();
            string str;
            Console.WriteLine("Enter a sentence.\n");
            str = Console.ReadLine();
            for (int i = 0; i < str.Length; i++)
            {
                bool b = false;
                if(charCount.ContainsKey(str[i]))
                {
                    b = true;
                    charCount[str[i]]++;
                }
                if (b == false)
                {
                    charCount.Add(str[i], 1);
                }
            }
            foreach(KeyValuePair<char, int> kvp in charCount)
            {
                if(kvp.Key != ' ')
                    Console.WriteLine(kvp.Key + ": " + kvp.Value);
            }
        }
    }
}
