public class SmallestInThree {
    public static void main(String[] args) {
        int a = 20;
        int b = 10;
        int c = 30;
        int smallest = (a < b) ? (a < c ? a : c) : (b < c ? b : c);
        System.out.println(smallest + " is the smallest.");
    }
}
