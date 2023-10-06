public class ReverseString {
    public static String reverseString(String str) {
        StringBuilder sb = new StringBuilder(str);
        return sb.reverse().toString();
    }

    public static void main(String[] args) {
        String str = "Hello, world!";
        String reversedString = reverseString(str);

        System.out.println(reversedString);
    }
}
