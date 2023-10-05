import java.util.Scanner;

public class StringLength {
    public static int getStringLength(String input) {
        return input.length();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String s = scanner.nextLine();

        int length = getStringLength(s);

        System.out.println("Length of the string: " + length);

        scanner.close();
    }
}
