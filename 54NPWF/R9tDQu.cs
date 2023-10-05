using System;

class Program
{
    static void Main()
    {
        double baseArea, height, volume;

        Console.WriteLine("Enter the base area of the pyramid: ");
        if (!double.TryParse(Console.ReadLine(), out baseArea))
        {
            Console.WriteLine("Invalid input. Please enter a valid number for the base area.");
            return;
        }

        Console.WriteLine("Enter the height of the pyramid: ");
        if (!double.TryParse(Console.ReadLine(), out height))
        {
            Console.WriteLine("Invalid input. Please enter a valid number for the height.");
            return;
        }

        volume = (1.0 / 3) * baseArea * height;

        Console.WriteLine($"The volume of the pyramid is: {volume}");
    }
}
