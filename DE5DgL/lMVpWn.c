#include <stdio.h>

int main() {
    // Declare variables to store the lengths of the three sides
    double side1, side2, side3;

    // Input the lengths of the three sides from the user
    printf("Enter the length of the first side: ");
    scanf("%lf", &side1);
    
    printf("Enter the length of the second side: ");
    scanf("%lf", &side2);
    
    printf("Enter the length of the third side: ");
    scanf("%lf", &side3);

    // Calculate the perimeter
    double perimeter = side1 + side2 + side3;

    // Print the result
    printf("The perimeter of the triangle is: %lf\n", perimeter);

    return 0;
}

