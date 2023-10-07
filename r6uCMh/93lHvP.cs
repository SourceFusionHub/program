using System;

class Program
{
    static void Main(string[] args)
    {
        Console.Write("Enter the number of elements in the array: ");
        int n = Convert.ToInt32(Console.ReadLine());

        int[] arr = new int[n];

        Console.WriteLine("Enter the elements of the array:");

        for (int i = 0; i < n; i++)
        {
            Console.Write($"Element {i + 1}: ");
            arr[i] = Convert.ToInt32(Console.ReadLine());
        }

        // Sort the array
        Array.Sort(arr);

        double median;

        // Calculate median
        if (n % 2 == 0)
            median = (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
        else
            median = arr[n / 2];

        Console.WriteLine($"The median of the array is: {median}");
    }
}
