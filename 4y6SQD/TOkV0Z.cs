using System;

public class Program
{
    public static double CalculateAverage(double num1, double num2, double num3)
    {
        // Calculate the average of the three numbers
        return (num1 + num2 + num3) / 3.0;
    }

    public static void Main(string[] args)
    {
        Console.WriteLine("Enter three numbers:");

        Console.Write("Number 1: ");
        double num1 = Convert.ToDouble(Console.ReadLine());

        Console.Write("Number 2: ");
        double num2 = Convert.ToDouble(Console.ReadLine());

        Console.Write("Number 3: ");
        double num3 = Convert.ToDouble(Console.ReadLine());

        // Calculate the average
        double average = CalculateAverage(num1, num2, num3);

        // Display the average
        Console.WriteLine("The average of {0}, {1}, and {2} is: {3}", num1, num2, num3, average);
    }
}
