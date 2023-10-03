using System;

class Program
{
    static void Main()
    {
        double radius, angleDegrees;

        // Input the radius and angle in degrees
        Console.Write("Enter the radius of the circle: ");
        radius = Convert.ToDouble(Console.ReadLine());

        Console.Write("Enter the central angle in degrees: ");
        angleDegrees = Convert.ToDouble(Console.ReadLine());

        // Calculate the area of the sector
        double area = (angleDegrees / 360.0) * Math.PI * Math.Pow(radius, 2);

        // Display the result
        Console.WriteLine($"The area of the sector is: {area}");
    }
}
