// Calculate the total marks and average marks of students
#include <stdio.h>

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    int marks[numStudents];
    
    int totalMarks = 0;
    float averageMarks;

    for (int i = 0; i < numStudents; i++) {
        printf("Enter marks for student %d: ", i + 1);
        scanf("%d", &marks[i]);
        totalMarks += marks[i];
    }

    averageMarks = (float)totalMarks / numStudents;

    printf("Total Marks: %d\n", totalMarks);
    printf("Average Marks: %.2f\n", averageMarks);

    return 0;
}
