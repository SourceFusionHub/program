class Box<T> {
    private T value;

    public Box(T value) {
        this.value = value;
    }

    public T getValue() {
        return value;
    }

    public void setValue(T value) {
        this.value = value;
    }
}
public class Main {
    public static void main(String[] args) {
        Box<Integer> integerBox = new Box<>(7); 
        int storedValue = integerBox.getValue(); 
        System.out.println("The stored integer is: " + storedValue);
    }
}
