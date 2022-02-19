using System;

namespace Duke3of5
{
    class Program
    {
        static void Main(string[] args)
        {
            problemOne();
            problemTwo();
            problemThree();
        }
        static void problemOne()
        {
            //Count all numbers between 0 & 100 divisible by 3 print count
            int count = 0;
            for (int i = 0;i<=100 ;i++ )
            {
                if (i % 3 == 0)
                    count++;
            }
            Console.WriteLine("The number of numbers divisible by 3 is " + count);
        }
        static void problemTwo()
        {
            //Ask for number or "Ok" print sum of all numbers input
            string input = "";
            int sum = 0;
            while (input != "Ok")
            {
                Console.WriteLine("Enter a number or Ok to exit: ");
                input = Console.ReadLine();
                if (input != "Ok")
                {
                    sum += int.Parse(input);
                }
            }
            Console.WriteLine("The total sum of all input numbers is " + sum);
        }
        static void problemThree()
        {
            //calculate factoral of input number
            // ex. factoral of 5 = % * 4 * 3 * 2 * 1
            int input = 0;
            int factoral = 1;
            Console.WriteLine("Enter a number: ");
            string tempInput = Console.ReadLine();
            input = int.Parse(tempInput);
            for (int i = 1; i <= input; i++)
            {
                factoral *= i;
            }
            Console.WriteLine(input + "! = " + factoral);
        }
    }
}
