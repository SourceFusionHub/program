public class Person {
    // Fields of the Person class
    String firstName;
    String lastName;
    int age;

    // Constructor to initialize the fields
    public Person(String firstName, String lastName, int age) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.age = age;
    }

    // Additional methods can be added here

    public static void main(String[] args) {
        // Creating an instance of Person using the constructor
        Person johnDoe = new Person("John", "Doe", 30);

        // Accessing the fields
        System.out.println("First Name: " + johnDoe.firstName);
        System.out.println("Last Name: " + johnDoe.lastName);
        System.out.println("Age: " + johnDoe.age);
    }
}
