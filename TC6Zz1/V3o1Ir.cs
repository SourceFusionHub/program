using System;
using System.Math;

public class RegularPolygon
{
    private int n; // number of sides
    private double s; // length of a side

    public RegularPolygon(int n, double s)
    {
        this.n = n;
        this.s = s;
    }

    public double GetArea()
    {
        return (n * s * s) / (4.0 * Math.Tan(Math.PI / n));
    }
}

public class Program
{
    public static void Main()
    {
        Console.WriteLine("Enter number of sides:");
        int n = int.Parse(Console.ReadLine());

        Console.WriteLine("Enter length of a side:");
        double s = double.Parse(Console.ReadLine());

        RegularPolygon polygon = new RegularPolygon(n, s);
        double area = polygon.GetArea();

        Console.WriteLine($"Area of the regular polygon with {n} sides and side length {s} is: {area}");
    }
}
