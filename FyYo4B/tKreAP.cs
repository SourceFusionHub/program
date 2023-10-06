using System;

class Program
{
    static void Main()
    {
        Console.Write("Enter a number to calculate its square root: ");
        string input = Console.ReadLine();

        if (double.TryParse(input, out double number))
        {
            double squareRoot = Math.Sqrt(number);
            Console.WriteLine($"Square root of {number} is {squareRoot}");
        }
        else
        {
            Console.WriteLine("Invalid input. Please enter a valid number.");
        }
    }
}
