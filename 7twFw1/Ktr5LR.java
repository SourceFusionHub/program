public class BinarySearch {
    // Binary search function
    static int binarySearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Check if the target is at the middle
            if (arr[mid] == target)
                return mid;

            // If the target is greater, ignore the left half
            if (arr[mid] < target)
                left = mid + 1;

            // If the target is smaller, ignore the right half
            else
                right = mid - 1;
        }

        // If the target is not found in the array
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
        int target = 12;
        int result = binarySearch(arr, target);

        if (result != -1)
            System.out.println("Element found at index " + result);
        else
            System.out.println("Element not found in the array");
    }
}
