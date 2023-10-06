import java.util.Scanner;

public class LeapYearChecker {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a year: ");
        int year = scanner.nextInt();
        
        if (isLeapYear(year)) {
            System.out.println(year + " is a leap year.");
        } else {
            System.out.println(year + " is not a leap year.");
        }
    }
    
    public static boolean isLeapYear(int year) {
         boolean ans = year % 4 == 0;
        if (year % 100 == 0){
            ans = false;
        }
        if (year % 400 == 0){
            ans = true;
        }
        return ans;
    }
}
