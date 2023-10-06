#include <stdio.h>
#include <math.h>

// Function to calculate the cosine of an angle in degrees
double calculateCosine(double angleDegrees) {
    // Convert the angle from degrees to radians
    double angleRadians = angleDegrees * (M_PI / 180.0);

    // Calculate the cosine
    double cosineValue = cos(angleRadians);

    return cosineValue;
}

int main() {
    double angleDegrees;
    
    // Prompt the user for input
    printf("Enter an angle in degrees: ");
    scanf("%lf", &angleDegrees);

    // Calculate the cosine of the angle using the function
    double cosine = calculateCosine(angleDegrees);

    // Display the result
    printf("Cosine of %.2lf degrees is %.4lf\n", angleDegrees, cosine);

    return 0;
}

