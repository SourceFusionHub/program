using System;

class Program
{
    static void Main()
    {
        Console.Write("Enter the side length of the regular hexagon: ");
        if (double.TryParse(Console.ReadLine(), out double sideLength))
        {
            double area = CalculateHexagonArea(sideLength);
            Console.WriteLine($"The area of the regular hexagon is: {area}");
        }
        else
        {
            Console.WriteLine("Invalid input. Please enter a valid number for side length.");
        }
    }

    static double CalculateHexagonArea(double sideLength)
    {
        // Formula for the area of a regular hexagon: (3 * √3 * side length^2) / 2
        return (3 * Math.Sqrt(3) * Math.Pow(sideLength, 2)) / 2;
    }
}
