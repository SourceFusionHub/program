public class SumCalculator {
    public static void main(String[] args) {
        int sum = 0;
        
        for (int i = 1; i <= 100; i++) {
            sum += i;
        }
        
        System.out.println("The sum of numbers from 1 to 100 is: " + sum);
    }
}
