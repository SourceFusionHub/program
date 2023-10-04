using System;

class Program
{
    static void Main()
    {
        Console.Write("Enter the length of a side of the icositetragon: ");
        double sideLength = Convert.ToDouble(Console.ReadLine());

        int numberOfSides = 24; 

        double area = CalculateIcositetragonArea(numberOfSides, sideLength);

        Console.WriteLine($"Area of the regular icositetragon: {area}");
    }

    static double CalculateIcositetragonArea(int numberOfSides, double sideLength)
    {
        double pi = Math.PI;
        double interiorAngle = 2 * pi / numberOfSides;
        double tanValue = Math.Tan(interiorAngle / 2);

        double area = (numberOfSides * Math.Pow(sideLength, 2)) / (4 * tanValue);
        return area;
    }
}
