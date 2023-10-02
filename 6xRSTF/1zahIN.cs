using System;

class Program
{
    // Recursive function to calculate factorial
    static long CalculateFactorial(int n)
    {
        if (n == 0)
        {
            return 1;
        }
        else
        {
            return n * CalculateFactorial(n - 1);
        }
    }

    static void Main()
    {
        Console.Write("Enter a positive integer: ");
        if (int.TryParse(Console.ReadLine(), out int num) && num >= 0)
        {
            long factorial = CalculateFactorial(num);
            Console.WriteLine($"Factorial of {num} is: {factorial}");
        }
        else
        {
            Console.WriteLine("Please enter a valid positive integer.");
        }
    }
}
