using System;

public class AuNoEo
{
    private double radius;
    private double height;

    public Cylinder(double radius, double height)
    {
        this.radius = radius;
        this.height = height;
    }

    public double CalculateSurfaceArea()
    {
        double baseArea = Math.PI * Math.Pow(radius, 2);
        double lateralArea = 2 * Math.PI * radius * height;

        return 2 * baseArea + lateralArea;
    }

    public static void Main(string[] args)
    {
        Console.Write("Enter the radius of the cylinder: ");
        double r = double.Parse(Console.ReadLine());

        Console.Write("Enter the height of the cylinder: ");
        double h = double.Parse(Console.ReadLine());

        Cylinder cylinder = new Cylinder(r, h);
        double surfaceArea = cylinder.CalculateSurfaceArea();

        Console.WriteLine($"The surface area of the cylinder is: {surfaceArea}");
    }
}
