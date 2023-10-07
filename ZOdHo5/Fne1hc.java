import java.util.Scanner;

public class AreaOfSector {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        //Created and imported the Scanner to accept inputs from user

        System.out.print("Enter the radius of the Circle: ");
        double radius = input.nextInt();
        //created a variable 'radius' to store the input for radius from the user

        System.out.print("Enter the angle of the Sector: ");
        double angle = input.nextInt();
        //created a variable 'angle' to store the input for angle of sector from the user

        //calling AreaOfSector
        AreaOfSector(radius, angle);


    }
    static void AreaOfSector(double radius, double angle)
    {
        //Creating a check to filter invalid angles
        if(angle >= 360)
        {
            System.out.println("Angle is not possible");
        }
        double area = ((22*radius*radius)/7) * (angle/360);
        System.out.print(area);
    }
}
