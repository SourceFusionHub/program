using System;

class Program
{
    static void Main()
    {
        // Input the radius and angle in degrees
        Console.Write("Enter the radius of the circle: ");
        double radius = Convert.ToDouble(Console.ReadLine());

        Console.Write("Enter the angle of the sector in degrees: ");
        double angleDegrees = Convert.ToDouble(Console.ReadLine());

        // Convert the angle from degrees to radians
        double angleRadians = angleDegrees * (Math.PI / 180.0);

        // Calculate the area of the sector
        double area = (angleRadians / (2 * Math.PI)) * Math.PI * Math.Pow(radius, 2);

        // Display the result
        Console.WriteLine("The area of the sector is: " + area);
    }
}
