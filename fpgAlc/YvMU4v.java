import java.util.Scanner;

public class GCDCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Ask the user to enter the count of numbers
        System.out.print("Enter the count of numbers: ");
        int count = scanner.nextInt();

        // Create an array to store the numbers
        int[] numbers = new int[count];

        // Ask the user to enter each number
        for (int i = 0; i < count; i++) {
            System.out.print("Enter number " + (i + 1) + ": ");
            numbers[i] = scanner.nextInt();
        }

        // Close the scanner
        scanner.close();

        // Find the GCD of the numbers
        int gcdResult = findGCD(numbers);

        // Print the GCD
        System.out.println("The GCD of the numbers is: " + gcdResult);
    }

    // Function to find the GCD of an array of numbers
    public static int findGCD(int[] numbers) {
        int result = numbers[0];
        for (int i = 1; i < numbers.length; i++) {
            result = gcd(result, numbers[i]);
        }
        return result;
    }

    // Function to find the GCD of two numbers using Euclidean algorithm
    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}
