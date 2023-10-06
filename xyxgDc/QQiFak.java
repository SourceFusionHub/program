import java.util.Scanner;

public class CylinderVolume {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Prompt user for radius and height
        System.out.print("Enter the radius of the cylinder: ");
        double radius = scanner.nextDouble();
        System.out.print("Enter the height of the cylinder: ");
        double height = scanner.nextDouble();

        // Calculate volume
        double volume = Math.PI * radius * radius * height;

        // Print volume
        System.out.println("The volume of the cylinder is: " + volume);
    }
}
