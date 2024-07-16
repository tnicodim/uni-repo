using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace lab5ex1
{
    internal class Program
    {
        public static int DisplayMenu()
        {
            Console.WriteLine("1. Cost of RSA key generation");
            Console.WriteLine("2. Cost of RSA key encryption");
            Console.WriteLine("3. Cost of RSA key decryption");
            Console.WriteLine("4. Cost of RSA key signing");
            Console.WriteLine("5. Exit!");
            Console.Write("Your option : ");
            var result = Console.ReadLine();
            return Convert.ToInt32(result);
        }

        public static void TimeGeneration(int keySize)
        {
            RSACryptoServiceProvider myrsa = new RSACryptoServiceProvider(1600);
            Stopwatch swatch = new Stopwatch();
            int size;
            int count = 100;
            swatch.Start();

            for (int i = 0; i < count; i++)
            {
                myrsa = new RSACryptoServiceProvider(keySize);
                size = myrsa.KeySize;
            }
            swatch.Stop();
            long ms = swatch.ElapsedMilliseconds;
            double result = (double)ms / count;
            Console.WriteLine("\r\nGeneration time : " + result.ToString() + " ms");

            swatch.Reset();
        }

        static void Main(string[] args)
        {
            int keySize;

            int userInput = 0;
            do
            {
                switch (userInput)
                {{  case 1:
                        TimeGeneration(1024);
                        TimeGeneration(2048);
                        TimeGeneration(3072);
                        TimeGeneration(4096);
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    default:
                        //Console.WriteLine("Option selected does not exist!");
                        break;
                }
                userInput = DisplayMenu();
            } while (userInput != 5);
        }
    }
}
