using System;

namespace MakeRectangle
{
    class Rectangle
    {
        public int length;
        public int width;

        public Rectangle()
        {

        }
        public Rectangle( int l, int w)
        {
            length = l;
            width = w;
        }
        

    }

    class Utility
    {
        public static int Area(int length, int width)
        {
            return length * width;
        }
        public static int Perimeter(int length, int width)
        {
            return 2 * (length + width);
        }
    }
    

    class Program
    {
        static void Main(string[] args)
        {
            Rectangle rect = new Rectangle();
            int l = 0;
            int w = 0;

            Console.WriteLine("Enter variable:_ ");
            string strVar = Console.ReadLine();
            int min = int.Parse(strVar);

            Console.WriteLine("Enter variable:_ ");
            strVar = Console.ReadLine();
            int max = int.Parse(strVar);

            MakeRectangle(min,max,l,w);

            rect.length = l;
            rect.width = w;

            Console.WriteLine("Length: " + rect.length);
            Console.WriteLine("Width: " + rect.width);
            Console.WriteLine("Area: " + Utility.Area(rect.length, rect.width));
            Console.WriteLine("Perimeter: " + Utility.Perimeter(rect.length, rect.width));
        }
        public static Random rand;
        static void MakeRectangle(int min, int max, out int l,out int w)
        {
            rand = new Random();
            l = rand.Next(min, max);
            w = rand.Next(min, max);
        }
    }
}
