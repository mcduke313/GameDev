using System;
using System.Text.RegularExpressions;
using System.IO;

namespace DukeFileRead
{
    class Program
    {
        static void Main(string[] args)
        {
            //Input File Path
            Console.WriteLine("Enter the file path of a text document: ");
            string path = Console.ReadLine();

            //Test Path for directory conventions
            Regex PathTester = new Regex(@"\D\:(\/\w+)+");
            bool ValidPath = true;

            if (PathTester.IsMatch(path))
                Console.WriteLine("File path is Valid");
            else
            {
                Console.WriteLine("File path is not Valid");
                ValidPath = false;
            }
                
            //Test is Path leads to File
            bool FileExists = true;
            try
            {
                StreamReader testSR = new StreamReader(path);
                

            }
            catch
            {
                if(ValidPath)
                    Console.WriteLine("File Does not exist");
                FileExists = false;
            }

            
            if(FileExists)
            {
                //Read File
                StreamReader sr = new StreamReader(path);
                Console.WriteLine("Opening file...");
                string FileContents = "";
                string line = "";
                do
                {
                    line = sr.ReadLine();
                    FileContents += " " + line;
                } while (line != null);

                //Count and Output number of words
                FileContents = FileContents.Trim();
                string[] Array = FileContents.Split(' ');
                int SIZE = Array.Length;
                int Words = 0;

                for(int i = 0; i< SIZE; i++)
                {
                    Words++;
                }
                Console.WriteLine("There are " + Words + " words in the file.");
            }
            
        }
    }
}
