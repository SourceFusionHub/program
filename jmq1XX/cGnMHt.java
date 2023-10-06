public class MyClass {
    private final int myFinalField; // Declare a final field

    public MyClass(int initialValue) {
        myFinalField = initialValue; // Initialize the final field in the constructor
    }

    public int getMyFinalField() {
        return myFinalField;
    }

    public static void main(String[] args) {
        MyClass obj = new MyClass(42);
        System.out.println("My final field value: " + obj.getMyFinalField());
    }
}
