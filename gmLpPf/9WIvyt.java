import java.util.Random;

public class Main {
    public static void main(String[] args) {
        Random rand = new Random();
        int randomNumber = rand.nextInt(100) + 1; // Generates a random number between 1 and 100
        System.out.println("Random number between 1 and 100 is: " + randomNumber);
    }
}
