import java.util.Scanner;
public class SquarePerimeter{
    public static void main(String[] args) {
        // Create a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        // Prompt the user to enter the side length of the square
        System.out.print("Enter the side length of the square: ");

        // Read the side length from the user
        double sideLength = scanner.nextDouble();

        // Close the Scanner to prevent resource leak
        scanner.close();

        // Calculate the perimeter of the square
        double perimeter = 4 * sideLength;

        // Print the result
        System.out.println("The perimeter of the square is: " + perimeter);
    }
}
