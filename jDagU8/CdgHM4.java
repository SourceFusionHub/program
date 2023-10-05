public class MyClass {
    /*
     * In Java all parameters are passed by value. so the changes made to the
     * parameters inside the method have no effect on the original arguments passed.
     * so i made the swap to happen inside an array.
     */
    public static void swapValues(int[] arr) {
        arr[0] = arr[0] + arr[1];
        arr[1] = arr[0] - arr[1];
        arr[0] = arr[0] - arr[1];
    }

    public static void main(String args[]) {
        int[] values = {10, 5};
        
        swapValues(values);

        System.out.println("a: " + values[0] + ", b: " + values[1]);
    }
}
