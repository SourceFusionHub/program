import java.util.Scanner;

public class FibonacciSeries {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the limit for the Fibonacci series: ");
        int limit = scanner.nextInt();
        
        // Print Fibonacci series up to the specified limit
        for (int i = 0; i < limit; i++) {
            System.out.print(fibonacci(i) + " ");
        }
    }

    // Recursive method to calculate Fibonacci numbers
    public static int fibonacci(int n) {
        if (n <= 1) {
            return n;
        } else {
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }
}
