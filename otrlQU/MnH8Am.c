#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_AAVS 5   // Number of AAVs in the swarm
#define MAX_STEPS 10 // Maximum simulation steps

// Structure to represent an AAV's position
typedef struct {
    double x;
    double y;
} AAV;

// Function to update the position of an AAV
void updateAAVPosition(AAV *aav) {
    // Simulate random motion (for demonstration purposes)
    aav->x += (rand() % 3 - 1) * 0.1; // Random value between -0.1 and 0.1
    aav->y += (rand() % 3 - 1) * 0.1;
}

// Function to simulate the swarm of AAVs
void simulateSwarm(AAV swarm[], int numSteps) {
    int step;
    for (step = 0; step < numSteps; step++) {
        printf("Step %d:\n", step + 1);
        for (int i = 0; i < NUM_AAVS; i++) {
            updateAAVPosition(&swarm[i]);
            printf("AAV %d: Position (%.2lf, %.2lf)\n", i + 1, swarm[i].x, swarm[i].y);
        }
        printf("\n");
    }
}

int main() {
    // Initialize random number generator with a seed
    srand(time(NULL));

    // Create an array of AAVs
    AAV swarm[NUM_AAVS];

    // Initialize AAV positions
    for (int i = 0; i < NUM_AAVS; i++) {
        swarm[i].x = (double)(rand() % 100) / 10.0; // Random initial x position (0 to 10)
        swarm[i].y = (double)(rand() % 100) / 10.0; // Random initial y position (0 to 10)
    }

    // Simulate the swarm's behavior for a certain number of steps
    simulateSwarm(swarm, MAX_STEPS);

    return 0;
}


