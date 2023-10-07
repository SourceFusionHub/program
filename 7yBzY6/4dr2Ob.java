interface Drawable {
    void draw();
}

class Circle implements Drawable {
    private int radius;

    public Circle(int radius) {
        this.radius = radius;
    }

    @Override
    public void draw() {
        System.out.println("Drawing a circle with radius " + radius);
    }

    public double calculateArea() {
        return Math.PI * radius * radius;
    }

    public double calculatePerimeter() {
        return 2 * Math.PI * radius;
    }
}

public class Main {
    public static void main(String[] args) {
        Circle myCircle = new Circle(5);
        myCircle.draw();
        System.out.println("Area: " + myCircle.calculateArea());
        System.out.println("Perimeter: " + myCircle.calculatePerimeter());
    }
}
