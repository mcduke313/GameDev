using System;

namespace DukeCar
{
    class Program
    {
        static void Main(string[] args)
        {
            Car car1 = new Car();
            Car car2 = new Car();
            Car car3 = new Car();

            int speedLimit;
            Console.WriteLine("What is the speed limit?");
            string tempSL = Console.ReadLine();
            speedLimit = int.Parse(tempSL);

            Console.WriteLine("What is the make of the first car?");
            car1.make = Console.ReadLine();
            Console.WriteLine("What is the model of the first car?");
            car1.model = Console.ReadLine();
            Console.WriteLine("What is the speed of the first car?");
            string tempSpeed = Console.ReadLine();
            car1.speed = int.Parse(tempSpeed);

            Console.WriteLine("What is the make of the second car?");
            car2.make = Console.ReadLine();
            Console.WriteLine("What is the model of the second car?");
            car2.model = Console.ReadLine();
            Console.WriteLine("What is the speed of the second car?");
            tempSpeed = Console.ReadLine();
            car2.speed = int.Parse(tempSpeed);

            Console.WriteLine("What is the make of the third car?");
            car3.make = Console.ReadLine();
            Console.WriteLine("What is the model of the third car?");
            car3.model = Console.ReadLine();
            Console.WriteLine("What is the speed of the third car?");
            tempSpeed = Console.ReadLine();
            car3.speed = int.Parse(tempSpeed);

            Console.WriteLine("Speed Limit: " + speedLimit);
            if (car1.speed < speedLimit)
            {
                Console.WriteLine(car1.make + " " + car1.model + " " + car1.speed + "mph: OK");
            }
            else
            {
                int difference = car1.speed - speedLimit;
                int demerits = difference / 5;
                if (demerits < 10)
                {
                    Console.WriteLine(car1.make + " " + car1.model + " " + car1.speed + "mph: " + demerits + " demerits");
                }
                else
                {
                    Console.WriteLine(car1.make + " " + car1.model + " " + car1.speed + "mph: " + demerits + " demerits <LICENSE SUSPENDED>");
                }
            }

            if (car2.speed < speedLimit)
            {
                Console.WriteLine(car2.make + " " + car2.model + " " + car2.speed + "mph: OK");
            }
            else
            {
                int difference = car2.speed - speedLimit;
                int demerits = difference / 5;
                if (demerits < 10)
                {
                    Console.WriteLine(car2.make + " " + car2.model + " " + car2.speed + "mph: " + demerits + " demerits");
                }
                else
                {
                    Console.WriteLine(car2.make + " " + car2.model + " " + car2.speed + "mph: " + demerits + " demerits <LICENSE SUSPENDED>");
                }
            }

            if (car3.speed < speedLimit)
            {
                Console.WriteLine(car3.make + " " + car3.model + " " + car3.speed + "mph: OK");
            }
            else
            {
                int difference = car3.speed - speedLimit;
                int demerits = difference / 5;
                if (demerits < 10)
                {
                    Console.WriteLine(car3.make + " " + car3.model + " " + car3.speed + "mph: " + demerits + " demerits");
                }
                else
                {
                    Console.WriteLine(car3.make + " " + car3.model + " " + car3.speed + "mph: " + demerits + " demerits <LICENSE SUSPENDED>");
                }
            }
        }
    }
    public class Car
    {
        public string make;
        public string model;
        public int speed;
    }
}
