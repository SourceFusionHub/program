public class ReverseString {
    public static void main(String[] args) {
        String original = "Hello, World!";
        String reversed = reverseString(original);
        System.out.println("Original: " + original);
        System.out.println("Reversed: " + reversed);
    }

    public static String reverseString(String input) {
        char[] charArray = input.toCharArray();

        int start = 0;
        int end = charArray.length - 1;

        // Reverse the characters in the array
        while (start < end) {
            // Swap characters at start and end positions
            char temp = charArray[start];
            charArray[start] = charArray[end];
            charArray[end] = temp;

            start++;
            end--;
        }

        // Convert the character array back to a string
        String reversed = new String(charArray);

        return reversed;
    }
}
