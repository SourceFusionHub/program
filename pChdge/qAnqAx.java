public interface Eatable {
    void eat();
}

public class Apple implements Eatable {
    @Override
    public void eat() {
        System.out.println("The apple is being eaten.");
    }
}

public class Main {
    public static void main(String[] args) {
        Apple apple = new Apple();
        apple.eat();
    }
}
