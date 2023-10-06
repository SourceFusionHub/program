using System;

class Program
{
    public static bool IsLeapYear(int year)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    static void Main(string[] args)
    {
        Console.Write("Enter a year to check if it's a leap year: ");

        if (int.TryParse(Console.ReadLine(), out int year))
        {
            if (IsLeapYear(year))
            {
                Console.WriteLine(year + " is a leap year.");
            }
            else
            {
                Console.WriteLine(year + " is not a leap year.");
            }
        }
        else
        {
            Console.WriteLine("Invalid input. Please enter a valid year.");
        }
    }
}
