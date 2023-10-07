public class WVKbSc {
    private double width;
    private double height;

    // Constructor
    public WVKbSc(double width, double height) {
        this.width = width;
        this.height = height;
    }

    // Method to calculate the area of the rectangle
    public double calculateArea() {
        return width * height;
    }

    // Method to calculate the perimeter of the rectangle
    public double calculatePerimeter() {
        return 2 * (width + height);
    }

    // Method to display information about the rectangle
    public void displayInfo() {
        System.out.println("Width: " + width);
        System.out.println("Height: " + height);
        System.out.println("Area: " + calculateArea());
        System.out.println("Perimeter: " + calculatePerimeter());
    }

    public static void main(String[] args) {
        // Create a Rectangle object with a specified width and height
        WVKbSc rectangle = new WVKbSc(5.0, 7.0);

        // Display information about the rectangle
        rectangle.displayInfo();
    }
}