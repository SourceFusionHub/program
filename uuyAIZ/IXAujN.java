public class SumCalculator {
  public static int calculateSum(int num1, int num2) {
    int sum = num1 + num2;
    
    return sum;
  }
  public static void main(String[] args) {
    int num1 = 5;
    int num2 = 10;
    
    int result = calculateSum(num1, num2);
    
    System.out.println("Sum of " + num1 + " and " + num2 + " is: " + result);
  }
}
