#include <stdio.h>
#include <math.h>

float calculateTriangleArea(float a, float b, float c) {
    float s = (a + b + c) / 2;
    float area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}

int main() {
    float side1, side2, side3;
    
    // Input the sides of the triangle
    printf("Enter the lengths of the sides of the triangle:\n");
    printf("Side 1: ");
    scanf("%f", &side1);
    printf("Side 2: ");
    scanf("%f", &side2);
    printf("Side 3: ");
    scanf("%f", &side3);
    
    // Calculate and output the area of the triangle
    float area = calculateTriangleArea(side1, side2, side3);
    printf("Area of the triangle: %.2f\n", area);
    
    return 0;
}
