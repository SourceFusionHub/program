import java.util.Arrays;
import java.util.Comparator;

class Student {
    private String name;
    private int age;
    private double grade;

    public Student(String name, int age, double grade) {
        this.name = name;
        this.age = age;
        this.grade = grade;
    }

    public int getAge() {
        return age;
    }

    @Override
    public String toString() {
        return "Student [name=" + name + ", age=" + age + ", grade=" + grade + "]";
    }
}

public class Main {
    public static void main(String[] args) {
        Student[] students = new Student[]{
            new Student("Alice", 22, 85.5),
            new Student("Bob", 19, 91.0),
            new Student("Charlie", 20, 78.2),
            new Student("David", 21, 92.3)
        };

        
        Arrays.sort(students, new Comparator<Student>() {
            @Override
            public int compare(Student student1, Student student2) {
                return Integer.compare(student1.getAge(), student2.getAge());
            }
        });

       
        for (Student student : students) {
            System.out.println(student);
        }
    }
}
