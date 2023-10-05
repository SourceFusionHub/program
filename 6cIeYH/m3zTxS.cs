using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        // Define the vertices of the polygon as (x, y) coordinates
        List<Tuple<double, double>> vertices = new List<Tuple<double, double>>
        {
            new Tuple<double, double>(1.0, 1.0),
            new Tuple<double, double>(2.0, 2.0),
            new Tuple<double, double>(3.0, 1.0),
            new Tuple<double, double>(2.0, 0.0)
        };

        double area = CalculatePolygonArea(vertices);
        Console.WriteLine("Area of the irregular polygon: " + area);
    }

    static double CalculatePolygonArea(List<Tuple<double, double>> vertices)
    {
        int n = vertices.Count;
        double area = 0.0;

        for (int i = 0; i < n; i++)
        {
            double x1 = vertices[i].Item1;
            double y1 = vertices[i].Item2;
            double x2 = vertices[(i + 1) % n].Item1;
            double y2 = vertices[(i + 1) % n].Item2;

            area += (x1 * y2 - x2 * y1);
        }

        return Math.Abs(area) / 2.0;
    }
}
