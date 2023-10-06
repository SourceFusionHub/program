using System;
using System.Collections.Generic;

// Define a class for an Autonomous Aerial Vehicle (AAV)
class AAV
{
    public double X { get; set; } // X-coordinate
    public double Y { get; set; } // Y-coordinate
    public double Speed { get; set; } // Speed of the AAV
    public double Direction { get; set; } // Direction of movement (in degrees)

    public AAV(double x, double y, double speed, double direction)
    {
        X = x;
        Y = y;
        Speed = speed;
        Direction = direction;
    }

    public void Move()
    {
        // Update the position based on speed and direction
        X += Speed * Math.Cos(Direction * Math.PI / 180.0);
        Y += Speed * Math.Sin(Direction * Math.PI / 180.0);
    }
}

class Program
{
    static void Main()
    {
        // Create a list of AAVs
        List<AAV> swarm = new List<AAV>();

        // Initialize and add AAVs to the swarm
        swarm.Add(new AAV(0, 0, 1.0, 30.0));
        swarm.Add(new AAV(10, 5, 0.8, 60.0));
        swarm.Add(new AAV(-5, 7, 1.2, 120.0));

        // Simulate the movement of AAVs
        for (int i = 0; i < 100; i++)
        {
            Console.WriteLine("Time Step " + (i + 1));
            foreach (AAV aav in swarm)
            {
                aav.Move();
                Console.WriteLine($"AAV at ({aav.X}, {aav.Y})");
            }
        }
    }
}
